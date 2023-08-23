def warshall_floyd(dist, cost, cost_matrix, max_num):
    """
    ワーシャル-フロイドのアルゴリズムで全点対最短距離と最大コストを計算する。
    さらに、負の閉路が存在するかも判定する。
    
    Args:
        dist (list of list of int): 各点から各点への最短距離を格納した2次元リスト。
        cost (list of list of int): 各点から各点への最大コストを格納した2次元リスト。
        cost_matrix (list of int): 各ノードのコストが格納されたリスト。
        max_num (int or float): 初期の最大距離値（通常は無限大を表す値）

    Returns:
        tuple: 計算後の最短距離と最大コストが格納された2次元リストと負の閉路の有無（dist, cost, has_negative_cycle）。
    """
    V = len(dist)  # ノードの数
    has_negative_cycle = False  # 負の閉路が存在するかどうか

    for i in range(V):
        dist[i][i]=0
        cost[i][i]=cost_matrix[i]

    # ワーシャル-フロイドのアルゴリズムの実行
    for k in range(V):
        for i in range(V):
            for j in range(V):
                if dist[i][k] == max_num or dist[k][j] == max_num:
                    continue  # 有効な経路がない場合、スキップ
                
                new_d = dist[i][k] + dist[k][j]  # 新しい距離
                new_c = cost[i][k] + cost[k][j] - cost_matrix[k]  # 新しいコスト
                
                if new_d < dist[i][j] or (new_d == dist[i][j] and new_c > cost[i][j]):
                    dist[i][j] = new_d  # 距離を更新
                    cost[i][j] = new_c  # コストを更新

    # 負の閉路の検出
    for i in range(V):
        if dist[i][i] < 0:
            has_negative_cycle = True  # 負の閉路が見つかった
            break

    return dist, cost, has_negative_cycle


#--------sample code--------
V,E=map(int,input().split())
dist=[[float("inf") for _ in range(V)] for _ in range(V)]
cost=[[0 for _ in range(V)] for _ in range(V)]
for _ in range(E):
    s,t,d=map(int,input().split())
    dist[s][t]=d
d,c,j=warshall_floyd(dist,cost,[0]*V,float('inf'))
if j:print("Negative cycle")
else:
    for i in range(V):
        for j in range(V):
            if d[i][j]==float("inf"):
                if(j==V-1):print("INF")
                else:print("INF",end=" ")
            else:
                if(j==V-1):print(d[i][j])
                else:print(d[i][j],end=" ")

