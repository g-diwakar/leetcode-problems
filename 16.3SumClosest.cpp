#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
  {
    int result;
    int temp;
   sort(nums.begin(),nums.end());

    result=nums[0]+nums[1]+nums[2];
    for(int i=0;i<nums.size()-2;++i)
    {
    
      int j=i+1, k=nums.size()-1;

      while(j<k)
        {
            temp=nums[i]+nums[j]+nums[k];

            if(abs(temp-target)<abs(result-target))
              result=temp;
            if(temp>target)
              --k;
            else
             ++j;
          }

    }




    return result;    
  }
};

int main()
{
  vector<int> nums;

  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(4);
  nums.push_back(8);
  nums.push_back(16);
  nums.push_back(32);
  nums.push_back(64);
  nums.push_back(128);

  Solution(s);

  cout<<s.threeSumClosest(nums,82)<<endl;
}
