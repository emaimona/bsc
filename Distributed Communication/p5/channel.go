package main

import (
	"fmt"
	"sync"
)

func main() {
	
	var wg sync.WaitGroup
	
	c := make(chan string)

	wg.Add(1)
	go func() { 
		defer wg.Done()
		s := "Hello" 
		c <- s
		fmt.Println("g1 sent ",s)
	}()

	wg.Add(1)
	go func() { 
		defer wg.Done()	
		r := <- c 
		fmt.Println("g2 received ", r)
	}()
	
	wg.Wait()

}