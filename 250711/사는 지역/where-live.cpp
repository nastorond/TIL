#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define MAX_N 10

using namespace std;

struct person
{
    string name;
    string number;
    string loc;
};

int n;
string name[MAX_N], street_address[MAX_N], region[MAX_N];
vector<person> people;

bool compare(person& a, person& b)
{
    return a.name > b.name;
}

int main() {
    cin >> n;

    person tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp.name;
        cin >> tmp.number;
        cin >> tmp.loc;
        people.push_back(tmp);
    }

    // Please write your code here.
    sort(people.begin(), people.end(), compare);

    cout << "name " << people[0].name << "\n" << "addr " << people[0].number << "\n" << "city " << people[0].loc << "\n";
    
    return 0;
}