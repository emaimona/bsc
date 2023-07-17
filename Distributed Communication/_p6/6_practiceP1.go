package main

import (
	"fmt"
	// "sync"
	"time"
)

type chs chan string

func main() {
	c := make(chan chs)

	// g1
	go func() {
		insideC := <-c
		fmt.Println("g1 receive the channel inside")
		insideC <- "Hello"
		fmt.Println("g1 sent Hello to the channel inside")
	}()

	// Main
	in := make(chs)
	
	select {
	case c <- in:
		fmt.Println("Main send the channel inside")
		msg := <- in
		fmt.Println("Main received", msg)
	case <-time.After(3 * time.Second):
		fmt.Println("Timeout, Quit")
		break
	}
}
