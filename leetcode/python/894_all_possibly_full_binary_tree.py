
# Definition for a binary tree node.

class Solution:
    memory = {}
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        if n % 2 == 0:
            return []
        
        if n == 1:
            return [TreeNode(0)]
        
        
        if n in self.memory:
            return self.memory[n]
        res = []
        for left_nodes in range(1, n, 2):
            right_nodes = n - 1 - left_nodes
            
            left_trees = self.allPossibleFBT(left_nodes)
            right_trees = self.allPossibleFBT(right_nodes)
            
            for left in left_trees:
                for right in right_trees:
                    root = TreeNode(0)
                    root.left = left
                    root.right = right
                    res.append(root)
        self.memory[n] = res
        return res