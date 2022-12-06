#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
    string numberToWords(int num)
    {
    if(num==0)
      return "Zero";

    string ones[]={"One ", "Two ", "Three ", "Four " , "Five ", "Six ", "Seven ", "Eight ", "Nine "};
    string tens[]={"Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    string exceptions[]={"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    string places[]={"", "Thousand ", "Million ", "Billion "};

    string answer="";
     
    long int divisor_1=1000;
    int c_num_1=0;
    bool flag=false;
    for(int i=0;i<4 && num>0;++i)
    {
      c_num_1=num%divisor_1;
      c_num_1=c_num_1/(divisor_1/1000);

      string c_answer="";

          if(c_num_1>99)
          {
            c_answer=ones[c_num_1/100-1] + "Hundred "+ c_answer;
            c_num_1-=(c_num_1/100)*100;
            flag=true;
           }
           if(c_num_1>=20 && c_num_1<=99)
          {
            c_answer= c_answer+tens[c_num_1/10-2];
            c_num_1-=(c_num_1/10)*10;
            flag=true;
          }
          if(c_num_1>9 && c_num_1<20)
          {
            c_answer=c_answer+exceptions[c_num_1%10];
            flag=true;
          }
          if(c_num_1>0 && c_num_1<10)
          {
            c_answer=c_answer+ones[c_num_1-1];
            flag=true;
          }
        
       if(flag){
        c_answer=c_answer+ places[i];
        }
        answer=c_answer+ answer;

        num=num-(num%divisor_1)/(divisor_1/1000)*(divisor_1/1000);
        divisor_1=divisor_1*1000;
        flag=false;
      }
    answer.pop_back();
    return answer;
    }
};

int main()
{
  Solution s;

  cout<<s.numberToWords(1000010)<<endl;
}
