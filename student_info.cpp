#include "student_info.h"

using std::istream;	using std::vector;
using std::cout;	using std::endl;

bool compare(const Student_info& x, const Student_info& y) {
	return x.name < y.name;
}

istream& read(istream& is, Student_info& s) {
	cout << "Student's name: ";
	getline(is, s.name);
	if (!is.eof()) {
		cout << endl << s.name << "'s midterm grade: ";
		is >> s.midterm;
		cout << endl << s.name << "'s final grade: ";
		is >> s.final;
		cout << endl << s.name << "'s homework grades (-1 to finish): ";
		read_hw(is, s.homework);
	}
	return is;
}

istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		hw.clear();

		double x;
		while (in >> x)
			if (x == -1){
				in.ignore();
				break;
			} else {
				in.ignore();
				hw.push_back(x);
			}

		in.clear();
	}
	return in;
}