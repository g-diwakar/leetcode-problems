class Solution:
    def longestSquareStreak(self, nums) -> int:
        nums = set(nums) #in operator with list takes O(n) time complexity but with sets its just O(1) 
        answer = 1

        for num in nums:
            tanswer = 1 
            tnum = num
            while tnum ** 2 in nums:
                tanswer+=1
                tnum = tnum ** 2

            answer = max (answer,tanswer)

        return -1 if answer == 1 else answer


if __name__ == "__main__":
    s = Solution()
    print(s.longestSquareStreak([4,3,6,16,8,2]))
    print(s.longestSquareStreak([2,3,5,6,7]))
        

         
