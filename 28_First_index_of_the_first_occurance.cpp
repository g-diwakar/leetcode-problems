#include<bits/stdc++.h>
using namespace std;

class Solution 
{
public:
	int strStr(string haystack, string needle)
	{
		int hm_pointer = 0;
		int n_pointer = 0 ;

		for(;hm_pointer<haystack.size();++hm_pointer)
		{
			if(haystack[hm_pointer] == needle[n_pointer])
			{
				while(n_pointer<needle.size() && hm_pointer+n_pointer<haystack.size())
				{
					if(haystack[hm_pointer+n_pointer] == needle[n_pointer])
					{
						++n_pointer;
						continue;
					}
					else
						break;
					
				}
				if(n_pointer == needle.size())
					return hm_pointer;
				else
				{
					n_pointer = 0;
				}
			}
			
		}
		return -1;


	}
};

int main()
{
	Solution s ;
	string haystack = "shorthand";
	string needle = "hand";
	cout<<s.strStr(haystack,  needle)<<endl;
}
