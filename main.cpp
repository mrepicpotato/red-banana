// Score Calc 1.0.cpp : Defines the entry point for the console application.
//

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "grade.h"
#include "student_info.h"

using std::cin;				using std::sort;
using std::cout;			using std::streamsize;
using std::endl;			using std::string;
using std::setprecision;	using std::vector;
using std::domain_error;	using std::max;

vector<Student_info> extract_fails(vector<Student_info>& students){
	vector<Student_info>::size_type fail;
	vector<Student_info>::size_type i = 0;

	while (i != students.size()){
		if (fgrade(students[i])){
			fail.push_back(students[i]);
			students.erase(students.begin() + i);
		} else {
			++i;
		}
	}
	return fail;
}

int main() {
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);
	cout << "Students Scores:" << endl;
	for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');
		try {
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec);
		}
		catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
cin.get();
return 0;
}

