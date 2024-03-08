class Solution:
    def longestPalindrome(self, s:str) -> str:
        left_pointer = 0 
        right_pointer = 1

        answer = ""

        while(left_pointer<=len(s)):
            while(right_pointer<=len(s)):
                sub_s = s[left_pointer:right_pointer+1]

                check = True if sub_s[::-1] == sub_s else False

                if check:
                    answer = sub_s if len(sub_s) >= len(answer) else answer

                    
                right_pointer+=1
            left_pointer+=1

        return answer

if __name__ == "__main__":
    s = Solution()
    print(s.longestPalindrome("babad"))
        

            