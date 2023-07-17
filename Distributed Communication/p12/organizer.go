package main
import (
	"fmt"
	"github.com/streadway/amqp"
	"log"
)
func main() {
	numWorkers := 10
	conn, err := amqp.Dial("amqp://guest:guest@localhost:5672/")
	failOnError(err, "Failed to connect to RabbitMQ")
	defer conn.Close()
	cho, err := conn.Channel()
	failOnError(err, "Failed to open a channel")
	err = cho.ExchangeDeclare("dispatch", "direct",
		false, true, false, false, nil)
	failOnError(err, "Failed to declare an exchange")
	for i := 0; i < numWorkers; i++ {
		msg := "1"
		err = cho.Publish("dispatch", "generator", false, false,
			amqp.Publishing{
				ContentType: "text/plain",
				Body:        []byte(msg),
			})

		failOnError(err, "Failed to publish a message")
		fmt.Printf("Organizer Published %s \n", string(msg))
	}

}
func failOnError(err error, msg string) {
	if err != nil {
		log.Fatalf("%s: %s", msg, err)
	}
}
