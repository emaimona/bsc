package main

import (
	"fmt"
	"sync"
	"sync/atomic"
)

func main() {
	var receivedCount uint64
	var wt sync.WaitGroup

	c := make(chan int)

	// g1
	wt.Add(1)
	go func() {
		defer wt.Done()
		for i:=0; i<=9; i++ {
			c <- i
			fmt.Println("g1 sent", i)
		}
	}()

	// g2
	go func() {
		defer wt.Done()
		for msg := range c {
			fmt.Println("g2 received", msg)
			atomic.AddUint64(&receivedCount, 1)
		}
	}()


	wt.Wait()
	fmt.Println("Received count:", receivedCount)
}


