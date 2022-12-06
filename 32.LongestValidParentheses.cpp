#include<iostream>
#include<bits/stdc++.h>
#include <pthread.h>

using namespace std;

class Solution
{
	public:
		int longestValidParentheses(string s)
		{
			int n=s.size();	
			vector<int> dp(n,0);
			int answer =0;

			//our approach here is we gonna find the opening bracket "("
			// for every closing bracket ")"
			
			//we are storing the match in the array dp
			for(int i=0;i<n;++i)
			{
				//since we've found the closing bracket,
				//we now will search for its matching opening bracket
				if(i>0 && s[i]==')')
				{
					//if its matching opening bracket is right before it 
					//we've found the pair
					// so add 2 to the dp array and look for the matching pairs before the opening bracket 
					//which is of index i-2
					if(s[i-1]=='(')
					{
						dp[i] = 2 + (i-2>=0? dp[i-2]:0);
					}

					//i-dp[i-1] -1 gives us the index for matching opening bracket 
					//still we'll be looking for the valid indexing and "(" is really 
					//present at that particular index 
					//we'll be now storing all the matching pairs in the dp array  

					else {
						int t = i - dp[i-1] -1;
						if(t>=0 and s[t] == '(')
						{
							dp[i] = 2+dp[i-1] + (t-1>=0 ? dp[t-1] : 0);
						}
					}
				}
				

				answer = max(answer, dp[i]);
			}




			return answer;
		}
};

int main()
{
	Solution s;

	string st;
//	st="";
	st = ")()()";

	cout<<s.longestValidParentheses(st)<<endl;

	return 0;
}
