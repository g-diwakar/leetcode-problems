#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution 
{
public:
    string st,ex;
    unordered_map<string, bool> dp;
    bool isMatch(string s, string p)
    {
      st=s;
      ex=p;
      

      return func(0,0);
    }

    bool func(int i, int j)
    {
//      string key;
 //     key=(char) i + (char) j;

  //    if(dp.find(key)!=dp.end())
   //     return dp[key];

      if(i>= st.length() && j>=ex.length())
        return true;

      if(j>=ex.length())
        {
    //    dp[key]=false;
     //   return dp[key];
		return false;
        }

      bool match =(i<st.length()) && (st[i] == ex[j]) || (ex[j] =='.');
      
      if((j+1)<ex.length() && ex[j+1] == '*')
      {
      //  dp[key]=func(i,j+2) || (match && func(i+1,j) );

		  return (func(i,j+2) || (match && func(i+1,j)));
       // return dp[key];
        }

      if (match)
      {
       // dp[key] = func(i+1,j+1);
		  return (func(i+1,j+1));
       // return dp[key];
      }

      //dp[key]=false;
     // return dp[key];
	  return false;


    }
  };

int main()
{
  Solution s;
  string st, ex;

  //st="aa";
  //ex="a";

  st="ab";
  ex=".*";

cout<<  s.isMatch(st, ex)<<endl;

  return 0;
}
