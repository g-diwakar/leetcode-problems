class Solution:
    def dividePlayers(self, skill:list[int]) -> int:
        skill.sort()

        length = len(skill)/2

        eSkill = set()
        chemistry = 0 
        for i in range(int(length)):
            back = -1 * (i + 1) 
            tSkill = skill[i] + skill[back]

            eSkill.add(tSkill)

            if len(eSkill) == 1:
                chemistry += (skill[i] * skill[back])

            else:
                return -1

        return chemistry

if __name__ == "__main__":
    s = Solution()
    print(s.dividePlayers([3,2,5,1,3,4]))
    print(s.dividePlayers([3,4]))


            
