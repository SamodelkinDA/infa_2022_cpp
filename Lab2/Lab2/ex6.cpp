#include <iostream>


int main(){
	int a, b = 0, c = 0;
	std::cin >> a;
	while (a != 0){
		if (b == 0){
			b = a;
			c = 1;
		}
		else{
			if (a > b) {
				b = a;
				c = 1;
			}
			else{
				if (a == b){
					c++;
				}
			}
		}
		std::cin >> a;
	}
	std::cout << c;
	return 0;
}