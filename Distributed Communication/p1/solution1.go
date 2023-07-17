package main

import (
	"fmt"
	"strconv"
	"errors"
	"strings"
)


func main(){
	result1:= inc(3)
	fmt.Println(result1)
	
	result2:= isEven(3)
	fmt.Println(result2)
	
	result3:= devides(3, 9)
	fmt.Println(result3)
	
	result4:= area(3, 4)
	fmt.Println(result4)
	
	result5, err := stringAdd("3", "4")
	fmt.Println(result5, err)
	
	result6, err := stringAdd("3", "a")
	fmt.Println(result6, err)
	
	result7 := isUpper("Apple")
	fmt.Println(result7)
	
	result8 := isUpper("APPLE")
	fmt.Println(result8)
}

func inc(a int) int {
	return a+1
}

func isEven(a int) bool {
	return (a%2)==0
}

func devides(a int, b int) bool {
	if a <= 0 {
		return false
	}
	return (b%a)==0
}

func area(a int, b int) int {
	return a*b
}

func stringAdd(a string, b string) (int, error) {
	i, err1 := strconv.Atoi(a)
	j, err2 := strconv.Atoi(b)
	
	if err1 != nil || err2 != nil{
		return -1, errors.New("Failed to convert")
	}
	
	return i+j, nil
}

func isUpper(s string) bool {
	return strings.ToUpper(s)==s
}


