#include <iostream>
#include <vector>
#include <ctime>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#define NUM 8
using namespace std;
bool check(int checkboard[NUM][NUM], int x, int y) {
  for(int i = 0; i < NUM; i++) {
    if(checkboard[x][i])
      return false;
  }
  for(int i = 0; i < x; i++) {
    if(checkboard[i][y])
      return false;
  }
  for(int i = 1; i <= x; i++) {
    if((y-i >= 0 && checkboard[x-i][y-i]) || (y+i < NUM && checkboard[x-i][y+i])) {
      // cout << "aaa" << checkboard[x-i][y-i]  << checkboard[x-i][y+i] << x << y << i << endl;
      return false;
    }
  }
  return true;
}

void printBoard(int checkboard[NUM][NUM]) {
  static int count = 0;
  for(int i = 0; i < NUM; i++) {
    for(int j = 0; j < NUM; j++) {
      cout << checkboard[i][j] << "  ";
    }
    cout << endl;
  }
  cout << "++++++++++   " << ++count << endl;
}

bool placeChess(int checkboard[NUM][NUM], int row) {
  if(row == NUM) {
    printBoard(checkboard);
  } else {
    for(int col = 0; col < NUM; col++) {
      if(check(checkboard, row, col)) {
        checkboard[row][col] = 1;
        if(!placeChess(checkboard, row + 1)) {
          checkboard[row][col] = 0;
        }
      }
    }
  }
  return false;
}

int main() {
  int checkboard[NUM][NUM] = {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}};
  placeChess(checkboard, 0);
  return 0;
}
