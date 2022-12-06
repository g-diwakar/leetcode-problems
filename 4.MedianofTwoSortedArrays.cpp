#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
      double answer;

      int s1=nums1.size();
      int s2=nums2.size();
    
      vector<int> nums;
      int i=0, j=0;

      while(i<s1 && j<s2)
      {
        if(nums1[i]<=nums2[j])
        {
          nums.push_back(nums1[i]);
          i++;
        }
        else 
        {
        nums.push_back(nums2[j]);
        j++;
        }
      }
      while(i<s1)
      {
        nums.push_back(nums1[i]);
        i++;
      }
      while(j<s2)
      {
        nums.push_back(nums2[j]);
        j++;
      }

      int s= nums.size()-1;
     if(s%2)
    {
        answer=(nums[s*0.5] + nums[s*0.5 +1]) * 0.5;
    }
     else 
    {
    answer=nums[s*0.5];
    }



    return answer;
        
    }
};

int main()
{
  vector<int> nums1, nums2;

  Solution s;

  nums1={1,2};
  nums2={3,4};

  cout<<endl<<s.findMedianSortedArrays(nums1, nums2)<<endl;

  return 0;
}
