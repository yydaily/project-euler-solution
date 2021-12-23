package main

import "fmt"

func main() {
	sumOfEven := 0
	a, b := 1, 2
	for b < 4*1000*1000 {
		if b%2 == 0 {
			sumOfEven += b
		}
		a, b = b, a+b
	}
	fmt.Printf("%d\n", sumOfEven)
}
