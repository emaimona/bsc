package main

import (
	"fmt"
	"github.com/rs/xid"
	"github.com/streadway/amqp"
	"log"
	"sync"
)

func main() {
	conn1, err := amqp.Dial("amqp://guest:guest@localhost:5672/")
	failOnError(err, "Failed to connect to RabbitMQ")
	defer conn1.Close()

	conn2, err := amqp.Dial("amqp://guest:guest@localhost:5672/")
	failOnError(err, "Failed to connect to RabbitMQ")
	defer conn2.Close()

	cho, err := conn1.Channel()
	failOnError(err, "Failed to open a channel")
	defer cho.Close()
	chi, err := conn2.Channel()
	failOnError(err, "Failed to open a channel")
	defer chi.Close()

	err = cho.ExchangeDeclare("solutionExchange", "direct", false, true, false, false, nil)
	failOnError(err, "Failed to declare an exchange")

	q, err := chi.QueueDeclare("", false, true, false, false, nil)
	failOnError(err, "Failed to declare a queue")

	err = chi.QueueBind(q.Name, q.Name, "solutionExchange", false, nil)
	failOnError(err, "Failed to bind a queue")

	msgs, err := chi.Consume(q.Name, "", false, false, false, false, nil)
	failOnError(err, "Failed to register a consumer")

	var jobCorr = make(map[string]string)
	var mu sync.Mutex

	go func() {
		for d := range msgs {
			mu.Lock()
			v, ok := jobCorr[d.CorrelationId]
			if ok {
				fmt.Println("Job:", v, "Got response:"+string(d.Body))
				delete(jobCorr, d.CorrelationId)
			} else {
				fmt.Println("Got a not related msg")
			}
			mu.Unlock()
			d.Ack(false)
		}
	}()

	links := []string{}
	for i := 10; i < 20; i++ {
		fakeLink := fmt.Sprintf("http://web%d.com", i)
		links = append(links, fakeLink)
	}

	for _, link := range links {
		var corrId = randomString()
		err := cho.Publish("solutionExchange", "key", false, false,
			amqp.Publishing{
				ContentType:   "text/plain",
				CorrelationId: corrId,
				ReplyTo:       q.Name,
				Body:          []byte(link),
			})

		failOnError(err, "Failed to publish")
		fmt.Println("Published job:" + link)
		mu.Lock()
		jobCorr[corrId] = link
		mu.Unlock()
	}

	forever := make(chan bool)
	<-forever
}
func failOnError(err error, msg string) {
	if err != nil {
		log.Fatalf("%s: %s", msg, err)
	}
}

func randomString() string {
	guid := xid.New()
	return guid.String()
}
