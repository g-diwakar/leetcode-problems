#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
      int maxArea=0;

      // this is the width of the outer rectangle 
      // which is the total column length;
      int rowSize= matrix[0].size();

      // this holds the height of the histogram 
      // firstly intialized with zeros
      vector<int> heights(rowSize,0);


      // What we are doing here is:
      // 1.first creating the histogram iterating 
      // through each elements in the row.
      // 2. then finding out the maximum area rectangle 
      // in the newly formed histogram 
      //3. and checking out if the area is maximum;
      // task 1 is done inside the inner loop
      // task 2 and task 3 is done just after coming out
      // from inner loop;
      for(int i=0;i<matrix.size();++i)
      {  
        for(int j=0;j<rowSize;++j)
        {
            
            if(matrix[i][j]=='1')
              ++heights[j];
            else
             heights[j]=0;
          }
        maxArea=max(maxArea, maximumAreaHistogram(heights));
      }


      return maxArea;
    }

    int maximumAreaHistogram(vector<int> heights)
  {
    int maxArea=0;
    
    // what we are storing in the stack is:
    // 1.position of the left bounded rectangle 
    // 2.height  
    stack<vector<int>> st;
    
    for(int i=0; i<heights.size();++i)
    {
      //this is the position of the left bounded rectangle
      int startingIndex=i;

      while(!st.empty() && st.top()[1]> heights[i])
      {
        vector<int> popedElement; 
        popedElement = st.top();
        st.pop();
        maxArea=max(maxArea, popedElement[1] *(i-popedElement[0]));
        startingIndex=popedElement[0];
      }
      st.push({startingIndex,heights[i]});
    }

    while(!st.empty())
    {
      vector<int> popedElement = st.top();
      st.pop();
      int tempArea= popedElement[1] * (heights.size()-popedElement[0]);
      maxArea=max(maxArea,tempArea) ;
    }
    

    return maxArea;
  }
};

int main()
{
  Solution s;
  vector<vector<char>> matrix;

  matrix={
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}
  };

  cout<<s.maximalRectangle(matrix)<<endl;

}
