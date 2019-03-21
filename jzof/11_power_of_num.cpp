/* 题目： 求一个数的整数次方。
 * 解法： 需要关注幂次的正负数。
 */
#include <iostream>
#include <map>

using namespace std;

double pow(double base, int exp) {
  if(exp == 0) return 1;
  double tmp = pow(base, exp/2);
  if(exp & 1) {
    return base < 0 ? 1/base * tmp * tmp : base * tmp * tmp;
  } else
    return tmp * tmp;
}

int main(int argc, char* argv[]) {
  if(argc < 3) {
    cout << "usage: " << argv[0] << " base exp" << endl;
    exit(1);
  }
  double base = atof(argv[1]);
  int    exp  = atoi(argv[2]);
  double res = 0;
  res = pow(base, exp);
  cout << "res: " << res << endl;
  return 0;
}
