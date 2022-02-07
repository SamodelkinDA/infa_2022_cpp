#include <iostream>

int STRING_practice(){
	char str[20] = "";
	std::cout << "String practice. \nThis program counts number of simbols \n";
	std::cout << "put a ';' to the end of line \n";
	std::cin.getline(str, 20, ';');
	unsigned i = 0;
	while (str[i]){
		i++;
	}
	std::cout << "Length: " << --i;
	return 0;
}