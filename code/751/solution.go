package main

import (
	"fmt"
	"github.com/shopspring/decimal"
)

func gao(a decimal.Decimal) decimal.Decimal {
	ret := "2."
	b1 := a
	for i := 1; i < 30; i++ {
		b2 := b1.Floor().Mul(b1.Sub(b1.Floor()).Add(decimal.NewFromInt(1)))
		ret = ret + b2.Floor().String()
		b1 = b2
	}
	val, err := decimal.NewFromString(ret)
	if err != nil {
		panic(err)
	}
	return val
}

func main() {
	decimal.DivisionPrecision = 100
	l := decimal.New(2, 0)
	r := decimal.New(3, 0)
	for i := 0; i < 1000; i++ {
		mid := l.Add(r).Div(decimal.NewFromInt(2))
		if gao(mid).GreaterThan(mid) {
			l = mid
		} else {
			r = mid
		}
	}
	fmt.Println(l)
}
