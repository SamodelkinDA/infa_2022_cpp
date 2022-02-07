#include <iostream>
#include <math.h>

int hipotenus(){
	std::cout << "Exercise 2; Hipotenus \n enter two float \n";
	std::cout << "program will print result \n";
	double a, b;
	std::cin >> a >> b;
	std::cout << "Result: "<< sqrt(a*a + b*b) << std::endl;
	return 0;
}