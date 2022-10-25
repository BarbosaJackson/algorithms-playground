#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  int i, j;
  vector<string> grid;
  cin >> i >> j;
  grid.resize(i);
  for (int k = 0; k < i; k++) {
    cin >> grid[k];
  }
  for (int w = 0; w < j; w++) {
    int count = 0;
    for (int k = 0; k < i; k++) {
      count += grid[k][w] == '#';
    }
    printf("%d%c", count, w + 1 == j ? '\n' : ' ');
  }
  return 0;
}