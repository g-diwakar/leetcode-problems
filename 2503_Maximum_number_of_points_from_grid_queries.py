class Solution:
    def maxPoints(self, grid:list[list[int]], queries:list[int]) -> list[int] :
        srowGrid = len(grid)
        scolGrid = len(grid[0])

        answer =[]
        for query in queries:
            dp = [[False for i in range(scolGrid+2)] for j in range(srowGrid+2)]
            dp[1][1] = True if queries[0] > grid[0][0] else False
            if not dp[1][1]:
                answer.append(0)
                continue

            tanswer = 0 
            for i in range(1,srowGrid+1):
                for j in range(1,scolGrid+1):
                    
                    print(dp[i][j])
                    dp[i][j] = (dp[i][j] or dp[i-1][j] or dp[i+1][j] or dp[i][j-1] or dp[i][j+1]) and query > grid[i-1][j-1]

                    if dp[i][j]:
                        tanswer +=1

            answer.append(tanswer)

        return answer


if __name__ == "__main__":
    s = Solution()
    print(s.maxPoints([[1,2,3],[2,5,7],[3,5,1]],[5,6,2]))


