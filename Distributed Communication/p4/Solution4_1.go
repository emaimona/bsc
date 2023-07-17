package main

import (
	"fmt"
	 "sync"
	 "net/http"
	 "time"
)

func main(){

	urls := []string{"www.google.com", "www.facebook.com","www.asdfasfad.com","www.ebay.com","www.amazon.com"}


	var mu sync.Mutex
	var wg sync.WaitGroup
	
	urlMap := make(map[string]string)
	
	for _, v := range urls {
		wg.Add(1)
		go func (a string) {
			defer wg.Done()
			mu.Lock()
			urlMap[a] = linkTest(a)
			mu.Unlock()
		}(v)
	}
	
	wg.Wait()
	
	fmt.Println(urlMap)
}

func linkTest(link string) string {
	client := http.Client{
		Timeout: 3*time.Second,
	}
	_, err := client.Get("http://"+link)
	if err != nil {
		resultString := "bad"
		return resultString
	}
	resultString := "good"
	return resultString
}