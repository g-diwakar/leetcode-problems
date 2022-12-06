class Solution:
    def divide(self,dividend:int, divisor:int) -> int:
        sign = (dividend < 0 and divisor < 0) or (dividend>0 and divisor>0)

        divid = abs(dividend)
        divis = abs(divisor)

        if(divid==divis):
            return 1 if sign else -1

        answer = 0

        while(divid>=divis):
            temp = 0 
            while(divid>(divis<<(temp+1))):
                temp+=1

            answer+=(1<<temp)
            divid -=(divis<<temp)

        answer = answer if sign else -1*answer

        maximum = (1<<31) -1 
        minimum = (1<<31) * -1 


        if answer<minimum:
            return minimum

        if answer > maximum :
            return maximum


        return answer

if __name__ == "__main__":
    s = Solution()
    print(s.divide(-11,-5))


