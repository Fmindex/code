#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <deque>
 
using namespace std;
double PI = 3.14159265358979323846;
long double e = 2.71828182845904523536028747135266249775724709369995;
long long gcd(long long a, long long b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int NUM_BIT = 32;
void printbit(long long x){
    string ans = "";
    for(int i = 0 ; i < NUM_BIT ; i++){
        ans += ('0'+(x%2));
        x/=2;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}
 
int mod = 1e9+7;
 
long long pow(long long a, long long n, long long m){
    if(n==0) return 1;
    if(n==1) return a%m;
    long long x = pow(a,n/2,m);
    if(n%2==0) return (x*x)%m;
    return (((x*x)%m)*a)%m;
}
 
void solve() {
  
    double n;
    cin >> n;
    double r = 0.5;
    double a = r/sin(PI/n/2);
    r /= tan(PI/n/2);
    r*=2;
    cout << a * 2 << endl;
    // double theta = atan(a*2-r);
    // cout << 2*a*cos(theta) << endl;
    // cout << r*cos(theta) + sin(theta) << endl;
 
    
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);
    //     cout << rand() << endl;
    int t;
    cin >> t;
    for(int i = 0 ; i < t; i++){
        // cout << "Case #" << i+1 <<": ";
        solve();
    }
 
    return 0;
}