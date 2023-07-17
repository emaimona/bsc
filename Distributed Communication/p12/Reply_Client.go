package main

import (
	"fmt"
	"github.com/rs/xid"
	"github.com/streadway/amqp"
	"log"
	"strconv"
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

	err = cho.ExchangeDeclare("replyExchange", "direct", false, true, false, false, nil)
	failOnError(err, "Failed to declare an exchange")

	q, err := chi.QueueDeclare("", false, true, false, false, nil)
	failOnError(err, "Failed to declare a queue")

	err = chi.QueueBind(q.Name, q.Name, "replyExchange", false, nil)
	failOnError(err, "Failed to bind a queue")

	var jobCorr = make(map[string]string)
	var mu sync.Mutex

	msgs, err := chi.Consume(q.Name, "", false, false, false, false, nil)
	failOnError(err, "Failed to register a consumer")

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

	ints := []string{}
	for i := 0; i < 10; i++ {
		s := strconv.Itoa(i)
		ints = append(ints, s)
	}

	for _, i := range ints {
		var corrId = randomString()
		err := cho.Publish("replyExchange", "key", false, false,
			amqp.Publishing{
				ContentType:   "text/plain",
				CorrelationId: corrId,
				ReplyTo:       q.Name,
				Body:          []byte(i),
			})

		failOnError(err, "Failed to publish")
		fmt.Println("Published job:" + i)
		mu.Lock()
		jobCorr[corrId] = i
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
