#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> score;

    // �̸��� �׸��� ������ ��Ī�Ͽ� �����մϴ�
    // ex. score[may] = 5, score[kein] = 10
    for (int i = 0; i < name.size(); i++) {
        score[name[i]] = yearning[i];
    }

    int sum;
    for (int i = 0; i < photo.size(); i++) {    // ���� ������ŭ �ݺ��մϴ�
        sum = 0;


        for (int j = 0; j < photo[i].size(); j++) { // �� ������ ���� ��� �� ��ŭ �ݺ��մϴ�.
            // ���� �� �ι��� �׸��� ������ ��� ���մϴ�.
            // score�� ����Ǿ� ���� ���� ��� 0�� ��µ˴ϴ�.
            // ex. score[may] = 5, score[hyobeen] = 0
            sum += score[photo[i][j]];
        }
        
        // �׸��� ������ ���� answer�� push���ݴϴ�.
        answer.push_back(sum);
    }


    return answer;
}