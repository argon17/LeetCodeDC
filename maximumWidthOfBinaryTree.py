# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def widthOfBinaryTree(self, root):
        ans, level, index = 0, 0, 0
        queue = [[root, level, index]]
        while queue:
            curNode, curLevel, curIndex = queue.pop(0)
            if curLevel > level:
                level, index = curLevel, curIndex
            ans = max(ans, curIndex - index + 1)
            if curNode.left:
                queue.append([curNode.left, curLevel + 1, curIndex*2 + 1])
            if curNode.right:
                queue.append([curNode.right, curLevel + 1, curIndex*2 + 2])
        return ans
