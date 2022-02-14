#include <string>
#include <iostream>
#include <cmath>

void printing_10 (int n){
	for (int j = 0; j < n; j++)
		std::cout << "<";
}
void printing_1(int n){
	for (int j = 0; j < n; j++)
		std::cout << "v";
}

int main(){
	int a, c=0, b;
	std::cin >> a;
	b = a;
	while (a != 0){
		a /= 60;
		c++;
	}
	for (int i = c-1 ; i > 0 ; i--){
		a = (b % int(pow(60, i+1))) / pow(60, i);
		printing_10(a / 10);
		printing_1(a % 10);
		std::cout << ".";
	}
	a = (b % 60);
	printing_10(a / 10);
	printing_1(a % 10);
	return 0;
}