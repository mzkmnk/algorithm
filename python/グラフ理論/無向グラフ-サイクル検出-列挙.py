import sys
sys.setrecursionlimit(10**7)
from collections import defaultdict
def find_cycle(graph):
    """
    graph:隣接リスト
    return:閉路を構成する頂点のリスト
    library checkerではTLE
    """
    visited = set()
    parent = defaultdict(int)
    def dfs(u,n):
        visited.add(u)
        parent[u]=n
        for v in graph[u]:
            if v not in visited:
                cycle=dfs(v,u)
                if cycle:return cycle
            elif v!=n:
                cycle=[u]
                now=u
                while(now!=v):
                    now=parent[now]
                    cycle.append(now)
                cycle.append(u)
                return cycle[::-1]
        return None
    for v in range(N):
        if v not in visited:
            cycle=dfs(v,None)
            if cycle:return cycle
    return None

N,M=map(int,input().split())
g=[[] for _ in range(N)]
edges=defaultdict(int)
for i in range(M):
    u,v=map(int,input().split())
    g[u].append(v)
    g[v].append(u)
    edges[(u,v)]=i
    edges[(v,u)]=i

cycle=find_cycle(g)

if cycle:
    print(len(cycle)-1)
    for i in range(len(cycle)-1): print(cycle[i],end=" ")
    print()
    for i in range(len(cycle)-1): print(edges[(cycle[i],cycle[i+1])],end=" ")
    print()
else:print(-1)