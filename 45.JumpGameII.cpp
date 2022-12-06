#include <cstdint>
#include<iostream>
#include<vector>
using namespace std;

class Solution
{
  public:
    int jump(vector<int> & nums)
    {
      int n=nums.size();

      //lets store the minimum jump to reach  every indexes in the jump array
      vector<int> jump(n,INT16_MAX);
      //minimum cost for the first element is zero
      jump[0]=0;

      for(int i=0 ; i<n-1;++i)
      {
          //starting at index i lets scan all possible reachable indexes
          for(int j=i+1;j<=(i+nums[i]) && j<n;++j)
          {
            //check whether the jump from index i to reach index j is minimum or not
            jump[j]=min(jump[i]+1, jump[j]);
          }

        }

      //return the minimum cost to reach the last index;
      return jump[n-1];

    }
  };

int main()
{
  Solution s;

  vector<int> nums;
  //nums={2,3,0,1,4};
  nums ={2,3,1,1,4};

  cout<<s.jump(nums)<<endl;


}
