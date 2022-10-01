def solve(n, l, c):
    text = input()
    len_word = len(text)
    start_word = 0
    cur_char = 0
    lines = 1
    for i in range(len_word):
        if (i > 0) and (text[i - 1] == ' '):
            start_word = i
        if(cur_char == c):
            lines += 1
            cur_char = 0 if text[i] == ' ' else (i - start_word + 1)
        else:
            cur_char += 1
    
    return int(lines / l) + (1 if lines % l > 0 else 0)
def main():
    while True:
        try:
            n, l, c = map(int, input().split())
            print(solve(n,l,c))
        except EOFError:
            break
main()