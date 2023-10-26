DEBUG = False

def solve() -> bool:
    try:
        n = int(input())
    except:
        return False
    
    words = []
    patterns = []
    
    for _ in range(0, n):
        words.append(input())
    
    g = int(input())
    for _ in range(0, g):
        patterns.append(input())

    for pattern in patterns:
        ans = 0
        for word in words:
            ok = 0
            for i in range(0, 5):
                if pattern[i] == 'X':
                    ok += (1 if word[i] not in words[0] else 0)
                elif pattern[i] == '*':
                    ok += (1 if word[i] == words[0][i] else 0)
                else:
                    ok += (1 if (word[i] in words[0] and word[i] != words[0][i]) else 0)
            ans += (1 if ok == 5 else 0)
        print(ans)
    return True

while(solve()):
    if DEBUG:
        print("debugging")