# Definition for a binary tree node.
import copy
from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def print_tree(node, level=0):
    for key, children in node.items():
        print("  " * level + str(key))
        print_tree(children, level + 1)

class Solution:

    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
