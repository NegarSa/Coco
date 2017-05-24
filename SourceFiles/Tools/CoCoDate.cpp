#include "CoCoDate.h"



CoCoDate::CoCoDate()
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	setYear(1900 + ltm->tm_year);
	setMonth(1 + ltm->tm_mon);
	setDay(ltm->tm_mday);
	setHour(ltm->tm_hour);
	setMin(ltm->tm_min);
	return;
}

CoCoDate::CoCoDate(int y, int m, int d, int h, int mi)
{
	setYear(y);
	setMonth(m);
	setDay(d);
	setHour(h);
	setMin(mi);
	return;
}


CoCoDate::~CoCoDate()
{
	return;
}

std::string CoCoDate::toString24()
{
	static char* monthsOfYear[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "July", "Aug", "Sep", "Oct", "Nov", "Dec" };
	std::string out;
	out += std::to_string(day);
	out += "th ";
	out += monthsOfYear[month - 1];
	out += " ";
	out += std::to_string(year);
	out += " - ";
	out += std::to_string(hour);
	out += ":";
	out += std::to_string(min);
	return out;
}

std::string CoCoDate::toString12()
{
	static char* monthsOfYear[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "July", "Aug", "Sep", "Oct", "Nov", "Dec" };
	std::string out;
	out += std::to_string(day);
	out += "th ";
	out += monthsOfYear[month - 1];
	out += " ";
	out += std::to_string(year);
	out += " - ";
	int h = (hour != 12 ? hour % 12 : 12);
	out += std::to_string(h);
	out += ":";
	out += std::to_string(min);
	out += (hour >= 12 ? "(PM)" : "(AM)");
	return out;
}

void CoCoDate::setYear(int y)
{
	year = y;
}

int CoCoDate::getYear()
{
	return year;
}

void CoCoDate::setMonth(int m)
{
	month = m;
}

int CoCoDate::getMonth()
{
	return month;
}

void CoCoDate::setDay(int d)
{
	day = d;
}

int CoCoDate::getDay()
{
	return day;
}

void CoCoDate::setHour(int h)
{
	hour = h;
}

int CoCoDate::getHour()
{
	return hour;
}

void CoCoDate::setMin(int m)
{
	min = m;
}

int CoCoDate::getMin()
{
	return min;
}
