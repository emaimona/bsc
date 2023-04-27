package main

import (
	"fmt"
	"sync"
	"sync/atomic"
)

func main() {
	var wg sync.WaitGroup
	var receivedCount uint64
	c := make(chan int)

	// g1
	wg.Add(1)
	go func() {
		defer wg.Done()
		for i:=0; i<=11; i++ {
			c <- i
			fmt.Printf("g1 sent < %d >\n", i)
		}
		close(c)
	} ()


	// g2
	wg.Add(1)
	go func() {
		defer wg.Done()

		for message := range c {
			fmt.Printf("g2 received< %d >\n", message)
			atomic.AddUint64(&receivedCount, uint64(1))
		}
	} ()

	wg.Wait()
	fmt.Println("\nReceived count:", receivedCount)
}