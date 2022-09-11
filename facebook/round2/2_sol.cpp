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

#define ll long long
double PI = 3.14159265358979323846;
// long double e = 2.71828182845904523536028747135266249775724709369995;
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

// bool isprime[1000000];
// vector<long long> p;
// void init(){
//     isprime[0] = true;
//     isprime[1] = true;
//     for(long long i = 2 ; i <= 999999 ; i++){
//         if(isprime[i]) continue;
//         p.push_back(i);
//         for(long long j = 2 ; j * i <= 999999 ; j++) isprime[i*j] = true;
//     }
// }
class dq {
public:
    long long n;
    deque<long long> q;
    long long ans;

    dq(){}

    void push(long long new_element){
        while (!q.empty() && q.back() > new_element)
            q.pop_back();
        q.push_back(new_element);
    }

    void pop(long long remove_element){
        if (!q.empty() && q.front() == remove_element)
            q.pop_front();
    }

    long long getmin(){
        return q.front();
    }
};

void solve(){
    ll n,k;
    cin >> n >> k;
    vector<long long> lv(k);
    vector<long long> hv(k);
    vector<long long> wv(k);
    for(int i = 0 ; i < k ; i++){
        cin >> lv[i];
    }
    ll al,bl,cl,dl;
    cin >> al >> bl >> cl >> dl;

    for(int i = 0 ; i < k ; i++){
        cin >> wv[i];
    }
    ll aw,bw,cw,dw;
    cin >> aw >> bw >> cw >> dw;

    for(int i = 0 ; i < k ; i++)
        cin >> hv[i];
    ll ah,bh,ch,dh;
    cin >> ah >> bh >> ch >> dh;

    ll ans = 1;
    ll mod = 1e9+7;
    ll l1 = lv[k-2];
    ll l2 = lv[k-1];
    ll w1 = wv[k-2];
    ll w2 = wv[k-1];
    ll h1 = hv[k-2];
    ll h2 = hv[k-1];
    ll p =0;
    unordered_map<ll,ll> m;
    set<ll> s;
    for(int i = 0 ; i < n ; i++) {
        ll l,h,w;
        if (i >= k) {
            l = (al*l1 + bl*l2 + cl)%dl;
            l++;
            h = (ah*h1 + bh*h2 + ch)%dh;
            h++;
            w = (aw*w1 + bw*w2 + cw)%dw;
            w++;
            l1 = l2;
            l2 = l;
            h1 = h2;
            h2 = h;
            w1 = w2;
            w2 = w;

        }else {
            l = lv[i];
            h = hv[i];
            w = wv[i];
        }

        ll leftmost;
        ll rightmost;

        if(s.find(l) == s.end()){
            s.insert(l);
            auto it = s.find(l);
            if(it == s.begin()){
                leftmost = l;
            }else {
                it--;
                if(m[*it] < 0){
                    leftmost = *it;
                }else {
                    leftmost = l;
                }
            }
            s.erase(l);
        }else{
            if(m[l] < 0){
                leftmost = l;
            }else {
                auto it = s.find(l);
                it--;
                leftmost = *it;
            }
        }

        if(s.find(l+w) == s.end()){
            s.insert(l+w);
            auto it = s.find(l+w);
            it++;
            if(it == s.end()){
                rightmost = l+w;
            }else {
                if (m[*it] < 0){
                    rightmost = l+w;
                }else {
                    rightmost = *it;
                }
            }
            s.erase(l+w);
        }else {
            auto it = s.find(l+w);
            if (m[*it] > 0){
                rightmost = l+w;
            }else {
                it++;
                rightmost = *it;
            }
        }

        s.insert(leftmost);
        s.insert(rightmost);

        ll accw = 0;
        ll acch = 0;
        ll pp = 0;
        auto it = s.find(leftmost);
        auto it2 = s.find(rightmost);
        ll prev = leftmost;
        while(it != it2){
            if(m[*it] < 0){
                accw += *it-prev;
                pp += -m[*it];
                acch += 1;
                prev = *it;
            }else if (m[*it] > 0){
                prev = *it;
                acch += 1;
            }
            auto tmp = it;
            it++;
            s.erase(tmp);

        }
        if (m[*it] == 0){
            accw += *it-prev;
        }else{
            acch++;
        }
        p -= pp;
        pp -= ((h*(acch-2))%mod);
        pp%=mod;
        accw %= mod;
        pp += 2*accw;
        pp%=mod;
        if(pp <= 0) pp += mod;

        s.insert(leftmost);
        s.insert(rightmost);
        m[leftmost] = -pp;
        m[rightmost] = pp;

        p += pp;

        


        p %= mod;
        if(p < 0) p += mod;
        ans *= p;
        ans %= mod;
        // cout << "p " << p << " " << acch << " " << accw << endl;
    }
    cout << ans << endl;



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(30);
    int T;
    cin >> T;
    for(int t = 1 ; t <= T ; t++){
        cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}