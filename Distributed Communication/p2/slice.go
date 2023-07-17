package main
import "fmt"
func main() {
	animals := []string{
		"dog",
		"cat",
		"bird",
		"lion",
	}
	animals = append(animals, "panda")
	animals = append(animals, "tiger", "wolf")
	for index, animal := range animals {
		fmt.Println(index, animal)
	}
	for _, animal := range animals {
		fmt.Println(animal)
	}
}