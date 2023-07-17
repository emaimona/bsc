package main

import (
	"fmt"
	"github.com/streadway/amqp"
	"log"
	"sync"
	"strconv"
)

func main() {
	var wt sync.WaitGroup
	//Connection
	conn, err := amqp.Dial("amqp://guest:guest@localhost:5672/")
	printErrorAndExit(err, "Failed to connect to RabbitMQ")
	defer conn.Close()

	//Channel
	ch, err := conn.Channel()
	printErrorAndExit(err, "Failed to open a channel")
	defer ch.Close()

	//Exchange
	err = ch.ExchangeDeclare(
		"p3fanoutExchange", // name
		"fanout",         // type
		false,            // durable
		true,             // auto-deleted
		false,            // internal
		false,            // no-wait
		nil,              // arguments
	)
	printErrorAndExit(err, "Failed to declare an exchange")

	//Decalre and bind queue
	q, err := ch.QueueDeclare(
		"",    // name,,empty string let server generate id
		false, // durable
		true,  // delete when unused
		true,  // exclusive
		false, // no-wait
		nil,   // arguments
	)
	printErrorAndExit(err, "Failed to declare a queue")
	err = ch.QueueBind(
		q.Name,           // queue name
		"",               // routing key
		"p3fanoutExchange", // exchange
		false,
		nil)
	printErrorAndExit(err, "Failed to bind a queue")

	//Consume
	msgs, err := ch.Consume(
		q.Name, // queue
		"Double",     // consumer,empty string let server generate id
		false,  // auto-ack
		false,  // exclusive
		false,  // no-local
		false,  // no-wait
		nil,    // args
	)
	printErrorAndExit(err, "Failed to register a consumer")

	wt.Add(1)
	go func() {
		for i := 0; i < 3; i++ {
			go func() {
				for d := range msgs {
					bodyString := string(d.Body)
					value, err := strconv.Atoi(bodyString)
					if err != nil {
						if (bodyString != "END") {
							log.Fatalln("Failed to convert to integer")
						} else {
							wt.Done()
							return
						}
					} else {
						double := value * 2
						fmt.Println("Received:", value, "Result:", double)
					}
					d.Ack(false)
				}
			}()
		}
	}()

	fmt.Println("Waiting for msgs")
	wt.Wait()
	fmt.Println("Finish")
}

func printErrorAndExit(err error, msg string) {
	if err != nil {
		log.Fatalln(msg, ":", err)
	}
}
