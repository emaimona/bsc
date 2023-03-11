package main

import (
	"fmt"
	"strconv"
)



func fibonnaci(x int) int{
	if (x == 1) {
		return x
	}
	if (x == 2) {
		return x
	}
	return (fibonnaci(x-1) + fibonnaci(x-1))
}


func Append(slice []string) []string {

	for i:=2; i<8; i++ {
		slice = append(slice, "www.web"+strconv.Itoa(i)+".com")
	}

	return slice
}


func PrintSlice(slice []string) {
	fmt.Println()

	for index, s := range slice {
		fmt.Println(index, s)
	}
}



func Nsum(nums ...int) int {
	sum := 0
	for _, i := range nums {
		sum += i
	}
	
	return sum
}

func main() {
	var a int
	var b int
	a = 6
	b = 7
	fmt.Println("Fibbonaci of 6 = ", fibonnaci(a))
	fmt.Println("Fibonnaci of 7 =", fibonnaci(b))


	urls := []string {
		"www.google.com", 
		"www.facebook.com",
	}

	urls = Append(urls)

	// Printing Slices of strings
	PrintSlice(urls)


	// Variadic functions
	nsum := Nsum(1,2,3,4)

	fmt.Println("\n", "Sum of 1, 2, 3, 4 = ", nsum)

}