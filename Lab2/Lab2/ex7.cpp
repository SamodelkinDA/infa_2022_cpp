#include <iostream>


int main(){
	int a, c = 2;
	int b = 1;
	std::cin >> a;
	while (c*c <= a){
		if (a%c == 0){
			b = 0;
			break;
		}
		c++;
	}
	std::cout << b;
	return 0;
}