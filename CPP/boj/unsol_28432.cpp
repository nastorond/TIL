#include <iostream>
#include <string.h>

using namespace std;

string strArr[100];
string canArr[100];

int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n, m, idx;
    int cnt=0;
    string a;
    char postWord, preWord;

    cin >> n;
    if(n==1){
        cin >> m;
        char answer;
        cin >> answer;
        cout << answer;
    }else{
        for(int i=0;i<n;i++){
        cin >> a;
        if(a == "?"){
            idx = i;
        }
        strArr[i] = a;
        }
        cin >> m;

        if (idx==n-1){
            postWord = strArr[idx-1].back();

            for(int i=0; i<m; i++){
                cin >> a;
                if(a.front() == postWord){
                    canArr[cnt] = a;
                    ++cnt;
                }
            }
        }else if(idx==0){
            preWord = strArr[idx-1].front();

            for(int i=0; i<m; i++){
                cin >> a;
                if(a.back() == preWord){
                    canArr[cnt] = a;
                    ++cnt;
                }
            }
        }else{
            postWord = strArr[idx-1].back();
            preWord = strArr[idx+1].front();

            for(int i=0; i<m; i++){
                cin >> a;
                if(a.front() == postWord && a.back()==preWord){
                    canArr[cnt] = a;
                    ++cnt;
                }
            }
        }

        string ck = " ";
        for(int i=0; i<n; i++){
            for(int j=0; j<cnt; j++){
                if(strArr[i] == canArr[j]){
                    canArr[j] = ck;
                }
            }
        }

        int res;
        for(int i=0; i<cnt; i++){
            if(canArr[i] != ck){
                res = i;
                break;
            }
        }
        cout << canArr[res] << "\n";
    }
    
    return 0;
}