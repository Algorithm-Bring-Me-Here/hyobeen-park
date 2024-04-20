#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    // 문자열 개수만큼 반복
    for (int i = 0; i < babbling.size(); i++) {
        // 직전에 말한 옹알이를 flag로 저장
        // none = 0; aya = 1; ye = 2; woo = 3; ma = 4
        int flag = 0;
        bool isBabbling = true;

        for (int j = 0; j < babbling[i].length(); j++) {
            if (babbling[i].substr(j, 3) == "aya" && flag != 1) {
                // j번째 글자부터 3글자가 "aya"와 일치 + 직전에 말한 옹알이가 "aya" 가 아님
                flag = 1;       // flag를 "aya"로 설정
                j += 2;         // j에 2 더하기 -> for문에서 1이 더해지기 때문에 (글자수 - 1)을 더함
            }
            else if (babbling[i].substr(j, 2) == "ye" && flag != 2) {
                flag = 2;
                j += 1;
            }
            else if (babbling[i].substr(j, 3) == "woo" && flag != 3) {
                flag = 3;
                j += 2;
            }
            else if (babbling[i].substr(j, 2) == "ma" && flag != 4) {
                flag = 4;
                j += 1;
            }
            else {
                // 말할 수 없는 옹알이일 경우
                isBabbling = false;
                break;
            }
        }

        if (isBabbling == true)
            answer++;
    }

    return answer;
}