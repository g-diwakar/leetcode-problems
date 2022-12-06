/****
Given n non-negative integers representing an elevation map 
where the width of each bar is 1, compute how much water 
it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented
by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water
(blue section) are being trapped.
***/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) 
    {
      int answer=0;
      int current=0;
      int size=height.size();

      stack<int> s;
      while(current<size) // lets scan the whole array
      {
        //we are using decreasing monotonic stack
        //so anything higher value comes up, this one can bound 
        //all the left values
        while(!s.empty() && height[current]> height[s.top()])
        {
          int top=s.top();
          s.pop();
          if(s.empty())
            break;
          //trapping water means it should have always left and right bounded bars
          int trapped_width=current-s.top()-1; 
          int trapped_height=min(height[current],height[s.top()])-height[top];
          answer+= trapped_height * trapped_width;
        } 
          s.push(current++);
      }
      

      return answer;
        
    }
};

int main()
{
  vector<int> h={0,1,0,2,1,0,1,3,2,1,2,1};

  Solution s;

  cout<<s.trap(h)<<endl;

}
