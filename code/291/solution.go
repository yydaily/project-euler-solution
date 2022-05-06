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

const upper = int64(5e15)

var v = []int64{0}

func main() {
	for n := int64(1); ; n++ {
		now := 2*n*n + 2*n + 1
		if now > upper {
			break
		}
		v = append(v, now)
	}

	ans := 0
	l := int64(len(v))
	for i := int64(1); i < l; i++ {
		p := v[i]
		if p == 2*i*i+2*i+1 {
			ans++
		}
		if p <= 1 {
			continue
		}
		for j := i; j < l; j += p {
			for v[j]%p == 0 {
				v[j] /= p
			}
		}
		for j := p - 1 - i; j < l; j += p {
			for v[j]%p == 0 {
				v[j] /= p
			}
		}
	}
	fmt.Println(ans)
}
