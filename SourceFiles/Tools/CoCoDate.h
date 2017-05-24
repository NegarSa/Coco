#pragma once
#include <string>
#include <ctime>

class CoCoDate
{
public:
	CoCoDate();
	CoCoDate(int, int, int, int, int);
	~CoCoDate();
	std::string toString24();
	std::string toString12();
	// range check?
	void setYear(int);
	int getYear();
	void setMonth(int);
	int getMonth();
	void setDay(int);
	int getDay();
	void setHour(int);
	int getHour();
	void setMin(int);
	int getMin();
private:
	int year;
	int month;
	int day;
	int hour;
	int min;
};

