/* 题目： 求一个整数的二进制形式中1的个数
 * 解法： 位操作
 */
#include <iostream>

using namespace std;

int solve(int n) {
  int count = 0;
  for(int i = 0; i < 32; i++) {
    if((n & 1) == 1)
      count++;
    n = n >> 1;
  }
  return count;
}

// 在n为负数是会进入死循环，因为负数的高位为1，
// 右移的时候，高位继续被填1，最终死循环
int solve1(int n) {
  int count = 0;
  while(n) {
    if(n & 1)
      count++;
    n = n >> 1;
  }
  return count;
}

int solve2(int n) {
  int count = 0;
  unsigned int flag = 1;
  while(flag) {
    if(n & flag)
      count++;
    flag = flag << 1;
  }
  return count;
}

// 对于任何数，(n-1)&(n) 使得n最右边的1消除
int solve3(int n) {
  int count = 0;
  while(n) {
    count++;
    n = (n-1)&(n);
  }
  return count;
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    cout << "usage: " << argv[0] << " n" << endl;
    exit(1);
  }
  cout << "solve n: " << atoi(argv[1]) << " res: " << solve(atoi(argv[1])) << endl;
  // cout << "solve1 n: " << atoi(argv[1]) << " res: " << solve1(atoi(argv[1])) << endl;
  cout << "solve2 n: " << atoi(argv[1]) << " res: " << solve2(atoi(argv[1])) << endl;
  cout << "solve3 n: " << atoi(argv[1]) << " res: " << solve3(atoi(argv[1])) << endl;
  return 0;
}
