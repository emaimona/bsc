package main

import (
	"fmt"
	"log"
	"math/rand"
	"sync"
	"time"

	"github.com/streadway/amqp"
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
	err = cho.ExchangeDeclare("pExchange", "direct",
		false, true, false, false, nil)
	failOnError(err, "Failed to declare an exchange")
	q, err := chi.QueueDeclare("", false, true, false, false, nil)
	failOnError(err, "Failed to declare a queue")
	err = chi.QueueBind(q.Name, "key", "pExchange", false, nil)
	failOnError(err, "Failed to bind a queue")
	msgs, err := chi.Consume(q.Name, "",
		false, false, false, false, nil)
	failOnError(err, "Failed to register a consumer")
	for i := 0; i < 100; i++ {
		fakeLink := fmt.Sprintf("http://web%d.com", i)
		err := cho.Publish("pExchange", "key", false, false,
			amqp.Publishing{
				ContentType: "text/plain",
				Body:        []byte(fakeLink),
			})
		failOnError(err, "Failed to publish")
		fmt.Println("Published job:" + fakeLink)
	}
	err = cho.Publish("pExchange", "key", false, false,
		amqp.Publishing{
			ContentType: "text/plain",
			Body:        []byte("END"),
		})
	failOnError(err, "Failed to publish")
	fmt.Println("Published END")
	var wg sync.WaitGroup
	start := time.Now()
	wg.Add(1)
	go func() {
		for d := range msgs {
			s := string(d.Body)
			if s == "END" {
				err = chi.Cancel(d.ConsumerTag, false)
				failOnError(err, "Failed to cancel a consumer")
			} else {
				result := linkTest(s)
				fmt.Println("goroutine", result)
			}
			d.Ack(false)
		}
		wg.Done()
	}()
	wg.Wait()
	duration := time.Since(start)
	fmt.Println("Time: ", duration)
}
func failOnError(err error, msg string) {
	if err != nil {
		log.Fatalf("%s: %s", msg, err)
	}
}
func linkTest(link string) string {
	time.Sleep(100 * time.Millisecond)
	if rand.Intn(2) == 1 {
		return link + ":Good"
	} else {
		return link + ":Bad"
	}
}
