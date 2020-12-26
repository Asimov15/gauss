#include "shared.h"

class endodatio
{
	private:
		double *solution;
	
	public:
		endodatio();
		~endodatio();
		void put(int, double);
		double get(int);
		void output();
};

class forma
{
	private: 
		double *x;

	public:
		forma();
		~forma();
		forma(double [][4]);
		double get(int, int);
		void put(int, int, double);
		void eliminate();
		void substitute(endodatio*);
		void output_matrix();
};

