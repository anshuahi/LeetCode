class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        parent = {}
        ch = 'a'
        for i in range(0, 26):
            parent[chr(ord(ch) + i)] = chr(ord(ch) + i)
            print(ord('d') - ord(ch))

        def union(a, b):
            x = find(a)
            y = find(b)
            if x == y:
                return
            z = min(x, y)
            parent[x] = z
            parent[y] = z

        def find(a):
            if parent[a] == a:
                return a
            parent[a] = find(parent[a])
            return parent[a]
        
        for i in range(len(s1)):
            union(s1[i], s2[i])
            # print(parent)
        s = ""

        for i in range(len(baseStr)):
            s = s + find(baseStr[i])

        return s
