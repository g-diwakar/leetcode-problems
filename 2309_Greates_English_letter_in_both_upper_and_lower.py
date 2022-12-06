class Solution:
    def greatesLetter(self, s:str)->str:
        up = 65
        low = 97
        answer = []

        for i in range(26):
            if chr(up+i) in s and chr(low+i) in s:
                answer.append(chr(up+i).upper())

        return answer[-1] if len(answer)>0 else ""

if __name__ == "__main__":
    s = Solution()
    print(s.greatesLetter("AbCdEfGhIjK"))
    print(s.greatesLetter("arRAzFif"))

