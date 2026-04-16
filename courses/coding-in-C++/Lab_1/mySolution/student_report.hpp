#ifndef STUDENT_REPORT_HPP
#define STUDENT_REPORT_HPP

#include <cstdint>
#include <string>

void readStudentData(std::string& name,
                     std::uint8_t& homework,
                     std::uint8_t& midterm,
                     std::uint8_t& finalExam);

void calculateGrade(std::uint8_t homework,
                    std::uint8_t midterm,
                    std::uint8_t finalExam,
                    double& finalGrade,
                    std::string& letterGrade);

void printReport(const std::string& name,
                 std::uint8_t homework,
                 std::uint8_t midterm,
                 std::uint8_t finalExam,
                 double finalGrade,
                 const std::string& letterGrade);

#endif