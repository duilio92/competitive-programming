# https://www.spoj.com/problems/CSTREET/
from sys import stdin, stdout
import heapq
    
    
class Edge(object):
    
    def __init__(self, start, dest, weight):
        self.start = start
        self.dest = dest
        self.weight = weight
    
    def __eq__(self, other):
        return ((self.start, self.dest, self.weight) == (other.start, other.dest, other.weight))
    
    def __ne__(self, other):
            return ((self.start, self.dest, self.weight) != (other.start, other.dest, other.weight))
    
    def __lt__(self, other):
        return self.weight < other.weight
    
    def __le__(self, other):
        if self.weight < other.weight:
            return True
        elif self.weight == other.weight:
            return ((self.start, self.dest, self.weight) == (other.start, other.dest, other.weight))
        return False
    
    def __gt__(self, other):
            return self.weight > other.weight
    
    def __ge__(self, other):
        if self.weight > other.weight:
            return True
        elif self.weight == other.weight:
            return ((self.start, self.dest, self.weight) == (other.start, other.dest, other.weight))
        return False
    
    def __repr__(self):
        return "%s %s" % (self.start, self.dest)
    
    
t = int(stdin.readline())
for i in range(0, t):
    price = int(stdin.readline())
    n = int(stdin.readline())
    m = int(stdin.readline())
    # restart list of sets(initially each sets only contains one vertex)
    sets = [set() for _ in range(0,n+1)]
    for x in range(1,n+1):
        sets[x].add(x)
    # initiailize heap empty
    heap = []
    for k in range(0, m):
        edge_k = [int(n) for n in stdin.readline().split()]
        my_edge = Edge(edge_k[0], edge_k[1], edge_k[2])
        heapq.heappush(heap, my_edge)
    largest_set_size = 0
    weight_sum = 0
    while(largest_set_size < n):
        top = heapq.heappop(heap)
        if sets[top.start] != sets[top.dest]:
            sets[top.start] = sets[top.start].union(sets[top.dest])
            for x in sets[top.start]:
                sets[x] = sets[top.start]
            largest_set_size = max(len(sets[top.start]), largest_set_size)
            weight_sum += top.weight
    stdout.write(str(price*weight_sum)+'\n')
    