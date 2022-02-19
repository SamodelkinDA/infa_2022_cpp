#include <iostream>
#include <fstream>
#include <ctime>

void model(int);

int main(){
	bool ask = true;
	unsigned c;
	int start, end;
	while (ask){
		system("cls");
		std::cout << "Dislocation. By Samodelkin_DA \n";
		std::cout << "choose the mode \n";
		std::cout << "print 0 to close \n";
		std::cin >> c;
		switch (c)
		{
		case 0:
			ask = false;
			break;
		default:
			start = clock();
			model(c);
			end = clock();
			break;
		}
		std::cout << "\n";
	}
	return 0;

}