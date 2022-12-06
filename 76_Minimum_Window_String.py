from collections import Counter

class Solution:
    def miniWindow(self, s:str, t:str) -> str:

        if t=="": return ""

        tCount = Counter(t) #count of characters in t 
        wCount = {} #count of characters in window

        current = 0 #we first are going to set the number of elements in t which are in the current window to zero
        required = len(tCount) #this is the required length to be equal to current to have the valid window

        ans = [-1,-1]#this will hold the left and right and index of the valid window
        ans_length = float("infinity") 

        left = 0

        for index, char in enumerate(s):
            wCount[char] = 1 + wCount.get(char,0) #this one stores the word count in the window

            #this one validates if the character in t is all found in the window 
            if char in tCount and wCount[char] == tCount[char]:
                current +=1

            
            #run the loop until the valid window is formed
            while current == required:
                #checking whether the current window is minimum or not 
                if (index - left + 1) < ans_length:
                    ans_length = index - left + 1
                    ans = [left,index]

                #sliding the window from left
                #this one just deletes the count of the character at the left edge of the window
                wCount[s[left]] -=1
                
                #similar to the operation above to update the values contributing to the validity of the window
                if s[left] in tCount and wCount[s[left]] < tCount[s[left]]:
                    current -=1

                #now finally slding the left edge of the window by 1
                left +=1

        return s[ans[0]:ans[1]+1] if ans_length != float("infinity") else "" 


if __name__ == "__main__":
    s = Solution()
    print(s.miniWindow("ADOBECODEBANC","ABC"))
    print(s.miniWindow("aa","aa"))


     
