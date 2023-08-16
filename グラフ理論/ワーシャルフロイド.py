def warshall_floyd(graph):
    """
    ワーシャル-フロイドのアルゴリズムを用いて、与えられたグラフの全点対間最短路を計算し、
    負の閉路の存在をチェックする。
    
    Args:
        graph (list of list of int): 初期化したグラフ。点iからjまでの距離を入れる（距離がない場合はfloat('inf')）。

    Returns:
        bool: 負のサイクルがある場合はFalse、ない場合はTrue。

    Note:
        計算量はO(|V|^3)である。関数の副作用として、graph[i][j]にiからjへの最短路のコストが格納される。
    """
    V = len(graph)
    # 自分自身を0に置く
    for i in range(V):
        graph[i][i] = 0
    for k in range(V):
        for i in range(V):
            for j in range(V):
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
    # 負のサイクルがあるかどうか判断　ある場合はFalse、ない場合はTrue
    for i in range(V):
        if graph[i][i] < 0:
            return False
    return True