class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        ver1 = list(map(int, version1.split('.')))
        ver2 = list(map(int, version2.split('.')))
        gap = len(ver1) - len(ver2)
        ver1 += [0] * -gap
        ver2 += [0] * gap
        return (ver1 > ver2) - (ver1 < ver2)