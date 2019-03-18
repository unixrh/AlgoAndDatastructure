/* 题目： 给你一堆n个箱子，箱子宽wi,高hi，深di。箱子不能翻转，将箱子堆起来时，下面箱子的宽度、高度和深度必须大于上面的箱子。
 * 解法： 遍历每个箱子，查看以它为底能得到的最大堆法，把每个记下来，实现动态规划
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Box {
  private:
    int h, w, d;
  public:
    Box(int h1, int w1, int d1) {
      h = h1;
      w = w1;
      d = d1;
    }
    bool canBeAbove(const Box b) {
      return b.h > h && b.w > w && b.d > d;
    }
    int getDepth(){
      return d;
    }
};

int stackDepth(vector<Box> boxes) {
  int sum = 0;
  for(auto item:boxes) {
    sum += item.getDepth();
  }
  return sum;
}

vector<Box> createStack(map<int, vector<Box> > &res, vector<Box> boxes, int bottom) {
  if(bottom < boxes.size() && res.find(bottom) != res.end()) {
    return res[bottom];
  }

  int max_depth = 0;
  vector<Box> max_stack;
  if(bottom >= boxes.size())
    return max_stack;
  for(int i = 0; i < boxes.size(); i++) {
    if(boxes[i].canBeAbove(boxes[bottom])) {
      vector<Box> tmp_stack = createStack(res, boxes, i);
      int tmp_depth = stackDepth(tmp_stack);
      if(tmp_depth > max_depth) {
        max_depth = tmp_depth;
        max_stack = tmp_stack;
      }
    }
  }
  max_stack.push_back(boxes[bottom]);
  res[bottom] = max_stack;
  return max_stack;
}

int main() {
  freopen("Question9_10.in", "r", stdin);
	int n;
	cin>>n;
	map<int, vector<Box> > res;
	vector<Box> boxes, result;
  // 关键点,在起始点插入一个最大的箱子，使得递归遍历可以执行
  boxes.push_back(Box(INT_MAX, INT_MAX, INT_MAX));
	float H, W, D;
	for (int i = 0; i < n; ++i) {
		cin>>H>>W>>D;
		boxes.push_back(Box(H, W, D));
	}
	result = createStack(res, boxes, 0);
  // 最大的箱子不用打印出来
	for (int i = 0; i < result.size() - 1; ++i) {
		cout<<result[i].getDepth()<<" ";
	}
	return 0;
}


