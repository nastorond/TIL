/*
상자는 고유한 번호를 가짐 
*/
#include <iostream>

using namespace std;

/**
* 1. 공장 설립 init
*    m 개의 벨트 총 n 개의 상자 각 벨트 마다  n / m 개 상자 세팅
*/
void init()
{
}

/**
* 2. 상자 하차
*    w_max 주어짐
*    1 ~ M 번까지 가장 앞 무게 확인 후 w_max 초과면 가장 맨 뒤로 보냄
*    아닌 경우 컨베이어 벨트에서 하차
*    총 합 출력
*/
void down_box(int w_max)
{
}

/**
* 3. 상자 제거
*    r_id 주어짐
*    해당 고유 번호가 벨트에 있다면 상자를 제거 후, 상자는 한칸씩 내려옴
*    없으면 -1 , 있으면 r_id 출력
*/
void remove_box(int r_id)
{
}

/**
* 4. 상자 확인
*     f_id 주어짐
*    벨트 번호 출력, 없으면 -1
*    상자가 있는 경우 해당 상자와 그 뒤에 있는 모든 상자를 앞으로 가져옴. 순서는 유지되어야 함
*/
void check_box(int f_id)
{
}

/*
* 5. 벨트 고장
*    b_num 주어짐
*    해당 벨트는 더이상 사용 불가
*    해당 벨트를 기준으로 오른쪽(오른 쪽이 없으면 가장 왼쪽으로 이동)
*    b_num 벨트가 이미 고장나있으면 -1 아니면 정상처리 했다는 의미로 b_num 출력
*/
void broken_conveyor(int b_id)
{
}

int main() {
    // Please write your code here.
    int q;
    cin >> q;
    while (q--)
    {
        int order, num;
        cin >> order;
        if (order == 100)
        {
            init()
        }
        else if (order == 200)
        {
            cin >> num;
            down_box(num);
        }
        else if (order == 300)
        {
            cin >> num;
            remove_box(num);
        }
        else if (order == 400)
        {
            cin >> num;
            check_box(num);
        }
        else
        {
            cin >> num;
            broken_conveyor(num);
        }
    }
    return 0;
}