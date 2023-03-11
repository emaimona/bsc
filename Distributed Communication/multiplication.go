package main
import (
	"fmt"
	"strconv"
)

func multiplicate(a , b int) int {
	return a * b
}

func multiplicateWithError(a, b int) (int, error) {
	return a*b, nil
}

func main() {
	fmt.Println(multiplicate(9, 3))
	j, err := strconv.Atoi("2k")
	if err != nil {
		fmt.Println("You are Doomed")
	} else {
		fmt.Println("The value was " , j)
	}

}