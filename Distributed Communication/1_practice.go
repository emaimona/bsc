package main
import (
	"fmt"
	"errors"
	"strconv"
	"strings"
)

func inc(x int) int {
	return x + 1
}

func isEven(x int) bool {
	return x % 2 == 0
}

func divides(x, y int) bool {
	return y % x == 0
}

func area(x, y int) (int, error) {
	if (x < 0 || y < 0) {
		return -1, errors.New("Not good")
	}

	return x * y, nil
}

func stringAdd(x, y string) int {
	a, err1 := strconv.Atoi(x)
	b, err2 := strconv.Atoi(y)

	if (err1 != nil || err2 != nil) {
		return -1
	}

	return a + b
}

func isUpper(x string) bool {
	return strings.ToUpper(x) == x
}


func main() {
	x := 3
	y := 9
	fmt.Println("Inc ", x, " : ", inc(x));
	fmt.Println("Is even ", x, "? ", isEven(x))
	fmt.Printf("%d divides %d : %v", x, y, divides(x, y))
	square, val := area(x, y)
	if (val == nil) {
		fmt.Printf("\nArea of %d and %d is : %d\n", x, y, square)
	}

	um := "1"
	dois := "2k"
	fmt.Println("Add " + um + " to " + dois + " =>> ", stringAdd(um, dois))

	name := "EMANUEL"

	fmt.Println("Is " + name + " upper? ", isUpper(name))
}