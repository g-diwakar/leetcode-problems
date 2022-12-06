#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
      sort(envelopes.begin(), envelopes.end());
      
      vector<int> LIS(envelopes.size(),1);
      int n=envelopes.size();
      for(int i=n-1;i>=0;--i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(envelopes[i][1]<envelopes[j][1] && envelopes[i][0]!=envelopes[j][0])
            {
              LIS[i]=max(LIS[i],1+LIS[j]);
            }
          }
      }
    return *max_element(LIS.begin(),LIS.end());
    }
};

int main()
{
  Solution s;

  vector<vector<int>> envelopes;

  //envelopes={{5,4},{6,4},{6,7},{2,3}};
 // envelopes={{1,1},{1,1},{1,1}};
  envelopes={{4,5},{4,6},{6,7},{2,3},{1,1}};

  cout<<endl<<s.maxEnvelopes(envelopes)<<endl;
}
