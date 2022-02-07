#include <iostream>
#include <vector>

int vector_ex(){
	std::cout << "vector practice; enter int n and then n of ints \n";
	int sum = 0, i, n = 0;
	std::cin >> n;
	std::vector<int> vec(n);
	for (i = 0; i < n; i++){
		std::cin >> vec.at(i);
	}
	
	for (i = 0; i < n; i++){
		sum += vec.at(i);
		std::cout << vec.at(i);
	}
	std::cout << " Sum: " << sum << std::endl;

	return 0;
}