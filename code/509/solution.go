package main /*{{{*/

import (
	"fmt"
)

var cnt = [50]int64{}

const mod = 1234567890

func S(a int64) int64 {
	cnt[0] = a/2 + a%2
	cnt[1] = a - cnt[0]
	for i := 2; cnt[i-1] > 0; i++ {
		cnt[i] = cnt[i-1] / 2
		cnt[i-1] -= cnt[i]
	}
	for i := 0; cnt[i] > 0; i++ {
		cnt[i] %= mod
	}
	ret := int64(0)
	for i := 0; cnt[i] > 0; i++ {
		for j := 0; cnt[j] > 0; j++ {
			for k := 0; cnt[k] > 0; k++ {
				if (i ^ j ^ k) != 0 {
					ret = (ret + cnt[i]*cnt[j]%mod*cnt[k]%mod) % mod
				}
			}
		}
	}
	return ret
}

func main() {
	fmt.Println(S(10))
	fmt.Println(S(100))
	fmt.Println(S(123456787654321))
}
