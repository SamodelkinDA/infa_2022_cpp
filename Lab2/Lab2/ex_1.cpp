#include <iostream>

unsigned gcd(unsigned a, unsigned b){
	a = a%b;
	if (a == 0){
		return b;
	}
	else{
		return gcd(b, a);
	}
}

int main(){
	unsigned a, b;
	std::cin >> a >> b;
	if (a < b){
		std::cout << gcd(b, a);
	}
	else{
		std::cout << gcd(a, b);
	}
	return 0;
}