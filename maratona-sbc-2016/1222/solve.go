package main
import (
	"fmt"
	"io"
	"bufio"
	"os"
)

func solve(n int, l int, c int) int {
	
	var total, qnt_chars, cur_len_lines, start_word, len_str int
	var text string
	start_word = 0
	total = 0
	qnt_chars = 0
	cur_len_lines = 1
	scanner := bufio.NewScanner(os.Stdin)

    if scanner.Scan() {
		text = scanner.Text()
	}
	len_str = len(text)
	for i := 0; i < len_str; i += 1 {
		if i > 0 && text[i - 1] == ' ' {
			start_word = i
		}
		if qnt_chars == c {
			cur_len_lines += 1
			if text[i] == ' ' {
				qnt_chars = 0
			} else {
				qnt_chars = i - start_word + 1
			}
		} else {
			qnt_chars += 1
		}
	}
	total = cur_len_lines / l
	if cur_len_lines % l > 0 {
		total += 1
	}
	return total
}

func main() {
	var n, l, c int
	_, err := fmt.Scanln(&n, &l, &c)
	for err != io.EOF {
		fmt.Println(solve(n, l, c))
		_, err = fmt.Scanln(&n, &l, &c)
	}
	
}