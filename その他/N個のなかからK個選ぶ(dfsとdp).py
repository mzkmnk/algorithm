N,K=map(int,input().split())
A=list(map(int,input().split()))
dfs_array=[]
def dfs(i,k,s):
    """
    i:現在の要素のインデックス
    k:選んだ要素の数
    s:選んだ要素の和
    計算量はO(2^N+K)
    """
    if(i==N):
        if(k==K):dfs_array.append(s)
        return
    dfs(i+1,k,s)
    if(k<K):dfs(i+1,k+1,s+A[i])

def dp():
    """
    dp[i][j][k]:i番目までの要素からj個選んで和がkになるような選び方の総数
    また[N][K]の値が1以上ならば、そのような選び方が存在することを表す
    計算量はO(N*K*sum(A))
    漸化式はdp[i-1][j][k]+dp[i-1][j-1][k-A[i-1]](k-A[i-1]>=0)
    初期化でdp[i][0][0]=1とする理由は、i番目までの要素から0個選んで和が0になるような選び方は常に1通りであるため
    """
    dp=[[[0]*(sum(A)+1) for _ in range(K+1)] for _ in range(N+1)]
    for i in range(N+1):dp[i][0][0]=1
    for i in range(1,N+1):
        for j in range(1,K+1):
            for k in range(sum(A)+1):
                dp[i][j][k]=dp[i-1][j][k]
                if(k-A[i-1]>=0):dp[i][j][k]+=dp[i-1][j-1][k-A[i-1]]
    #for i in dp:print(*i)