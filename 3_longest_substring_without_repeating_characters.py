class Solution:
    def lengthOfLongestSubstring(self, s:str) -> int:

        if s =="": #handling exception
            return 0 
        subarray=[] #stores the substring 
        length=1


        # what we'll be doing here is iterating through all the characters 
        # subarray storing the unrepeated characters
        for char in s:
            if char not in subarray:
                subarray.append(char)
            else:
                length = len(subarray) if len(subarray) > length else length
                #delete the characters before the repeated character "char"
                # for string "dvdf" subarray = "dv" now d is found at the third iteration the index of the repeated charcter"d" is taken out and 
                # all the elements before the repeated character"d" is removed from the subarray
                i = subarray.index(char)
                subarray = subarray[i+1:]
                subarray.append(char)

        return length if len(subarray)<length else len(subarray)


if __name__ == "__main__":
    s = Solution()
    print(s.lengthOfLongestSubstring("pwwkew"))
    print(s.lengthOfLongestSubstring("bbbbb"))
    print(s.lengthOfLongestSubstring("abcabcbb"))
    print(s.lengthOfLongestSubstring(""))
    print(s.lengthOfLongestSubstring(" "))
                


        
