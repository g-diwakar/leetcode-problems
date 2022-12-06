#include<bits/stdc++.h>
using namespace std; 

class Solution 
{
public:
	int findMin(vector<int> &nums)
	{
		int lower = 0 ;
		int higher = nums.size()-1;
		

		int mid;
		while(lower<=higher)
		{
			mid = lower+(higher-lower)/2;
			if(nums[mid+1] < nums[mid]) return nums[mid+1];
			if(nums[mid-1]>nums[mid]) return nums[mid];

			if(nums[higher]>nums[mid])
			{
				//looks like right half is all increasing 
				//its now better to look at the left half 
				higher = mid;
			}
			else 
			{
				// if not left half is all increasing 
				// now look at the right half 
				lower = mid+1;
			}

		}
		return nums[0];
	}

};
int main()
{
	Solution s ;
	vector<int> nums;
	nums = {11,13,15,17};
	cout<<s.findMin(nums)<<endl;
}
