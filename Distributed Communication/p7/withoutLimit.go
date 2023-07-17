package main

import (
	"fmt"
	"math/rand"
	"runtime"
	"sync"
	"sync/atomic"
	"time"
)

var jobQueue = make(chan string, 100)
var maxGo uint64
var wg sync.WaitGroup

func main() {
	go goroutineCounter()

	start := time.Now()
	wg.Add(1)
	go linkSender()

	wg.Add(1)
	go workerCreator()

	wg.Wait()

	fmt.Println("Max goroutine number: ", atomic.LoadUint64(&maxGo))
	duration := time.Since(start)
	fmt.Println("Time: ", duration)
}
func goroutineCounter() {
	for {
		n := runtime.NumGoroutine()
		u := uint64(n)
		if u > maxGo {
			atomic.StoreUint64(&maxGo, u)
		}
		time.Sleep(50 * time.Millisecond)
	}
}

func linkSender() {
	defer wg.Done()
	links := []string{}
	var numOfLink = 1000
	for i := 0; i < numOfLink; i++ {
		fakeLink := fmt.Sprintf("http://web%d.com", i)
		links = append(links, fakeLink)
	}
	for _, link := range links {
		jobQueue <- link
	}
	close(jobQueue)
}

func workerCreator() {
	defer wg.Done()
	for link := range jobQueue {
		wg.Add(1)
		go worker(link)
	}
}

func worker(l string) {
	defer wg.Done()
	fmt.Println(linkTest(l))
}

func linkTest(link string) string {
	time.Sleep(500 * time.Millisecond)
	if rand.Intn(2) == 1 {
		return link + ": Good"
	} else {
		return link + ": Bad"
	}
}
