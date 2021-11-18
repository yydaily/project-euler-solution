package main

import "fmt"

func cal(a int, b int) int {
	c := b / a;
	return a * c * (c+1) / 2;
}

func main() {
	fmt.Printf("%d\n", cal(3, 999) + cal(5, 999) - cal(15, 999));
}
