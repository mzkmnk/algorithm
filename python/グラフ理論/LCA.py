class LCA:
    #頂点数と隣接リストを渡す
    #lca関数でu,vの最近共通祖先を求める
    #dist関数でu,vの最小距離を求める
    def __init__(self,n,graph):
        self.n=n
        self.graph=graph
        self.logn=(n-1).bit_length()
        self.depth=[0]*n
        self.dp=[[-1 for _ in range(n)] for _ in range(self.logn)]

        self.dfs(0,-1)
        
        for i in range(1,self.logn):
            for j in range(n):
                if(self.dp[i-1][j]!=-1):
                    self.dp[i][j]=self.dp[i-1][self.dp[i-1][j]]
    
    def dfs(self,v,p):
        for u in self.graph[v]:
            if(u==p):
                continue
            self.dp[0][u]=v
            self.depth[u]=self.depth[v]+1
            self.dfs(u,v)
    
    def lca(self,u,v):
        if(self.depth[u]<self.depth[v]):
            u,v=v,u
        
        diff = self.depth[u]-self.depth[v]
        for i in range(self.logn):
            if((diff>>i)&1):
                u=self.dp[i][u]
        
        if(u==v):
            return u

        for i in reversed(range(self.logn)):
            if(self.dp[i][u]!=self.dp[i][v]):
                u,v=self.dp[i][u],self.dp[i][v]
        
        return self.dp[0][u]
    
    def dist(self,u,v):
        lca_uv=self.lca(u,v)
        return self.depth[u]+self.depth[v]-2*self.depth[lca_uv]