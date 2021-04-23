#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//priority_queue greedy algorithm
struct Data{
    int money;
    int deadline;
    Data(int m, int d){
        money = m;
        deadline = d;
    }
    bool operator<(Data &b){
        return deadline > b.deadline;
    }
};
int main(){
    int n, m, d, sum = 0, max = -21470000;
    priority_queue<int> pq; //max heap M을 저장할
    vector<Data> T;
    
    cin >> n;
    
    for(int i = 1; i <= n; ++i){
        cin >> m >> d;
        T.push_back(Data(m,d));
        if(d > max){
            max = d;
        }
    }
    sort(T.begin(),T.end());
    int j = 0;
    for(int i = max; i >= 1; --i){
        for(; j < n; ++j){
            if(T[j].deadline < i) break;
            pq.push(T[j].money);
        }
        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum << endl;
    return 0;
}