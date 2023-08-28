type
  # Union-Findのデータ構造を定義
  UnionFind = object
    N: int # 要素数
    root: seq[int] # 各要素の根またはグループサイズ（負の数で格納）

# Union-Findの初期化
proc initUnionFind(N: int): UnionFind =
  result.N = N
  result.root = newSeqWith(N, -1)

# 根を見つける
proc find(uf: var UnionFind, x: int): int =
  var r = x
  while uf.root[r] >= 0:
    r = uf.root[r]

  # 経路圧縮
  var tmp = x
  while uf.root[tmp] >= 0:
    swap(uf.root[tmp], r)
    tmp = uf.root[tmp]

  return r

# 二つの要素が属する木を結合
proc union(uf: var UnionFind, x, y: int): bool =
  var x = find(uf, x)
  var y = find(uf, y)
  if x == y:
    return false

  # ランクが低い方を高い方に結合
  if uf.root[y] < uf.root[x]:
    swap(x, y)
  uf.root[x] += uf.root[y]
  uf.root[y] = x

  return true

# 同じ集合に属するかどうかを判断
proc same(uf: var UnionFind, x, y: int): bool =
  return find(uf, x) == find(uf, y)

# 集合のサイズを取得
proc count(uf: var UnionFind, x: int): int =
  return -uf.root[find(uf, x)]

# 集合内のメンバーをリストとして取得
proc members(uf: var UnionFind, x: int): seq[int] =
  let _root = find(uf, x)
  result = @[]
  for i in 0..<uf.N:
    if find(uf, i) == _root:
      result.add(i)

# 全ての根（代表要素）をリストとして取得
proc roots(uf: var UnionFind): seq[int] =
  result = @[]
  for i, x in uf.root:
    if x < 0:
      result.add(i)

# 連結成分（独立した集合）の数を取得
proc groupCount(uf: var UnionFind): int =
  result = 0
  for i in uf.root:
    if i < 0:
      inc(result)

# 各集合のメンバーを取得（ルート要素をキーとするテーブルで返す）
proc allGroupMembers(uf: var UnionFind): Table[int, seq[int]] =
  var groups = initTable[int, seq[int]]()
  for r in uf.roots():
    groups[r] = @[]
  for i in 0..<uf.N:
    groups[find(uf, i)].add(i)
  return groups