package main /*{{{*/

import (
	"fmt"
	"math"
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

func sqrt(a int64) int64 {
	x := math.Sqrt(float64(a))
	return int64(x)
}

/*}}}*/

func main() {
	upper := int64(e9 * e9)
	cnt := (upper - e4) / 104
	ans := cnt * 12
	fmt.Println(ans + 724)
}
