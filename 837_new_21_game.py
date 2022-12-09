class Solution:
    def new21Game(self, n:int, k:int , maxPts:int) -> float:
        if (k == 0 or n>k+maxPts ):
            return 1.0

        '''
        before running to the solution first make little bit of things clear:
            we are interested in finding the probaility of number between n & k P(?) = P(k) + ..... + P(n)
            as the question itself reads the probability of each draw is independent and equal: 
                probaility of getting any point would be 1/maxPts 
            and the probability of getting any points say 15  , with maxPts = 8 would be :
                dp[15] = dp[14] * P(1) + dp[13] * P(2) + dp[12] * P(3) ....... + dp[15-8] * P(8)
                summarizing, :
                    dp[i] = dp[i-1] * P(1) + dp[i-2] * P(2) + ...... + dp[i-maxPts] * P(maxPts) 
                    since, P(1) = P (2) = .... = P(maxPts)
                    dp[i] = 1/maxPts *(dp[i-1] +....... + dp[i-maxPts])
                
                the above equation is true only when i<k
                when i>k :
                    dp[i] = 1/maxPts(dp[k]+....+dp[i-maxPts])

                and of course P(k) ..... P(n) =:
                    dp[k] + dp[k+1] + ..... + dp[n]

        '''
        p = 1/maxPts 

        dp = [0.0] *(n+1) # this stores the probability of getting 0,,,,n points

        dp[0] = 1 #probability of getting 0 is always 1

        currentSum = dp[0] # this is expected to hold the sum between dp[i-1] +.......dp[i-maxPts]

        answer = 0 

        for i in range(1,n+1):

            dp[i] = currentSum *p

            #now we're adjusting the currentSum to dp[i-1] ... dp[i-maxPts]

            if(i<k):
                currentSum += dp[i] 
            else:
                answer +=dp[i] # since we've to stop after getting k or more points there is no point on increasing the currentSum 

            if (i-maxPts >=0):
                currentSum -= dp[i-maxPts]

        return answer


if __name__ == "__main__":
    s = Solution()
    print(s.new21Game(10,1,10))
    print(s.new21Game(21,17,10))

