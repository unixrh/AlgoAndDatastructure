/* 题目：一个M X N的网格，从左上角走到右下角(只能往右或者往下)，问有多少种走法；
 * 解法：若不考虑其中的禁区点，则可以用数学方法做，可以知道总共要走M+N步，其中有M步向右，N步向下，因此可以走(M+N)选M
 *       若考虑其中的禁区点找到一条路径，
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef struct POINT {
  public:
    int x, y;
    POINT(int a, int b) : x(a), y(b){}
} Point;

static const int arr[5][5] = {
  {0,0,1,0,0},
  {0,0,1,0,0},
  {0,0,1,0,0},
  {0,0,0,0,0},
  {0,0,1,0,0}
};
bool isFree(int x, int y) {
  return arr[x][y] != 1;
} 

bool isAtOrigin(int x, int y) {
  return x == 0 && y == 0;
}

bool getPath(int x, int y, vector<Point>& path) {
  if(x < 0 || y < 0 || !isFree(x, y)) {
    return false;
  }
  // 如果有路径可以到达(x,y)，则将他加入路径中
  if(isAtOrigin(x, y) || getPath(x-1, y, path) || getPath(x, y-1, path)) {
    Point p(x, y);
    path.push_back(p);
    return true;
  }
  return false;
}

void printPoints(vector<Point> arr) {
  for(auto item : arr) {
    printf("(%d, %d) \t", item.x, item.y);
  }
}

// 将以前的计算结果缓存起来
bool getPathDP(int x, int y, vector<Point> path, map<Point, bool> cache) {
  if(x < 0 || y < 0 || !isFree(x, y)) {
    return false;
  }
  Point p(x, y);
  if(cache[p])
    return true;
  bool success = false;
  if(isAtOrigin(x, y) || getPathDP(x-1, y, path, cache) || getPathDP(x, y-1, path, cache)) {
    path.push_back(p);
    success = true;
  }
  cache[p] = true;
  return false;
}

int main() {
  vector<Point> path;
  if(getPath(4,4, path)) {
    cout << "yes" << endl;
    printPoints(path);
  } else {
    cout << "no" << endl;
  }
  return 0;
}
