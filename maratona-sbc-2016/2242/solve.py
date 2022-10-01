def is_vocal(c):
    return c in "aeiou"

def solve(str):
    ans = 'S'
    i = 0
    str_len = len(str)
    j = str_len - 1
    while i < j:
        while i < str_len and not is_vocal(str[i]):
            i += 1
        while j > -1 and not is_vocal(str[j]):
            j -= 1
        if(str[i] != str[j]):
            # print(i, j, str[i], str[j])
            ans = "N"
            break
        i += 1
        j -= 1
    return ans

while True:
    try:
        print(solve(input()))
    except EOFError:
        break
