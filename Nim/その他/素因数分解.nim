import math
proc prime_factors(n:int):seq[int]=
    var factors: seq[int] = @[]
    var m = n
    while m mod 2 == 0:
        factors.add(2)
        m = m div 2
    for i in countup(3,int(sqrt(float(m)))+1,2):
        while m mod i == 0:
            factors.add(i)
            m = m div i
    if m > 2:factors.add(m)
    return factors

var a:seq[seq[int]] = @[]
for i in A:a.add(prime_factors(i))