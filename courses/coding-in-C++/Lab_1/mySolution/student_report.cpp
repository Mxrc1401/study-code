#include "student_report.hpp"

#include <iomanip>
#include <iostream>
#include <limits>

namespace
{
const int MIN_SCORE = 0;
const int MAX_SCORE = 100;

void readScore(const std::string& label, std::uint8_t& score)
{
    int input = 0;
    bool isValid = false;

    while (!isValid)
    {
        std::cout << label;

        if (!(std::cin >> input))
        {
            std::cout << "Invalid input. Please enter a number between 0 and 100." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if ((input < MIN_SCORE) || (input > MAX_SCORE))
        {
            std::cout << "Invalid input. Please enter a number between 0 and 100." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        score = static_cast<std::uint8_t>(input);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        isValid = true;
    }
}
}

void readStudentData(std::string& name,
                     std::uint8_t& homework,
                     std::uint8_t& midterm,
                     std::uint8_t& finalExam)
{
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);

    while (name.empty())
    {
        std::cout << "Name must not be empty. Please enter student name: ";
        std::getline(std::cin, name);
    }

    readScore("Homework score: ", homework);
    readScore("Midterm score: ", midterm);
    readScore("Final exam score: ", finalExam);
}

void calculateGrade(std::uint8_t homework,
                    std::uint8_t midterm,
                    std::uint8_t finalExam,
                    double& finalGrade,
                    std::string& letterGrade)
{
    const double HOMEWORK_WEIGHT = 0.40;
    const double MIDTERM_WEIGHT = 0.25;
    const double FINAL_EXAM_WEIGHT = 0.35;

    finalGrade = (static_cast<double>(homework) * HOMEWORK_WEIGHT) +
                 (static_cast<double>(midterm) * MIDTERM_WEIGHT) +
                 (static_cast<double>(finalExam) * FINAL_EXAM_WEIGHT);

    if (finalGrade >= 90.0)
    {
        letterGrade = "A";
    }
    else if (finalGrade >= 80.0)
    {
        letterGrade = "B";
    }
    else if (finalGrade >= 70.0)
    {
        letterGrade = "C";
    }
    else if (finalGrade >= 60.0)
    {
        letterGrade = "D";
    }
    else if (finalGrade >= 50.0)
    {
        letterGrade = "E";
    }
    else
    {
        letterGrade = "F";
    }
}

void printReport(const std::string& name,
                 std::uint8_t homework,
                 std::uint8_t midterm,
                 std::uint8_t finalExam,
                 double finalGrade,
                 const std::string& letterGrade)
{
    std::string status = "FAIL";

    if ((letterGrade == "A") || (letterGrade == "B") || (letterGrade == "C"))
    {
        status = "PASS";
    }
    else if ((letterGrade == "D") || (letterGrade == "E"))
    {
        status = "CONDITIONAL PASS";
    }

    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Student Report" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << std::endl;
    std::cout << "Scores" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    std::cout << std::left << std::setw(16) << "Homework" << ": "
              << std::right << std::fixed << std::setprecision(2)
              << static_cast<double>(homework) << std::endl;

    std::cout << std::left << std::setw(16) << "Midterm" << ": "
              << std::right << std::fixed << std::setprecision(2)
              << static_cast<double>(midterm) << std::endl;

    std::cout << std::left << std::setw(16) << "Final Exam" << ": "
              << std::right << std::fixed << std::setprecision(2)
              << static_cast<double>(finalExam) << std::endl;

    std::cout << std::endl;

    std::cout << std::left << std::setw(16) << "Final Grade" << ": "
              << std::right << std::fixed << std::setprecision(2)
              << finalGrade << std::endl;

    std::cout << std::left << std::setw(16) << "Letter Grade" << ": "
              << std::right << letterGrade << std::endl;

    std::cout << std::left << std::setw(16) << "Status" << ": "
              << std::right << status << std::endl;

    std::cout << "-------------------------------------" << std::endl;
}