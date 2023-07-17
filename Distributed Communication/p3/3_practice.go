package main
import "fmt"


type animal struct {
	specie string
	name string
}

func (a *animal) setName(name string) {
	(*a).name = name
}

func (a animal) move() {
	fmt.Println(a.specie, a.name, "move")
}

func main () {
	dog1 := animal{"Dog", "One"};
	fmt.Println(dog1)
	fmt.Println("The dog1 name is", dog1.name)

	dog1.name = "Two"
	fmt.Println("The modified name is", dog1.name)
	(&dog1).setName("Three")
	fmt.Println("The new name is", dog1.name)

	dog1.move()
	fmt.Println()

	animalSlice := []animal {
		animal{"Dog", "one"},
		animal{"Dog", "two"},
		animal{"Cat", "three"},
		animal{"Cat", "four"},
		animal{"Bird", "five"},
	}
	fmt.Println(animalSlice)
	fmt.Println(animalSlice[3])
	fmt.Println(animalSlice[1:3])

	fmt.Println()

	//anotherMap := make(map[string]animal)

	animalMap := map[string]animal {
		"A" : dog1,
		"B" : animal{"Dog", "Two"},
		"C" : animal{"Cat", "Three"},
		"D" : animal{"Cat", "Four"},
		"E" : animal{"Bird", "Five"},
	}
	fmt.Println(animalMap)
	fmt.Println("The length of the map is", len(animalMap))
	animalMap["C"] = animal{"Bird", "Three"}
	fmt.Println(animalMap)

	fmt.Println()
	b, flag := animalMap["B"]
	if (flag) {
		fmt.Println("B", b)
		delete(animalMap, "B")
		fmt.Println(animalMap)
	}
}
