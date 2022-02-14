#include <iostream>


int main(){
	unsigned a;
	bool b = true;
	std::cin >> a;
	while (a != 1){
		if (a % 2 == 0){
			a = a / 2;
		}
		else{
			b = false;
			break;
		}

	}
	if (b){
		std::cout << "YES";
	}
	else{
		std::cout << "NO";
	}
	return 0;
}