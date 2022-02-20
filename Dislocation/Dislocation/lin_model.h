#include <iostream> 
#include <random>
#include <windows.h>


const int Field_Size = 30;

void visualisation(char cells[Field_Size + 2]){
	system("cls");
	for (int i = 1; i <= Field_Size; i++)
	{
		std::cout << cells[i] << " ";
	}
}

bool loop_step(char(&cells_copy)[Field_Size + 2]){
	static int Probability = 4;
	bool finished = true;
	static char cells[Field_Size + 2];
	for (int i = 1; i <= Field_Size; i++)
	{
		cells[i] = cells_copy[i];
	}
	int reaction;
	for (int i = 1; i <= Field_Size; i++)
	{
		if (cells[i] == '0'){
			if (cells[i - 1] == '.' && cells[i + 1] == '.'){
				//cells[i - 1] != '0' && cells[i + 1] != '0'
				reaction = rand() % Probability;
				finished = false;
				if (reaction == 0 && cells_copy[i - 1] == '.'){
					cells_copy[i] = '.';
					cells_copy[i - 1] = '0';
				}
				else if (reaction == 1 && cells_copy[i + 1] == '.'){
					cells_copy[i] = '.';
					cells_copy[i + 1] = '0';
				}
			}
		}
	}
	return finished;
}


bool loop_step_wall(char(&cells_copy)[Field_Size + 2]){
	static int Probability = 4;
	bool finished = true;
	int reaction;
	for (int i = 1; i <= Field_Size; i++)
	{
		if (cells_copy[i] == '0'){
			if (cells_copy[i - 1] == '.' && cells_copy[i + 1] == '.'){
				reaction = rand() % Probability;
				finished = false;
				if (reaction == 0 && cells_copy[i - 1] == '.'){
					cells_copy[i] = '.';
					cells_copy[i - 1] = '0';
				}
				else if (reaction == 1 && cells_copy[i + 1] == '.'){
					cells_copy[i] = '.';
					cells_copy[i + 1] = '0';
				}
			}
		}
	}
	return finished;
}

void model(int Number_of_dislocations){
	int i = 0;
	bool finished = false;
	char cells[Field_Size + 2];
	for (i = 1; i <= Field_Size; i++)
	{
		cells[i] = '.';
	}
	cells[0] = 'b';
	cells[Field_Size + 1] = 'b';

	int x;
	if (Number_of_dislocations < Field_Size){
		while (Number_of_dislocations > 0){
			x = rand() % Field_Size + 1;
			if (cells[x] == '.'){
				cells[x] = '0';
				Number_of_dislocations--;
			}
		}
		while (!GetAsyncKeyState(VK_ESCAPE) && !finished){
			finished = loop_step(cells);
			visualisation(cells);
			//Sleep(200);
		}
	}

	//system("pause");

}