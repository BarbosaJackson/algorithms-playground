package main
import (
	"fmt"
	"math"
)

func main() {
    var A, B, C, D, x, ans, i int64
	var sqrt_c float64
    ans = -1
    fmt.Scanln(&A, &B, &C, &D)
	i = 0
	sqrt_c = math.Sqrt(C)
	for i <= sqrt_c {
		if (x % B) && !(C % x) && (D % x) {
			ans = x
			break
		}
		i += 1
		x += A
	}
	fmt.Println(ans)
}