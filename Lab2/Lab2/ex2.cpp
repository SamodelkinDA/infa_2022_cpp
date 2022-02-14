#include <iostream>


int main(){
	unsigned a;
	std::cin >> a;
	if (a % 400 == 0){
		std::cout << "YES";
	}
	else{
		if (a % 100 == 0){
			std::cout << "NO";
		}
		else{
			if (a % 4 == 0){
				std::cout << "YES";
			}
			else std::cout << "NO";
		}
	}

	return 0;
}