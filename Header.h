#include <iostream>
#include <cassert>

struct Date
{
	short Day;
	short Month;
	short Year;
};

void ImputDay(Date &_ptr);
void ImputMonth(Date &_ptr);
void ImputYear(Date &_ptr);

void Cheñk(Date _ptr);

void Output(Date _ptr);

int JulianDay(Date _ptr);
int GregorianDay(Date _ptr);

void FindZodiac(Date _ptr);