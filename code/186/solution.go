package main /*{{{*/

import (
	"fmt"
)

const (
	e4 = int64(10000)
	e5 = int64(100000)
	e6 = int64(1000000)
	e7 = int64(10000000)
	e8 = e4 * e4
	e9 = e8 * 10
)

/*}}}*/

const root = 524287
const mod = int(e6)

var pre = [mod]int{}
var cnt = [mod]int{}
var val = [e4]int{}

func find(a int) int {
	if pre[a] == a {
		return a
	}
	pre[a] = find(pre[a])
	return pre[a]
}
func merge(a, b int) bool {
	if a == b {
		return true
	}
	aa := find(a)
	bb := find(b)
	if aa == bb {
		return false
	}
	pre[bb] = aa
	cnt[aa] += cnt[bb]
	return false
}
func get(index int64) int {
	if index <= 55 {
		val[index] = int((100003 - 200003*index + 300007*index*index*index) % int64(mod))
	} else {
		val[index%e4] = (val[(index+e4-24)%e4] + val[(index-55+e4)%e4]) % mod
	}
	return val[index%e4]
}
func main() {
	for i := 0; i < mod; i++ {
		pre[i] = i
		cnt[i] = 1
	}
	ans := 0
	for i := 1; ; i++ {
		a := get(int64(i<<1) - 1)
		b := get(int64(i << 1))
		if merge(a, b) {
			ans--
		}
		if cnt[find(root)] >= mod/100*99 {
			fmt.Println(i + ans)
			break
		}
	}
}
