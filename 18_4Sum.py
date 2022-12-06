class Solution : 
    def fourSum(self, nums: list[int], target : int) -> list[list[int]]:
        n = len(nums)
        past = set()
        answer = set()

        for i in range (n):
            for j in range(i+1,n):
                for k in range(j+1,n):
                    total = nums[i] + nums[j] + nums[k]
                    remaining = target - total 
                    if remaining in past:
                        answer.add((nums[i],nums[j],nums[k],remaining))

            past.add(nums[i])

        return list(answer)


if __name__ == "__main__":

    s = Solution() 
    print(s.fourSum(nums=[2,2,2,2,2],target = 8))




