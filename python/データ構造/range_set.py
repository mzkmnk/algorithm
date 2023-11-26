class RangeSet:
    # RangeSetクラスは、数値の範囲（区間）を管理するためのクラスです。
    # これは区間の集合を効率的に管理し、区間の挿入、削除、および照会をサポートします。
    def __init__(self):
        self.TINF = sys.maxsize
        self.sum = 0
        self.st = SortedSet()
        self.st.add((-self.TINF, -self.TINF))
        self.st.add((self.TINF, self.TINF))

    def covered(self, l, r):
        # covered関数は、与えられた範囲[l, r)が既存のどの区間にも完全に含まれているかどうかを判定します。
        assert l <= r
        if l == r:
            return True
        itr = self.st.bisect_left((l, self.TINF)) - 1
        return self.st[itr][0] <= l and r <= self.st[itr][1]

    def covered_by(self, l, r):
        # covered_by関数は、与えられた範囲[l, r)を含む既存の区間を返します。
        # そのような区間が存在しない場合、(-TINF, -TINF)を返します。
        assert l <= r
        if l == r:
            return (-self.TINF, -self.TINF)
        itr = self.st.bisect_left((l, self.TINF)) - 1
        if self.st[itr][0] <= l and r <= self.st[itr][1]:
            return self.st[itr]
        return (-self.TINF, -self.TINF)

    def insert(self, l, r):
        # insert関数は新しい範囲[l, r)を追加します。
        # この関数は、追加された範囲のサイズを返し、既存の範囲と重複する部分を考慮に入れて調整します。
        assert l <= r
        if l == r:
            return 0
        itr = self.st.bisect_left((l, self.TINF)) - 1
        sum_erased = 0

        # 以下のコードは範囲の追加および更新処理を行います。

    def erase(self, l, r):
        # erase関数は、範囲[l, r)を削除します。
        # この関数は削除された範囲のサイズを返します。
        assert l <= r
        if l == r:
            return 0
        itr = self.st.bisect_left((l, self.TINF)) - 1
        ret = 0

        # 以下のコードは範囲の削除処理を行います。

    def size(self):
        # size関数は、管理されている区間の数を返します。
        return len(self.st) - 2

    def mex(self, x=0):
        # mex関数は、指定された数値x以上で、どの区間にも含まれていない最小の数値を返します。
        itr = self.st.bisect_left((x, self.TINF)) - 1
        if self.st[itr][0] <= x < self.st[itr][1]:
            return self.st[itr][1]
        else:
            return x

    def sum_all(self):
        # sum_all関数は、すべての区間における合計範囲のサイズを返します。
        return self.sum

    def dump(self):
        # dump関数は、管理されている区間を出力します。
        ranges = [f"[{p[0]},{p[1]})" for p in self.st if abs(p[0]) != self.TINF]
        print("range_set:", ",".join(ranges))

