import io, os

def solve():
    input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
    s = input().decode()
    print('-> ' + s)
    # print(" ".join(sorted(map(int, input().split()))))

def main():
    N = int(input())
    while N > 0:
        solve()
        N -= 1
        return 0
main()