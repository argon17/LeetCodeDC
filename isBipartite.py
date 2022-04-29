class Solution:
    def isBipartite(self, graph: List[List[int]]) -> bool:
        n = len(graph)
        color = {}
        def dfs(cur):
            for adj in graph[cur]:
                if adj in color:
                    if color[adj] == color[cur]:
                        return False
                else:
                    color[adj] = 1 - color[cur]
                    if not dfs(adj):
                        return False
            return True
        for node in range(n):
            if node not in color:
                color[node] = 0
                if not dfs(node):
                    return False
        return True
