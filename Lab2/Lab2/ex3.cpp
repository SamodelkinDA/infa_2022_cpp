#include <iostream>


int main(){
	unsigned a, b=0;
	do{
		std::cin >> a;
		if (a % 2 == 0) b++;
	} while (a != 0);
	std::cout << b - 1;
	return 0;
}