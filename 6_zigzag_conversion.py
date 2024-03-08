class Solution:
    def convert(self, s:str, numRows:int):
        if numRows==1:
            return s
        answer = [["" for i in range(1)] for j in range(numRows)]

        i=0
        down = True

        for c in s:
            answer[i].append(c)
            print(answer) 
            if i==numRows-1:
                down = False
            if i == 0 :
                down = True

            i = i+1 if down else i-1

        result = ''.join(''.join(item for item in row if item) for row in answer)

        return result 

if __name__ == "__main__":
    s = Solution()

    print(s.convert("AB",1))
