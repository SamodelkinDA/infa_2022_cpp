#include <iostream>

int hipotenus();
int Practice();
int STRING_practice();
int vector_ex();

int main(){
	std::cout << "Lab 1. By Samodelkin_DA \n";
	bool ask = true;
	unsigned c;
	while (ask){
		std::cout << "choose the exercise \n";
		std::cout << "print 0 to close \n";
		std::cin >> c;
		switch (c)
		{
		case 0:
			ask = false;
			break;
		case 2:
			hipotenus();
			break;
		case 3:
			STRING_practice();
			break;
		case 4:
			vector_ex();
			break;
		case 1:
			Practice();
			break;
		default:
			std::cout << "Not a correct number \n";
			break;
		}
		std::cout << "\n";
	}
	return 0;

}