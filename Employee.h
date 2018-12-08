#include <ostream>

enum CompareBy {
	PERFORMANCE_SCORE,
	CALLS
};

class Employee {
	int id;
	int numberOfCalls;
	int positiveFeedback;
	int negativeFeedback;
	int performanceScore;
	CompareBy compareBy;

public:

	Employee();
	Employee(int id, int numberOfCalls, int positiveFeedback, int negativeFeedback, CompareBy compareBy);
	Employee & operator=(const Employee & e1);
	Employee & operator=(const int i);
	Employee operator+(const Employee & e1);
	Employee & operator+=(const Employee & e1);
	bool operator==(const Employee & e1);
	bool operator==(const int i);
	bool operator>(const Employee & e1);
	bool operator<(const Employee & e1);
	bool operator>=(const Employee & e1);
	bool operator<=(const Employee & e1);
	bool operator!=(const int i);
	friend std::ostream& operator<<(std::ostream &os, const Employee &employee);
	int getId() const;
	int getNumberOfCalls() const;
	int getPerformanceScore() const;
	void setId(int input);
	void setNumberOfCalls(int input);
	void setPositiveFeedback(int input);
	void setNegativeFeedback(int input);
	void setCompareBy(CompareBy input);
	void calculatePerformanceScore();
};