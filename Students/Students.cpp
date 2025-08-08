#include <iostream>
#include <string>
#include <fstream>


#include <chrono>
#include <Windows.h>

#include "Student.h"
#include "Menu.h"
#include "Sort.h"

#include "DATE.h"

// Students 

//  
//
//
//
//
//
//
//
//


// This project is designed to practice dynamic arrays, 
// read and write data to a file, 
// as well as writing an object to a file 
// and possibly a list of states (students, graduates, enrolling).
// I chose students because it is a more realistic task

namespace param
{
    bool end{ false };
    bool end_write{ false };
    bool end_read{ false };
}

namespace Parameters
{
    // Characteristcs for Menu
    std::string input{};

    // Characteristcs for Student
    std::string Name{};
    std::string Last_Name{};
    int Date_Of_Birth[3]{};
    int Age{};
    std::string Classroom{};
    STATUS::State Status{};

    // End

    bool end{};
    bool end_write{};
    bool end_read{};
}

    // Check
    //bool Is_Number(const std::string TEXT)
    //{
    //    const std::string NUMBER{ "0123456789" };
    //    if(NUMBER.find(TEXT[0])>NUMBER.size())
    //    {
    //        return false;
    //    }
    //     /*for (size_t i = 0; i < NUMBER.size(); i++)
    //     {
    //       if (text[0] == NUMBER[i]) 
    //       {
    //          
    //       }
    //     }*/
    //    return true;
    //}
    //bool Is_String(const std::string TEXT)
    //{
    //    const std::string ALPHABET{ "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz" };
    //    for (size_t i = 0; i < TEXT.size(); i++)
    //    {
    //        if(ALPHABET.find(TEXT[i])>ALPHABET.size())
    //        {
    //            return false;
    //        }
    //    }
    //    return true;
    //}
    //bool Is_String_And_Number(const std::string TEXT)
    //{ 
    //    const std::string ALPHABET_AND_NUMBER{ "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789" };
    //    for (size_t i = 0; i < TEXT.size(); i++)
    //    {
    //        if(ALPHABET_AND_NUMBER.find(TEXT[i])>ALPHABET_AND_NUMBER.size())
    //        {
    //            return false;
    //        }
    //    }
    //    return true;
    //}

void _Init_ID()
{
    Student temp;
    temp.Initialisation_ID();
} // ??
                                    


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    _Init_ID();
    Menu menu;
    /*menu.Greeting();*/

    while (Parameters::input!="0")
    {
        // At zero, the loop will close
        menu.Clear();
        menu.Information();
        std::cin >> Parameters::input;
        // String length check
        if (Parameters::input.size() > 1)
        {
            menu.Clear();
            continue;
        }
        // Checking for digits in the string
        if (!menu.Is_Number(Parameters::input))
        {
            menu.Clear();
            continue;
        }
        switch (std::stoi(Parameters::input))
        {
        case 1:
        {
            Parameters::Name = menu.Enter_Name();
            Parameters::Last_Name = menu.Enter_Last_Name();
            menu.Enter_Date_Of_Birth(Parameters::Date_Of_Birth);
            Date::DATE date(menu.To_String_Date(Parameters::Date_Of_Birth));
            Parameters::Age = menu.Enter_Age(date);
            Parameters::Classroom = menu.Enter_Classroom();
            Parameters::Status = menu.Enter_State();
            Parameters::end_write = true;
            menu.Pause();
            break;
        }
        case 2:
        {
            std::cout << "Im 2" << std::endl;
            if (Parameters::end_write == true)
            {
                Student student{ Parameters::Name, Parameters::Last_Name, Parameters::Date_Of_Birth, Parameters::Age, Parameters::Classroom, Parameters::Status };
                student.Info();
            }
            menu.Pause();
            break;
        }
        }
    }

//    while (std::cin >> input)
//    {
//      
//        if (menu.Is_Number(input))
//        {
//            char button { input[0] };
//            while (param::end == false)
//            {
//                switch (button)
//                {
//#pragma region Write data
//                case '1':     
//#pragma region Name
//                    system("cls");
//                    std::cout << "Entering a student in the list\n" << std::endl;
//                    std::cout << "\nName: " << std::endl;
//                    while (std::cin >> Name)
//                    {
//                        if (!menu.Is_String(Name))
//                        {
//                            Name = "";
//                            system("cls");
//                            std::cout << "Entering a student in the list\n" << std::endl;
//                            std::cout << "\nName: " << std::endl;
//                            continue;
//                        }
//                        else
//                        {
//                            system("cls");
//                            std::cout << "Name: " << Name << " is it written correctly?(Y/N||y/n)" << std::endl;
//
//                            input = "";
//                            while (std::cin >> input)
//                            {
//                                if (input.size() > 1)
//                                {
//                                    system("cls");
//                                    std::cout << "Name: " << Name << " is it written correctly?(Y/N||y/n)" << std::endl;
//                                    continue;
//                                }
//                                if (input == "Y" || input == "y")
//                                {
//                                    break;
//                                }
//                                if (input == "N" || input == "n")
//                                {
//                                    break;
//                                }
//                                system("cls");
//                                std::cout << "Name: " << Name << " is it written correctly?(Y/N||y/n)" << std::endl;
//                            }
//                            if (input == "Y" || input == "y")
//                            {
//                                system("cls");
//                                break;
//                            }
//                            if (input == "N" || input == "n")
//                            {
//                                system("cls");
//                                std::cout << "Entering a student in the list\n" << std::endl;
//                                std::cout << "\nName: " << std::endl;
//                                continue;
//                            }
//                        }
//                    }
//#pragma endregion
//#pragma region Last name
//                    std::cout << "Entering a student in the list\n" << std::endl;
//                    std::cout << "\nLast name: " << std::endl;
//                    while (std::cin >> Last_Name)
//                    {
//                        if (!menu.Is_String(Last_Name))
//                        {
//                            Last_Name = "";
//                            system("cls");
//                            std::cout << "Entering a student in the list\n" << std::endl;
//                            std::cout << "\nLast name: " << std::endl;
//                            continue;
//                        }
//                        else
//                        {
//                            system("cls");
//                            std::cout << "Last name: " << Last_Name << " is it written correctly?(Y/N||y/n)" << std::endl;
//
//                            input = "";
//                            while (std::cin >> input)
//                            {
//                                if (input.size() > 1)
//                                {
//                                    system("cls");
//                                    std::cout << "Last name: " << Last_Name << " is it written correctly?(Y/N||y/n)" << std::endl;
//                                    continue;
//                                }
//                                if (input == "Y" || input == "y")
//                                {
//                                    break;
//                                }
//                                if (input == "N" || input == "n")
//                                {
//                                    break;
//                                }
//                                system("cls");
//                                std::cout << "Last name: " << Last_Name << " is it written correctly?(Y/N||y/n)" << std::endl;
//                            }
//                            if (input == "Y" || input == "y")
//                            {
//                                system("cls");
//                                break;
//                            }
//                            if (input == "N" || input == "n")
//                            {
//                                system("cls");
//                                std::cout << "Entering a student in the list\n" << std::endl;
//                                std::cout << "\nLast name: " << std::endl;
//                                continue;
//                            }
//                        }
//                    }
//#pragma endregion
//#pragma region Classroom
//                    std::cout << "Entering a student in the list\n" << std::endl;
//                    std::cout << "\nClassroom: " << std::endl;
//                    while (std::cin >> Classroom)
//                    {
//                        if (Classroom.size() > 3)
//                        {
//                            Classroom = "";
//                            system("cls");
//                            std::cout << "Entering a student in the list\n" << std::endl;
//                            std::cout << "\nClassroom: " << std::endl;
//                            continue;
//                        }
//                        if (!menu.Is_String_And_Number(Classroom))
//                        {
//                            Classroom = "";
//                            system("cls");
//                            std::cout << "Entering a student in the list\n" << std::endl;
//                            std::cout << "\nClassroom: " << std::endl;
//                            continue;
//                        }
//                        else
//                        {
//                            system("cls");
//                            std::cout << "Classroom: " << Classroom << " is it written correctly?(Y/N||y/n)" << std::endl;
//
//                            input = "";
//                            while (std::cin >> input)
//                            {
//                                if (input.size() > 1)
//                                {
//                                    system("cls");
//                                    std::cout << "Classroom: " << Classroom << " is it written correctly?(Y/N||y/n)" << std::endl;
//                                    continue;
//                                }
//                                if (input == "Y" || input == "y")
//                                {
//                                    break;
//                                }
//                                if (input == "N" || input == "n")
//                                {
//                                    break;
//                                }
//                                system("cls");
//                                std::cout << "Classroom: " << Classroom << " is it written correctly?(Y/N||y/n)" << std::endl;
//                            }
//                            if (input == "Y" || input == "y")
//                            {
//                                system("cls");
//                                break;
//                            }
//                            if (input == "N" || input == "n")
//                            {
//                                system("cls");
//                                std::cout << "Entering a student in the list\n" << std::endl;
//                                std::cout << "\nClassroom: " << std::endl;
//                                continue;
//                            }
//                        }
//                    }
//#pragma endregion
//#pragma region Age
//                    std::cout << "Entering a student in the list\n" << std::endl;
//                    std::cout << "\nAge: " << std::endl;
//                    while (std::cin >> Age)
//                    {
//                        if (!menu.Is_Number(Age))
//                        {
//                            Age = { "" };
//                            system("cls");
//                            std::cout << "Entering a student in the list\n" << std::endl;
//                            std::cout << "\nAge: " << std::endl;
//                            continue;
//                        }
//                        if (std::stoi(Age) >= 100 || std::stoi(Age) < 7)
//                        {
//                            Age = { "" };
//                            system("cls");
//                            std::cout << "Entering a student in the list\n" << std::endl;
//                            std::cout << "\nAge: " << std::endl;
//                            continue;
//                        }
//                        else
//                        {
//                            system("cls");
//                            std::cout << "Age: " << Age << " is it written correctly?(Y/N||y/n)" << std::endl;
//
//                            input = "";
//                            while (std::cin >> input)
//                            {
//                                if (input.size() > 1)
//                                {
//                                    system("cls");
//                                    std::cout << "Age: " << Age << " is it written correctly?(Y/N||y/n)" << std::endl;
//                                    continue;
//                                }
//                                if (input == "Y" || input == "y")
//                                {
//                                    break;
//                                }
//                                if (input == "N" || input == "n")
//                                {
//                                    break;
//                                }
//                                system("cls");
//                                std::cout << "Age: " << Age << " is it written correctly?(Y/N||y/n)" << std::endl;
//                            }
//                            if (input == "Y" || input == "y")
//                            {
//                                system("cls");
//                                break;
//                            }
//                            if (input == "N" || input == "n")
//                            {
//                                system("cls");
//                                std::cout << "Entering a student in the list\n" << std::endl;
//                                std::cout << "\nAge: " << std::endl;
//                                continue;
//                            }
//                        }
//                    }
//#pragma endregion
//#pragma region Another Student
//                    system("cls");
//                    std::cout << "Would you like to sign up another student?(Y/N || y/n)" << std::endl;
//                    input = "";
//                    while(std::cin >> input)
//                    { 
//                        if (input.size() > 1)
//                        {
//                            input = "";
//                            system("cls");
//                            std::cout << "Would you like to sign up another student?(Y/N || y/n)" << std::endl;
//                            continue;
//                        }
//                        if (input == "Y" || input == "y")
//                        {
//                            /*std::ofstream OutFile;
//                            OutFile.open("Students.txt", std::ofstream::app);*/
//                            if (count_students == 0) 
//                            {
//                                array_students[count_students] = Students(Name, Last_Name, Classroom, std::stoi(Age));
//                                count_students++;
//                            }
//                            else
//                            {
//                                array_students->add_student_in_end_array(array_students, SIZE, Students(Name, Last_Name, Classroom, std::stoi(Age)));
//                                count_students++;
//                            }
//                            break;
//                        }
//                        if (input == "N" || input == "n")
//                        {
//                            if (count_students == 0)
//                            {
//                                array_students[count_students] = Students(Name, Last_Name, Classroom, std::stoi(Age));
//                                count_students++;
//                            }
//                            else
//                            {
//                                array_students->add_student_in_end_array(array_students, SIZE, Students(Name, Last_Name, Classroom, std::stoi(Age)));
//                                count_students++;
//                            }
//                            std::ofstream OutFile;
//                            OutFile.exceptions(std::ofstream::badbit);
//                            try
//                            {
//                                OutFile.open("Students.txt", std::ofstream::app);
//                                for (size_t i = 0; i < SIZE; i++)
//                                {
//                                    OutFile.write((const char*)&array_students[i], sizeof(Students));
//                                }
//                                OutFile.close();
//                            }
//                            catch (const std::ofstream::failure& ex)
//                            {
//                                std::cout <<"Error: " << ex.what() << std::endl;
//                            }
//                            std::cout << "Writing data to the list is complete" << std::endl;
//                            Sleep(2000);
//                            param::end_write = true;
//                            //param::end = true;
//                            break;
//                        }
//                    }
//                    break;
//#pragma endregion
//#pragma endregion
//
//#pragma region Read List
//                case '2':
//                    
//                    param::end = true;
//                    break;
//#pragma endregion
//                case '0':
//                    break;
//                default:
//                    break;
//                }
//
//
//
//
//
//                if (param::end_write == true) 
//                {
//                    system("cls");
//                    std::ifstream InFile;
//                    InFile.exceptions(std::ifstream::badbit);
//                    try
//                    {
//                        InFile.open("Students.txt");
//                        Students student_temp;
//                        while(InFile.read((char*)&student_temp, sizeof(Students)))
//                        {                                                     
//                            student_temp.info();
//                        }
//                        InFile.close();
//                    }
//                    catch (const std::ifstream::failure& ex)
//                    {
//                        std::cout << "Error: " << ex.what() << std::endl;
//                    }
//                    /*for (size_t i = 0; i < SIZE; i++)
//                    {
//                        array_students[i].info();
//                    }*/
//                    param::end = true;
//                }
//            }
//            break;
//        }
//        system("cls");
//        std::cout << "Write student(1)" << std::endl;
//        std::cout << "List students(2)" << std::endl;
//        std::cout << "Leave(0)" << std::endl;
//    }



//bool Menu::Is_Number(const std::string TEXT)
//{
//	const std::string NUMBER{ "0123456789" };
//	for (size_t i = 0; i < TEXT.size(); i++)
//	{
//		if (NUMBER.find(TEXT[i]) > NUMBER.size()) {
//			return false;
//		}
//	}
//	return true;
//}









  

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

   /* std::ofstream Write_File;
    Write_File.open("Students.txt", std::fstream::app);
    try
    {
        Write_File.write((char*)&student1, sizeof(Students));
        Write_File.close();
        std::ifstream Read_File;
        Read_File.open("Students.txt");

        while (!Read_File.eof())
        {
            Students student_temp;
            Read_File.read((char*)&student_temp, sizeof(Students));
            student_temp.info();
        }
        Read_File.close();
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }*/

    return 0;
}

/*auto start = std::chrono::high_resolution_clock::now();
    for (char i = 0; i < 127; i++)
    {
        std::string j{i};
        Is_String(j);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_ms = end - start;
    std::cout << "Time: " << duration_ms.count() << " milisec\n";*/
