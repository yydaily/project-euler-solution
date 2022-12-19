package main /*{{{*/

import (
	"fmt"
)

func Q(length int64) int64 {
	ret := int64(0)
	base := int64(904962)
	length /= 2
	for length > 0 {
		length /= 2
		ret += length * base
	}
	return ret
}

func main() {
	fmt.Println(Q(8))
	fmt.Println(Q(int64(1e12)))
}
