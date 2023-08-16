def soe(n):
    """
    n以下の素数を列挙する
    エラトステネスの篩を用いる
    計算量はO(nloglogn)
    """
    primes = [True for i in range(n+1)]
    p = 2
    while(p * p <= n):
        if (primes[p] == True):
            for i in range(p * p, n + 1, p):
                primes[i] = False
        p += 1
    prime_numbers = [p for p in range(2, n) if primes[p]]
    return prime_numbers