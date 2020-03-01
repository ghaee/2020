#include <vector>
#include <iostream>
#include <cassert>

std::vector<float> add(const std::vector<float>& v1, const std::vector<float>& v2){

	assert(v1.size() == v2.size());
	std::vector<float> s(v1.size());
	for(unsigned i = 0; i < v1.size(); ++i){
		s[i] = v1[i] + v2[i];
	}

	return s;

}


int main(){

	
	std::vector<float> v = {1,2,3}, w = {7,8,9}, s = add(v,w);

	// std::vector<float> v(3), w(3), s;

	// v[0] = 1; v[1] = 2; v[2] = 3;
	// w[0] = 7; w[1] = 8; w[2] = 9;
	// s = add(v,w);

	for(unsigned i = 0; i < s.size(); ++i){
		std::cout << "s[" << i << "] = " << s[i] << std::endl;
	}

}
