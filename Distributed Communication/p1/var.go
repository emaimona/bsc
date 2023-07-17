package main

import "fmt"
var x, y, z bool              // package level variable
func main() {
	var i int                // function level variable
	fmt.Println(i, x, y, z)
}
