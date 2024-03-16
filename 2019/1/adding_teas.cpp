#include <iostream>
#include <map>

using namespace std;

int main() {
  map<char, int> teas;
  char t;
  int x;

  cin >> t;
  while (t != 'D') {
    cin >> x;
    teas[t] += x;
    cin >> t;
  }

  for (char c : "GCEPLS"s) {
    cout << teas[c] << ' ';
  }

  cout << endl;

  return 0;
}
