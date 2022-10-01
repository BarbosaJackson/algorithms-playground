package main
import (
	"fmt"
	"os"
	"bufio"
	"io"
)

func is_vocal(ch byte) bool {
	vocals := "aeiou"
	for i := 0; i < 5; i++ {
		if vocals[i] == ch {
			return true
		}
	}
	return false
}

func solve(str string, len_str int) string {
	var i, j int
	var ans string
	ans = "S"
	i = 0
	j = len_str - 1
	for i < j {
		for i < len_str && !is_vocal(str[i]) {
			i++
		}
		for j > -1 && !is_vocal(str[j]) {
			j--
		}
		if str[i] != str[j] {
			ans = "N"
			break
		}
		i++
		j--
	}
	return ans
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	text, err := reader.ReadString('\n')
	for err != io.EOF {
		fmt.Println(solve(text, len(text) - 1))
		text, err = reader.ReadString('\n')
	}
	
}