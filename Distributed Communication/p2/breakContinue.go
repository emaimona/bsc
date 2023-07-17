package main

import("fmt")

func main(){
	fmt.Println("break")
	for i:=0; i<5 ;i++{
		if i == 3 {
			break
		}
		fmt.Println("i",i)
	}
	
	fmt.Println("continue")
	for i:=0; i<5 ;i++{
		if i == 3 {
			continue
		}
		fmt.Println("i",i)
	}
}