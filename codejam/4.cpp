#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t, B;
  cin >> t >> B;
  for (int lap = 1; lap <= t; lap++) {
    int position = 1;
    int counter = 1;
    char ans[2000];
    char x;
    while (counter <= B) {
      
      cout << position << endl;
      cin >> x;
      ans[position] = x;
      
      cout << B - (position - 1) << endl;
      cin >> x;
      ans[B - (position - 1)] = x;
      
      position++;
      counter+=2;
    }
    bool isAsk = false;
    for (int i = 0; i < B/10; i++) {
        int isToggle = 0;
        int isReverse = 0;
        for (int j = 1; j <= 5; j++) {
            int curPos = i * 5 + j;
            int revPos = B - (i * 5 + j - 1);
            if (ans[curPos] == ans[revPos]) {
                cout << curPos << endl;
                isAsk = true;
                cin >> x;
                if (ans[curPos] != x) {
                  isToggle = 1;
                } else {
                  isToggle = -1;
                }
                break;
            }
        }
        if (!isAsk) {
          cout << 1 << endl;
          cin >> x;
        }
        isAsk = false;
        for (int j = 1; j <= 5; j++) {
            int curPos = i * 5 + j;
            int revPos = B - (i * 5 + j - 1);
            if (ans[curPos] != ans[revPos]) {
                cout << curPos << endl;
                isAsk = true;
                cin >> x;
                if (ans[curPos] != x) {
                    if (isToggle == 1) {
                        isReverse = -1;
                    } else {
                        isReverse = 1;
                    }
                } else {
                    if (isToggle == 1) {
                        isReverse = 1;
                    } else {
                        isReverse = -1;
                    }
                }
                break;
            }
        }
        if (!isAsk) {
          cout << 1 << endl;
          cin >> x;
        }
        isAsk = false;
        if (isToggle == 1) {
          for (int j = 1; j <= 5; j++) {
            int curPos = i * 5 + j;
            int revPos = B - (i * 5 + j - 1);
            ans[curPos] = ans[curPos] == '1' ? '0' : '1';
            ans[revPos] = ans[revPos] == '1' ? '0' : '1';
          }
        }
        if (isReverse == 1) {
          for (int j = 1; j <= 5; j++) {
            int curPos = i * 5 + j;
            int revPos = B - (i * 5 + j - 1);
            char temp = ans[curPos];
            ans[curPos] = ans[revPos];
            ans[revPos] = temp;
          }
        }
    }
    if (B == 100) {
     
      for (int i = 0; i < B/50; i++) {
          int isToggle = 0;
          int isReverse = 0;
          for (int j = 1; j <= 25; j++) {
              int curPos = i * 25 + j;
              int revPos = B - (i * 25 + j - 1);
              if (ans[curPos] == ans[revPos]) {
                  cout << curPos << endl;
                  cin >> x;
                  if (ans[curPos] != x) {
                    isToggle = 1;
                  } else {
                    isToggle = -1;
                  }
                  break;
              }
          }
          for (int j = 1; j <= 25; j++) {
              int curPos = i * 25 + j;
              int revPos = B - (i * 25 + j - 1);
              if (ans[curPos] != ans[revPos]) {
                  cout << curPos << endl;
                  cin >> x;
                  if (ans[curPos] != x) {
                      if (isToggle == 1) {
                          isReverse = -1;
                      } else {
                          isReverse = 1;
                      }
                  } else {
                      if (isToggle == 1) {
                          isReverse = 1;
                      } else {
                          isReverse = -1;
                      }
                  }
                  break;
              }
          }
          if (isToggle == 1) {
            for (int j = 1; j <= 25; j++) {
              int curPos = i * 25 + j;
              int revPos = B - (i * 25 + j - 1);
              ans[curPos] = ans[curPos] == '1' ? '0' : '1';
              ans[revPos] = ans[revPos] == '1' ? '0' : '1';
            }
          }
          if (isReverse == 1) {
            for (int j = 1; j <= 25; j++) {
              int curPos = i * 25 + j;
              int revPos = B - (i * 25 + j - 1);
              char temp = ans[curPos];
              ans[curPos] = ans[revPos];
              ans[revPos] = temp;
            }
          }
      }
    }
    for (int i = 1; i <= B; i++) {
      cout << ans[i];
    }
    cout << endl;
    string sol;
    cin >> sol;
    if (sol == "N") {
        break;
    }
  }
}