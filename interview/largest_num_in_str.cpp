#include <iostream>
#include <string>

using namespace std;

double solve(string str) {
  double res = 0.0;
  double part1 = 0.0;
  double part2Int = 0.0;
  int cur10 = 1;
  bool dot = false;
  for(unsigned int i = 0; i < str.size(); i++) {
    cout << res << endl;
    if(str[i] >= '0' && str[i] <= '9') {
      if(!dot) {
        part1 = part1 * 10 + (str[i] - '0');
      } else {
        cur10 *= 10;
        part2Int = part2Int * 10 + (str[i] - '0');
        cout << part2Int << endl;
      }
    } else if(str[i] == '.') {
      if(dot){
        part1 = part2Int;
        part2Int = 0;
        cur10 = 1;
      } else {
        dot = true;
      }
    } else {
      res = max(res, part1 + (double)part2Int/cur10);
      res = max(res, part2Int);
      part1 = 0;
      part2Int = 0;
      cur10 = 1;
      dot = false;
    }
  }
  res = max(res, part1 + (double)part2Int/cur10);
  res = max(res, part2Int);
  return res;
}

int main(int argc, char* argv[]) {
  string src = argv[1];

  cout << solve(src) << endl;
  return 0;
}
