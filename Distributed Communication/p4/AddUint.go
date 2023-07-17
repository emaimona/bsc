package main

import (
	"fmt"
	 "sync"
	 "sync/atomic"
)

func main(){

	var result uint64
	var wg sync.WaitGroup
	
	for i := 0; i < 1000; i++ {
		wg.Add(1)
		go func (a int) {
			defer wg.Done()
			u:= uint64(a)
			atomic.AddUint64(&result, u)
		}(i)
	}
	
	wg.Wait()
	
	fmt.Println(result)
}