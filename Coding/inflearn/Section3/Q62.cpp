#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Devide & Conquer
int n;
int a[101], tmp[101];
void DnC(int start, int end){
    int mid;
    int p1, p2, p3;
    if(start < end){ 

        //Devide 
        mid = (start+end)/2;
        DnC(start,mid);
        DnC(mid+1,end);

        //Conquer
        p1 = start;
        p2 = mid+1;
        p3 = start;
        while(p1 <= mid && p2 <= end){
            if(a[p1] < a[p2]) tmp[p3++] = a[p1++];
            else tmp[p3++] = a[p2++];
        }
        while(p1 <= mid) tmp[p3++] = a[p1++];
        while(p2 <= end) tmp[p3++] = a[p2++];
        
        //copy from tmp[] to a[]
        for(int i = start; i <= end; ++i){
            a[i] = tmp[i];
        }
    }
}
int main(int argc, char** argv){
    cin >> n;
    vector<int> v(n);
    
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    
    DnC(0, n-1);
    
    for(int i = 0; i < n; ++i){
        cout << a[i];
    }
    cout << endl;
    //system("PAUSE");
    return 0;
}