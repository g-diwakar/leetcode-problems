class Solution:
    def minimumNumbers(self,num:int, k:int) -> int:
        if num == 0:
            return 0 

        for i in range(1,11):
            if ((i*k)%10 == num%10 and i*k <=num):
                return i

        return -1

if __name__ == "__main__":
    s = Solution()
    print(s.minimumNumbers(47,9))
    
