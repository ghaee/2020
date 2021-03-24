#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv){
    int n, m, p1=0, p2=0, p3=0;

    scanf("%d",&n);
    vector<int> v1(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &v1[i]);
    }

    scanf("%d",&m);
    vector<int> v2(m);
    for(int i = 0; i < m; ++i){
        scanf("%d", &v2[i]);
    }

    vector<int> v3(n+m);
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    while(p1 < n && p2 < m){
        if(v1[p1] == v2[p2]){
            v3[p3++] = v1[p1++];
            p2++;
        }else if(v1[p1] < v2[p2]){
            p1++;
        }else{
            p2++;
        }
    }

    for(int i = 0; i < p3; ++i){
        printf("%d ",v3[i]); 
    }
	return 0;
}