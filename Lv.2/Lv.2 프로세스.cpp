#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int, int>> q;

    for (int i = 0; i < priorities.size(); i++) {
        // (값, 인덱스) 형태로 큐에 저장
        q.push({ priorities[i], i });
    }

    // 내림차순으로 정렬
    sort(priorities.begin(), priorities.end(), greater<int>());

    while (!q.empty()) {
        int a = q.front().first;    // 값
        int b = q.front().second;   // 인덱스

        // 큐 맨 앞에 있는 값 삭제
        q.pop();

        if (a == priorities[answer]) {  // 큐 안에 있는 값 중 가장 큰 값 -> 프로세스 실행
            if (b == location)      // 우리가 알고자 하는 프로세스였으면 break
                break;
            answer++;
        }

        // 프로세스가 실행되지 않았기 때문에 맨 뒤로 push
        q.push({ a, b });

    }

    // answer가 0에서 시작했기 때문에 1 더해주기
    return answer + 1;
}