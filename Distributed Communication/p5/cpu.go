package main

import (
	"fmt"
	"sync"
	"time"
	"runtime"
)

func main(){
	fmt.Println(runtime.NumCPU())
	_ = runtime.GOMAXPROCS(1)
	
	start := time.Now()
	var mu sync.Mutex
	var wg sync.WaitGroup
	
	var result = 0
	
	for i := 0; i < 10000; i++ {
		wg.Add(1)
		go func (a int) {
			defer wg.Done()
			mu.Lock()
			result += a
			mu.Unlock()
		}(i)
	}
	
	wg.Wait()
	
	fmt.Println(result)
	duration := time.Since(start)
    fmt.Println("Time: ", duration)
}
