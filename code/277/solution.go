package main /*{{{*/

import (
	"fmt"
)

const (
	e4  = int64(10000)
	e5  = int64(100000)
	e6  = int64(1000000)
	e7  = int64(10000000)
	e8  = e4 * e4
	e9  = e8 * 10
	mod = int64(1e9 + 7)
)

/*}}}*/

var query = "UDDDUdddDDUDDddDdDddDDUDDdUUDd"

func meet(a int64, index int) bool { /*{{{*/
	for i := 0; i <= index; i++ {
		if query[i] == 'D' {
			if a%3 != 0 {
				return false
			}
			a /= 3
		} else if query[i] == 'd' {
			if a%3 != 2 {
				return false
			}
			a = (a*2 - 1) / 3
		} else {
			if a%3 != 1 {
				return false
			}
			a = (a*4 + 2) / 3
		}
	}
	return true
} /*}}}*/
func main() {
	base := int64(1)
	x1, x2 := base-1, base-1

	for i := 0; i < len(query); i++ {
		for !meet(x1, i) {
			x1 += base
		}
		x2 = x1 + base
		for !meet(x2, i) {
			x2 += base
		}
		base = x2 - x1
	}
	for x2 <= int64(1e15) {
		x2 += base
	}
	fmt.Println(x2)
}
