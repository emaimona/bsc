package main

import (
	"fmt"
	"sync"
	"time"
)

func main() {
	
	var wg sync.WaitGroup
	
	c := make(chan int,5)

	wg.Add(1)
	go func() { 
		defer wg.Done()
		for i:=0;i<10;i++{
			c<-i
			fmt.Println("g1 sent ",i)
		}
		close(c)
	}()

	wg.Add(1)
	go func() { 
		defer wg.Done()	
		time.Sleep(5*time.Second)
		for r := range c {
			fmt.Println("g2 received ", r)
		}
		
	}()
	
	wg.Wait()
}