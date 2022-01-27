# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        def inorder(node):
            if not node:
                return []
            return inorder(node.right) + [node.val] + inorder(node.left)
        res, a, b = [], inorder(root1), inorder(root2)
        # merge two sorted lists
        while a and b:
            if a[-1] < b[-1]:
                res += a.pop(),
            else:
                res += b.pop(),
        return res + (a[::-1] or b[::-1])
        