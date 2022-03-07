package main

import (
	"fmt"
	"math/big"
)

func add(a, b *big.Int) *big.Int {
	var ret = big.NewInt(0)
	ret.Add(a, b)
	return ret
}
func sub(a, b *big.Int) *big.Int {
	var ret = big.NewInt(0)
	ret.Sub(a, b)
	return ret
}
func mul(a, b *big.Int) *big.Int {
	var ret = big.NewInt(0)
	ret.Mul(a, b)
	return ret
}
func div(a, b *big.Int) *big.Int {
	var ret = big.NewInt(1)
	ret.Div(a, b)
	return ret
}
func qpow(a, b *big.Int) *big.Int {
	ret := big.NewInt(1)
	zero := big.NewInt(0)
	one := big.NewInt(1)
	for b.Cmp(zero) > 0 {
		ret = mul(ret, a)
		b = sub(b, one)
	}
	return ret
}

func main() {
	n1 := big.NewInt(1)
	n2 := big.NewInt(2)
	n3 := big.NewInt(3)
	n4 := big.NewInt(4)

	a := qpow(big.NewInt(21), big.NewInt(7))
	b := qpow(big.NewInt(7), big.NewInt(21))
	c := qpow(big.NewInt(12), big.NewInt(7))

	buf := add(mul(n4, sub(a, c)), b)
	base := mul(buf, n2)
	base = sub(base, a)
	base = add(base, n1)
	base = mul(base, a)
	base = div(base, n2)

	cnt := div(add(b, n1), a)

	ans := mul(base, n2)
	ans = add(ans, mul(mul(n3, a), mul(sub(a, c), sub(cnt, n1))))
	ans = div(mul(cnt, ans), n2)

	buf = add(buf, mul(n3, mul(cnt, sub(a, c))))
	ind := big.NewInt(0).Mod(b, a)
	ans = add(ans, div(mul(add(ind, n1), sub(mul(buf, n2), ind)), n2))

	mod := big.NewInt(1000000000)
	fmt.Printf("%+v\n", ans.Mod(ans, mod))
}
