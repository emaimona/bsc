package main
import "fmt"
func main() {
	animals := []string{
		"0_dog",
		"1_cat",
		"2_bird",
		"3_lion",
		"4_panda",
		"5_tiger",
		"6_wolf",
	}

	fmt.Println(animals[3])

	fmt.Println(animals[:3])
	
	fmt.Println(animals[3:])
	
	fmt.Println(animals[2:4])
	
	animals[3] = "SSS"
	fmt.Println(animals)
	
	result := append(animals[:2], animals[5:]...)
	fmt.Println(result)
}