// Jimmy Liu
// Project 6
// 16 Nov. 2015
// XCode 7.0

// Specification file for the CountryList class
#ifndef CountryList_H
#define CountryList_H
using namespace std;

class NumDays {
	private:
		double daysCount;
		void calculate(int);
	public:
		NumDays();
		NumDays(int);
		NumDays(double);
		void setHour(int);
		double getDay() const;
		NumDays operator+(const NumDays&);
		NumDays operator-(const NumDays&);
		NumDays operator++(int);
		NumDays operator--(int);
};

#endif