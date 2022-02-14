#include <iostream>


int main(){
	int a, c = 2;
	std::cin >> a;
	while (c*c <= a){
		if (a%c == 0){
			std::cout << c<<std::endl;
			a = a / c;
			c--;
		}
		c++;
	}
	if (a != 1){
		std::cout << a;
	}
	return 0;
}