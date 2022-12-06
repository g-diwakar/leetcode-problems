class Solution:
    def countTexts(self,pressedKeys:str)->int:
        n = len(pressedKeys)
        dp =[0]*(n+1)
        dp[0]=1 

        for i in range(1,n+1):
            dp[i] = dp[i-1]

            if i-2>=0 and pressedKeys[i-1]==pressedKeys[i-2]:
                dp[i]+=dp[i-2]

            if i-3>=0 and pressedKeys[i-1] == pressedKeys[i-2] and pressedKeys[i-1]==pressedKeys[i-3]:
                dp[i]+=dp[i-3]

            #exception case for 7 and 9 as they have four different options

            if pressedKeys[i-1] in {"7","9"}:
                if i-4>=0 and pressedKeys[i-1] == pressedKeys[i-2] and pressedKeys[i-1]==pressedKeys[i-3] and pressedKeys[i-1]==pressedKeys[i-4]:
                    dp[i]+=dp[i-4]

        
        return dp[-1] %(10**9+7)


if __name__ == "__main__":
    s = Solution()

    print(s.countTexts("22233"))





