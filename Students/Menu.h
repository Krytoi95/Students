#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
class Menu
{
public:
	void Greeting();
	void Information();

	std::string Enter_Name();
	std::string Enter_Last_Name();
	std::string Enter_Date_Of_Birth();
	void Enter_Age(int& Age);
	std::string Enter_Classroom();
	std::string Enter_State();

	void Pause();
	void Clear();

	void Sleeping(const int TIMER);

	bool Is_Number(const std::string TEXT);

	bool Is_String(const std::string TEXT);

	bool Is_Date(const std::string TEXT);

	bool Date(const std::string TEXT)
	{
		// 14.10.2008
		enum Month
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
		int Day{};
		int Month{};
		int Year{};
		// Day

		std::cout << Day << std::endl;
		return true;
	}


private:

};