package main
import "fmt"
func main(){
	fmt.Println("First")
	defer fmt.Println("Last1")
	defer fmt.Println("Last2")
	defer fmt.Println("Last3")
	fmt.Println("Second")
}
