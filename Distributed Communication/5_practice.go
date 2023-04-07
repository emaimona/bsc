package main;

import (
	"fmt"
	"sync"
	"time"
)

func main() {
	var wg sync.WaitGroup
	c := make(chan string)

	wg.Add(1)

	go func() {
		defer wg.Done()
		c <- "Hello"
		fmt.Println("G1 sent Hello")
		close(c)
	} ()

	message := <- c
	fmt.Println("The message was: ", message)
	wg.Wait()




	// P2
	chint := make(chan int, 5)
	wg.Add(1)
	go func() {
		// defer wg.Done()

		for i:=0; i<9; i++ {
			chint <- i 
			fmt.Println("g1 sent ", i)
		}
		close(chint)
 	} ()

	go func() {
		defer wg.Done()
		time.Sleep(2*time.Second)
		for r := range chint {
			fmt.Println("g2 recieved ", r)
		}
	} ()


	wg.Wait()

}