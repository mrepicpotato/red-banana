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

using namespace std;

vector<Student_info> extract_fails(vector<Student_info>& students){
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();

	while (iter != students.end()){
		if (fgrade(*iter)){
			fail.push_back(*iter);
			iter = students.erase(iter);
		} else {
			++iter;
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

