#include <iostream>


int main(){
	int a, b=0;
	do{
		std::cin >> a;
		if (a%2 == 0 && a != 0){ 
			if (b == 0){
				b = a;
			}
			else{
				if (a > b) b = a;
			}
		}

	} while (a != 0);
	std::cout << b;
	return 0;
}