package main

import ("fmt")

func main(){
	fmt.Println(multiplicateR(3,4))
}

func multiplicateR (a int, b int) int{
	if a== 0{
		return 0
	}
	return b + multiplicateR(a-1, b)
}