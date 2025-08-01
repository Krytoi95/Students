#pragma once

#include <iostream>
#include <string>
#include <fstream>

class Student
{
public:
    // Info Student
    enum State
    {
        Graduate,
        Study,
        Admission
    };
    // Functions
    Student();
    Student(const std::string Name, const std::string Last_Name, const int Date[], const int Age, const std::string Classroom, const State state);
    void Info();

    void Write_Student_In_File();
    void Write_Student_From_File(const int ID);
    void Write_Student_From_File();
    void Read_Student_From_File(Student&student);

    int GetID();
   
    


private:
    // Info Student
    std::string Name{};
    std::string Last_Name{};
    int Date_Of_Birth[3]{};
    int Age{};
    std::string Classroom{};
    int ID_Student{};
    State state;
    //Global Info
    static int ID;

    // Functions

    std::string Date_Of_Birth_To_String();
    std::string State_To_String();
    void String_To_Date_Of_Birth(std::string Date, int Date_Of_Birth);
    

    int Search_ID(const Student&student);
    int Search_ID(const int ID);


    bool Comparison_ID(const int FIRST_COMPARISON_ID, const int SECOND_COMPARISON_ID);

    void Initialisation_ID();
    friend void _Init_ID();
};