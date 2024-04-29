#include <string>
#include <vector>

using namespace std;

int answer = 0;

void get_target_number(vector<int> numbers, int target, int sum, int index) {
    if (index == numbers.size()) {
        // 모든 숫자를 다 사용했을 때 종료
        if (sum == target) {
            // 만약에 모든 숫자를 다 사용한 결과가 타겟 넘버와 일치하면 answer 추가
            answer++;
        }
        return;
    }

    // 숫자를 다 사용하지 않았을 경우 다음 더했을 때랑 뺄 때의 경우 모두 탐색
    get_target_number(numbers, target, sum + numbers[index], index + 1);
    get_target_number(numbers, target, sum - numbers[index], index + 1);


}

int solution(vector<int> numbers, int target) {
    get_target_number(numbers, target, 0, 0);

    return answer;
}