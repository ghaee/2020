#include <memory>
#include <iostream>
std::shared_ptr<double> f(){

	std::shared_ptr<double> p1{new double};
	std::shared_ptr<double> p2{new double}, p3 = p2;

	std::cout << "p3.use_count() = " << p3.use_count() << std::endl;

	return p3;

}

int main(){
	std::shared_ptr<double> p = f();

	std::cout << "p.use_count() = " << p.use_count() << std::endl;
}