package main

import (
	"fmt"
	"math/rand"
	"net/http"
	"sync"
	"sync/atomic"
	"time"
)

func main() {
	var wt sync.WaitGroup
	var mu sync.Mutex

	urls := []string{"www.google.com", "www.facebook.com", "www.asdfasfad.com", "www.ebay.com", "www.amazon.com"}
	urlMap := make(map[string]string)

	for _, url := range urls {
		wt.Add(1)
		go func(u string) {
			defer wt.Done()
			mu.Lock()
			urlMap[u] = linkTest(u)
			mu.Unlock()
		}(url)
	}

	// P2
	var result int64
	r := rand.Intn(1000)

	for i := 0; i < r; i++ {
		wt.Add(1)
		go func() {
			defer wt.Done()
			atomic.AddInt64(&result, 1)
		}()
	}

	wt.Wait()
	fmt.Println(urlMap)
	fmt.Println("The r", r, "and the result", result)
}

func linkTest(link string) string {
	client := http.Client{
		Timeout: 3 * time.Second,
	}
	_, err := client.Get("http://" + link)
	if err != nil {
		resultString := "bad"
		return resultString
	}
	resultString := "good"
	return resultString
}
