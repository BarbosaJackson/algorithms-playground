def d(i, j, qnt):
    barril_i = []
    barril_j = []
    barril_i.append(i)
    barril_j.append(j)
    count = 0
    # print(f'qnt: {qnt}')
    while True:
        # print(i, j)
        if i in barril_j:
            break
        if j in barril_i:
            break
        i = i * 2 + qnt
        j = j * 2 + qnt
        i -= (qnt if i < (2 * qnt) else 2 * qnt)
        j -= (qnt if j < 2 * qnt else 2 * qnt)
        # print(i, j, "\n-----\n")
        barril_i.append(i)
        barril_j.append(j)
    # print(barril_i)
    # print(barril_j)
    sum_b = 0
    if j in barril_i:
        sum_b = barril_i.index(j) + barril_j.index(j)
    elif i in barril_j:
        sum_b = barril_i.index(i) + barril_j.index(i)
    # print(sum_b, barril_i[0], barril_j[0])
    return sum_b

def solve(N, Q):
    pos = [-1 for _ in range(100)]
    dp = [pos for _ in range(100)]
    v_sum = 0
    qnt = 2 ** N
    k = 0
    while Q > 0:
        i, j = map(int, input().split())
        if dp[i][j] == -1:
            dp[i][j] = d(i, j, qnt)
        # print(i, j, dp[i][j])
        v_sum += (dp[i][j] * (N ** k))
        k += 1
        # break
        Q -= 1
    print(v_sum)



N, Q = map(int, input().split())
solve(N, Q)
