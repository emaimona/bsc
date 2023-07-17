package main
import (
    "fmt"
    "time"
)

func main() {
	c := make(chan chan string)
	
	go func() {
		//time.Sleep(4 * time.Second)
		insideC:= <- c
		fmt.Println("g1 receive the channel inside")
		insideC <- "Hello"
		fmt.Println("g1 sent Hello to the channel inside")
    }()
	
	in:= make(chan string)
    select {
    case c <- in:
        fmt.Println("Main send the channel inside")
		resp:= <- in
		fmt.Println("Main received", resp)
    case <- time.After(3 * time.Second):
		fmt.Println("Timeout, Quit")
		break
	}
}
	