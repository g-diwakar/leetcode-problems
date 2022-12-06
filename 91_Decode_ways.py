class Solution:
    def numDecodings(self, s:str)-> int:
        #initialize dp array of lenghth n with 0 
        dp = [0] * len(s)
        dp.append(1) 

        #we'll go through top down approach  
        for i in range(len(s)-1,-1,-1):
            # 0 alone cannot decode any string so we'll skip the part
            if (s[i]=="0"):
                continue
            
            #the ways we can decode the string is stored in the next index
            #this is the reason why we made dp array of lenght + 1 and initialize with 1 ; cause any number from 1-9 can be decoded in its own way
            dp[i]+=dp[i+1]

            #looking if the combined two digit numbers would ddcode or not ; if the combined digit <=26 then we're good to go
            #in this case s[i] and s[i+1] would form a digit so we'd look for the ways after the 2 more index
            if (i+1<len(s) and (s[i]+s[i+1] <="26")):
                dp[i]+=dp[i+2]

        return dp[0]
            

if __name__ == "__main__":
    s = Solution()
   # print(s.numDecodings("100"))
    print(s.numDecodings("1123"))
    #print(s.numDecodings("06"))
            
