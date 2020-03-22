# https://www.spoj.com/problems/BBIN/
from sys import stdin, stdout
import math
def binary_search(querry):
    pos_left = 0
    pos_right = n -1
    while pos_left < pos_right:
        pos_middle = math.floor((pos_left + pos_right)/2)
        if arr[pos_middle] < querry:
            pos_left = pos_middle +1
        else:
            pos_right = pos_middle
    if(arr[pos_left] != querry):
        return -1
    else:
        return pos_left
 
n,q = map(int, stdin.readline().split())
 
arr = [ int(n) for n in stdin.readline().split() ]
 
for i in range(0, q):
    query = int(stdin.readline())
    stdout.write(str(binary_search(query)) + "\n")
 