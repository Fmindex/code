#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++) {
    int n;
    string a;
    int cntA = 0;
    cin >> n >> a;
    for (char x: a) {
      if (x == 'A') cntA++;
    }
    int cntB = n - cntA;
    
    cout << "Case #" << lap << ": ";
    cout << ((abs(cntA - cntB) <= 1) ? "Y\n" : "N\n");
    
  }
}