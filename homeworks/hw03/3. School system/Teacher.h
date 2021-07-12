#pragma once
#include "Person.h"

class Course;

enum Title {
	Part_Time, Assistant_Professor, Doctor, Associate_Professor, Professor
};

class Teacher : public Person {
public:
	Teacher(string n, Title t);

	void grade_student(Course* c, unsigned int fn, unsigned int value);

	void join_course(Course* c) const;
	void leave_course(Course* c) const;

	Title get_title() const;

	bool teaches(Course* c) const;

private:
	Title t_title;
	vector<Course*> t_courses;
};