#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n; // sums to be done
  int s; // total lines
  cin >> n >> s;

  int pence = 0;

  for (int i = 0; i < s; i++) {
    string ln;
    cin >> ln;

    // first char always #
    ln = ln.substr(1);

    vector<int> tokens;
    string token;
    stringstream ss(ln);

    while (getline(ss, token, '-')) {
      tokens.push_back(stoi(token));
    }

    int x = tokens[0];
    int y = tokens[1];
    int z = tokens[2];

    pence += x * 240;
    pence += y * 12;
    pence += z;
  }

  int pound = pence / 240;
  pence %= 240;

  int shilling = pence / 12;
  pence %= 12;

  cout << '#' << pound << '-' << shilling << '-' << pence << '\n';
  return 0;
}
