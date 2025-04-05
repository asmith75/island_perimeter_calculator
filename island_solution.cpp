#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/*
* calcualtes perimeter for island
* @param grid consist of 0s represents water and 1s represents 
* @return perimeter of island as unsigned int
*/
int calc_perimeter(const vector<vector<unsigned int>>& grid) {
	int perimeter = 0;
	size_t rows = grid.size();
	size_t cols = grid[0].size();

	//check each neighbor and subtract sides
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			if (grid[i][j] == 1) {
				perimeter += 4;

				if (i > 0 && grid[i - 1][j] == 1) perimeter--;
				if (i < rows - 1 && grid[i + 1][j] == 1) perimeter--;
				if (j > 0 && grid[i][j - 1] == 1) perimeter--;
				if (j < cols - 1 && grid[i][j + 1] == 1) perimeter--;
			}
		}
	}
	return perimeter;
}

int main() {
	ifstream inputFile("island_2.txt");
	ofstream outputFile("perimeter_1.txt");


	//check input file opened 
	if (!inputFile.is_open() || !outputFile.is_open()) {
		cout << "Error: Unable to open file!" << endl;
		return 1;
	}

	//read rows and cols
	int rows, cols;
	inputFile >> rows >> cols;

	//make 2d vector with given dimensions
	vector<vector<unsigned int>> grid(rows, vector<unsigned int>(cols));

	//read values from file to fill grid
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			inputFile >> grid[i][j];
		}
	}

	//call calc_permeter func
	int perimeter = calc_perimeter(grid);

	//write result to output file
	outputFile << "Perimeter: " << perimeter << endl;

	//close files
	inputFile.close();
	outputFile.close();

	return 0;
}