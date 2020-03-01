#include <iostream>

class complex
{
public:
	complex(double newr, double newi) : r(), i(){
		r = newr; i = newi;
	}
	// ~complex();


private:
	double r,i;

	// friend std::ostream& operator << (std::ostream&, const complex&);
	// friend class complex_algebra;
	
};

int main(){
	complex c1(2.0,3.0);
	/*
	complex* p = &c;
	*p.r = 3.5; //ERROR 역참조 *(p.r)을 의미
	(*p).r = 3.5; // OK 포인터 *로 멤버에 접근
	p->r = 3.5;
	std::cout << "p.r is (" << (*p).r <<")\n";
	*/
	
	return 0;
}