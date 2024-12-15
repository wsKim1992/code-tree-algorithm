#include <iostream>
#include <tuple>
#include <algorithm>

#define MAX_N 10000
#define MAX_M 100000

using namespace std;

// 변수 선언
int n, m;

tuple<int, int, int> edges[MAX_M + 1];

int uf[MAX_N + 1];
char ab_type[MAX_N + 1];

int Find(int x) {
    if(uf[x] == x)
        return x;
    return uf[x] = Find(uf[x]);
}

void Union(int x, int y) {
    int X = Find(x);
    int Y = Find(y);
    uf[X] = Y;
}

int main() {
    // 입력:
    cin >> n >> m;

    // n개의 정점에 대해 각각 a, b종류 중 어느 쪽인지 저장합니다.
    for(int i = 1; i <= n; i++)
        cin >> ab_type[i];

    for(int i = 1; i <= m; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;

        // cost 순으로 오름차순 정렬을 만들기 위해 순서를 cost 먼저 적어줍니다.
        edges[i] = make_tuple(cost, x, y);
    }

    // cost 순으로 오름차순 정렬을 진행합니다.
    sort(edges + 1, edges + m + 1);

    // uf 값을 초기값을 적어줍니다.
    for(int i = 1; i <= n; i++)
        uf[i] = i;
    
    // cost가 낮은 간선부터 순서대로 보며
    // 아직 두 노드가 연결이 되어있지 않을 경우에만
    // 해당 간선을 선택하고 두 노드를 합쳐주면서
    // mst를 만들어줍니다.
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        int x, y, cost;
        tie(cost, x, y) = edges[i];

        // 두 노드의 타입이 같다면 해당 간선은 사용할 수 없습니다.
        if(ab_type[x] == ab_type[y]) continue;

        // x, y가 연결되어 있지 않다면
        if(Find(x) != Find(y)) {
            // 해당 간선은 MST에 속하는 간선이므로
            // 답을 갱신해주고
            // 두 노드를 연결해줍니다.
            ans += cost;
            Union(x, y);
        }
    }

    // 모든 정점이 연결되어있는지를 판단하기 위해
    // is_all_connected라는 변수에 관리합니다.
    bool is_all_connected = true;
    for(int i = 2; i <= n; i++) {
        int x = Find(1);
        int y = Find(i);
        if(x != y) 
            is_all_connected = false;
    }

    // 만약 전부 연결되어있다면 사용한 비용의 합을 출력합니다.
    // 그렇지 않다면 -1을 출력합니다.
    if(is_all_connected)
        cout << ans;
    else
        cout << -1;

    return 0;
}