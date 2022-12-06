#include<iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        int low=0;
        int high=x;
        int mid=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(x==(mid*mid))
                return mid;
            else if(x<(mid*mid))
                high=mid-1;
            else
                low=mid+1;
        }
        return (low-1);
    }
};

int main()
{
  Solution s;
  cout<<s.mySqrt(69)<<endl;
}
