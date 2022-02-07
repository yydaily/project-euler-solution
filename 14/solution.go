package main

import "fmt"

const upper = int64(1e7)

var val = [upper]int{}

func get(a int64) int {
	if a < upper && val[a] > 0 {
		return val[a]
	}
	if a == 1 {
		return 1
	}
	b := a >> 1
	if (a & 1) > 0 {
		b = a*3 + 1
	}

	v := get(b) + 1
	if a < upper {
		val[a] = v
	}
	return v
}

func main() {
	ans, ind := 0, 0
	for i := 1; i < 1000000; i++ {
		v := get(int64(i))
		if v > ans {
			ans = v
			ind = i
		}
	}
	fmt.Printf("%d\n", ind)
}
