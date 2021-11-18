package main

import "fmt"

func main() {
	a := int64(600851475143)
	for i:=int64(2);i<=a;i++ {
		for a%i == 0 {
			fmt.Printf("%d\n", i)
			a /= i
		}
	}
}
