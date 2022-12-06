from functools import cache

class Solution:
    def numSquares(self, n:int) -> int :

        perfect_squares = []

        i = 1
        square = 1

        while(square<=n) :
            square = i*i
            perfect_squares.append(square)
            i+=1
        
        perfect_squares.pop()
        perfect_squares=perfect_squares[::-1]

        @cache
        def helper(n) -> int:
            if n<=0 :
                return 0

            minimum_count = 2**31-1
            for num in perfect_squares:
                current_count = 1 + helper(n-num)
                minimum_count = min(current_count,minimum_count)

            return minimum_count

        return helper(n)


if __name__ == "__main__":
    s = Solution()

    print(s.numSquares(12))
            
