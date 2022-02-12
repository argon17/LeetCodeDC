class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0
        adj = collections.defaultdict(list)
        wordList.append(beginWord)
        for word in wordList:
            for ind in range(len(word)):
                pat = word[:ind] + "_" + word[ind + 1:]
                adj[pat].append(word)
        queue = [beginWord]
        vis = set([beginWord])
        ans = 1
        while queue:
            for _ in range(len(queue)):
                word = queue.pop(0)
                if word == endWord:
                    return ans
                for ind in range(len(word)):
                    pat = word[:ind] + "_" + word[ind + 1:]
                    for neighbor in adj[pat]:
                        if neighbor not in vis:
                            queue.append(neighbor)
                            vis.add(neighbor)
            ans += 1
        return 0