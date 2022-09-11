#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int lap = 1; lap <= t; lap++)
  {
    long long w, n;
    long long a[200000] = {0LL};
    long long qs[200000] = {0LL};
    cin >> w >> n;
    for (int i = 1; i <= w; i++)
    {
      cin >> a[i];
    }
    long long key = n / 2LL;
    sort(a + 1, a + w + 1);
    for (int i = 1; i <= w; i++)
    {
      qs[i] = qs[i - 1] + a[i];
      // cout << qs[i] << " ";
    }
    // cout << "\n";
    long long answer = 1e17;
    for (int i = 1; i <= w; i++)
    {
      long long left = (long long)(lower_bound(a + 1, a + w + 1, a[i] - key) - a);
      long long right = (long long)(lower_bound(a + 1, a + w + 1, a[i] + key) - a - 1LL);

      long long wLeft = (long long)i - left;
      long long sumLeft = a[i] * (wLeft) - (qs[i - 1] - qs[left - 1]);
      // cout << "sum left1 : " << a[i] * (wLeft) << " - " << (qs[i - 1] - qs[left - 1]) << "\n";
      sumLeft += (qs[left - 1] - qs[0]) + (left - 1LL) * (n - a[i]);
      // cout << "sum left2 : " << (qs[left - 1] - qs[0]) << " + " << ((left - 1LL) * (n - a[i])) << "\n";

      long long wRight = right - (long long)i;
      long long sumRight = (qs[right] - qs[i]) - (wRight * a[i]);
      // cout << "sum right1 : " << sumRight << "\n";
      // cout << (qs[right] - qs[i]) << " : " << (wRight * a[i]) << "  \n";
      sumRight += ((n * (w - right)) - (qs[w] - qs[right])) + ((w - right) * a[i]);
      // cout << "sum right2 : " << sumRight << "\n";
      // cout << wRight << " : " << a[i] << "  \n\n";
      // cout << left << " " << right << "\n";
      // cout << sumLeft << " " << sumRight << "\n\n";
      answer = min(answer, sumLeft + sumRight);
    }
    cout << "Case #" << lap << ": ";

    cout << answer << "\n";
  }
}