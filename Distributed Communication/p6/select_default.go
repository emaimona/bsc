package main
import (
    "fmt"
    "time"
)

func main() {
	c := make(chan int)
	
	go func() {
		time.Sleep(2 * time.Second)
		c <- 1
		fmt.Println("g1 sent 1")
    }()
	
	L: for {
        select {
        case msg := <-c:
            fmt.Println("Main received ", msg)
			break L
		default:
			time.Sleep(500 * time.Millisecond)
			fmt.Println("Default")
		}
    }
}
	