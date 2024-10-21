class Solution {
public:
  int findComplement(int n) {
    int i;
    for (i = 31; i >= 0; i--) {
      if ((n >> i) & 1) {
        break;
      }
    }
    if (i == -1) {
      return 1;
    }
    int ret = 0;
    while (i >= 0) {
      ret = ret * 2 + !((n >> i) & 1);
      i -= 1;
    }
    return ret;
  }
};