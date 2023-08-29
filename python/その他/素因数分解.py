from math import sqrt
def prime_factors(n):
    factors = []
    # 2で割り切れるだけ割り続ける
    while n % 2 == 0:
        factors.append(2)
        n = n // 2
    
    # 3, 5, 7,... と奇数で割り切れるだけ割り続ける
    for i in range(3, int(sqrt(n))+1, 2):
        while n % i == 0:
            factors.append(i)
            n = n // i
    
    # n が2より大きい場合、それ自体が素数である。
    if n > 2:
        factors.append(n)
    
    return factors