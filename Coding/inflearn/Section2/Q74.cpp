#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    //priority_queue<int,vector<int>,less<int>> pq; //max heap
    priority_queue<int,vector<int>,greater<int>> pq; //min heap
    int a;

    while(true){
        cin >> a;
        if(a == -1) break;
        else if(a== 0){
            if(pq.empty()) cout << -1 << endl;
            else{
                cout << pq.top() << endl; //print root
                pq.pop();
            }
        }else{
            pq.push(a);
        }
    }
    return 0;
}