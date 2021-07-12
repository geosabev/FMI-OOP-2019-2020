#pragma once
#include "Student.h"
#include "Teacher.h"

enum Type {
	Compulsory, Elective, Practicum
};

class Course {
public:
	Course(string n, Type type, unsigned int c, Teacher* t);

	void add_student(Student* s);
	void remove_student(Student* s);

	void change_teacher(Teacher* t);

	string get_name() const;
	Type get_type() const;
	unsigned int get_code() const;
	Teacher* get_teacher() const;
	Student* get_student(unsigned int fn) const;

	bool contains(Student* s) const;

	void students_list() const;

private:
	string c_name;
	Type c_type;
	unsigned int c_code;
	Teacher* c_teacher;
	vector<Student*> c_students;
};