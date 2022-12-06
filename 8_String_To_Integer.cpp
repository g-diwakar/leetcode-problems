#include<bits/stdc++.h>
using namespace std;

class Solution 
{
	public:
		int myAtoi(string s)
		{
			long long res = 0 ;
			int counter=0; 
			int length = s.size();

			while (((s[counter]<'0' || s[counter] >'9') && (s[counter] != '+' && s[counter] !='-')) && counter < length)
			{
				++counter;
			}
			

			
			int sign = 1;
			if(s[counter]=='-')
			{
				++counter;
				sign = -1;
			}
			else if(s[counter]=='+') 
				++counter;

			
			while (counter<length && (s[counter]>='0' && s[counter] <='9'))
			{
				res = res*10 + s[counter] -'0';

				if(sign == -1 && res*sign<=INT_MIN) return INT_MIN;
				if(sign == 1 && res>=INT_MAX) return INT_MAX;

				cout<<res<<endl;
				cout<<s[counter]<<endl;
				++counter;
			}


			return res*sign ;
		}
};

int main()
{
	Solution s;
	
	cout<<s.myAtoi("-+735")<<endl;
	cout<<INT_MIN<<endl;
}
