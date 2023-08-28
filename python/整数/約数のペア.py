def get_divisor_pairs(n):
    """
    nの約数のペアを全て求める
    ここでは,(1,n),(n,n)を含を含む。
    ２次元配列で返す
    """
    res = []
    for i in range(1, int(n**0.5)+1):
        if n%i == 0:
            res.append([i, n//i])
    return res