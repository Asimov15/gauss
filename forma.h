#include "shared.h"

class forma
{
	private: 
		double *x;

	public:
		forma();
		~forma();
		forma(double*);
		double get(int, int);
		void put(int, int, double);
		void eliminate();
		void substitute(endodatio*);
		void output_matrix();
};

