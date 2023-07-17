package main
import (
	"fmt"
	"github.com/streadway/amqp"
	"log"
	"os/exec"
)
func main() {
	conn, err := amqp.Dial("amqp://guest:guest@localhost:5672/")
	failOnError(err, "Failed to connect to RabbitMQ")
	defer conn.Close()
	ch, err := conn.Channel()
	failOnError(err, "Failed to open a channel")
	err = ch.ExchangeDeclare("dispatch", "direct", false, true, false, false, nil)
	failOnError(err, "Failed to declare an exchange")
	queueArg, err := ch.QueueDeclare("generatorQueue", false, true, false, false, nil)
	failOnError(err, "Failed to declare a queue")
	err = ch.QueueBind(queueArg.Name, "generator", "dispatch", false, nil)
	failOnError(err, "Failed to bind a queue")
	msg, err := ch.Consume(queueArg.Name, "", false, false, false, false, nil)
	failOnError(err, "Failed to register a consumer")
	go func() {
		for d := range msg {
			// cmd := exec.Command("cmd", "/C", "start", "go", "run", "./Reply_Server.go")
			//cmd := exec.Command("./main") //* go build -o main Reply_Server.go
			cmd := exec.Command("go", "run", "./Reply_Server.go")
			// cmd := exec.Command("bash", "-c", "go run ./Reply_Server.go")
			err = cmd.Run()

			failOnError(err, "Failed to generate server")
			fmt.Println("generated one server")
			d.Ack(false)
		}
	}()
	forever := make(chan bool)
	<-forever
}
func failOnError(err error, msg string) {
	if err != nil {
		log.Fatalf("%s: %s", msg, err)
	}
}