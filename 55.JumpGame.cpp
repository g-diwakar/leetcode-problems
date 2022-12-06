#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
      // we are at initially at index 0
      int reachableIndex =0 ;

    // lets iterate through all the array
    // calculate the next reachableIndex using
    // reachableIndex = reachableIndex + nums[i];
    // if reachableIndex < currentIndex it is sure we can't move any further
    // if reachableIndex > size of array , congratulations , we have jumped all the way through
      for(int i=0;i<nums.size();++i)
      {
        if(reachableIndex<i)
          return false;
        if(reachableIndex>=nums.size()-1)
          return true;
       reachableIndex=max( reachableIndex, i+ nums[i]);
      }

      return true;
      
        
    }
};

int main()
{
  Solution s;
  vector<int> nums;

  //nums={2,3,1,1,4};
  //nums={1};
  nums={3,2,1,0,4};
 // nums={3,2,1,1,2,0,0,0};

  cout<< s.canJump(nums)<<endl;

  return 0;
}
