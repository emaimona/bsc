package main
import (
    "fmt"
    "time"
)

func main() {
	c1 := make(chan int)
	c2 := make(chan int)
	
	go func() {
        for i := 0; i < 5; i++ {
			time.Sleep(500 * time.Millisecond)
			c1 <- i
			fmt.Println("g1 sent ", i)
		}
    }()
	
	go func() {
        for i := 0; i < 5; i++ {
			time.Sleep(500 * time.Millisecond)
			c2 <- i
			fmt.Println("g2 sent ", i)
		}
    }() 
	
	L: for {
        select {
        case msg := <-c1:
            fmt.Println("Main received ", msg, " from g1")
		case msg := <-c2:
            fmt.Println("Main received ", msg, " from g2")
        case <- time.After(3 * time.Second):
			fmt.Println("Timeout, Quit")
			break L
		}
    }
}
	