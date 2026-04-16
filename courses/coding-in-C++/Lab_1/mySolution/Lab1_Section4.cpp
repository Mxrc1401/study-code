#include "student_report.hpp"

#include <cstdint>
#include <string>

int main()
{
	std::string name;
	std::uint8_t homework = 0U;
	std::uint8_t midterm = 0U;
	std::uint8_t final_exam = 0U;
	double final_grade = 0.0;
	std::string letter_grade;

	readStudentData(name, homework, midterm, final_exam);
	calculateGrade(homework, midterm, final_exam, final_grade, letter_grade);
	printReport(name, homework, midterm, final_exam, final_grade, letter_grade);

	return 0;
}
