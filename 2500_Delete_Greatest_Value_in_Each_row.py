class Solution:
    def deleteGreatestValue(self, grid:list[list[int]]) -> int:
       n = len(grid) # row length
       m = len(grid[0]) #column length

       #first of all sort each row
       for i in range(n):
           grid[i].sort()

       answer = 0 

    # now find the greatest element in each column of the row
       while m > 0:
            tList = []

            for i in range(n):
                tList.append(grid[i][m-1])

            answer += max(tList)
            m-=1
        
       return answer

if __name__ == "__main__":
    s = Solution()

    print(s.deleteGreatestValue([[1,2,4],[3,3,1]]))
    print(s.deleteGreatestValue([[10]]))
            
