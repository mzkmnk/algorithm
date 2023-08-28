def calc_next(S):
    # res[i][c] := i 文字目以降で最初に文字 c が登場する index
    # 存在しないときは N
    # 文字列 S の長さ
    """
    文字列Nの中からK個選んで作る文字列のうち、辞書順で最小のものを求める時に使う配列
    writer by けんちょんさん
    """
    N = len(S)

    # 答え
    res = [[N] * 26 for _ in range(N + 1)]

    # 後ろから見る
    for i in range(N - 1, -1, -1):
        # i + 1 文字目以降の結果を一旦 i 文字にコピー
        for j in range(26):
            res[i][j] = res[i + 1][j]

        # i 文字目の情報を反映させる
        res[i][ord(S[i]) - ord('a')] = i

    # 答えを返す
    return res