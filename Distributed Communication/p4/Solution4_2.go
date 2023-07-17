package main

import (
	"fmt"
	 "sync"
	 "sync/atomic"
	 "math/rand"
)

func main(){

	var result uint64
	var wg sync.WaitGroup
	
	r := rand.Intn(1000) 
	
	for i := 0; i < r; i++ {
		wg.Add(1)
		go func () {
			defer wg.Done()
			atomic.AddUint64(&result, 1)
		}()
	}
	
	wg.Wait()
	
	fmt.Println(int(result)==r)
}