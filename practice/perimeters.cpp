#include <iostream>

using namespace std;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int hor = y2 - y1;
  int vert = x2 - x1;
  int dist = 2 * (hor + vert);

  cout << dist << "\n";
  return 0;
}
