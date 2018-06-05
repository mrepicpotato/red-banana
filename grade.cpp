#include <vector>
#include <stdexcept>
#include <list>
#include "grade.h"
#include "median.h"
#include "student_info.h"

using std::domain_error;	using std::vector;
using std::list;

double grade(double midterm, double finals, double homework) {				//Used to calculate the final score from midterm, final and avg homework scores
	return 0.2 * midterm + 0.4 * finals + 0.4 * homework;
}

double grade(double midterm, double finals, const vector<double>& hw) {		//Used to determine whether vector hw has any values
	if (hw.size() == 0)
		throw domain_error("Student has done no homework");
	return grade(midterm, finals, median(hw));
}

double grade(const Student_info& s) {
	return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info& s) {
	return grade(s) < 60;
}

list<Student_info> extract_fails(list<Student_info>& students){
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();

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