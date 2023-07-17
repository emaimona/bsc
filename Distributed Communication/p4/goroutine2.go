package main

import (
	"fmt"
	"time"
)

func main(){
	go func () {
		fmt.Println("Hi 1")
	}()
	
	go func (s string) {
		fmt.Println(s)
	}("Hi 2")
	
	time.Sleep(1 * time.Second)
}


