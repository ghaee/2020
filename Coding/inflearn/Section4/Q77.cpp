#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//Union And Find
//Make Disjoint set

int f_set[1001];

int Find(int a){ //Find student's set number
    if(a == f_set[a]) return a;
    else return f_set[a] = Find(f_set[a]); //memoization
}

void Union(int a, int b){
    //if they belong to different set 
    a = Find(a);
    b = Find(b);
    if(a != b){
        f_set[a] = b; // Union, change student's set number
    }
}

int main(){
    int n, m, f1, f2;
    cin >> n >> m;

    //initialize all studetns to belong to their own set
    for(int i = 1; i <= n; ++i){
        // index 'i' : student neumber
        f_set[i] = i;
        //i-th element : set number 
;
    }
    
    //Union
    for(int i = 1; i <= m; ++i){
        cin >> f1 >> f2;
        Union(f1,f2);
    }

    //Find
    cin >> f1 >> f2;
    f1 = Find(f1);
    f2 = Find(f2);
    if(f1 == f2) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}