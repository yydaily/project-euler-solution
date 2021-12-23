package main

import "fmt"

func main() {
	upper := 100
	a1 := upper * upper * (upper + 1) * (upper + 1) / 4
	a2 := upper * (upper + 1) * (upper<<1 | 1) / 6
	fmt.Printf("%d\n", a1-a2)
}
