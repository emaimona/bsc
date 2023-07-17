package main

import (
	"fmt"
	"time"
)

func main(){
	go printR("Hi 1")
	go print("Hi 2")
	time.Sleep(1 * time.Second)

}

func print(s string) {
	fmt.Println(s)
}


func printR(s string) string {
	fmt.Println(s)
	return s
}

