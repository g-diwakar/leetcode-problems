#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    bool canCross(vector<int> &  stones)
    {

      //this is the exceptional case 
      if(stones[1]!=1) return false;


      int n=stones.size();

      vector<vector<bool>> dp(n,{false});
      //in the process of recursion there may be several instances where
      // we will have same combination of lastIndex and currentIndex
      // we will use dp to check whether the same combination of lastIndex and currentIndex has occured or not
     // this will minimize repeated further computation

      return func(stones,0,1,dp);


    }

    bool func(vector<int>& stones, int lastIndex, int currentIndex, vector<vector<bool>> &dp)
    {
      //Reached the last index => we have made it through 
      //hence return true
      if(currentIndex== stones.size()-1)
        return true;
     
      if(dp[lastIndex][currentIndex]) return false;


      int lastJump = stones[currentIndex] - stones[lastIndex];

      int nextIndex = currentIndex + 1;

      //at max we are allowed to move through only the one step greater than the previous step
      //this is what the second condition is
      while(nextIndex < stones.size() && stones[nextIndex] <= stones[currentIndex] + lastJump + 1)
      {
          int nextJump= stones[nextIndex] - stones[currentIndex];
          int jump = nextJump - lastJump;

          if(jump>=-1 && jump<=1)
          {  
           if( func(stones, currentIndex, nextIndex, dp))
              return true;
          }
          
          nextIndex ++;


      }

      //we have checked for given lastIndex and currentIndex So
      //tick for this given combination 
      dp[lastIndex][currentIndex]= true;

      return false;
      
    }

    
  };

int main()
{
  Solution s;
  vector<int> stones;

  stones={0,1,3,5,6,8,12,17};
//  stones={0,1,2,3,4,8,9,11};

  cout<<s.canCross(stones)<<endl;

  return 0;
}
