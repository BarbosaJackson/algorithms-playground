def solve(N):
    meat = []
    for i in range(N):
        name, valid = input().split()
        valid = int(valid)
        meat.append((valid, name))
    meat = sorted(meat)
    ans = []
    for m in meat:
        ans.append(m[1])
    print(" ".join(ans))
while True:
    try:
        N = int(input())
        solve(N)
    except EOFError:
        break