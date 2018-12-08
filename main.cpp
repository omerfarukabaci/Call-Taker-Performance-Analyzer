#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include "Employee.h"
#include "Heap.cpp"

using namespace std;

int main() {
	Heap<Employee> bestPerformance(MAX_HEAP);
	Heap<Employee> maximumCalls(MAX_HEAP);
	Heap<Employee> worstPerformance(MIN_HEAP);
	Heap<Employee> minimumCalls(MIN_HEAP);
	ifstream inputFile;
	string data;
	char fileName[20];
	strcpy(fileName, "day1.csv");
	int id = 0;
	int numberOfCalls = 0;
	int positiveFeedback = 0;
	int negativeFeedback = 0;
	Employee employee;

	for (int i = 1; i <= 10; i++) {
		if (i != 10) {
			inputFile.open(fileName);
			fileName[3]++;
		}
		else {
			strcpy(fileName, "day10.csv");
			inputFile.open(fileName);
		}

		if (inputFile.good()) {
			while (!inputFile.eof()) {
				getline(inputFile, data, ',');
				if (data == "") break;
				id = atoi(data.c_str());
				employee.setId(id);

				getline(inputFile, data, ',');
				numberOfCalls = atoi(data.c_str());
				employee.setNumberOfCalls(numberOfCalls);

				getline(inputFile, data, ',');
				positiveFeedback = atoi(data.c_str());
				employee.setPositiveFeedback(positiveFeedback);

				getline(inputFile, data, '\n');
				negativeFeedback = atoi(data.c_str());
				employee.setNegativeFeedback(negativeFeedback);

				employee.calculatePerformanceScore();
				employee.setCompareBy(PERFORMANCE_SCORE);

				bestPerformance.insert(employee);
				worstPerformance.insert(employee);

				employee.setCompareBy(CALLS);

				maximumCalls.insert(employee);
				minimumCalls.insert(employee);
			}
		}
		else
			cout << "FILE ERROR!" << endl;

		inputFile.close();

		bestPerformance.buildMaxHeap();
		worstPerformance.buildMinHeap();
		maximumCalls.buildMaxHeap();
		minimumCalls.buildMinHeap();

		std::cout << "AFTER DAY-" << i << endl;
		cout << "BEST PERFORMANCE" << setw(3) << ": ";
		bestPerformance.printMax3();
		cout << "WORST PERFORMANCE" << setw(2) << ": ";
		worstPerformance.printMin3();
		cout << "MAXIMUM CALLS" << setw(6) << ": ";
		maximumCalls.printMax3();
		cout << "MINIMUM CALLS" << setw(6) << ": ";
		minimumCalls.printMin3();
		std::cout << endl;
	}

	return 0;
}