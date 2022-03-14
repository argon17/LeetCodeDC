class Solution:
    def simplifyPath(self, path: str) -> str:
        ans = []
        for place in [p for p in path.split('/') if p and p != '.']:
            if place == '..':
                if ans:
                    ans.pop()
            else:
                ans.append(place)
        return '/' + '/'.join(ans)