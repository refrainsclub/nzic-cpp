#include <iostream>
#include <string>

using namespace std;

int main() {
  for (string tea : {"Ginger", "Chamomile", "Earl Gray", "Peppermint", "Lemon",
                     "Strawberry"}) {
    int n;
    cin >> n;
    cout << tea << " " << n * 10 * 24 << endl;
  }
}
