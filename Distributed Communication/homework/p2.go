package main

import (
	"fmt"
	"sync"
	"strconv"
)

func main() {
	var wg sync.WaitGroup
	var mu sync.Mutex

	ints := [] int {1,2,-3,-4,5}
	intMap := make(map[int]string)

	for _, val := range ints {
		wg.Add(1)
		go func(n int) {
			defer wg.Done()
			mu.Lock()
			intMap[n] = strconv.Itoa(handleInt(n))
			mu.Unlock()
		} (val)
	}


	wg.Wait()
	fmt.Println(intMap)
}

func handleInt(n int) int {
	return (n+6)*3 
}