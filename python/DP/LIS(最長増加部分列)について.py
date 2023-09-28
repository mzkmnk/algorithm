"""
LISとは連続ではない部分増加列を求める
例
N=6
A=[2 ,3 ,1 ,6 ,4 ,5]
ここで最長増加部分列は2 3 4 5である
これを求める方法は
dp=[float('inf')]*N
として初期化する
またここでのテーブルはi(=インデックス番号,0-indexed)として
(i+1)個の部分増加列を作るときの最小の値をdp[i]とする
for i in range(N):
    dp[bisect_left(dp,A[i])]=min(dp[bisect_left(dp,A[i])],A[i])

"""