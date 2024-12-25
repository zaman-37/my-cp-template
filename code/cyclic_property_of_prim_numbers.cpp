#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define sz(x) (int)x.size()
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define tt int t; cin >> t; for (int tc=1; tc<=t; tc++)
#define disp(res) cout << "Case " << tc << ": " << (res) << "\n "[tc == t];
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2147483647;
const ll infLL = 9223372036854775807;
const ll MOD = 1000000007LL;



int main() {
    ll n ;
    cout << "Enter a prim number less than 20: ";
    cin >> n; 
    ll cycle = 0;
    
    for (int i=1; i<=n-1; i++) {
        ll temp = pow(10, i);
        cycle += temp%(n);
        cout << temp%(n) << " \n"[i==n-1];
    }
    cout << "Sum of the cycle: " << cycle << endl;
    cout << "Sum of the cycle % n = " << cycle % (n) << endl;

    return 0;
}