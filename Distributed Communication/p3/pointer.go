package main
import "fmt"
type student struct {
	name   string
	id string
}
func main() {
	adam := student{"Adam", "abcdef"}
	fmt.Println(adam)
	
	modifyStudentName(&adam, "Levi")
	fmt.Println(adam)
	
	animals := []string{
		"dog",
		"lion",
		"panda",
	}
	fmt.Println(animals)
	
	modifyFirstElement(animals, "cat")
	fmt.Println(animals)
}

func modifyStudentName(pointerToStudent *student, newName string) {
	(*pointerToStudent).name = newName
}

func modifyFirstElement(animals []string, newFirstElement string) {
	animals[0] = newFirstElement
}