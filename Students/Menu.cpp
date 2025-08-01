#include "Menu.h"

// Interaction
void Menu::Greeting()
{
	std::cout << "Hi! This is a regular project to practice some topics." << std::endl;
	std::cout << "It's made in C++ on OS Windows." << std::endl;
	std::cout << "This project is to record students in a file." << std::endl;
	std::cout << "Are they in school, are they entering school or are they graduates." << std::endl;
	std::cout << "Also their first name, last name, how old they are, their id." << std::endl;
	std::cout << "And that's about it." << std::endl;
}

std::string Menu::Enter_Name()
{
	Clear();
	std::string input{};
	std::cout << "Enter name: " << std::endl;
	while (std::cin >> input)
	{
		if (!Is_String(input))
		{
			Clear();
			std::cout << "Enter name: " << std::endl;
			continue;
		}
		else
		{
			break;
		}
	}
	return input;
}

std::string Menu::Enter_Last_Name()
{
	Clear();
	std::string input{};
	std::cout << "Enter last name: " << std::endl;
	while (std::cin >> input)
	{
		if (!Is_String(input))
		{
			Clear();
			std::cout << "Enter last name: " << std::endl;
			continue;
		}
		else
		{
			break;
		}
	}
	return input;

}

std::string Menu::Enter_Date_Of_Birth()
{
	Clear();
	std::string input{};
	std::string Date_Of_Birth{};
	std::cout << "Enter date of birth: " << std::endl;
	std::cout << std::endl;
	// Day
	std::cout << "Enter day: " << std::endl;
	while (std::cin >> input)
	{
		if (!Is_Number(input))
		{
			Clear();
			std::cout << "Enter date of birth: " << std::endl;
			std::cout << std::endl;
			std::cout << "Enter day: " << std::endl;
			continue;
		}
		if (input.size() > 2)
		{
			Clear();
			std::cout << "Enter date of birth: " << std::endl;
			std::cout << std::endl;
			std::cout << "Enter day: " << std::endl;
			continue;
		}
		if (std::stoi(input)>31||std::stoi(input)<1)
		{
			Clear();
			std::cout << "Enter date of birth: " << std::endl;
			std::cout << std::endl;
			std::cout << "Enter day: " << std::endl;
			continue;
		}
		Date_Of_Birth += input + ".";
		break;
	}
	//Month
	Clear();
	std::cout << "Enter date of birth: " << std::endl;
	std::cout << std::endl;
	std::cout << "Enter month: " << std::endl;
	while (std::cin >> input)
	{
		if (!Is_Number(input))
		{
			Clear();
			std::cout << "Enter date of birth: " << std::endl;
			std::cout << std::endl;
			std::cout << "Enter month: " << std::endl;
			continue;
		}
		if (input.size() > 2)
		{
			Clear();
			std::cout << "Enter date of birth: " << std::endl;
			std::cout << std::endl;
			std::cout << "Enter month: " << std::endl;
			continue;
		}
		if (std::stoi(input) > 12 || std::stoi(input) < 1)
		{
			Clear();
			std::cout << "Enter date of birth: " << std::endl;
			std::cout << std::endl;
			std::cout << "Enter month: " << std::endl;
			continue;
		}
		Date_Of_Birth += input + ".";
		break;
	}
	//Year
	Clear();
	std::cout << "Enter date of birth: " << std::endl;
	std::cout << std::endl;
	std::cout << "Enter year: " << std::endl;
	while (std::cin >> input)
	{
		if (!Is_Number(input))
		{
			Clear();
			std::cout << "Enter date of birth: " << std::endl;
			std::cout << std::endl;
			std::cout << "Enter year: " << std::endl;
			continue;
		}
		if (input.size() > 4)
		{
			Clear();
			std::cout << "Enter date of birth: " << std::endl;
			std::cout << std::endl;
			std::cout << "Enter year: " << std::endl;
			continue;
		}
		if (std::stoi(input) < 1925)
		{
			// I chose this year(1925) because I don't think people that old need uni.
			Clear();
			std::cout << "Enter date of birth: " << std::endl;
			std::cout << std::endl;
			std::cout << "Enter year: " << std::endl;
			continue;
		}
		Date_Of_Birth += input;
		break;
	}
	return Date_Of_Birth;
}
void Menu::Enter_Age(int &Age)
{
	std::cout << "Enter age: " << std::endl;
}
std::string Menu::Enter_Classroom()
{
	std::cout << "Enter classroom: " << std::endl;
	return "5";
}
std::string Menu::Enter_State()
{
	std::cout << "Enter state: " << std::endl;
	return "5";
}

void Menu::Information()
{
	std::cout << "Write student(1)" << std::endl;
	std::cout << "List students(2)" << std::endl;
	std::cout << "Leave(0)" << std::endl;
}

void Menu::Pause()
{
	system("pause");
}
void Menu::Clear()
{
	system("cls");
}

void Menu::Sleeping(const int TIMER)
{
	Sleep(TIMER);
}

bool Menu::Is_Number(const std::string TEXT)
{
	const std::string NUMBER{ "0123456789" };

		if (NUMBER.find(TEXT[0]) > NUMBER.size())
		{
			return false;
		}
	return true;
}

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

bool Menu::Is_Date(const std::string TEXT)
{
	// 14.10.2008
	// Checking in for a high-season year
	return false;
}
