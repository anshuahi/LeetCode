class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        nums.sort()
        n = len(nums)
        k = (n+1)//2
        a1 = nums[:k]
        a2 = nums[k:]
        a1.reverse()
        a2.reverse()
        i1 = 0
        i2=0

        for i in range(n):
            if i%2 == 0:
                nums[i] = a1[i1]
                i1 +=1
            else :
                nums[i] = a2[i2]
                i2 +=1
        