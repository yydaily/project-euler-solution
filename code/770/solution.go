package main

import (
	"fmt"
	"math"
)

func main() {
	for i := 1; ; i++ {
		if math.Sqrt(3.141592653589793238462643383279502884197169399375105820974944592307816406286*float64(i)) > 19999 {
			fmt.Printf("%d\n", i)
			return
		}
	}
}
