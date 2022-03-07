package main /*{{{*/

import (
	"fmt"
)

const (
	e4  = int64(10000)
	e8  = e4 * e4
	mod = 1e9 + 7
) /*}}}*/

const upper = int64(1e14)

func main() {
	m := map[int64]bool{}
	cnt := 0
	for i := int64(1); i*i*(i+1)*(i+1) < upper; i++ {
		for j := i; i*j*(i+1)*(j+1) < upper; j++ {
			val := i * j * (i + 1) * (j + 1)
			if !m[val] {
				m[val] = true
				cnt++
			}
		}
	}
	fmt.Println(cnt)
}
