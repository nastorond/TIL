#define MAXL	5
#define MAXF	10
#define MAXN    10003

#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<set<int>> friends(MAXN);
int user_num;

/**
 * 전체 호출 회수 50000회, init 10회, recommend 400회
 * add + del => 49590회
 * add / del 에서는 간단한 로직만 돌려야 할듯
 * 힙, 정적 메모리를 합쳐서 95MB
 */

/**
 * 초기화 함수
 * @param N 사용자 수
 * friends set 초기화
 */
void init(int N)
{
    user_num = N;
	for (int i=0; i<=N; i++) {
        friends[i].clear();
    }
}

/**
 * 무조건 새로운 친구
 * 서로 친구로 추가
 * add / del 최적화 여지가 있네.. 따로 빼뒀다가 recommend 할 때 해줘도 문제없을듯
 */
void add(int id, int F, int ids[MAXF])
{
    for (int i=0; i<F; i++) {
        friends[id].insert(ids[i]);
        friends[ids[i]].insert(id);
    }
}

/**
 * 서로의 친구 항목에서 삭제
 * 친구가 아닌 경우는 주어지지 않음
 */
void del(int id1, int id2)
{
    friends[id1].erase(id2);
    friends[id2].erase(id1);
}

/**
 * 사용자 id인 유저에게 친구 추천
 * list 에 저장, 최대 추천 수는 5
 * 추천할 친구가 없다면 0
 * 각 테케에서 recommend 호출 횟수는 40 / 최대 400회
 * recommend 에서 가장 복잡한 로직
 */
int recommend(int id, int list[MAXL])
{
    for (int i=0; i<MAXL; i++) {
        list[i] = 0;
    }

    // 친구가 아무도 없다면 서로 친구가 없기때문에 0 리턴
    if (friends[id].empty()) return 0;

    vector<int> none_friend_list;
    vector<pair<int, int>> tmp;

    /**
     * 모든 번호를 순회하며 해당 유저와 친구인지 확인
     * 아닐 경우에만 none_friend_list 에 삽입
     */
    for (int i=1; i<=user_num; i++) {
        if (friends[id].count(i) == 0) none_friend_list.push_back(i);
    }

    // 모두가 친구라면 추천할 친구가 없으므로 0 리턴
    if (none_friend_list.size() == 0) return 0;

    for (int not_friend_num: none_friend_list) {
        int cnt = 0;

        /**
         * 친구가 아닌 사람의 set을 순회하며 해당 유저와 친구가 되어있는 유저가 있는지 확인
         * 있으면 cnt ++
         */
        for (auto it = friends[not_friend_num].begin(); it!=friends[not_friend_num].end(); it++) {
            if (friends[id].count(*it) != 0) cnt += 1;
        }
        if (cnt > 0) tmp.push_back(make_pair(cnt, not_friend_num));
    }

    // first(서로 친구 수)를 기준으로 내림차순, 유저 번호를 기준으로 오름차순으로 정렬
    sort(tmp.begin(), tmp.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    // 최대 5개까지만 입력
    for (int i=0; i<tmp.size() && i<MAXL; i++) list[i] = tmp[i].second;

	return tmp.size() >= 5 ? 5 : tmp.size();
}