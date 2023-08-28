def LCS(S,T):
    """
    最長共通部分列（LCS)の数を求める
    dp[i][j]:Sのi文字目までとTのj文字目までのLCSの長さ
    """
    SN,TN=len(S),len(T)
    dp=[[0 for _ in range(TN+1)] for _ in range(SN+1)]
    S='@'+S
    T='@'+T
    for i in range(1,SN+1):
        for j in range(1,TN+1):
            if(S[i]==T[j]):dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1)
            else:dp[i][j]=max(dp[i-1][j],dp[i][j-1])
    for i in dp:print(*i)
    #S,Tの最長共通部分列の文字列を求める->復元作業
    i,j,res=SN,TN,""
    while(i>0 and j>0):
        if(dp[i][j]==dp[i-1][j]):i-=1
        elif(dp[i][j]==dp[i][j-1]):j-=1
        else:
            res=S[i]+res
            i-=1
            j-=1
    return res