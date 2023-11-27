from heapq import heappush, heappop, heapify
from functools import reduce
from atcoder.modint import ModContext as modwith
from atcoder.modint import Modint as mint
from atcoder.dsu import DSU
from atcoder.segtree import SegTree
from atcoder.lazysegtree import LazySegTree
from atcoder.maxflow import MFGraph
from graphlib import TopologicalSorter
from sortedcontainers import SortedDict, SortedList, SortedSet
from more_itertools import chunked
from collections import defaultdict, deque, Counter
from itertools import permutations, combinations, accumulate
from math import gcd, sqrt, factorial, ceil, comb, perm, lcm
from bisect import bisect_left, bisect_right
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def STR(): return input().rstrip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def MAP_DEC(): return map(lambda x: int(x) - 1, input().split())
def LIST(): return list(map(int, input().split()))
def LIST_DEC(): return list(map(lambda x: int(x) - 1, input().split()))

def clamp(val, low, high): return max(low, min(val, high))

MOD = 998244353
INF = float('inf')
d4 = [[-1, 0], [1, 0], [0, -1], [0, 1]]
d8 = [[-1, 0], [1, 0], [0, -1], [0, 1], [-1, -1], [-1, 1], [1, -1], [1, 1]]
