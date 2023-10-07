#include <iostream>
#include <vector>

using namespace std;

vector <int>tree[51];
int delNodes[51];
int res = 0;


void countLeaf(int node, int delNode){
    if (node == delNode) return ;
    if (tree[node].size() == 0){
        ++res;
        return ;
    }
    for(int i=0;i<tree[node].size();i++){
        if (tree[node][i] == delNode && tree[node].size() == 1){
            ++res;
            continue;
        }
        countLeaf(tree[node][i], delNode);
    }
}


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n, node, del_node, root;
    int cnt=0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> node;
        if(node == -1){
            root = i;
        }else tree[node].push_back(cnt);
        ++cnt;
    }
    
    cin >> del_node;

    countLeaf(root, del_node);

    cout << res << "\n";

    return 0;
}