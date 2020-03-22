class Solution:
    def from_num_to_val(self,num, n):
        aux = num
        if aux < 1:
            aux += n
        if aux < 1:
            aux += n
        return aux

    def findDuplicates(self, nums):
        n= len(nums)
        for num in nums:
            val = self.from_num_to_val(num, n)
            nums[val-1] -= n
        for i in range(0,len(nums)):
            num = nums[i]
            if num + 2 * n <= n:
                nums[i]= i + 1
            else:
                nums[i]= n +1
        nums = [x for x in nums if x != n+1]
        return nums