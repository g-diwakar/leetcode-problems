#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	int search(vector<int> &nums, int target)
	{
		
		int lower = 0;
		int upper = nums.size() -1;

		int mid;

		while(lower<upper)
		{
			mid = lower + (upper-lower)/2;
			if (target == nums[mid]) return mid;
			if(target == nums[lower]) return lower;
			if(target == nums[upper]) return upper;


			if(nums[lower]<nums[mid])
			{  //this seems like left hand side is sorted 
			   // first condition checks if the target is  in the left hand side 
				// if not , now check on the right hand side shifting the lower bound to be mid+1;
				if(target < nums[mid] && target > nums[lower]) upper = mid-1;
				else lower = mid+1;
			}
			else
			{
				//seems like right hand is sorted 
				// similar to above checks if the target is in the right hand side 
				// if not , simply look on the left hand side shifting the upper bound to be mid - 1;
				if (target > nums[mid] && target < nums[upper]) lower = mid+1; 
				else upper = mid -1;
			}

		}

		// out of loop means the target is not present 
		return -1;

				
		

	}


};

int main()
{
	Solution s;
	vector<int> nums;
	nums = {4,5,6,7,0,1,2};
	cout<<s.search(nums, 1);
}
