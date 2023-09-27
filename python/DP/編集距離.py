def edit_distance(S,T):
    """
    S,Tはそのまま、関数内で最初の1文字追加する
    """
    S='f'+ S
    T='f'+ T
    N=len(S)
    M=len(T)
    dp=[[float('inf') for _ in range(M)] for _ in range(N)]
    for i in range(N):dp[i][0]=i
    for i in range(M):dp[0][i]=i

    for i in range(1,N):
        for j in range(1,M):
            c=0 if S[i]==T[j] else 1
            dp[i][j]=min(dp[i][j],dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+c)
    return dp[-1][-1]