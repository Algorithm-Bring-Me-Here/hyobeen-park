#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> score;

    // 이름과 그리움 점수를 매칭하여 저장합니다
    // ex. score[may] = 5, score[kein] = 10
    for (int i = 0; i < name.size(); i++) {
        score[name[i]] = yearning[i];
    }

    int sum;
    for (int i = 0; i < photo.size(); i++) {    // 사진 개수만큼 반복합니다
        sum = 0;


        for (int j = 0; j < photo[i].size(); j++) { // 각 사진에 찍힌 사람 수 만큼 반복합니다.
            // 사진 속 인물의 그리움 점수를 모두 더합니다.
            // score에 저장되어 있지 않은 경우 0이 출력됩니다.
            // ex. score[may] = 5, score[hyobeen] = 0
            sum += score[photo[i][j]];
        }
        
        // 그리움 점수의 합을 answer에 push해줍니다.
        answer.push_back(sum);
    }


    return answer;
}