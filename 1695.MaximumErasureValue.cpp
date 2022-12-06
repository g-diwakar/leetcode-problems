#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution
{
	public:
		int maximumUniqueSubarray(vector<int> &nums)
		{
			//this stores the list of visited elements
			unordered_set<int> visited_elements;
			int current_sum=0;
			int answer =0;

			//i holds the index of the starting point of subarray 
			// j holds the last index of the starting point of subarray
			//we keep j increasing every time
			int i=0,j=0;
			
			while(j<nums.size())
			{
				//if current element i.e. nums[j] is already present on the set of visited elements
				//we keep on increasing the starting index of the sub array
				while(visited_elements.count(nums[j])>0)
				{
					visited_elements.erase(nums[i]);

					
					//since nums[i] is already erased from our subarray,we also remove the contribution of nums[i] into our sum
					current_sum -=nums[i];
					++i;
				}

				visited_elements.insert(nums[j]);
				current_sum +=nums[j];
				answer = max(answer, current_sum);

				++j;


			}





			return answer;
		}
};

int main()
{
	Solution s;

	vector<int> nums;

//	nums={4,2,4,5,6};
	nums={5,2,1,2,5,2,1,2,5};

	cout<<s.maximumUniqueSubarray(nums)<<endl;
}
