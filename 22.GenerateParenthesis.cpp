#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution
{
	public:
		vector<string> generateParenthesis(int n)
		{
			string temp ="";
			vector<string> answer;
			func(0,0,n,temp , answer);
			return answer;	
		}

		void func(int openN, int closedN, int n, string temp , vector<string>&answer)
		{
           if(openN == n && closedN ==n)
		   {
			   answer.push_back(temp);
			   return ;
		   }

		   if(openN<n)
		   {
			   //temp+="(";
			   //openN++;
			   func(openN+1, closedN,n, temp+'(', answer);
			  // temp.erase(temp.size()-1);
		   }
		   if(closedN<openN)
			{
				//temp+=")";
				//closedN++;
				func(openN, closedN+1,n, temp+')', answer);
				//temp.erase(temp.size() -1);
			}
		}
};

int main()
{
	Solution s;

	vector<string> answer;

	answer = s.generateParenthesis(2);

	for (int i=0;i<answer.size();++i)
	{
		cout<<answer[i]<<endl;
	}

	return 0;

}
