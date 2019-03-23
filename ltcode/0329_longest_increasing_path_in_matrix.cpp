#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
  public:
    Solution() {}
    int helper(vector<vector<bool> > &flags, vector<vector<int> >& matrix, int prev, int x, int y, vector<vector<int> > &cache) {
      if( x < 0 || x >= matrix.size()
          || y <  0 || y >= matrix[0].size()
          || prev >= matrix[x][y] || flags[x][y] == false)
        return 0;
      if(cache[x][y]) return cache[x][y];
      flags[x][y] = false;
      int res = INT_MIN;
      int x1 = helper(flags, matrix, matrix[x][y], x - 1, y, cache) + 1;
      int x2 = helper(flags, matrix, matrix[x][y], x + 1, y, cache) + 1;
      int y1 = helper(flags, matrix, matrix[x][y], x, y - 1, cache) + 1;
      int y2 = helper(flags, matrix, matrix[x][y], x, y + 1, cache) + 1;
      flags[x][y] = true;
      res = max(max(max(x1, x2), y1), y2);
      cache[x][y] = res;
      return res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      if(matrix.size() == 0) return 0;
      vector<vector<bool> > flags(matrix.size(), vector<bool>(matrix[0].size(), true));
      vector<vector<int> > cache(matrix.size(), vector<int>(matrix[0].size(), 0));
      int res = INT_MIN;
      for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
          res = max(res, helper(flags, matrix, INT_MIN, i, j, cache));
        }
      }
      return res;
    }
};
void print2DVector(vector<vector<int> > &matrix) {
  for(int i = 0; i < matrix.size(); i++) {
    for(int j = 0; j < matrix[0].size(); j++) {
      printf("%2d ", matrix[i][j]);
    }
    printf("\n");
  }
}
int main() {
  vector<vector<int> > matrix{
    {5,8,9,3,12,8,16,2,11,8,17,4,4,15,8,10,8,1,6,18},
    {18,8,7,7,6,12,1,19,5,6,19,6,5,2,9,11,11,17,2,6},
    {16,6,10,0,0,13,17,8,4,18,3,15,12,1,1,2,18,14,6,1},
    {18,8,14,19,11,11,16,10,19,14,16,4,11,1,0,4,2,4,12,1},
    {5,12,4,0,19,11,18,18,15,2,5,11,15,4,18,14,3,7,1,10},
    {15,19,8,14,6,11,16,15,18,7,1,2,5,4,1,9,14,15,9,2},
    {4,16,16,15,19,19,17,6,13,14,12,17,13,19,8,15,8,6,16,13},
    {16,14,16,11,6,16,15,6,7,16,7,8,7,4,14,16,3,5,0,0},
    {14,16,14,10,7,7,17,18,5,16,3,14,7,6,4,19,3,13,5,16},
    {2,3,1,10,4,10,8,3,14,16,3,8,16,18,6,17,1,6,12,16},
    {1,15,18,11,16,15,3,7,8,7,4,10,1,15,17,12,9,14,0,14},
    {1,3,14,6,9,10,4,3,0,0,7,12,17,5,16,7,14,8,12,4},
    {6,14,3,13,14,17,4,16,16,8,17,3,12,16,5,17,16,1,13,7},
    {0,19,3,0,11,16,14,10,18,10,18,11,19,11,3,3,6,13,2,1},
    {11,5,0,10,19,3,4,19,13,7,16,1,13,8,8,14,5,19,19,4},
    {0,12,18,15,17,12,11,6,16,2,19,6,0,19,12,17,13,1,19,14},
    {12,9,6,14,18,1,14,15,18,13,11,14,16,19,13,6,11,10,11,1},
    {13,16,11,4,6,19,18,2,3,18,10,18,6,17,6,13,16,14,8,3},
    {18,0,11,3,5,18,1,18,13,18,12,13,0,12,13,3,13,9,1,16},
    {12,1,16,1,17,1,16,6,18,7,4,18,17,3,6,15,11,14,19,9},
    {15,2,13,5,7,10,19,10,17,14,1,12,9,6,7,5,15,11,9,1},
    {17,18,13,3,16,2,13,11,0,14,11,11,13,12,3,5,16,13,8,18},
    {19,12,7,5,18,3,17,7,3,8,12,15,17,2,14,16,13,17,7,18},
    {10,19,4,2,7,10,13,13,11,2,11,4,1,8,18,15,6,5,15,7}};
  // Solution *s = new Solution(matrix.size(), matrix[0].size());
  Solution *s = new Solution();
  print2DVector(matrix);
  int res = s->longestIncreasingPath(matrix);
  cout << res << "+++" << endl;
}
