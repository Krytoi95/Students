#pragma once

#ifndef DATE_H

#define DATE_H

#include <iostream>
#include <string>
#include <ctime>

namespace Date
{
	enum MONTHS_AMOUNT_DAYS
	{
		January = 31,
		February = 28,
		March = 31,
		April = 30,
		May = 31,
		June = 30,
		July = 31,
		August = 31,
		September = 30,
		October = 31,
		November = 30,
		December = 31
	};

	std::string Current_Time(const char current);
	
	class DATE
	{
	public:

		DATE(const std::string DATE);
		
		int Return_Amount_Days(const int num);
		
		bool Is_Leap_Year();
		
		bool Is_Date();
		// Check correct date

		bool Check_Month(const int month);
		
		int GetDay();
		int GetMonth();
		int GetYear();
		
		void InfoDate();
		
	private:
		int Day{};
		int Month{};
		int Year{};
	};
}

#endif
