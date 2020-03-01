#include <iostream>
#include <fstream>
#include <sstream>

void write_smth(std::ostream& os){

	os << "Hi stream, did you know that 3*3 = " << 3 * 3 << std::endl;
}

int main(int argc, char* argv[]){

	std::ofstream myfile("test.txt");
	std::stringstream mysstream;

	write_smth(std::cout);
	write_smth(myfile);
	write_smth(mysstream);
	
	std::cout << "mysstream is:" << mysstream.str();
}