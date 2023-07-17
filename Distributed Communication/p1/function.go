package main
import (
	"fmt"
	"errors"
)

func main() {
	fmt.Println(multiplicate(3, 4))
	
	p, e := multiplicateWithError(3,4,true)
	fmt.Println(p,e)
	p, e = multiplicateWithError(3,4,false)
	fmt.Println(p,e)
}

func multiplicate(x int, y int) int {
	return x * y
}

func multiplicateWithError (x int, y int, b bool) (int, error){
	if b {
		return 0, errors.New("special error")
	} else {
		return x*y, nil
	}
}
