#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class DynamicArray {
private:
	static const unsigned int DEFAULT_CAPACITY = 10;
	unsigned int capacity; //max capacity ofarray
	unsigned int num_of_items; // number of elements
	unsigned int* data;

	void resize() {
		capacity *= 2;
		unsigned int* newData = new unsigned int[capacity];
		for (unsigned int i = 0; i < num_of_items; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
	}

public: 
	
	//Default constructor initiliazes an empty array w/ default capacity
	DynamicArray() : capacity(DEFAULT_CAPACITY), num_of_items(0) {
		data = new unsigned int[capacity];
	}

	//copy constructor -> deep copy
	DynamicArray(const DynamicArray& other) : capacity(other.capacity), num_of_items(other.num_of_items) {
		data = new unsigned int[capacity];
		for (unsigned int i = 0; i < num_of_items; i++) {
			data[i] = other.data[i];
		}
	}

	//destrcutor to deallocate data
	~DynamicArray() {
		delete[] data;
	}

	//overload assignment operator
	DynamicArray& operator=(const DynamicArray& other) {
		if (this != &other) {
			delete[] data;
			capacity = other.capacity;
			num_of_items = other.num_of_items;
			data = new unsigned int[capacity];
			for (unsigned int i = 0; i < num_of_items; i++) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}

	//overload sbscript operator for rvalue
	unsigned int operator[](unsigned int index) const {
		return data[index];
	}

	//overload subscript operator for lvalue
	unsigned int& operator[](unsigned int index) {
		return data[index];
	}

	//returns the number of elements in the array
	unsigned int size() const {
		return num_of_items;
	}

	//check if array is empty
	bool empty() const {
		return num_of_items == 0;
	}

	//adds new element to the arrray resizing if needed
	void push_back(unsigned int value) {
		if (num_of_items >= capacity) {
			resize();
		}
		data[num_of_items++] = value;
	}

	//removes last element from array
	void pop_back() {
		if (!empty()) {
			num_of_items--;
		}
	}

};

//process commands from input file and writes invalid commans to output fiole

int main() {
	DynamicArray arr;
	ifstream inputFile("commands_2.txt");
	ofstream outputFile("invalid.txt");
	outputFile << "INVALID COMMANDS" << endl;
	string line;
	unsigned int commandID;
	string command;
	int value;

	while (inputFile >> commandID >> command) {
		if (command == "PUSH") {
			if (inputFile >> value) {
				if (value < 0) {  // Explicitly check for negative values
					outputFile << commandID << endl;
				}
				else {
					arr.push_back(static_cast<unsigned int>(value));
				}
			}
			else {
				outputFile << commandID << endl;
				inputFile.clear();
				inputFile.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		else if (command == "POP") {
			if (arr.empty()) {
				outputFile << commandID << endl;
			}
			else {
				arr.pop_back();
			}
		}
		else {
			outputFile << commandID << endl;
		}
	}

	inputFile.close();
	outputFile.close();
	return 0;

}