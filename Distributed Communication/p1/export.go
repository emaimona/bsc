package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	fmt.Println("strconv-------")
	fmt.Println(strconv.IntSize)
	s := strconv.Itoa(1)
	fmt.Println(s)
	i, err := strconv.Atoi("2")
	if err != nil {
        panic(err)
    }
	fmt.Println(i)
	
	fmt.Println("strings-------")
	fmt.Println("ToLower: "+strings.ToLower("APPLE"))
	fmt.Println("ToUpper: "+strings.ToUpper("apple"))
	fmt.Println(strings.Contains("apple","pp"))
	fmt.Println(strings.Count("apple","p"))
	fmt.Println(strings.Split("a,p,p,l,e",","))
}

