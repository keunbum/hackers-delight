class Solution {
public:
  bool isPalindrome(int _x) {
    long long x = _x;
    if (x < 0 || (x != 0 && x % 10 == 0)) {
      return false;
    }
    long long y = 0;
    long long t = x;
    while (t > 0) {
      y = y * 10 + t % 10;
      t /= 10;
    }
    return (x == y);       
  }
};