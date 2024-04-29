#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 순위를 알려주는 함수
int get_rank(int corr) {
    switch (corr) {
        case 0: return 6;
        case 1: return 6;
        case 2: return 5;
        case 3: return 4;
        case 4: return 3;
        case 5: return 2;
        case 6: return 1;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    // 0(알아볼 수 없는 수)의 개수
    int cnt_0 = 0;
    // 로또 당첨 번호와 일치하는 개수
    int corr = 0;

    // 오름차순으로 정렬
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());

    for (int i = 0, j = 0; i < 6; i++) {
        // 알아볼 수 없는 수의 개수 세기
        if (lottos[i] == 0) {
            cnt_0++;
            continue;
        }


        // 구매한 번호가 작으면 i를 추가하고
        // 당첨번호가 작으면 j를 추가해서 비교해야 함
        // 구매한 번호가 당첨 번호보다 크거나 같을 때
        while (lottos[i] >= win_nums[j]) {
            if (lottos[i] == win_nums[j]) {
                // 당첨 번호와 일치하면 corr 추가
                corr++;
            }
            // 다음 당첨번호와 비교
            j++;
        }

    }

    // 최고 순위 = 알아볼 수 없는 번호가 전부 당첨번호와 일치할 때
    answer.push_back(get_rank(corr + cnt_0));
    answer.push_back(get_rank(corr));

    return answer;
}