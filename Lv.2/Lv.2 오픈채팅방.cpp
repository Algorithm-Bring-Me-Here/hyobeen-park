#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string, string> nickname;
    vector<pair<string, string>> rec;

    for (auto it = record.begin(); it != record.end(); it++) {
        stringstream ss(*it);
        string id, name, cmd;

        ss >> cmd;

        if (cmd.compare("Enter") == 0) {
            ss >> id >> name;
            nickname[id] = name;
        }
        else if (cmd.compare("Change") == 0) {
            ss >> id >> name;
            nickname[id] = name;
        }
        else {
            ss >> id;
        }

        rec.push_back({ id, cmd });
    }

    for (auto it = rec.begin(); it != rec.end(); it++) {
        auto now = *it;
        auto nowId = now.first;
        auto nowCmd = now.second;

        if (nowCmd.compare("Enter") == 0) {
            answer.push_back(nickname[nowId] + "님이 들어왔습니다.");
        }
        else if (nowCmd.compare("Leave") == 0) {
            answer.push_back(nickname[nowId] + "님이 나갔습니다.");
        }
    }


    return answer;
}