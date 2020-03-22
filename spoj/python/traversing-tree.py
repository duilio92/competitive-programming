https://www.spoj.com/problems/TREEVERSE/
from sys import stdin, stdout
 
class Tree:
    def __init__(self):
        self.left = None
        self.right = None
        self.data = None
 
def insert(tree, elem):
    if tree == None:
        new_tree = Tree()
        new_tree.data = elem
        return new_tree
    else:
        if elem < tree.data:
            tree.left = insert(tree.left, elem)
        else:
            tree.right = insert(tree.right, elem)
        return tree 
 
def build_tree(arr):
    t = Tree()
    t.data = arr[0]
    for i in range(1, len(arr)):
        insert(t,arr[i])
    return t
 
def pre_order(t):
    #prints pre order list
    if t.data:
        stdout.write(" " + str(t.data))
    if t.left:
        pre_order(t.left)
    if t.right:
        pre_order(t.right)
 
def post_order(t):
    if t.left:
        post_order(t.left)
    if t.right:
        post_order(t.right)
    if t.data:
        stdout.write(" " + str(t.data))
    
    
def in_order(t):
    if t.left:
        in_order(t.left)
    if t.data:
        stdout.write(" " + str(t.data))
    if t.right:
        in_order(t.right)
    
n = int(stdin.readline())
arr = [ int(n) for n in stdin.readline().split() ]
tree = build_tree(arr)
stdout.write("Pre order :")
pre_order(tree)
stdout.write('\n')
stdout.write("In order  :")
in_order(tree)
stdout.write('\n')
stdout.write("Post order:")
post_order(tree)
stdout.write('\n') 