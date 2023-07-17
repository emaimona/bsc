package main

import (
	"fmt"
)

func main() {
	req := request{first: 2, second: 3}
	fmt.Println("Then product of", req.first, "and", req.second, "is", product(req))
}

type request struct {
	first  int
	second int
}

func product(r request) int {
	return r.first * r.second
}
