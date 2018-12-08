#include "Employee.h"
#include <iostream>

Employee::Employee() {
	id = -1;
	numberOfCalls = 0;
	positiveFeedback = 0;
	negativeFeedback = 0;
	performanceScore = 0;
	compareBy = PERFORMANCE_SCORE;
}

Employee::Employee(int id, int numberOfCalls, int positiveFeedback, int negativeFeedback, CompareBy compareBy) {
	this->id = id;
	this->numberOfCalls = numberOfCalls;
	this->positiveFeedback = positiveFeedback;
	this->negativeFeedback = negativeFeedback;
	this->compareBy = compareBy;
	calculatePerformanceScore();

}

int Employee::getId() const{
	return id;
}

int Employee::getNumberOfCalls() const{
	return numberOfCalls;
}

int Employee::getPerformanceScore() const{
	return performanceScore;
}

void Employee::setId(int input) {
	id = input;
}

void Employee::setNumberOfCalls(int input){
	numberOfCalls = input;
	calculatePerformanceScore();
}

void Employee::setPositiveFeedback(int input) {
	positiveFeedback = input;
	calculatePerformanceScore();
}

void Employee::setNegativeFeedback(int input) {
	negativeFeedback = input;
	calculatePerformanceScore();
}

void Employee::setCompareBy(CompareBy input) {
	compareBy = input;
}

void Employee::calculatePerformanceScore() {
	performanceScore = ((2 * numberOfCalls) + positiveFeedback - negativeFeedback);
}

Employee& Employee::operator=(const Employee & e1) {
	this->id = e1.id;
	this->numberOfCalls = e1.numberOfCalls;
	this->positiveFeedback = e1.positiveFeedback;
	this->negativeFeedback = e1.negativeFeedback;
	this->performanceScore = e1.performanceScore;
	this->compareBy = e1.compareBy;

	return *this;
}

Employee& Employee::operator=(const int i) {
	this->id = i;
	this->numberOfCalls = 0;
	this->positiveFeedback = 0;
	this->negativeFeedback = 0;
	this->performanceScore = 0;
	this->compareBy = PERFORMANCE_SCORE;

	return *this;
}

Employee & Employee::operator+=(const Employee & e1) {
	this->numberOfCalls += e1.numberOfCalls;
	this->positiveFeedback += e1.positiveFeedback;
	this->negativeFeedback += e1.negativeFeedback;
	calculatePerformanceScore();

	return *this;
}

Employee Employee::operator+(const Employee & e1) {
	Employee result;
	result.id = this->id;
	result.numberOfCalls = this->numberOfCalls + e1.numberOfCalls;
	result.positiveFeedback = this->positiveFeedback + e1.positiveFeedback;
	result.negativeFeedback = this->negativeFeedback + e1.negativeFeedback;
	result.compareBy = this->compareBy;
	result.calculatePerformanceScore();

	return result;
}

bool Employee::operator==(const Employee & e1) {
	return (this->id == e1.id);
}

bool Employee::operator==(const int i) {
	return (this->id == i);
}

bool Employee::operator>(const Employee & e1){
	if (compareBy == CALLS)
		return(this->numberOfCalls > e1.numberOfCalls);

	return (this->performanceScore > e1.performanceScore);

}

bool Employee::operator<(const Employee & e1){
	if (compareBy == CALLS)
		return(this->numberOfCalls < e1.numberOfCalls);

	return (this->performanceScore < e1.performanceScore);
}

bool Employee::operator>=(const Employee & e1) {
	if (compareBy == CALLS)
		return(this->numberOfCalls >= e1.numberOfCalls);

	return (this->performanceScore >= e1.performanceScore);
}

bool Employee::operator<=(const Employee & e1){
	if (compareBy == CALLS)
		return(this->numberOfCalls <= e1.numberOfCalls);

	return (this->performanceScore <= e1.performanceScore);
}

bool Employee::operator!=(const int i) {
	return (this->id != i);
}

std::ostream& operator<<(std::ostream &os, const Employee &employee) {
	os << employee.getId();
	return os;
}