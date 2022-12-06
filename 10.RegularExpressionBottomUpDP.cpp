#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution
{
	public:
		bool isMatch(string text, string pattern)
		{
			int n=text.length();
			int m=pattern.length();
			vector<vector<bool>> dp(n+1,vector<bool>(m+1));

			dp[n][m]= true;

			for(int i=n;i>=0;--i)
			{
				for(int j=m-1;j>=0;--j)
				{
					bool match = (i<n && ((text[i]==pattern[j]) || pattern[j] == '.') );
				    if((j+1 < m) && pattern[j+1]=='*')
					{ 
						dp[i][j] = dp[i][j+2] || (match && dp[i+1][j]);
					}
					else
					{
				     	 dp[i][j]= match && dp[i+1][j+1];
					}
				}
              
			}

			return dp[0][0];
		}
};

int main()
{
	Solution s;
	string text , pattern ;
	text = "ab";
	pattern = ".*";

	// text = "aa"
	// pattern = "a"; 

	cout<<s.isMatch(text, pattern)<<endl;

	return 0;
}
