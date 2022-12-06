#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
   {
     if(nums.size()<3)
        return {};
      vector<vector<int>> answer;

      int t_i=1,t_j=1,t_k=1;
      vector<int> tanswer;

      sort(nums.begin(),nums.end());
      
      for(int i=0;i<nums.size()-2;++i)
      {
        if(i>0 && nums[i]==nums[i-1])
           continue;
        for(int j=i+1;j<nums.size()-1;++j)
        {
          int temp=nums[i]+nums[j];

          for(int k=j+1;k<nums.size();++k)
          {
            if(nums[k]==(-1)*temp)
            {
              if(t_i==nums[i] && t_j==nums[j] && t_k==nums[k] )
                break;
              tanswer.push_back(nums[i]);
              tanswer.push_back(nums[j]);
              tanswer.push_back(nums[k]);
              answer.push_back(tanswer);
              
              t_i=nums[i];
              t_j=nums[j];
              t_k=nums[k];
              tanswer.clear();
              break;
            }
          }
        }
      }


    return answer;
    }
};

int main()
{
  Solution s;

  vector<int> num;

  //num.push_back(-1);
  num.push_back(0);
  num.push_back(0);
 num.push_back(0);
 num.push_back(0);

 //num.push_back(1);
 // num.push_back(2);
 // num.push_back(-1);
 // num.push_back(-4); 

  vector<vector<int>> answer;

  answer=s.threeSum(num);
  cout<<answer.size()<<endl;
  for(int i=0;i<answer.size();++i)
  {
    for(int k=0;k<answer[i].size();++k)
    {
      cout<<answer[i][k]<<"\t";
    }
    cout<<endl;
  }

}
