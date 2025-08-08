#include "Student.h"

// Static variable

int Student::ID = 0;

// Public Functions

// Constructor
Student::Student() {}
Student::Student(const std::string Name, const std::string Last_Name, const int Date[], const int Age, const std::string Classroom, const STATUS::State state)
{
	this->Name = Name;
	this->Last_Name = Last_Name;
	for (size_t i = 0; i < 3; i++)
	{
		this->Date_Of_Birth[i] = Date[i];
	}
	this->Age = Age;
	this->Classroom = Classroom;
	this->state = state;
	ID_Student = ID++;
}

// Info
void Student::Info()
{
	std::cout << "Student: " << ID_Student << std::endl;
	std::cout << "Name: " << Name << std::endl;
	std::cout << "Last name: " << Last_Name << std::endl;
	std::cout << "Date of birth: " << Date_Of_Birth_To_String() << std::endl;
	std::cout << "Age: " << Age << std::endl;
	std::cout << "Classroom: " << Classroom << std::endl;
	std::cout << "State: " << State_To_String() << std::endl;
}

// File Handling
void Student::Write_Student_In_File() 
{
	std::ofstream WriteInfoInFile;
	WriteInfoInFile.open("ListStudents.txt", std::ofstream::app);
	/*WriteInfoInFile.write(reinterpret_cast<char*>(&str), sizeof(std::string));*/
	WriteInfoInFile << "\nStudent: " << ID_Student << std::endl;
	WriteInfoInFile << "Name: " << Name << std::endl;
	WriteInfoInFile << "Last name: " <<Last_Name << std::endl;
	WriteInfoInFile << "Date of birth: " << Date_Of_Birth_To_String() << std::endl;
	WriteInfoInFile << "Age: " << Age << std::endl;
	WriteInfoInFile << "Classroom: " << Classroom << std::endl;
	WriteInfoInFile << "State: " << state << std::endl;
	WriteInfoInFile.close();
}
void Student::Write_Student_From_File(const int ID)
{
	std::string buffer{};
	int i{};
	int StartPoint{Search_ID(ID)};
	std::ifstream ReadInfoFromFile;
	ReadInfoFromFile.open("ListStudents.txt");
	while (std::getline(ReadInfoFromFile, buffer))
	{
		if (StartPoint == i)
		{
			this->ID_Student = std::stoi(buffer.erase(0, 9));

			std::getline(ReadInfoFromFile, buffer);
			this->Name = buffer.erase(0, 6);

			std::getline(ReadInfoFromFile, buffer);
			this->Last_Name = buffer.erase(0, 11);

			std::getline(ReadInfoFromFile, buffer);
			buffer.erase(0, 15);
			std::string Day{buffer.erase(2,10)};
			buffer.erase(0, 3);
			std::string Mouth{buffer.erase(2,7)};
			buffer.erase(0, 3);
			std::string Year{ buffer };
			this->Date_Of_Birth[0] = std::stoi(Day);
			this->Date_Of_Birth[1] = std::stoi(Mouth);
			this->Date_Of_Birth[2] = std::stoi(Year);

			std::getline(ReadInfoFromFile, buffer);
			this->Age = std::stoi(buffer.erase(0, 5));

			std::getline(ReadInfoFromFile, buffer);
			this->Classroom = buffer.erase(0, 11);

			std::getline(ReadInfoFromFile, buffer);
			this->state = (STATUS::State)std::stoi(buffer.erase(0,7));
			break;
		}
		i++;
	}
}

void Student::Write_Student_From_File()
{

}

void Student::Read_Student_From_File(Student&student) 
{
	std::ifstream File;
	std::string buffer{};
	int i{};
	File.open("ListStudents.txt");
	while (std::getline(File,buffer))
	{
		if (i == 1)
		{

		}
		i++;
	}
}

// Private Functions

std::string Student::Date_Of_Birth_To_String ()
{
	return std::to_string(Date_Of_Birth[0]) + "." + std::to_string(Date_Of_Birth[1]) + "." + std::to_string(Date_Of_Birth[2]);
}
std::string Student::State_To_String()
{
	switch (state)
	{
	case 0:
		return "Graduate";
	case 1:
		return "Study";
	case 2:
		return "Admission";
	}
	return "";
}



int Student::Search_ID(const Student& student)
{
	int ID{};
	int i{};
	std::string buffer{};
	std::ifstream ReadInfoFromFile;
	ReadInfoFromFile.open("ListStudents.txt");
	while (std::getline(ReadInfoFromFile, buffer))
	{
		if (i == 1)
		{
			buffer.erase(0,9);
			ID = std::stoi(buffer);
			if (Comparison_ID(student.ID_Student, ID))
			{
				return ID;
			}
			i -= 8;
		}
		i++;
	}
	ReadInfoFromFile.close();
	return ID;
}

int Student::Search_ID(const int ID)
{
	int i{};
	int StartPoint{1};
	std::string buffer{};
	std::ifstream ReadInfoFromFile;
	ReadInfoFromFile.open("ListStudents.txt");
	while (std::getline(ReadInfoFromFile, buffer))
	{
		if (StartPoint==i)
		{
			buffer.erase(0, 9);
			if (Comparison_ID(ID, std::stoi(buffer)))
			{
				return StartPoint;
			}
			StartPoint += 8;
		}
		i++;
	}
	return StartPoint;
}

bool Student::Comparison_ID(const int FIRST_COMPARISON_ID, const int SECOND_COMPARISON_ID)
{
	if(FIRST_COMPARISON_ID==SECOND_COMPARISON_ID)
	{
		return true;
	}
	return false;
}




void Student::Initialisation_ID() //////////////////////////
{
	int ID{};
	int i{};
	std::string buffer{};
	std::ifstream ReadInfoFromFile;
	ReadInfoFromFile.open("ListStudents.txt");
	while (std::getline(ReadInfoFromFile, buffer))
	{
		if (i == 1)
		{
			buffer.erase(0, 9);
			ID = std::stoi(buffer);
			i -= 8;
		}
		i++;
	}
	ReadInfoFromFile.close();
	this->ID = ++ID;
}
int Student::GetID()
{
	switch (ID)
	{
	case 0:
		Initialisation_ID();
		break;
	}
	return ID;
}