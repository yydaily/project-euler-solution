package main /*{{{*/

import (
	"fmt"
)

var n, k = [50]int64{}, [50]int64{}

func main() {
	n[0] = 1
	k[0] = 2
	n[1] = 3
	k[1] = 5

	ans := int64(0)
	for i := 0; i < 40; i++ {
		n[i+2] = 3*n[i] + 2*k[i] + 3
		k[i+2] = 4*n[i] + 3*k[i] + 5
		ans += n[i]
	}
	fmt.Println(ans)
}
