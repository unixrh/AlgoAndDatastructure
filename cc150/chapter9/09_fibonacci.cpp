/* 题目： 求fibonacci数列第n个元素的值
 * 解法： 通过动态规划将递归优化为循环
 */
#include <iostream>
#include <cstring>

using namespace std;

int recursive(int n) {
  if(n == 0)
    return 0;
  if(n == 1) 
    return 1;
  return recursive(n - 1) +  recursive(n - 2);
}

int loop(int n) {
  if(n == 0)
    return 0;
  if(n == 1) 
    return 1;
  int sum = 0;
  int a = 0;
  int b = 1;
  for(int i = 2; i <= n; i++) {
    sum = a + b;
    a = b;
    b = sum;
  }
  return sum;
}

int main(int argc, char* argv[]) {
  if(argc < 3) {
    cout << "usage: " << argv[0] << " method n" << endl;
    exit(1);
  }

  int n = atoi(argv[2]);
  if(strncmp(argv[1], "l", 1) == 0) { // strncmp: 参数1小于参数2 则返回<0
    cout << "loop fibonacci of nth is: " << loop(n) << endl;
  } else {
    cout << "recursive fibonacci of nth is: " << recursive(n) << endl;
  }
}
