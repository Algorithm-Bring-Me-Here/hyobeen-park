#include <iostream>

using namespace std;

/* 
(현재 번호 + 1) / 2 == 다음 라운드 번호
a와 b의 다음 라운드 번호가 일치하면 두 참가자가 붙게 된다.

1라운드 -> a = 4, b = 7
2라운드 -> a = 2, b = 4
3라운드 -> a = 1, b = 2
4라운드 -> a = 1, b = 1

4라운드에서 a와 b의 라운드 번호가 일치했기 때문에 3라운드에서 두 참가자가 붙게 된다.

*/

int solution(int n, int a, int b)
{
    int answer = 0;

    while (1) {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        answer++;

        if (a == b) break;
    }


    return answer;
}