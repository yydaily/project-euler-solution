package main

import (
	"fmt"
	"math/big"
)

func cal(a *big.Int) int64 {
	zero := big.NewInt(0)
	ten := big.NewInt(10)
	n := big.NewInt(0)
	ret := int64(0)
	for a.Cmp(zero) == 1 {
		ret += n.Mod(a, ten).Int64()
		a.Div(a, ten)
	}
	return ret
}

func main() {
	val := big.NewInt(1)
	for i := int64(1); i <= 100; i++ {
		v := big.NewInt(i)
		val.Mul(val, v)
	}
	fmt.Println(cal(val))
}
