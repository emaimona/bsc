package main
import "fmt"
func main(){
	fmt.Println("First")
	defer fmt.Println("Last")
	fmt.Println("Second")
}
