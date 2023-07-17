package main

import (
	"fmt"
	"github.com/streadway/amqp"
	"log"
	"strings"
)

func main() {
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
		"fanoutExchange", // name
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
		"fanoutExchange", // exchange
		false,
		nil)
	printErrorAndExit(err, "Failed to bind a queue")

	//Consume
	msgs, err := ch.Consume(
		q.Name, // queue
		"",     // consumer,empty string let server generate id
		false,  // auto-ack
		false,  // exclusive
		false,  // no-local
		false,  // no-wait
		nil,    // args
	)
	printErrorAndExit(err, "Failed to register a consumer")

	for i := 0; i < 4; i++ {
		go func() {
			for d := range msgs {
				bodyString := string(d.Body)
				lower := strings.ToUpper(bodyString)
				fmt.Println("Received:", bodyString, "Upper:", lower)
				d.Ack(false)
			}
		}()
	}

	fmt.Println("Waiting for msgs")
	forever := make(chan bool)
	<-forever
}

func printErrorAndExit(err error, msg string) {
	if err != nil {
		log.Fatalln(msg, ":", err)
	}
}
