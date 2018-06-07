// Score Calc 1.0.cpp : Defines the entry point for the console application.
//

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <list>
#include "grade.h"
#include "student_info.h"

using namespace std;

int main() {
	list<Student_info> students;
	list<Student_info>::iterator iter = students.begin();
	Student_info record;
	string::size_type maxlen = 0;

	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
		system("clear");
	}

	students.sort(compare);
	cout << "Students Scores :" << endl;
	for (iter = students.begin(); iter != students.end(); ++iter) {
		cout << iter->name << string(maxlen + 1 - iter->name.size(), ' ');
		try {
			double final_grade = grade(*iter);
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

