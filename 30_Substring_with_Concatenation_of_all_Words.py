from collections import Counter
class Solution:
    def findSubstring(self, s:str, words:list[str]) -> list[int]:
        if not words:return[]
        word_size = len(words[0])

        answer = []

        wCount = Counter(words)


        for left in range(len(s)):
            d = wCount.copy() 
            for right in range(left+word_size, len(s)+1, word_size):
                word = s[right-word_size:right]

                if word in d:
                    d[word]-=1
                else:
                    left = right - word_size
                    break

                if d[word] < 0:
                    left = right - word_size
                    break;

                if left + word_size * len(words) == right:
                    answer.append(left)

        return answer


if __name__ == "__main__":
    s = Solution()
    print(s.findSubstring("barfoothefoobarman",["foo","bar"]))
    print(s.findSubstring("barfoofoobarthefoobarman",["bar","foo","the"]))
    print(s.findSubstring("abaababbaba",["ba","ab","ab"]))
    print(s.findSubstring("wordgoodgoodgoodbestword",["word","good","best","word"]))
    

            
        



