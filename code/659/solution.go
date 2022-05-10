package main /*{{{*/

import "fmt"

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

var ans = [e7 + 10]int64{}
var num = [e7 + 10]int64{}

func main() {
	for i := int64(1); i <= e7; i++ {
		num[i] = 4*i*i + 1
	}
	for i := int64(1); i <= e7; i++ {
		p := num[i]
		if p == 4*i*i+1 {
			ans[i] = p
		}
		if p <= 1 {
			continue
		}
		for j := i; j <= e7; j += p {
			for num[j]%p == 0 {
				ans[j] = max(ans[j], p)
				num[j] /= p
			}
		}
		for j := p - i; j <= e7; j += p {
			if j <= 0 {
				continue
			}
			for num[j]%p == 0 {
				ans[j] = max(ans[j], p)
				num[j] /= p
			}
		}
	}
	rans := int64(0)
	mod := e9 * e9
	for i := int64(1); i <= e7; i++ {
		rans = (rans + ans[i]) % mod
	}
	fmt.Println(rans)
}

func max(a, b int64) int64 {
	if a < b {
		return b
	}
	return a
}
