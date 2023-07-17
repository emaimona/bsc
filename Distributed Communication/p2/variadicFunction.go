package main

import ("fmt")

func main(){
	result1 := product(2,3)
	fmt.Println(result1)
	
	result2 := product(2,3,4)
	fmt.Println(result2)
}

func product(nums ...int) int {
    result := 1
    for _, num := range nums {
        result *= num
    }
    return result
}