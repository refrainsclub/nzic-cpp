#include <iostream>

using namespace std;

int n;
int k;
int q;
int consec;
int fault[3];

int main() {
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> q;

    if (q >= k) {
      consec = 0;
      continue;
    }

    fault[consec] = q;
    consec++;

    if (consec == 3) {
      cout << "Fault Detected\n";

      for (int f : fault) {
        cout << f << " ";
      }

      cout << endl;
      return 0;
    }
  }

  cout << "No Fault\n";
  return 0;
}
