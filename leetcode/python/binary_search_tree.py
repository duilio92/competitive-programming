# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        aux = []
        self._build_list(root, aux)
        self.in_orden_list = aux
        self.pos = 0

    def _build_list(self, root, aux):
        if root.left:
            self._build_list(root.left, aux)
        aux.append(root.val)
        if root.right:
            self._build_list(root.right, aux)
    
    def next(self) -> int:
        aux = self.in_orden_list[self.pos]
        self.pos += 1
        return aux
    
    def hasNext(self) -> bool:
        return self.pos < len(self.in_orden_list)
        
# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()