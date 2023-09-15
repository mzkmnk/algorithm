def prim(G,start):
    """
    G:隣接リスト
    start:始点
    prim法で最小全域木のコストを求める
    計算量:O(ElogV)
    """
    vis=[0]*N
    hq=[]
    heapify(hq)
    heappush(hq,[0,start])
    ans=0
    while(hq):
        cost,now=heappop(hq)
        if(vis[now]):continue
        vis[now]=1
        ans+=cost
        for to,c in G[now]:
            if(vis[to]):continue
            heappush(hq,[c,to])
    return ans