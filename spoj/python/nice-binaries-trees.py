# your code goes here
#https://www.spoj.com/problems/NICEBTRE/
    
from sys import stdin, stdout
    
num_cases = int(stdin.readline())
    
def build_tree_depth(tree_string):
    depth = 0
    if len(tree_string) == 0:
        return 0, ''
    if tree_string[0] == 'n':
        depth_left, remaining_string = build_tree_depth(tree_string[1:])
        depth_right, remaining_string = build_tree_depth(remaining_string)
        depth = 1 + max(depth_left, depth_right)
        return depth, remaining_string
    else:
        return 0, tree_string[1:] # if it is a leave depth is 0.
for i in range(0, num_cases):
    tree_string = stdin.readline()
    stdout.write(str(build_tree_depth(tree_string)[0])+ '\n')
    