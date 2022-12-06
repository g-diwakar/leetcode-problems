class Solution:
    def longestSubsequence(self,s:str,k:int) -> int :
        if s == "":
            return 0
        place= 0 
        value = 0 

        # looking from behind makes the perfect sense to include the number or not ; this way we can protect the relative position of the number
        for i in range(len(s)-1,-1,-1):
            # we're now checking whether including the current number would exceed the number 'k' or not 
            # if not value is updated and count (place) is increased by 1
            t_value = value + 2**place *  int(s[i])
            if(t_value <= k):
                value = t_value
                place +=1

        return place

if __name__ == "__main__":
    s = Solution()

    print(s.longestSubsequence("1001010",5))


