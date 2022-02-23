"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if node is None:
            return node
        def dfs(node, mapping):
            for neighbor in node.neighbors:
                if neighbor not in mapping:
                    mapping[neighbor] = Node(neighbor.val)
                    dfs(neighbor, mapping)
                mapping[node].neighbors.append(mapping[neighbor])
        mapping = {node : Node(node.val)}
        dfs(node, mapping)
        return mapping[node]