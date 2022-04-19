# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        self.first = self.second = self.pre = None
        def traverse(node):
            if node:
                traverse(node.left)
                if self.pre:
                    if not self.first and self.pre.val > node.val:
                        self.first = self.pre
                    if self.first and self.pre.val > node.val:
                        self.second = node
                self.pre = node
                traverse(node.right)
        traverse(root)
        self.first.val, self.second.val = self.second.val, self.first.val
