package main

import "fmt"

func main() {
	neptunMap := make(map[string]string)

	neptunMap["AABBCC"] = "Adam"
	neptunMap["CCBBAA"] = "Ben"
	neptunMap["BBAACC"] = "Ada"
	fmt.Println(neptunMap)
	fmt.Println(len(neptunMap))
	
	neptunMap["BBAACC"]  = "CCC"
	fmt.Println(neptunMap)
	
	delete(neptunMap, "BBAACC")
	fmt.Println(neptunMap)
	
	v1, ok1 := neptunMap["CCBBAA"]
	fmt.Println(v1, ok1)
	v2, ok2 := neptunMap["AAAAAA"]
	fmt.Println(v2, ok2)
	
	for k,v :=range neptunMap {
		fmt.Println(k,v)
	}
	
	for _,v :=range neptunMap {
		fmt.Println(v)
	}
}