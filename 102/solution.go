package main /*{{{*/

import (
	"fmt"
	"io/ioutil"
	"math"
	"os"
	"reflect"
	"strconv"
	"strings"
)

const (
	e4  = int64(10000)
	e5  = int64(100000)
	e6  = int64(1000000)
	e7  = int64(10000000)
	e8  = e4 * e4
	mod = int64(1e9 + 7)
)

func add(list ...interface{}) int64 { /*{{{*/
	if len(list) == 0 {
		return 0
	}
	ret := int64(0)
	for _, i := range list {
		buf := int64(0)
		switch reflect.TypeOf(i).String() {
		case "int":
			buf = int64(i.(int))
		case "int64":
			buf = i.(int64)
		}
		ret = (ret + buf) % mod
	}
	return ret
} /*}}}*/
func mul(list ...interface{}) int64 { /*{{{*/
	if len(list) == 0 {
		return 0
	}
	ret := int64(1)
	for _, i := range list {
		buf := int64(0)
		switch reflect.TypeOf(i).String() {
		case "int":
			buf = int64(i.(int))
		case "int64":
			buf = i.(int64)
		}
		ret = (buf % mod * ret) % mod
	}
	return ret
} /*}}}*/
func qpow(a, b int64) int64 { /*{{{*/
	ret := int64(1)
	for b > 0 {
		if (b & 1) == 1 {
			ret = mul(ret, a)
		}
		a = mul(a, a)
		b >>= 1
	}
	return ret
} /*}}}*/
/*}}}*/

const o = float64(0)

func area(x1, y1, x2, y2, x3, y3 float64) float64 {
	a, b, c, p, s := o, o, o, o, o
	a = math.Sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))
	b = math.Sqrt((x1-x3)*(x1-x3) + (y1-y3)*(y1-y3))
	c = math.Sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3))
	p = (a + b + c) / 2
	s = math.Sqrt(p * (p - a) * (p - b) * (p - c))
	return s
}

func check(x1, y1, x2, y2, x3, y3 float64) bool {
	origin := area(x1, y1, x2, y2, x3, y3)
	s1 := area(0, 0, x1, y1, x2, y2)
	s2 := area(0, 0, x2, y2, x3, y3)
	s3 := area(0, 0, x1, y1, x3, y3)
	origin -= s1 + s2 + s3
	if origin < 0 {
		origin = -origin
	}
	return origin <= 1e-6
}

func main() {
	file, err := os.Open("./in")
	if err != nil {
		panic(err)
	}
	defer file.Close()
	content, err := ioutil.ReadAll(file)
	if err != nil {
		panic(err)
	}
	queries := strings.Split(string(content), "\n")
	ans := 0
	for _, query := range queries {
		if len(query) <= 1 {
			continue
		}
		num := strings.Split(query, ",")
		ints := []float64{}
		for _, n := range num {
			x, err := strconv.ParseFloat(n, 64)
			if err != nil {
				panic(err)
			}
			ints = append(ints, x)
		}
		if len(ints) != 6 {
			panic("length invalid")
		}
		if check(ints[0], ints[1], ints[2], ints[3], ints[4], ints[5]) {
			ans++
		}
	}
	fmt.Println(ans)
}
