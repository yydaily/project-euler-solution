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
var ans = [e6]int{}

func cal(a int) int {
	ret := (a-1)%9 + 1
	for i := 2; i*i <= a; i++ {
		if a%i == 0 && ans[i]+ans[a/i] > ret {
			ret = ans[i] + ans[a/i]
		}
	}
	ans[a] = ret
	return ret
}
func main() {
	ans := 0
	for i := 2; i < int(e6); i++ {
		ans += cal(i)
	}
	fmt.Println(ans)
}
