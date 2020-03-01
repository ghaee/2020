#include <iostream>
#include "list_template.cpp"
#include "sum_template.cpp"
using namespace std;

int main(){
	//*** accumulate_array test ***//
	 int ai[] = {2,4,7};
	 double ad[] = {2.,4.5,7.};
	// cout << "sum ai is " << accumulate_array(ai,&ai[3]) << '\n';
	// cout << "sum ad is " << accumulate_array(ad,ad+3) <<'\n';
	

	//*** list sum test ***//
	 list<float> l;

	 l.append(2.2f); l.append(4.1f); l.append(7.0f);
	 l.append(8.2f);

	// cout << "sum of the indices of list is " << sum(l) <<'\n';


	//**both array and list with accumulate()**//
	cout << "array sum = " << accumulate(ai,&ai[3],0)<<'\n';
	cout << "array list = " << accumulate(l.begin(),l.end(),0.0) <<'\n';
}
