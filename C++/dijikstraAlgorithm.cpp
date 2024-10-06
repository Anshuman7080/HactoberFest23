#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ipair pair<ll, ll>
#define MAXN 110000
#define INF LLONG_MAX

vector<ipair> adj_list[MAXN];
vector<ll> dis(MAXN, INF);
vector<ll> parent(MAXN, -1);

void dijkstra(ll src) {
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
    dis[src] = 0;
    pq.emplace(dis[src], src);

    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();

        // Process each neighbor of u
        for (const auto& p : adj_list[u]) {
            ll v = p.first;
            ll weight = p.second;

            // Relaxation step
            if (dis[v] > dis[u] + weight) {
                dis[v] = dis[u] + weight;
                parent[v] = u;
                pq.emplace(dis[v], v);
            }
        }
    }
}

void printPath(ll destination) {
    if (dis[destination] == INF) {
        cout << -1 << endl; // No path found
        return;
    }

    stack<ll> path;
    for (ll i = destination; i != -1; i = parent[i]) {
        path.push(i);
    }

    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
}

int main() {
    ll v, e;
    cin >> v >> e;

    for (ll i = 0; i < e; i++) {
        ll u, v, cost;
        cin >> u >> v >> cost;
        adj_list[u].emplace_back(v, cost);
        adj_list[v].emplace_back(u, cost); // Assuming undirected graph
    }

    dijkstra(1); // Start Dijkstra from vertex 1
    printPath(v); // Print the shortest path to vertex v

    return 0;
}
