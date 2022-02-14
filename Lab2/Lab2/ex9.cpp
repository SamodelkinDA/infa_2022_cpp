
#include <string>
#include <iostream>

int main(){
	int a, c, sum = 0;
	std::string b;
	std::string n = "A999AA";
	std::cin >> a >> b;
	while (b != n){
		if (a > 60){
			c = 0;
			if (b[1] == b[2]) c++;
			if (b[1] == b[3]) c++;
			if (b[3] == b[2]) c++;
			if (c == 0){
				sum += 100;
			}
			else{
				if (c == 1){
					sum += 500;
				}
				else{
					sum += 1000;
				}
			}
		}
		std::cin >> a >> b;
	}
	std::cout << sum;
	return 0;
}