#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include "DATE.h"
#include "Student.h"
class Menu
{
public:
	void Greeting();
	void Information();

	std::string Enter_Name();
	std::string Enter_Last_Name();
	void Enter_Date_Of_Birth(int Date[]);
	int Enter_Age(Date::DATE& date);
	std::string Enter_Classroom();
	STATUS::State Enter_State();

	void Pause();
	void Clear();

	bool Is_Number(const std::string TEXT);

	std::string To_String_Date(const int Date[]);

private:

	bool Is_String(const std::string TEXT);

	bool Is_Classroom(const std::string TEXT);

	bool Is_Number(const char CHAR);

	bool CheckDateSyntax(const std::string TEXT);

	bool Is_Correct(const std::string TEXT);
	bool Is_Answer(const std::string TEXT);

	STATUS::State Int_To_State(const int num);

	
};