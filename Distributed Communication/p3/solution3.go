package main

import "fmt"

func main() {

	dog1 := animal{"dog", "One"}
	fmt.Println(dog1)
	fmt.Println(dog1.name)
	dog1.name = "Two"
	fmt.Println(dog1)
	
	(&dog1).setName("Three")
	fmt.Println(dog1)
	
	dog1.move()
	
	animalSlice := []animal{
		animal{"dog", "One"},
		animal{"dog", "Two"},
		animal{"cat", "Three"},
		animal{"cat", "Four"},
		animal{"bird", "Five"},
	}
	fmt.Println(animalSlice)

	fmt.Println(animalSlice[2])
	fmt.Println(animalSlice[1:4])

	animalMap := make(map[string]animal)
	animalMap["A"] = animal{"dog", "One"}
	animalMap["B"] = animal{"dog", "Two"}
	animalMap["C"] = animal{"cat", "Three"}
	animalMap["D"] = animal{"bird", "Four"}
	fmt.Println(animalMap)
	fmt.Println(len(animalMap))

	animalMap["C"] = animal{"bird", "Three"}
	fmt.Println(animalMap)
	
	v1, ok1 := animalMap["B"]
	if (ok1) {
		fmt.Println("B", v1)
		delete(animalMap, "B")
		fmt.Println(animalMap)
	}
}

type animal struct{
	specie string
	name string
} 

func (a animal) move(){
	fmt.Println(a.specie,a.name,"move")
}

func (ap *animal) setName(n string){
	(*ap).name = n
}