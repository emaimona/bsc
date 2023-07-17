package main
import "fmt"

type student struct {
	name   string
	id string
}

type neptun string

func main() {
	adam := student{"Adam", "abcdef"}
	fmt.Println(adam.getNameR())
	fmt.Println(getNameA(adam))
	
	var aNeptun neptun = "asdf"
	aNeptun.printId()
}

func (s student) getNameR() string {
	return s.name
}

func getNameA(s student) string {
	return s.name
}

func (i neptun) printId(){
	fmt.Println(i)
}
