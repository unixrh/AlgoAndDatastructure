/*Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has piles[i] bananas.  The guards have gone and will come back in H hours.
Koko can decide her bananas-per-hour eating speed of K.  Each hour, she chooses some pile of bananas, and eats K bananas from that pile.  If the pile has less than K bananas, she eats all of them instead, and won't eat any more bananas during this hour.
Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.
Return the minimum integer K such that she can eat all the bananas within H hours.
*/
#include <iostream>
#include <vector>

using namespace std;

int minSpeed(vector<int> &piles, int H) {
  int l = 0, h = 1000000000;
  while(l < h) {
    int m = l + ((h-l)>>1), total = 0;
    for(int p : piles) total += (p+m-1)/m;
    if(total > H) l = m + 1;
    else h = m;
  }
  return l;
}

int main(int argc, char* argv[]) {
  if(argc < 2) {
    cout << "usage: " << argv[0] << " hours" << endl;
    exit(1);
  }

  vector<int> piles{3, 6, 7, 11};
  cout << minSpeed(piles, atoi(argv[1])) << endl;
  return 0;
}
