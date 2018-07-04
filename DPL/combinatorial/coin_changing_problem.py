# DPL_1_A
# https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_A
MAX = 50005

n, m = map(int, input().split())
c = list(map(int, input().split()))

# dp[v] := 価値v円を支払うときに使用するコインの最小枚数
dp = [MAX for _ in range(n+1)]
dp[0] = 0

for i in range(m):
    for j in range(n+1):
        if j + c[i] > n: break
        dp[j + c[i]] = min(dp[j + c[i]], dp[j] + 1)
        # print(i, j, dp)

print(dp[n])
