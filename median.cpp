#include <algorithm>
#include <vector>
#include <stdexcept>
#include "median.h"

using std::domain_error;	using std::sort;	using std::vector;

double median(vector<double> vec) {											//Used to calculate the avg of all scores in the homework vector
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("Median of an empty vector");

	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}