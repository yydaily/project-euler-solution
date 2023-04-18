package main /*{{{*/

import (
	"fmt"
)

const e9 = int64(1e9)

var a = [10]int64{}

func add(a, b int64) int64 {
	return (a + b) % e9
}

func qpow(a, b int64) int64 {
	ret := int64(1)
	for b > 0 {
		if (b & 1) > 0 {
			ret = (ret * a) % e9
		}
		a = a * a % e9
		b >>= 1
	}
	return ret
}

func G(n int64) int64 {
	a[0] = 0
	for n > 0 {
		a[0]++
		a[a[0]] = n & 1
		n >>= 1
	}
	ans := int64(0)
	for true {
		if a[1] > 0 {
			ans = add(ans, a[1])
			a[1] = 0
			continue
		}
		if a[2] > 0 {
			a[2]--
			ans = add(ans, ans+3)
			continue
		}
		if a[3] > 0 {
			a[3]--
			added := (qpow(2, ans+3) - 1) * (ans + 3) % e9
			ans = add(ans, added)
			continue
		}
		if a[4] > 0 {
			a[4]--
			a[1], a[2], a[3] = ans+2, ans+2, ans+2
			ans += 1
			continue
		}
		break
	}
	return ans
}

func main() {
	ans := int64(0)
	for i := int64(1); i < 16; i++ {
		ans += G(i)
	}
	fmt.Println(ans % e9)
}
