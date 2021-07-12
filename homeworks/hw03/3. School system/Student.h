#pragma once
#include "Person.h"

class Course;

struct Grade {
public:
	Grade(Course* c, unsigned short v);
	
	unsigned short get_value() const;
	Course* get_course() const;

private:
	unsigned short value;
	Course* course;

	friend class Teacher;
};

class Student : public Person {
public:
	Student(string n, unsigned int fn);

	unsigned int get_faculty_number() const;

	void join_course(Course* c);
	void leave_course(Course* c);

	void courses_list() const;
	void grades_list() const;

	bool joined(Course* c) const;
	bool has_grade(Course* c) const;

private:
	unsigned int s_faculty_number;
	vector<Course*> s_courses;
	vector<Grade*> s_grades;
};