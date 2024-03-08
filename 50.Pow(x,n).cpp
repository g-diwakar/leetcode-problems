#include <iostream>
using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    double answer = 1;

    for (int i = 0; i < abs(n); ++i) {
      answer *= x;
    }

    if (n < 0) {
      answer = 1 / answer;
    }

    return answer;
  }
};

int main() {
  Solution s;

  cout << s.myPow(2, -1) << endl;
}
