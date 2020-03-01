#include <iostream>

class vector{
public:
	vector(const vector& v)
		: my_size(v.my_size), data(new double[my_size])
		{
			for (unsigned i = 0; i < my_size; ++i)
				data[i] = v.data[i];
		}
	~vector(){ delete[] data;}
	

private:
	unsigned my_size;
	double *data;
};


int main(){

}