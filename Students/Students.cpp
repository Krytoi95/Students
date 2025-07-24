#include <iostream>
#include <string>
#include <fstream>

// Students 

// This project is designed to practice dynamic arrays, 
// read and write data to a file, 
// as well as writing an object to a file 
// and possibly a list of states (students, graduates, enrolling).
// I chose students because it is a more realistic task

class Menu {};

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
    void Info()
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

    std::fstream Write_File;
    Write_File.open("Students.txt", std::fstream::out);
    try
    {
        write(Write_File);
        std::cout << "Correct!" << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}

