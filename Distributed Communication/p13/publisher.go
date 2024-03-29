package main

import (
	"fmt"
	"github.com/streadway/amqp"
	"log"
)

func main() {
	//Connection
	conn, err := amqp.Dial("amqp://admin:admin@192.168.0.183:5672/")
	printErrorAndExit(err, "Failed to connect to RabbitMQ")
	defer conn.Close()

	//Channel
	ch, err := conn.Channel()
	printErrorAndExit(err, "Failed to open a channel")
	defer ch.Close()

	//Exchange
	err = ch.ExchangeDeclare(
		"jobExchange", // name
		"direct",      // type
		false,         // durable
		true,          // auto-deleted
		false,         // internal
		false,         // no-wait
		nil,           // arguments
	)
	printErrorAndExit(err, "Failed to declare an exchange")

	//Send Message
	body := "Hi"
	err = ch.Publish(
		"jobExchange", // exchange
		"jobkey",      // routing key
		false,         // mandatory
		false,         // immediate
		amqp.Publishing{
			ContentType: "text/plain",
			Body:        []byte(body),
		})
	printErrorAndExit(err, "Failed to publish a message")
	fmt.Println("Sent: ", body)
}

func printErrorAndExit(err error, msg string) {
	if err != nil {
		log.Fatalln(msg, ":", err)
	}
}
