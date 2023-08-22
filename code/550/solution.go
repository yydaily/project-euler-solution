package main /*{{{*/

import (
	"fmt"
)

const (
	mod    = int64(987654321)
	sg_cnt = 64
)

type matrix struct {
	d [sg_cnt][sg_cnt]int64
}

func memset(a *matrix) {
	for i := range a.d {
		for j := range a.d[i] {
			a.d[i][j] = 0
		}
	}
}

func mul(a, b matrix) matrix {
	ret := matrix{d: [sg_cnt][sg_cnt]int64{}}
	memset(&ret)

	for i := 0; i < sg_cnt; i++ {
		for j := 0; j < sg_cnt; j++ {
			for k := 0; k < sg_cnt; k++ {
				ret.d[i][k] = (ret.d[i][k] + a.d[i][j]*b.d[j][k]) % mod
			}
		}
	}

	return ret
}

func qpow(a matrix, b int64) matrix {
	ret := matrix{d: [sg_cnt][sg_cnt]int64{}}
	memset(&ret)
	for i := 0; i < sg_cnt; i++ {
		ret.d[i][i] = 1
	}

	for b > 0 {
		if (b & 1) > 0 {
			ret = mul(ret, a)
		}
		a = mul(a, a)
		b >>= 1
	}
	return ret
}

func cal(m map[int]int64, power int64) int64 {
	start := matrix{d: [sg_cnt][sg_cnt]int64{}}
	memset(&start)

	for i := 0; i < sg_cnt; i++ {
		for k, v := range m {
			start.d[i][i^k] = (start.d[i][i^k] + v) % mod
		}
	}
	start = qpow(start, power)
	ans := int64(0)
	for i := 1; i < sg_cnt; i++ {
		ans = (ans + start.d[0][i]) % mod
	}
	return ans
}

func main() {
	m := map[int]int64{
		0: 4,
		1: 4,
		2: 1,
	}
	fmt.Println(cal(m, 5))

	m2 := map[int]int64{
		0:  664579,
		1:  1904324,
		2:  2444359,
		4:  2050696,
		7:  1349779,
		8:  774078,
		11: 409849,
		13: 207207,
		14: 101787,
		16: 49163,
		19: 23448,
		21: 11068,
		22: 5210,
		25: 2406,
		26: 1124,
		28: 510,
		31: 233,
		32: 102,
		35: 45,
		37: 21,
		38: 7,
		41: 3,
		42: 1,
	}
	fmt.Println(cal(m2, 1e12))
}
