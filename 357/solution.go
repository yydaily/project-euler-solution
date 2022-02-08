package main /*{{{*/

import (
	"fmt"
)

const (
	e4  = int64(10000)
	e8  = e4 * e4
	mod = 1e9 + 7
) /*}}}*/

var need_check = []int64{}
var p = [e8]bool{}

func check(a int64) bool {
	for i := int64(2); i*i <= a; i++ {
		if a%i == 0 && p[i+a/i] {
			return false
		}
	}
	return true
}

func main() {
	p[0], p[1] = true, true
	for i := int64(2); i < e8; i++ {
		if !p[i] {
			need_check = append(need_check, i-1)
			for j := i << 1; j < e8; j += i {
				p[j] = true
			}
		}
	}
	sum := int64(0)
	for _, i := range need_check {
		if check(i) {
			sum += i
		}
	}
	fmt.Println(sum)
}
