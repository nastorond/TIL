/* Color Tree
다양한 색의 노드로 구성
Node
{
    - m_id
    - p_id          : parent Node - if p_id == -1 : root
    - Color         : 1 ~ 5 (red, orange, yellow, green, brue)
    - last updated
    - max_depth     : sub_tree's max height is had root as m_id
    - childs        : vector<m_id>
}

1. add Node / Called 20,000 / O(depth(100) * 20,000)
- m_id, p_id, color, max_depth
- 추가했을 때, 모순이 생기면 추가 안함.
- 구현
    - 생성 가능 여부 검사
    - 부모 노드 저장
    - 부모에서 나를 자식으로 추가

2. change Color / Called 50,000 / 
- m_id, color
    - m_id 를 root 로 하는 서브트리를 모두 color 로 변경
- 노드의 개수가 최대 20,000 개.
    - 색을 다 바꿀 수는 없네. 다 바꾸는 연산 -> 50,000 * 20,000
- 색을 바꾸는건 나중에 고민.
- 구현
    - m_id color 변경. 마지막으로 업데이트 된 시간 저장.

3. get color / Called 20,000 / 
- m_id
- 조회 한번 당 max_depth 정도는 탐색 가능.
    - 가장 마지막으로 갱신된 부모 노드의 색이 m_id 노드의 색이 된다.
    - 색과 turn 을 기록하면 찾기 가능
- 구현
    - 부모로 올라가며 마지막으로 update 된 색깔

4. get score / Called 100 /
- 모든 노드의 가치 제곱의 합.
- 가치 : 해당 노드를 루트로 한 서브트리에 존재하는 노드의 색 종류
- 모든 노드 순회 가능. 20,000 * 100
- 루트로부터 내려가면서 모든 노드의 색을 점검 가능.
- 모든 노드에 대해서 체크배열 생성 가능.
    - 근데 그럼 너무 어려우니까.
    - 하위 노드로부터 정보를 얻어와서 상위 노드에 대해서 채워준다.
- TreeDP를 이용해서, 각 노드의 가치를 계산.
    - DP[i] : i 를 루트로 했을 때, 서브트리의 색깔 종류를 나타내는 상태값.

### DP
- Definition
- recurrence equals
- initial value

### Bit Mask
- 경우의 수가 5개 밖에 안되기 때문에
- 11100 | 00101 => 11101 이런식으로 연산
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
    int m_id;
    Node* par;
    int max_depth;

    pair<int, int> color; //! color with time / basic time = -1
    vector<Node*> childs;
};

int turn; //! global turn checking
unordered_map<int, Node*> nodes;

bool can_make(Node* cur, int h)
{
    if (cur->max_depth < h) return false;

    return cur->par == nullptr || can_make(cur->par, h+1);
}

void add_node() //! 100
{
    //! need to fix

    int m_id, p_id, color, depth;
    cin >> m_id >> p_id >> color >> depth;

    if (!can_make(nodes[p_id], depth)) return;
    
    Node* tmp_node;
    tmp_node->par = p_id == -1 ? nullptr : nodes[p_id];
    tmp_node->m_id = m_id;
    tmp_node->color = make_pair(color, -1);
    tmp_node->childs = vector<Node*>();
    nodes[m_id] = tmp_node;
}

void update_color() //! 200
{
    int color, m_id;
    cin >> m_id, color;

    nodes[m_id]->color = make_pair(color, turn);
}

pair<int, int> find_color(Node* cur)
{
    int color = 0;
    int last_updated = -1;

    //! iter
    while (cur->par != nullptr)
    {
        if (cur->color.second > last_updated)
        {
            color = cur->color.first;
            last_updated = cur->color.second;
        }

        cur = cur->par;
    }
    return make_pair(color, last_updated);
}

void get_color() //! 300
{
    int m_id;
    cin >> m_id;

    nodes[m_id]->color = find_color(nodes[m_id]); //! get color
}

int get_one(int state)
{   
    int cnt = 0;
    for (int i=0; i<5; ++i)
    {
        if (state & (1 << i))
        {
            ++cnt;
        }
    }
    return cnt;
}

int find_childs_color(Node* cur, unsigned long long& ret)
{
    int state = 1 << cur->color.first;

    for (auto chd : cur->childs)
    {
        state |= find_childs_color(chd, ret);
    }

    int cnt = get_one(state);
    ret += cnt * cnt;

    return state;
}


unsigned long long get_score() //! 400
{
    unsigned long long ret = 0;

    for (auto it = nodes.begin(); it != nodes.end(); ++it)
    {
        if (it->second->par == nullptr) continue;
        find_childs_color(it->second, ret);
    }
    
    return ret;
}

int main() 
{
    int Q;
    cin >> Q;

    int query;
    for (turn=0; turn < Q; ++turn)
    {
        cin >> query;
        if (query == 100)
        {
            add_node();
        }
        else if (query == 200)
        {
            update_color();
        }
        else if (query == 300)
        {
            get_color();
        }
        else //! query == 400
        {
            cout << get_score() << "\n";
        }
    }

    // Please write your code here.
    return 0;
}