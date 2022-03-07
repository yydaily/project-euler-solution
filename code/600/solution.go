package main

import "fmt"

func cal2(x int) int64 {
	lower := x%2 + 1
	upper := x + 1
	length := (upper-lower)/2 + 1
	return int64(lower+upper) * int64(length) / 2
}

func cal(x int) int64 {
	ret := int64(0)
	for a := 1; a*3 <= x; a++ {
		ret += cal2(x - a*3)
	}
	return ret
}

func main() {
	ans := int64(0)
	upper := 55106
	for i := 0; i*3+6 <= upper; i++ {
		ans += cal((upper - i*3) / 2)
	}
	fmt.Printf("%d\n", ans)
}
