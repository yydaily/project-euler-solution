package main

import "fmt"

const upper = int64(2e7 + 10)

var p = [upper]bool{}
var minn = [upper]int64{}

func init() {
	for i := int64(2); i < upper; i++ {
		if !p[i] {
			for j := i; j < upper; j += i {
				p[j] = true
				minn[j] = i
			}
		}
		minn[i] = minn[i/minn[i]] + minn[i]
	}
}

func main() {
	lower, upper := 15000000, 20000000
	ans := int64(0)
	for i := 1; i <= upper-lower; i++ {
		ans += minn[lower+i] - minn[i]
	}
	fmt.Printf("%d\n", ans)
}
