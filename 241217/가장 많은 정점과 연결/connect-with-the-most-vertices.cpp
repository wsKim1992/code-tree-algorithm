#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100002
#define MAX_M 100002

using namespace std;

// 변수 선언
int n, m, k;

// 각 그룹의 최소비용을 관리합니다.
int min_cost[MAX_N+ 1];

bool visited[MAX_N + 1];

vector<int> cost_list;

int uf[MAX_N + 1];

int Find(int x) {
    if(uf[x] == x)
        return x;
    return uf[x] = Find(uf[x]);
}

void Union(int x, int y) {
    int X = Find(x);
    int Y = Find(y);
    uf[X] = Y;

    // 각 그룹의 최소비용을 관리합니다.
    min_cost[Y] = min(min_cost[Y], min_cost[X]);
}

int main() {
    // 입력:
    cin >> n >> m >> k;

    // min_cost의 초기값이 주어집니다.
    for(int i = 1; i <= n; i++)
        cin >> min_cost[i];

    // uf 값을 초기값을 적어줍니다.
    for(int i = 1; i <= n; i++)
        uf[i] = i;

    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;

        // 이미 연결되어 있으므로 union을 진행합니다.
        Union(x, y);
    }

    // 각 그룹들에 대해 min_cost값을 모아줍니다.
    for(int i = 1; i <= n; i++) {
        int I = Find(i);

        // 중복되는 그룹은 패스합니다.
        if(visited[I])
            continue;
        
        visited[I] = true;
        cost_list.push_back(min_cost[I]);
    }

    // min_cost를 오름차순으로 정렬합니다.
    sort(cost_list.begin(), cost_list.end());

    // 가장 작은 min_cost 쪽과 간선을 연결하는 것이 최선입니다.
    int ans = 0;
    for(int i = 1; i < (int) cost_list.size(); i++)
        ans += cost_list[0] + cost_list[i];

    if(ans <= k)
        cout << ans;
    else
        cout << "NO";
    return 0;
}