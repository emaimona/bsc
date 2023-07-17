package main

import (
	"fmt"
	"strconv"
)

func main(){
	result1 := fibonacci(6);
	fmt.Println(result1)
	
	result2 := fibonacci(7);
	fmt.Println(result2)

	urls := []string{"www.google.com", "www.facebook.com"}

	for i:=2;i<9;i++ {
		url := "www.web" + strconv.Itoa(i)+".com"
		urls = append(urls, url)
	}

	for _ ,u := range urls{
		fmt.Println(u)
	}
	
	result3 := sum(2,3)
	fmt.Println(result3)
	
	result4 := sum(2,3,4)
	fmt.Println(result4)
}

func fibonacci(n int) int {
	if (n == 1) {
		return 0
	}
	if (n == 2) {
		return 1
	}
	return fibonacci(n-1)+fibonacci(n-2)
} 

func sum(nums ...int) int {
    result := 0
    for _, num := range nums {
        result += num
    }
    return result
}

