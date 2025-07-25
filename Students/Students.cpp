#include <iostream>
#include <string>
#include <fstream>

// Students 

// This project is designed to practice dynamic arrays, 
// read and write data to a file, 
// as well as writing an object to a file 
// and possibly a list of states (students, graduates, enrolling).
// I chose students because it is a more realistic task

class Menu 
{
private:
    std::string Greeting{
        "Hi! This is a regular project to practice some topics.\n"
        "It's made in C++ on OS Windows.\n"
        "This project is to record students in a file.\n"
        "Are they in school, are they entering school or are they graduates.\n"
        "Also their first name, last name, how old they are, their id.\n"
        "And that's about it.\n"
    };
    std::string Enter_Student{
        "Enter student\n"
    };
    std::string Enter_Name{
    "Enter name: \n"
    };
    std::string Enter_Last_Name{
        "Enter last name: \n"
    };
    std::string Enter_Classroom{
        "Enter classroom: \n"
    };
    std::string Enter_Age{
        "Enter age: \n"
    };

public:
    void Say_Greeting()
    {
        std::cout << Greeting << std::endl;
    }
    void Say_Enter_Students()
    {
        std::cout << Enter_Student << std::endl;
    }
    void Say_Enter_Name()
    {
        std::cout << Enter_Name << std::endl;
    }
    void Say_Enter_Last_Name() 
    {
        std::cout << Enter_Last_Name << std::endl;
    }
    void Say_Enter_Classroom()
    {
        std::cout << Enter_Classroom << std::endl;
    }
    void Say_Enter_Age()
    {
        std::cout << Enter_Age << std::endl;
    } 

};

class Sort {};

class Students
{
private:
    int age;
    static int id;
    std::string first_name;
    std::string second_name;
    std::string classroom;
public:
    Students() {}
    Students(std::string first_name,std::string second_name,std::string classroom, int age)
    {
        this->first_name = first_name;
        this->second_name = second_name; 
        this->classroom = classroom; 
        this->age = age;
        id++;
    }
    void info()
    {
        std::cout << "F: " << first_name << " S: " << second_name << " CL: " << classroom << " A: " << age  << " I: " << id << std::endl;
    }
    // Если известны все данные
};

int Students::id = 0;

bool write(std::fstream &file)
{
    if (file.is_open() != true)
    {
        throw std::exception("Error open file!");
    }
    return true;
}

int main()
{
    Menu menu;
    std::string first_name{};
    std::string second_name{};
    std::string classroom{};
    int age{};

    std::cout << "Enter Student: \nSecond name: \nClassroom: \nAge: " << std::endl;
    std::cout << "\nFirst name: " << std::endl;
    std::cin >> first_name;
    std::cout << "\nSecond name: " << std::endl;
    std::cin >> second_name; 
    std::cout << "\nClassroom: " << std::endl;
    std::cin >> classroom;
    std::cout << "\nAge: " << std::endl;
    std::cin >> age;
    Students student1(first_name, second_name, classroom, age);
    student1.info();

    // Test array 

   /* const size_t SIZE{ 5 };
    Students students[SIZE];
    students[0] = Students("Gay", "Mam", "A6", 45);
    students[0].Info();
    Students* point_class = new Students[SIZE];
    point_class[0] = Students("Gay", "Mam", "A6", 45);
    point_class[0].Info();
    delete[] point_class;
    point_class = nullptr;*/

    // Test write\read object in file

    std::ofstream Write_File;
    Write_File.open("Students.txt", std::fstream::app);
    try
    {
        Write_File.write((char*)&student1, sizeof(Students));
        Write_File.close();
        std::ifstream Read_File;
        Read_File.open("Students.txt");
        Students student_temp;
        while (Read_File.read((char*)&student_temp, sizeof(Students)))
        {
            student_temp.info();
        }
        Read_File.close();
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}

