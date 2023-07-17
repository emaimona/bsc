package main
import "fmt"

type student struct {
	name   string
	id string
}
func main() {
	adam := student{"Adam",  "abcdef"}
	fmt.Println(adam)
	fmt.Println(adam.name)
	
	adam.id = "nnnnn"
	fmt.Println(adam)
}