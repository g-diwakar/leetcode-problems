#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
      int answer =0;
      stack<int> pst;
      stack<int> nst;
      vector<int> previosSmaller;
      vector<int> nextSmaller(heights.size());
      
      for(int i=0;i<heights.size();++i)
      {
        while(!pst.empty() && heights[pst.top()]>= heights[i] )
        {
          pst.pop();
        }
        if(pst.empty())
          previosSmaller.push_back(-1);
        else
          previosSmaller.push_back(pst.top());
        pst.push(i);
      }
      
      for(int i=heights.size()-1;i>=0;--i)
      {
        if(nst.empty())
        {
          nextSmaller[i]=heights.size();

        }
        else
        {
        while(!nst.empty() && heights[nst.top()]>=heights[i])
          nst.pop();
        if(nst.empty())
          nextSmaller[i]=heights.size();
        else
         nextSmaller[i]=nst.top();
      
        }
        nst.push(i);
      }
      for(int i=0;i<heights.size();i++)
      {
        if(previosSmaller[i]==-1)
          answer=max(answer, nextSmaller[i]*heights[i]);
        else
          answer= max(answer,(i-previosSmaller[i])+(nextSmaller[i]-i)*heights[i]);
      }


      return answer;
       
    }
};

int main()
{
  Solution s;

  vector<int> h;
  h={2,4};

  cout<<s.largestRectangleArea(h)<<endl;

  return 0;
}
