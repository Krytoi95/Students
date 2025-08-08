#include "DATE.h"


std::string Date::Current_Time(const char current)
{
	// 'Y' = year, 'm' == month, 'd' == day, 'f'==full
	std::time_t now1{ std::time(nullptr) };
	std::tm timeinfo;
	localtime_s(&timeinfo, &now1);
	char buffer[11];
	switch (current)
	{
	case'Y':
		std::strftime(buffer, sizeof(buffer), "%Y", &timeinfo);
		break;
	case 'm':
		std::strftime(buffer, sizeof(buffer), "%m", &timeinfo);
		break;
	case'd':
		std::strftime(buffer, sizeof(buffer), "%d", &timeinfo);
		break;
	case 'f':
		std::strftime(buffer, sizeof(buffer), "%d.%m.%Y", &timeinfo);
		break;
	default:
		break;
	}
	return static_cast<std::string>(buffer);
}
// ++
Date::DATE::DATE(const std::string DATE)
{
	// 01.02.2001
	std::string Day{ DATE,0,2 };
	// 01
	std::string Month{ DATE,3,2 };
	// 02
	std::string Year{ DATE,6,4 };
	// 2001
	this->Day = std::stoi(Day);
	this->Month = std::stoi(Month);
	this->Year = std::stoi(Year);
}
// ++
int Date::DATE::Return_Amount_Days(const int num)
{
	switch (num)
	{
	case 1:
		return MONTHS_AMOUNT_DAYS::January;
	case 2:
		return MONTHS_AMOUNT_DAYS::February;
	case 3:
		return MONTHS_AMOUNT_DAYS::March;
	case 4:
		return MONTHS_AMOUNT_DAYS::April;
	case 5:
		return MONTHS_AMOUNT_DAYS::May;
	case 6:
		return MONTHS_AMOUNT_DAYS::June;
	case 7:
		return MONTHS_AMOUNT_DAYS::July;
	case 8:
		return MONTHS_AMOUNT_DAYS::August;
	case 9:
		return MONTHS_AMOUNT_DAYS::September;
	case 10:
		return MONTHS_AMOUNT_DAYS::October;
	case 11:
		return MONTHS_AMOUNT_DAYS::November;
	case 12:
		return MONTHS_AMOUNT_DAYS::December;
	}
	return -1;
}
// ++
bool Date::DATE::Is_Leap_Year()
{
	if (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0)
	{
		return true;
	}
	return false;
}
// ++
bool Date::DATE::Is_Date()
{
	if (!Check_Month(Month))
	{
		return false;
	}

	if (Month == 2)
	{
		if (Is_Leap_Year())
		{
			if (Day > (Return_Amount_Days(Month)+1) || Day <= 0)
			{
				return false;
			}
			if (Year < 1925 || Year>std::stoi(Current_Time('Y')))
			{
				return false;
			}
			return true;
		}
	}

	if (Day > Return_Amount_Days(Month) || Day <= 0)
	{
		return false;
	}

	if (Year < 1925||Year>std::stoi(Current_Time('Y')))
	{
		return false;
	}

	return true;
}
// ++
// Check correct date

bool Date::DATE::Check_Month(const int month)
{
	switch (month)
	{
	case 1:
		return true;
	case 2:
		return true;
	case 3:
		return true;
	case 4:
		return true;
	case 5:
		return true;
	case 6:
		return true;
	case 7:
		return true;
	case 8:
		return true;
	case 9:
		return true;
	case 10:
		return true;
	case 11:
		return true;
	case 12:
		return true;
	default:
		return false;
	}
	return false;
}
// ++
int Date::DATE::GetDay()
{
	return Day;
}
// ++
int Date::DATE::GetMonth()
{
	return Month;
}
// ++
int Date::DATE::GetYear()
{
	return Year;
}
// ++
void Date::DATE::InfoDate()
{
	std::cout << "Day: " << Day << "\nMonth: " << Month << "\nYear: " << Year << std::endl;
}
// ??