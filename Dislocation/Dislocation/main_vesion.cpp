#include <iostream> 
#include <random>
#include <windows.h>


const int Field_Size = 10;

void visualisation(char cells[Field_Size + 2][Field_Size + 2]){
	system("cls");
	for (int i = 1; i <= Field_Size; i++)
	{
		for (int j = 1; j <= Field_Size; j++){
			std::cout << cells[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

bool loop_step(char (&cells_copy)[Field_Size + 2][Field_Size + 2]){
	static int Probability = 8;
	bool finished = true;
	static char cells[Field_Size + 2][Field_Size + 2];
	for (int i = 1; i <= Field_Size; i++)
	{
		for (int j = 1; j <= Field_Size; j++){
			cells[i][j] = cells_copy[i][j];
		}
	}
	int reaction;
	for (int i = 1; i <= Field_Size; i++)
	{
		for (int j = 1; j <= Field_Size; j++){
			if (cells[i][j] == '0'){
				if (cells[i - 1][j] != '0' && cells[i][j - 1] != '0' &&
					cells[i + 1][j] != '0' && cells[i][j + 1] != '0'){
					reaction = rand() % Probability;
					finished = false;
					if (reaction == 0 && cells_copy[i - 1][j] == '.'){
						cells_copy[i][j] = '.';
						cells_copy[i - 1][j] = '0';
					}
					else if (reaction == 1 && cells_copy[i][j - 1] == '.'){
						cells_copy[i][j] = '.';
						cells_copy[i][j - 1] = '0';
					}
					else if (reaction == 2 && cells_copy[i + 1][j] == '.'){
						cells_copy[i][j] = '.';
						cells_copy[i + 1][j] = '0';
					}
					else if (reaction == 3 && cells_copy[i][j + 1] == '.'){
						cells_copy[i][j] = '.';
						cells_copy[i][j + 1] = '0';
					}
				}
			}
		}
	}
	return finished;
}

void model(int Number_of_dislocations){
	int i = 0;
	bool finished = false;
	char cells[Field_Size + 2][Field_Size + 2];
	for (i = 1; i <= Field_Size; i++)
	{
		for (int j = 1; j <= Field_Size; j++){
			cells[i][j] = '.';
		}
	}
	for (i = 0; i <= Field_Size; i++)
	{
		cells[i + 1][Field_Size + 1] = 'b';
		cells[i][0] = 'b';
		cells[Field_Size + 1][i] = 'b';
		cells[0][i + 1] = 'b';

	}
	int x, y;
	for (i = 0; i < Number_of_dislocations; i++){
		x = rand() % Field_Size + 1;
		y = rand() % Field_Size + 1;
		cells[x][y] = '0';
	}
	while (!GetAsyncKeyState(VK_ESCAPE) && !finished){
		finished = loop_step(cells);
		visualisation(cells);
		//Sleep(200);
	}
	
	//system("pause");

}