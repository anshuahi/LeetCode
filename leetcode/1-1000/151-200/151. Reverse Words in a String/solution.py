class Solution:
    def reverseWords(self, s: str) -> str:
        p = " "
        ar = s.split(' ')
        
        ar.reverse()
        a = filter(lambda x: len(x) > 0, ar)
        # print(a)
        p = p.join(a)
        # p = a.join(' ')
        return p