from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: list[int],k:int) -> list[int]:
        ans = [] #stores the maximum values
        q = deque() #stores the indices, the queue here will be monotonically decreasing queue

        l = 0 
        r =0

        while (r<len(nums)):
            #the queue here is decreasing queue , so we're going to pop if the current number is greater the rightmost part
            #of the queue 
            while q and nums[q[-1]] < nums[r]:
                q.pop()

            q.append(r)

            #checking whether the left index of the window is out of range
            if l > q[0]:
                q.popleft()

            #if u got the valid window add the maximum value in the queue which is of course the first of the index to the answer
            if (r+1) >=k:
                ans.append(nums[q[0]])
                l+=1 #slides the window by 1 
            r+=1

        return ans




        
if __name__ == "__main__":
    s = Solution()
    print(s.maxSlidingWindow([1],1))



