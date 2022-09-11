#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
long long cal(int x, int y, int z) {
  long long X = (long long)(x - y) * (long long)(x - y);
  long long Y = (long long)(x - z) * (long long)(x - z);
  long long Z = (long long)(z - y) * (long long)(z - y);
  return X + Y + Z;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++)
  {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> A, B, C;
    for (int i = 0; i < a; i++)  {
      int x;
      cin >> x;
      A.push_back(x);
    }
    for (int i = 0; i < b; i++)  {
      int x;
      cin >> x;
      B.push_back(x);
    }
    for (int i = 0; i < c; i++)  {
      int x;
      cin >> x;
      C.push_back(x);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    int ia, ib, ic;
    ia = ib = ic = 0;
    long long pre = 0LL;
    long long ans = cal(A[ia], B[ib], C[ic]);
    while (true) {
      pre = cal(A[ia], B[ib], C[ic]);
      ans = min(ans, pre);
      if (ia == a - 1 && ic == c - 1 && ib == b - 1) {
        break;
      } else if (ia == a - 1 && ic == c - 1) { 
        ib++;
      } else if (ib == b - 1 && ic == c - 1) { 
        ia++;
      } else if (ia == a - 1 && ib == b - 1) { 
        ic++;
      } else if (ia == a - 1) { 
        if (C[ic] <= B[ib]) {
          ic++;
        } else {
          ib++;
        }
      } else if (ib == b - 1) { 
        if (C[ic] <= A[ia]) {
          ic++;
        } else {
          ia++;
        }
      } else if (ic == c - 1) { 
        if (A[ia] <= B[ib]) {
          ia++;
        } else {
          ib++;
        }
      } else if (A[ia] <= B[ib] && A[ia] <= C[ic]) {
        ia++;
      } else if (B[ib] <= A[ia] && B[ib] <= C[ic]) {
        ib++;
      } else if (C[ic] <= B[ib] && C[ic] <= A[ia]) { 
        ic++;
      } 
    }
    cout << ans << "\n";
  }
}