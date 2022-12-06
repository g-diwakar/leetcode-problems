#include<iostream>
#include<set>
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
      int temp;
      int j,k;

      sort(nums.begin(),nums.end());
      
      for(int i=0;i<nums.size()-2;++i)
      {
        if(i>0 && nums[i]==nums[i-1])
            continue;
        j=i+1; k= nums.size()-1;

        temp=nums[i]+nums[j];


        while(j<k && temp<=0)
        {
          
          if((-1)*temp>nums[k])
              {
              ++j;
              temp=nums[i]+nums[j];
              }
          else if((-1)*temp<nums[k])
            --k;

          else
                {
                  answer.push_back({nums[i],nums[j], nums[k]});

          
                  while(j<k && nums[k]==nums[k-1]) k--;
                  while(j<k && nums[j]==nums[j+1])
                  {
                      ++j;
                      temp=nums[i]+nums[j];
                  }

                  ++j;
                  temp=nums[i]+nums[j];

                };


          }

      
      }

    return answer;
   }
};

int main()
{
  Solution s;

  vector<int> num;

  //num.push_back(-4);
  //num.push_back(-3);
  //num.push_back(-2);
 //num.push_back(-1);
 //num.push_back(-1);
 num.push_back(0);
 num.push_back(0);
 num.push_back(0);
 //num.push_back(1);
 //num.push_back(2);
 //num.push_back(3);
 //num.push_back(4);

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
