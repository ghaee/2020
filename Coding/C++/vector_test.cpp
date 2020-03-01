#include <iostream>
#include <vector>
#include <algorithm>

int main(){
	using namespace std;
	vector<int> v = {3,4,7,9};
	auto it = find(v.begin(), v.end(),4);
	cout << "AFTER " << *it << " comes " <<*(it+1) << '\n';

	auto it2 = v.insert(it+1,5);
	for(auto i : v){
		cout << i << ',';
	}
	cout <<'\n';
	v.erase(v.begin());
	for(auto i : v){
		cout << i << ',';
	}
	cout <<'\n';
	cout << "Size = " << v.size() <<", capacity = " << v.capacity() <<'\n';

	v.shrink_to_fit();
	cout << "After_shrink | Size = " << v.size() <<", capacity = " << v.capacity() <<'\n';
	v.push_back(7);
	for(auto i : v){
		cout << i << ',';
	}
	cout <<'\n';
	cout << "Size = " << v.size() <<", capacity = " << v.capacity() <<'\n';
}