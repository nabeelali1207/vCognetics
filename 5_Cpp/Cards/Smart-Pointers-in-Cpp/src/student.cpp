#ifndef STUDENT_CPP
#define STUDENT_CPP

#include <iostream>
#include "student.h"

void student::set_subject_marks(std::string _subject, int _marks)
{
	result[_subject] = _marks;
}
int student::get_subject_marks(std::string _subject)
{
	return result[_subject];
}
void student::print_all_marks()
{
	for (const auto &pair : result)
	{
		std::cout << "Subject: " << pair.first << ", Marks: " << pair.second << std::endl;
	}
}
void student::set_student_name(std::string _student_name)
{
	current_student.student_name = _student_name;
}
std::string student::get_student_name()
{
	return current_student.student_name;
}
void student::set_roll_no(std::string _roll_no)
{
	current_student.roll_no = _roll_no;
}
std::string student::get_roll_no()
{
	return current_student.roll_no;
}
void student::set_age(float _age)
{
	current_student.age = _age;
}
float student::get_age()
{
	return current_student.age;
}
void student::set_cgpa(float _cgpa)
{
	current_student.cgpa = _cgpa;
}
float student::get_cgpa()
{
	return current_student.cgpa;
}

#endif