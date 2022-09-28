package main
import (
	"fmt"
	"math"
)

func main() {
    var A, B, C, D, x, ans, i, sqrt_c int64
    ans = -1
    fmt.Scanln(&A, &B, &C, &D)
	i = 0
	sqrt_c = int64(math.Sqrt(float64(C)))
	for i <= sqrt_c {
		if (x % B) != 0 && (C % x) == 0 && (D % x) != 0 {
			ans = x
			break
		}
		i += 1
		x += A
	}
	fmt.Println(ans)
}