import math
A, B, C, D = input().split()
A = int(A)
B = int(B)
C = int(C)
D = int(D)
ans = -1
x = A
sqrt_c = int(math.sqrt(C))
i = 0
while i <= sqrt_c:
    if (x % B) and not(C % x) and (D % x) :
        ans = x
        break
    x += A
    i += 1

print(ans)