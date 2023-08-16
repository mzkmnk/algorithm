def topo_sort(g,n):
    """
    g:隣接リスト
    n:頂点数
    -1:閉路が存在する
    """
    order=[]
    indeg=[0]*n
    for v in range(n):
        for v1 in g[v]:
            indeg[v1]+=1
    st=[v for v in range(n) if indeg[v]==0]
    while st:
        v=st.pop()
        order.append(v)
        for v1 in g[v]:
            indeg[v1]-=1
            if indeg[v1]==0:
                st.append(v1)
    if len(order)==n:
        return order
    return -1