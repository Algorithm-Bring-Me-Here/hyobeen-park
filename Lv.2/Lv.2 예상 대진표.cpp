#include <iostream>

using namespace std;

/* 
(���� ��ȣ + 1) / 2 == ���� ���� ��ȣ
a�� b�� ���� ���� ��ȣ�� ��ġ�ϸ� �� �����ڰ� �ٰ� �ȴ�.

1���� -> a = 4, b = 7
2���� -> a = 2, b = 4
3���� -> a = 1, b = 2
4���� -> a = 1, b = 1

4���忡�� a�� b�� ���� ��ȣ�� ��ġ�߱� ������ 3���忡�� �� �����ڰ� �ٰ� �ȴ�.

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