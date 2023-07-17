package main

import (
	"fmt"
	"github.com/rs/xid"
	"github.com/streadway/amqp"
	"log"
	"sync"
	"strconv"
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

	err = cho.ExchangeDeclare("p4Exchange", "direct", false, true, false, false, nil)
	failOnError(err, "Failed to declare an exchange")

	q, err := chi.QueueDeclare("", false, true, false, false, nil)
	failOnError(err, "Failed to declare a queue")

	err = chi.QueueBind(q.Name, q.Name, "p4Exchange", false, nil)
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

	jobs := []string{
		"123",
		"abc",
		"abb",
		"ccd",
		"456",
	}
	

	for _, link := range jobs {
		var corrId = randomString()

		
		if isNumber(link) {
			err := cho.Publish("p4Exchange", "int", false, false,
			amqp.Publishing{
				ContentType:   "text/plain",
				CorrelationId: corrId,
				ReplyTo:       q.Name,
				Body:          []byte(link),
			})
			fmt.Println("Published job:" + link)
			failOnError(err, "Failed to publish")
		} else {
			err := cho.Publish("p4Exchange", "string", false, false,
			amqp.Publishing{
				ContentType:   "text/plain",
				CorrelationId: corrId,
				ReplyTo:       q.Name,
				Body:          []byte(link),
			})
			fmt.Println("Published job:" + link)
			failOnError(err, "Failed to publish")
		}
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


//, it will check if the message is a number by try to convert it to integer 
func isNumber(s string) bool {
	_, err := strconv.Atoi(s)
	return err == nil
}