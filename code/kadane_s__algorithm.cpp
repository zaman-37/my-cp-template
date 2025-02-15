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
#define endl "\n"

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2147483647;
const ll infLL = 9223372036854775807;
const ll MOD = 1000000007LL;


ll max_subarray_sum(vector<int> &v, int s, int e) {
    ll ans = v[s];
    ll tem = v[s];
    for (int i=s+1; i<=e; i++) {
        if (tem < 0) {
            tem = v[i];
        }
        else {
            tem += v[i];
        }
        ans = max(ans, tem);
    }
    return ans; 
}

ll min_subarray_sum(vector<int> &v, int s, int e) {
    ll ans = infLL;
    ll tem = infLL;
    for (int i=s; i<=e; i++) {
        if (tem > 0) {
            tem = v[i];
        }
        else {
            tem += v[i];
        }
        ans = min(ans, tem);
    }
    return ans;
}


int main() {
    optimize()
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    ll ans1 = min_subarray_sum(a, 0, n-1);
    ll ans2 = max_subarray_sum(a, 0, n-1);
    cout << "Max: " << ans2 << endl;
    cout << "Min: " << ans1 << endl;

    return 0;
}


/*
For min subarray sum: 
7
3 -4 2 -3 -1 7 -5
min: -6
max: 7
*/

/*
For max subarray sum:
7
2 3 -8 7 -1 2 3
max: 11
min: -8
*/