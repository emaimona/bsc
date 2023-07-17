package main

import "fmt"

func main() {
	adam := student{"Adam", "abcdef"}
	fmt.Println(adam)
	(&adam).setName1("AAAA")
	fmt.Println(adam)
	adam.setName2("BBBB")
	fmt.Println(adam)
}

type student struct {
    name   string
    id string
}

func (pointerToStudent *student) setName1(newName string) {
    (*pointerToStudent).name = newName
}

func (pointerToStudent *student) setName2(newName string) {
    pointerToStudent.name = newName
}