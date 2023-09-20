class RMQ:
    """
    RMQ(Range Maximum Queries)はlからr([l,r))までの最大値を求める。
    またupdateでdat[pos]=x（1-indexeed)で配列の値を変換できる。
    Nは配列の長さ
    aは配列の初期化値
    """
    def __init__(self,N,a):
        self.N=N
        self.a=a
        self.siz=1
        while(self.siz<N):self.siz*=2
        self.dat=[self.a for _ in range(300000)]
    """
    posは1-indexedでxは更新する値
    """
    def update(self,pos,x):
        pos=pos+self.siz-1
        self.dat[pos]=x
        while(pos>=2):
            pos//=2
            self.dat[pos]=max(self.dat[2*pos],self.dat[2*pos+1])
    """
    l,rは1-indexedで[l,r)と半間区間となる
    """
    def query(self,l,r,a=1,b=None,u=1):
        if b is None:b=self.siz+1
        if(r<=a or b<=l):return -10**18
        if(l<=a and b<=r):return self.dat[u]
        mid=(a+b)//2
        a_l=self.query(l,r,a,mid,u*2)
        a_r=self.query(l,r,mid,b,u*2+1)
        return max(a_l,a_r)
