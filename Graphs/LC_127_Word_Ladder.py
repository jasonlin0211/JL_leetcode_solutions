# Written by: Jian-Yuan Lin
# Date: 2022.11.18

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordlist = set(wordList)
        q = collections.deque()
        q.append(beginWord)
        steps = 0
        if endWord not in wordlist:
            return 0
        
        while q:
            size = len(q)
            for _ in range(size):
                cur = q.popleft()
                if cur == endWord:
                    return steps + 1
                for i in range(len(cur)):
                    for ch in "abcdefghijklmnopqrstuvwxyz":
                        if ch == cur[i]:
                            continue
                        temp = cur[:i] + ch + cur[i+1:]
                        if temp in wordlist:
                            q.append(temp)
                            wordlist.remove(temp)
            steps += 1
        
        return 0
                     