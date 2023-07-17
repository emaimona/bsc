package main

import (
	"fmt"
	 "sync"
)

func main(){

	var wg sync.WaitGroup
	
	var result = 0
	
	for i := 0; i < 1000; i++ {
		wg.Add(1)
		go func (a int) {
			defer wg.Done()
			result += a
		}(i)
	}
	
	wg.Wait()
	
	fmt.Println(result)
}