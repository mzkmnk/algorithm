class StringHash:
    """
    Nは文字列
    Sは文字列
    与えられた文字列をローリングハッシュする。
    """
    def __init__(self, N, S, MOD=2147483647):
        self.N = N
        self.S = S
        self.MOD = MOD
        self.hash_S = [0]
        self.pow_100 = [1]
        self.__calculate_hash()
        self.__calculate_pow()

    def __calculate_hash(self):
        for i in range(1,self.N+1):
            new_hash = (self.hash_S[i-1] * 100 + (ord(self.S[i-1]) - ord('a') + 1)) % self.MOD
            self.hash_S.append(new_hash)

    def __calculate_pow(self):
        for i in range(1, self.N+1):
            new_pow = (self.pow_100[i-1] * 100) % self.MOD
            self.pow_100.append(new_pow)
    """
    l,rは1-indexedとなる
    """
    def hash_l_r(self, l, r):
        return (self.hash_S[r] - (self.hash_S[l - 1] * self.pow_100[r - l + 1]) % self.MOD + self.MOD) % self.MOD
"""
例
string_hash=StringHash(N,S)
"""
