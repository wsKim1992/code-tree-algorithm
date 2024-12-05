#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX_N 100000

using namespace std;

// 변수 선언:
int n;
vector<pair<int, int> > edge[MAX_N + 1];
bool visited[MAX_N + 1];
int dist[MAX_N + 1];
int max_dist;
int last_node;
int a, b;
int ans;

// 모든 노드의 정점을 탐색하는 DFS를 진행합니다.
void DFS(int x, int ignore_num) {
    for(int i = 0; i < edge[x].size(); i++) {
        int y, dis;
        tie(y, dis) = edge[x][i];

        // 이미 방문한 정점이면 스킵합니다.
        if(visited[y]) continue;

        visited[y] = true;
        dist[y] = dist[x] + dis;

        // 현재 정점을 기준으로 가장 먼 노드를 찾습니다.
        // 단, ignore_num이면 무시합니다.
        if(dist[y] > max_dist && y != ignore_num) {
            max_dist = dist[y];
            last_node = y;
        }

        DFS(y, ignore_num);
    }
}

int main() {
    // 입력:
    cin >> n;

    // n - 1개의 간선 정보를 입력받습니다.
    for(int i = 1; i <= n - 1; i++) {
        int x, y, dis;

        cin >> x >> y >> dis;

        edge[x].push_back({y, dis});
        edge[y].push_back({x, dis});
    }

    // DFS를 통해 가장 먼 노드를 찾습니다. 이 노드를 a라 합니다.
    visited[1] = true;
    DFS(1, -1);
    a = last_node;

    // 다시 한번 먼 노드를 찾아줍니다. 이 위치를 b라 합니다.
    for(int i = 1; i <= n; i++) {
        visited[i] = false;
        dist[i] = 0;
    }
    max_dist = -1;
    visited[a] = true;
    DFS(a, -1);
    b = last_node;

    // 이제 a에서 b를 제외한 노드 중 가장 먼 노드까지의 거리를 구합니다.
    // 이후 답을 갱신합니다.
    for(int i = 1; i <= n; i++) {
        visited[i] = false;
        dist[i] = 0;
    }
    max_dist = -1;
    visited[a] = true;
    DFS(a, b);
    ans = max(ans, max_dist);

    // 이제 b에서 a를 제외한 노드 중 가장 먼 노드까지의 거리를 구합니다.
    // 이후 답을 갱신합니다.
    for(int i = 1; i <= n; i++) {
        visited[i] = false;
        dist[i] = 0;
    }
    max_dist = -1;
    visited[b] = true;
    DFS(b, a);
    ans = max(ans, max_dist);

    cout << ans;
    return 0;
}