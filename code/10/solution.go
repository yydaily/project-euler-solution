package main

import "fmt"

const upper = 2000000

var p = [upper]bool{}

func main() {
	sum := int64(0)
	for i := int64(2); i < upper; i++ {
		if p[i] {
			continue
		}
		sum += i
		for j := i << 1; j < upper; j += i {
			p[j] = true
		}
	}
	fmt.Printf("%d\n", sum)
}
