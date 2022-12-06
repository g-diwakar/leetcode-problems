#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
      int hourSpent=0;
      
    //minimum speed = one , idiot 
      int left=1;
      
      //maximum speed taken = the maximum value of the array
      int right = *max_element(piles.begin(), piles.end());
      cout<<endl<< right<<endl<<endl;
      
    //our answer is in between left and right
    //apply binary search -> make it fast
      while(left<right)
      {
        int middle = (left + right)/2;
        hourSpent=0;

        //no.of bananas / speed (middle) = total time taken
        //bananas%middle!=0 -> this gives the ceiling value
        // bananas =5 ,speed =2, acc to the question constraints
        // it takes actually 3 hours to complete this one pile of bananas
        // 2+2+1
        //lets iterate over all the piles and calculate total hours taken
        for(int bananas:piles)
        {
          hourSpent+=bananas/middle + (bananas%middle !=0);
        }
        
        //if hours taken is still less than the given hour
        // koko can eat with even the less speed 
        // so narrow down the search and set right =middle
        //else value less than middle are not workable speed
        // and we look for even higher speed than middle
        if(hourSpent<=h)
          right=middle;
        else
         left=middle+1;
      }
      //continue the iteration until the search is confined to a single value
      //which is a minimum working speed


      return right;
    }
};

int main()
{
  Solution s;
  vector<int> v;

  v={30,11,23,4,20};

  cout<<s.minEatingSpeed(v, 6)<<endl;

  return 0;
}
