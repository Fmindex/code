#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int lap = 1; lap <= t; lap++) {
        int n, k;
        cin >> n >> k;
        
        int v[100005];
        for (int i = 0; i < n; i++) {
          int cur;
          cin >> v[i];
        }
        int left = 1, right = 1e9, ans = 1e9;
        while (left < right) {
            int mid = (left + right) / 2;
            int c = 0;
            priority_queue<int> q;
            for (int i = 1; i < n; i++) {
              q.push(v[i] - v[i - 1]);
            }
            while (!q.empty()) {
              if (c > k) break;
              int x = q.top();
              if (x <= mid) break;
              
              q.pop();
              c++;
              q.push(mid);
              q.push(x - mid);
            }
            if (c <= k) {
                ans = min(ans, mid);
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        

        cout << "Case #" << lap << ": " << ans << "\n";
    }
}
// 2 2 1 1 1
