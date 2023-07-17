package main

import (
	"fmt"
	"sync"
	"time"
	"strconv"
)

type request struct {
	first string
	second string
	resp chan string
}

func main() {
	var wt sync.WaitGroup
	attach := make(chan request)
	reverse := make(chan request)	

	// g1
	wt.Add(1)
	go func() {
		defer wt.Done()
		for i := 0; i<3; i++ {
			time.Sleep(500 * time.Millisecond)
			s1 := strconv.Itoa(i)
			s2 := strconv.Itoa(i+1)
			req := request{first: s1, second: s2, resp: make(chan string)}
			attach <- req
			result := <- req.resp
			fmt.Println("(attach) g1 sent", req.first, req.second,  "received", result)
		}
 	}()


	// g2
	wt.Add(1)
	go func() {
		defer wt.Done()
		for i := 0; i<3; i++ {
			time.Sleep(500 * time.Millisecond)
			s1 := strconv.Itoa(i)
			s2 := strconv.Itoa(i+1)
			req := request{first: s1, second: s2, resp: make(chan string)}
			reverse <- req
			result := <- req.resp
			fmt.Println("(reverse) g2 sent", req.first, req.second,  "received", result)
		}
	}()


	//main
	go func() {
		wt.Wait()
	}()
	L: for {
		select {
			case req := <- attach:
				result := req.first + req.second
				req.resp <- result
				fmt.Println("(attach) Main received",req.first, req.second, "sent result", result)
			case req := <- reverse:
				result :=  req.second + req.first
				req.resp <- result
				fmt.Println("(reverse attach) Main received",req.first, req.second, "sent result", result)

			case <- time.After(3  * time.Second):
				fmt.Println("Timeout")
				break L
		}
	}
}

