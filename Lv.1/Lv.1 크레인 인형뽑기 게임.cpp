#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;

    vector<int> basket;

    for (int i = 0; i < moves.size(); i++) {
        int location = moves[i] - 1;

        for (int j = 0; j < board.size(); j++) {
            if (board[j][location] == 0) continue;

            if (!basket.empty() && board[j][location] == basket.back()) {
                basket.pop_back();
                answer += 2;
            }
            else {
                basket.push_back(board[j][location]);
            }

            board[j][location] = 0;
            break;
        }
    }

    return answer;
}