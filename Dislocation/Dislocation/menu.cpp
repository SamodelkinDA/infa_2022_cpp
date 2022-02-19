#include <iostream>
#include <fstream>
#include <ctime>

void model(int);

int main(){
	bool ask = true;
	unsigned c;
	int start, end, num_of_trys;
	std::ifstream in("../Dislocation/Data.txt");
	std::ofstream out;          
	out.open("../Dislocation/OUT.txt");
	in >> num_of_trys;
	out << num_of_trys << "\n";
	while (ask){
		system("cls");
		std::cout << "Dislocation. By Samodelkin_DA \n";
		std::cout << "choose the mode \n";
		std::cout << "print 0 to close \n";
		in >> c;
		//std::cin >> c;
		switch (c)
		{
		case 0:
			ask = false;
			break;
		default:
			out << c << " ";
			for (int i = 0; i < num_of_trys; i++){
				start = clock();
				model(c);
				end = clock();
				out << ((end - start) / CLOCKS_PER_SEC) << " ";
			}
			out << "\n";
			break;
		}
		std::cout << "\n";
	}
	out.close();
	in.close();
	return 0;

}