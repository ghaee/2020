#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

// binary search

int main(int argc, char** argv){
    int n, m, lt, rt, mid;
    
    scanf("%d %d",&n, &m);
    vector<int> v(n+1);

    for(int i = 1; i <= n; ++i){
        scanf("%d",&v[i]);
    }

    sort(v.begin(),v.end()); //sort before search
    
    lt = 0;
    rt = n;
    while(lt <= rt){
        mid = (lt+rt)/2;
        if(v[mid] == m){
            cout << mid << endl;
            break;
        }else if(v[mid] > m){
            rt = mid -1;
        }else{
            lt = mid +1;
        }
    }

    // bs 이용안할 때
    // for(int i = 1; i <= n; ++i){
    //     if(v[i] == m){
    //         cout << i <<endl;
    //         break;
    //     }
    // }

    system("PAUSE");
	return 0;
}