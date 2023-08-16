from heapq import heapify,heappop,heappush
def dijkstra(g,s):
    """
    g:隣接リスト
    s:始点
    戻り値:sから各頂点への最短距離(dist)
    """
    deq=[(0,s)]
    heapify(deq)
    N=len(g)
    dist=[float('inf') for _ in range(N+1)]
    dist[s]=0
    vis=[0]*(N+1)
    while(deq):
        _,v=heappop(deq)
        if(vis[v]):continue
        vis[v]=1
        for v1,c in g[v]:
            if(vis[v1]):continue
            if(dist[v1]>dist[v]+c):
                dist[v1]=dist[v]+c
                heappush(deq,(dist[v1],v1))
    return dist