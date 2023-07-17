package main

import (
	"fmt"
	 "sync"
)

func main(){

	var wg sync.WaitGroup
	
	for i := 0; i < 5; i++ {
		wg.Add(1)
		go func (a int) {
			defer wg.Done()
			fmt.Println("Hi",a)
		}(i)
	}
	
	wg.Wait()
}