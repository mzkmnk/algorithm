from collections import deque
def bipartite_bfs(N, g):
    vis = [0] * N
    """
    2部グラフを求める関数
    Args:
        N (int): 頂点数
        g (list of list of int): 隣接リスト
    Returns:
        bool:
    2部グラフならtrue,そうではないならfalse
    """
    for i in range(N):
        if vis[i] == 0:
            deq = deque([i])
            vis[i] = 1
            while deq:
                u = deq.popleft()
                for v in g[u]:
                    if vis[v] == 0:
                        vis[v] = vis[u] * (-1)
                        deq.append(v)
                    # すでに訪問されている頂点が同じ色であれば、グラフは2部ではない
                    elif vis[v] == vis[u]:
                        return False, vis
    return True, vis