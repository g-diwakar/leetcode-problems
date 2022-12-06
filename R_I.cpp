#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) 
    {
    map<string, int> Roman;
    
        Roman["I"]=1;
        Roman["V"]=5;
        Roman["X"]=10;
        Roman["L"]=50;
        Roman["C"]=100;
        Roman["D"]=500;
        Roman["M"]=1000;
        
        
        int result=0;
        
        for(int i=s.length()-1; i>=0; i--)
        {
            std::string temp_1;
            temp_1=s[i];
            result=result+Roman[temp_1];
            
          if(i>0)
          {
            std::string temp_2;
            temp_2=s[i-1];
            if(Roman[temp_2]<Roman[temp_1])
            {
                result=result-Roman[temp_2];
                i--;
            }
                               
        }
                     }
        
        return result;
    }
};
