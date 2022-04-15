package main /*{{{*/

import (
	"fmt"
)

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

var a = "1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"
var b = "8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196"
var length = [1000]int64{}

func D(index int64) byte {
	length[0] = int64(len(a))
	length[1] = int64(len(b))
	ind := 1
	for length[ind] < index {
		length[ind+1] = length[ind] + length[ind-1]
		ind++
	}
	for ind > 1 {
		if length[ind-2] >= index {
			ind -= 2
		} else {
			index -= length[ind-2]
			ind--
		}
	}
	if ind == 1 {
		return b[index]
	}
	return a[index]
}

func main() {
	base := int64(1)
	ans := []byte{}
	for i := int64(0); i <= 17; i++ {
		ans = append([]byte{D((127+19*i)*base - 1)}, ans...)
		//ans += D((127+19*i)*base-1)
		base *= 7
	}
	fmt.Println(string(ans))
}
