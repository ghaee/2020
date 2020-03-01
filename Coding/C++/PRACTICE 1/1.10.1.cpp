#include <iostream>
#include <fstream>

void result(std::ostream& os, int age){
	os << "I'm " << age << " years old" << std::endl;
}
int main(){
	int age;
	std::ofstream file("myage.txt");
	std::cout << "How old are you? " << std::endl;
	std::cin >> age; 
	
	result(std::cout,age);
	result(file,age);

	return 0;

}