#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    int mid, color, value, pid, maxDepth, prevDepth;
    vector<Node*> next;

    Node() : mid(0), color(0), value(0), pid(0), prevDepth(0) {}
};

vector<Node*> rootNodes;
unordered_map<int, Node*> getNode;
int value=0;

void appendNode() {
    Node* chd = new Node();
    cin >> chd->mid >> chd->pid >> chd->color >> chd->maxDepth;

    if (chd->pid == -1) {
        rootNodes.push_back(chd);
        chd->prevDepth = chd->maxDepth-1;
        getNode[chd->mid] = chd;
        return ;
    }

    Node* par = getNode[chd->pid];
    if (par->prevDepth == 0) return ;

    getNode[chd->mid] = chd;

    par->next.push_back(chd);
    chd->prevDepth = min(par->prevDepth-1, chd->maxDepth-1);

    return ;
}

void changingColor (Node* root, int color) {
    if (root->next.size() == 0) return ;

    for (Node* node : root->next) {
        node->color = color;
        changingColor(node, color);
    }
}

void changeColor() {
    int pid, color;
    cin >> pid >> color;

    Node* root = getNode[pid];
    root->color = color;
    root->value = 1;

    changingColor(root, color);

    return ;
}

void getNodeColor() {
    int pid;
    cin >> pid;

    cout << getNode[pid]->color << "\n";
}

void countingColors (vector<bool>& colors, Node* node) {
    if (node->next.size() == 0) {
        value += 1;
        colors[node->color] = true;
        return ;
    }

    vector<bool> newColors(6, 0);
    for (Node* chdNode : node->next) {
        countingColors(newColors, chdNode);
    }

    colors[node->color] = true;
    int cnt=0;

    for (int i=0; i<6; i++) {
        if (colors[i] || newColors[i]) cnt++;
    }

    value += cnt*cnt;

    return ;
}

void getValue () {
    vector<bool> colors(6, false);
    value = 0;

    for (Node* root : rootNodes) {
        countingColors(colors, root);
    }

    cout << value << "\n";

    return ;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int Q, queryName;
    cin >> Q;
    for (int i=0; i<Q; i++) {
        cin >> queryName;
        switch (queryName) {
            case 100:
                appendNode();
                break;
            case 200:
                changeColor();
                break;
            case 300:
                getNodeColor();
                break;
            case 400:
                getValue();
                break;
        }
    }    

    return 0;
}