#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    int answer=1;

    sort(nums.begin(), nums.end());

    for(int i=0;i<nums.size();++i)
    {
      if(nums[i]==nums[i-1])
          continue;
      if(answer==nums[i])
          ++answer;
      }

    return answer;    
    }
};

int main()
{
  vector<int> num;

  num.push_back(5);
  num.push_back(5);
  num.push_back(7);
  num.push_back(2);
  num.push_back(3);
  num.push_back(0);
  num.push_back(-1);
  num.push_back(8);
  cout<<&num[num.size()]-&num[-1]<<endl;
  cout<<&num[-1]<<endl;
  Solution s;
  cout<<s.firstMissingPositive(num)<<endl;

}
