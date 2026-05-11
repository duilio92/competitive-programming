# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def generate_subtree_dict(self, root: TreeNode):
        if root is None or root.val is None:
            return '#'
        if root.left is None and root.right is None:
            key = f"{root.val}"
        else:
            key = f"{root.val}, {self.generate_subtree_dict(root.left)}, {self.generate_subtree_dict(root.right)}"
        if key in self.subtree_dict:
            self.subtree_dict[key] = self.subtree_dict[key][0] + 1, root
        else:
            self.subtree_dict[key] = 1, root
        return key
 
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        self.subtree_dict = {}
        list_of_duplicates = []
        self.generate_subtree_dict(root)
        #print(self.subtree_dict)
        for x in self.subtree_dict.keys():
            val = self.subtree_dict[x]
            if val[0] > 1:
                list_of_duplicates.append(val[1])
        return list_of_duplicates
        