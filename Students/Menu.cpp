#include "Menu.h"

// Interaction

// PUBLIC

void Menu::Greeting()
{
	std::cout << "Hi! This is a regular project to practice some topics." << std::endl;
	std::cout << "It's made in C++ on OS Windows." << std::endl;
	std::cout << "This project is to record students in a file." << std::endl;
	std::cout << "Are they in school, are they entering school or are they graduates." << std::endl;
	std::cout << "Also their first name, last name, how old they are, their id." << std::endl;
	std::cout << "And that's about it." << std::endl;
}
// ++

std::string Menu::Enter_Name()
{
	Clear();
	std::string input{};
	std::cout << "Enter name: (Under 16 characters)" << std::endl;
	while (std::cin >> input)
	{
		if (input.size() > 16)
		{
			Clear();
			std::cout << "Enter name: (Under 16 characters)" << std::endl;
			continue;
		}
		if (!Is_String(input))
		{
			Clear();
			std::cout << "Enter name: (Under 16 characters)" << std::endl;
			continue;
		}
		if (!Is_Correct(input))
		{
			Clear();
			std::cout << "Enter name: (Under 16 characters)" << std::endl;
			continue;
		}
		else
		{
			break;
		}
	}
	return input;
}
// ++

std::string Menu::Enter_Last_Name()
{
	Clear();
	std::string input{};
	std::cout << "Enter last name: (Under 16 characters)" << std::endl;
	while (std::cin >> input)
	{
		if (input.size() > 16)
		{
			Clear();
			std::cout << "Enter last name: (Under 16 characters)" << std::endl;
			continue;
		}
		if (!Is_String(input))
		{
			Clear();
			std::cout << "Enter last name: (Under 16 characters)" << std::endl;
			continue;
		}
		if (!Is_Correct(input))
		{
			Clear();
			std::cout << "Enter last name: (Under 16 characters)" << std::endl;
			continue;
		}
		else
		{
			break;
		}
	}
	return input;

}
// ++

void Menu::Enter_Date_Of_Birth(int Date[])
{
	Clear();
	std::string input{};
	std::cout << "Enter date of birth: "
		<< std::endl
		<< "(Example: 01.02.2001)"
		<< std::endl
		<< "(Only 10 characters)"
		<< std::endl;
	while (std::cin >> input)
	{
		//01.02.2001
		if (input.size() != 10)
		{
			Clear();
			std::cout << "Enter date of birth: "
				<< std::endl
				<< "(Example: 01.02.2001)"
				<< std::endl
				<< "(Only 10 characters)"
				<< std::endl;
			continue;
		}
		if (!CheckDateSyntax(input))
		{
			Clear();
			std::cout << "Enter date of birth: "
				<< std::endl
				<< "(Example: 01.02.2001)"
				<< std::endl
				<< "(Only 10 characters)"
				<< std::endl;
			continue;
		}
		// Correct date
		else
		{
			Date::DATE date(input);
			if (!date.Is_Date())
			{
				Clear();
				std::cout << "Enter date of birth: "
					<< std::endl
					<< "(Example: 01.02.2001)"
					<< std::endl
					<< "(Only 10 characters)"
					<< std::endl;
				continue;
			}
			if (!Is_Correct(input))
			{
				Clear();
				std::cout << "Enter date of birth: "
					<< std::endl
					<< "(Example: 01.02.2001)"
					<< std::endl
					<< "(Only 10 characters)"
					<< std::endl;
				continue;
			}
			else
			{
				Date[0] = date.GetDay();
				Date[1] = date.GetMonth();
				Date[2] = date.GetYear();
				break;
			}
		}
	}
} 
// ++

int Menu::Enter_Age(Date::DATE& date)
{
	//Even if a person enters that a person is about to turn 17, 
	// it will put their age back one year, which is 16. 
	// And vice versa. Made against accidental user errors
	Clear();
	std::string input{};
	std::cout << "Enter age: (Under 2 characters)" << std::endl;
	while (std::cin >> input)
	{
		if (input.size() > 2)
		{
			Clear();
			std::cout << "Enter age: (Under 2 characters)" << std::endl;
			continue;
		}
		if (!Is_Number(input))
		{
			Clear();
			std::cout << "Enter age: (Under 2 characters)" << std::endl;
			continue;
		}
		if (!Is_Correct(input))
		{
			Clear();
			std::cout << "Enter age: (Under 2 characters)" << std::endl;
			continue;
		}
		else
		{
			// 17
			int Current_Year{ std::stoi(Date::Current_Time('Y')) }; // 2025
			int Birth_Year{ date.GetYear() }; // 2008
			int Been_Age{ Current_Year - Birth_Year }; // 2025 - 2008 = 17
			int Age{ std::stoi(input) };
			if (Been_Age == Age)
			{
				int Current_Month{ std::stoi(Date::Current_Time('m')) };
				int Birth_Month{ date.GetMonth() };
				if (Current_Month > Birth_Month)
				{
					return Age;
				}
				if (Current_Month < Birth_Month)
				{
					return Age - 1;
				}
				if (Current_Month == Birth_Month)
				{
					int Current_Day{ std::stoi(Date::Current_Time('d')) };
					int Birth_Day{ date.GetDay() };
					if (Current_Day > Birth_Day)
					{
						return Age;
					}
					if (Current_Day <= Birth_Day)
					{
						return Age - 1;
					}
				}
			}
			// 16
			if (Been_Age == Age + 1)
			{
				int Current_Month{ std::stoi(Date::Current_Time('m')) };
				int Birth_Month{ date.GetMonth() };
				if (Current_Month < Birth_Month)
				{
					return Age;
				}
				if (Current_Month > Birth_Month)
				{
					return Age + 1;
				}
				if (Current_Month == Birth_Month)
				{
					int Current_Day{ std::stoi(Date::Current_Time('d')) };
					int Birth_Day{ date.GetDay() };
					if (Current_Day > Birth_Day)
					{
						return Age + 1;
					}
					if (Current_Day <= Birth_Day)
					{
						return Age;
					}
				}
			}
			else
			{
				Clear();
				std::cout << "Enter age: (Under 2 characters)" << std::endl;
				continue;
			}
		}
	}
	return -1; // error
}
// ++

std::string Menu::Enter_Classroom()
{
	Clear();
	std::string input{};
	std::cout << "Enter classroom: (Under 3 characters)" << std::endl;
	while (std::cin >> input)
	{
		if (input.size() > 3|| input.size() < 2)
		{
			Clear();
			std::cout << "Enter classroom: (Under 3 characters)" << std::endl;
			continue;
		}
		if (!Is_Classroom(input))
		{
			Clear();
			std::cout << "Enter classroom: (Under 3 characters)" << std::endl;
			continue;
		}
		if (!Is_Correct(input))
		{
			Clear();
			std::cout << "Enter classroom: (Under 3 characters)" << std::endl;
			continue;
		}
		else
		{
			break;
		}
	}
	return input;
}
// ++

STATUS::State Menu::Enter_State()
{
	Clear();
	std::string input{};
	std::cout << "Enter state: " << std::endl;
	std::cout << "Graduate(0) " << std::endl;
	std::cout << "Study(1) " << std::endl;
	std::cout << "Admission(2) " << std::endl;
	while (std::cin >> input)
	{
		if (input.size() > 1)
		{
			Clear();
			std::cout << "Enter state: " << std::endl;
			std::cout << "Graduate(0) " << std::endl;
			std::cout << "Study(1) " << std::endl;
			std::cout << "Admission(2) " << std::endl;
			continue;
		}
		if (!Is_Number(input))
		{
			Clear();
			std::cout << "Enter state: " << std::endl;
			std::cout << "Graduate(0) " << std::endl;
			std::cout << "Study(1) " << std::endl;
			std::cout << "Admission(2) " << std::endl;
			continue;
		}
		if (!Is_Correct(input))
		{
			Clear();
			std::cout << "Enter state: " << std::endl;
			std::cout << "Graduate(0) " << std::endl;
			std::cout << "Study(1) " << std::endl;
			std::cout << "Admission(2) " << std::endl;
			continue;
		}
		else 
		{
			break;
		}
	}
	return Int_To_State(std::stoi(input));
}
// ++

void Menu::Information()
{

	std::cout << "  ###### ######## ##     ## ########  ######## ##    ## ######## ######  " << std::endl;
	std::cout << " ##    ##   ##    ##     ## ##     ## ##       ###   ##    ##   ##    ## " << std::endl;
	std::cout << " ##         ##    ##     ## ##     ## ##       ####  ##    ##   ##       " << std::endl;
	std::cout << " ######     ##    ##     ## ##     ## ######   ## ## ##    ##    ######   " << std::endl;
	std::cout << "      ##    ##    ##     ## ##     ## ##       ##  ####    ##         ##" << std::endl;
	std::cout << "##    ##    ##    ##     ## ##     ## ##       ##   ###    ##   ##    ##" << std::endl;
	std::cout << " ######     ##     #######  ########  ######## ##    ##    ##    ###### " << std::endl;
	std::cout << "\n" << std::endl;
	std::cout << "Write student(1)" << std::endl;
	std::cout << "List students(2)" << std::endl;
	std::cout << "Leave(0)" << std::endl;
}
// ++

void Menu::Pause()
{
	system("pause");
}
// ++

void Menu::Clear()
{
	system("cls");
}
// ++

bool Menu::Is_Number(const std::string TEXT)
{
	const std::string NUMBER{ "0123456789" };

	for (size_t i = 0; i < TEXT.size(); i++)
	{
		if (NUMBER.find(TEXT[i]) > NUMBER.size())
		{
			return false;
		}
	}
	return true;
}
// ++

std::string Menu::To_String_Date(const int Date[])
{
	std::string Date_S{};
	// 02.02.2008
	if (Date[0] < 10)
	{
		Date_S += "0" + std::to_string(Date[0])+'.';
	}
	else
	{
		Date_S += std::to_string(Date[0]) + '.';
	}
	if (Date[1] < 10)
	{
		Date_S += "0" + std::to_string(Date[1]) + '.';
	}
	else
	{
		Date_S += std::to_string(Date[1]) + '.';
	}
	Date_S += std::to_string(Date[2]);
	return Date_S;
}
// ++


// PRIVATE

bool Menu::Is_String(const std::string TEXT)
{
	const std::string ALPHABET{ "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz" };
	for (size_t i = 0; i < TEXT.size(); i++)
	{
		if (ALPHABET.find(TEXT[i]) > ALPHABET.size()) {
			return false;
		}
	}
	return true;
}
// ++

bool Menu::Is_Classroom(const std::string TEXT)
{
	//Проверяет, есть ли заглавные буквы, находятся ли они на втором или третьем месте и есть ли цифры.
	const std::string CAPITAL_LETTERS{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	const std::string NUMBER{ "123456789" };
	for (size_t i = 0; i < TEXT.size(); i++)
	{
		const std::string CAPITAL_LETTERS_AND_NUMBER{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789" };
		if (CAPITAL_LETTERS_AND_NUMBER.find(TEXT[i]) > CAPITAL_LETTERS_AND_NUMBER.size())
		{
			return false;
		}
	}
	if (NUMBER.find(TEXT[1]) <= NUMBER.size())
	{
		// 11A
		for (size_t i = 0; i < 2; i++)
		{
			if (NUMBER.find(TEXT[i]) > NUMBER.size())
			{
				return false;
			}
		}
		if (CAPITAL_LETTERS.find(TEXT[2]) > CAPITAL_LETTERS.size())
		{
			return false;
		}
	}
	if (CAPITAL_LETTERS.find(TEXT[1])<=CAPITAL_LETTERS.size())
	{
		// 9A
		if (NUMBER.find(TEXT[0]) > NUMBER.size())
		{
			return false;
		}
		if (CAPITAL_LETTERS.find(TEXT[1]) > CAPITAL_LETTERS.size())
		{
			return false;
		}
		if (TEXT[2]!='\0')
		{
			return false;
		}
	}
	return true;
}
// ++

bool Menu::CheckDateSyntax(const std::string TEXT)
{
	// Checks for correctness of writing
	for (size_t i = 0; i < TEXT.size(); i++)
	{
		if (i == 2 || i == 5)
		{
			if (TEXT[i] != '.')
			{
				return false;
			}
		}
		else
		{
			if (!Is_Number(TEXT[i]))
			{
				return false;
			}
		}
	}
	return true;
}
// ++

bool Menu::Is_Number(const char CHAR)
{
	const std::string NUMBER{ "0123456789" };
	if (NUMBER.find(CHAR) > NUMBER.size())
	{
		return false;
	}
	return true;
}
// ++

bool Menu::Is_Answer(const std::string TEXT)
{
	std::string ANSWER{ "YyNn" };
	if (ANSWER.find(TEXT[0])>ANSWER.size())
	{
		return false;
	}
	return true;
}
// ++

bool Menu::Is_Correct(const std::string TEXT)
{
	Clear();
	std::string input{};
	std::cout << TEXT << " correct? (Y/y or N/n)" << std::endl;
	while (std::cin >> input)
	{
		if (input.size() > 1)
		{
			Clear();
			std::cout << TEXT << " correct? (Y/y or N/n)" << std::endl;
			continue;
		}
		if (!Is_Answer(input))
		{
			Clear();
			std::cout << TEXT << " correct? (Y/y or N/n)" << std::endl;
			continue;
		}
		switch (input[0])
		{
		case 'Y':
			return true;
			break;
		case 'N':
			return false;
			break;
		case 'y':
			return true;
			break;
		case 'n':
			return false;
			break;
		}
	}
	return true;
}
// ++

STATUS::State Menu::Int_To_State(const int num)
{	
	switch (num)
	{
	case 0:
		return STATUS::Graduate;
		break;
	case 1:
		return STATUS::Study;
		break;
	case 2:
		return STATUS::Admission;
		break;
	default:
		break;
	}
	return STATUS::Admission;
}
// ++
