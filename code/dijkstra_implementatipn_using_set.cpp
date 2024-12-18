#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define tt int t; cin >> t; for (int tc=1; tc<=t; tc++)
#define disp(res) cout << "Case " << tc << ": " << (res) << endl
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
const int inf = 2147483647;
const ll infLL = 9223372036854775807;

vector<vector<pll>> adj;
vl dist;

void dijkstra (ll source, ll n) {
    dist.clear();
    dist.assign(n+5, infLL);
    dist[source] = 0;
    set<pll> pq;
    pq.insert({0, source});

    while (!pq.empty()) {
        pll temp = *pq.begin();
        int u = temp.second;
        ll currD = temp.first;
        pq.erase(pq.begin());

        if (dist[u] != currD) {  // greater distance will be ignored 
            continue;
        }

        for (auto ch : adj[u]) {
            int v = ch.first;
            ll w = ch.second;
            if (dist[v] <= currD + w) { 
                continue;
            }

            dist[v] = currD + w;
            pq.insert({dist[v], v});
        }
    }
}


int main() {
    optimize() 
    int n, m; 
    cin >> n >> m; 
    adj.assign(n+5, vector<pll>()); 
    

    for (int i=0; i<m; i++) { 
        ll u, v, w; 
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); 
        adj[v].push_back({u, w}); 
    }

    dijkstra(0, n);

    for (int i=0; i<n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;


    return 0;
}


/*

5 7
1 3 3
1 2 2
1 4 6
2 0 6
2 3 7
0 4 3
3 4 5

output: 0 8 6 8 3
*/