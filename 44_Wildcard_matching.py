class Solution:
    def isMatch(self, s:str, p:str) -> bool:
        n = len(s)
        m = len(p)
        #we'll be using bottom up approach for solving the problem
        dp=[[False for i in range(m+1)] for j in range (n+1)]
        dp[0][0] = True

        # a hack for exception 
        for i in range(1,m+1):
            if(p[i-1]=="*"):
                dp[0][i] = True
            else:
                break

        for i in range(1,n+1):
            for j in range(1,m+1):

                #if this is a perfect match we'll be simply copying the previous match results
                if s[i-1] == p[j-1] or p[j-1] =="?":
                    dp[i][j] = dp[i-1][j-1]

                #if * is found we'll have two option whether use it for more of the same kind or discard it for the empty sequence
                #dp[i-1][j] will see the result if we discard it and dp[i][j-1] will see if we use it 
                elif p[j-1] == "*":
                    dp[i][j] = dp[i-1][j] or dp[i][j-1]
                else:
                    dp[i][j] = False
        print(dp)       
        return dp[n][m]

if __name__ == "__main__":
    s = Solution()

    print(s.isMatch("aa","*"))



