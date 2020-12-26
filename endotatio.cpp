#include "shared.h"

endodatio::endodatio()
{
	int i;
	solution = (double *) malloc(SIZE * sizeof(double));
	for(i = 0; i < SIZE; i++)
	{
		solution[i] = 0;
	}
}

double endodatio::get(int i)
{
	assert(i >= 0 && i < SIZE);
	return solution[i];
}

void endodatio::put(int i, double value)
{
	assert(i >= 0 && i < SIZE);
	solution[i] = value;
}

void endodatio::output()
{
	int i;
	for (i = 0; i < SIZE - 1; i++)
	{
		cout << solution[i] << ",";
	}
	
	cout << solution[SIZE - 1] << endl;

}

endodatio::~endodatio()
{
	delete[] solution;
}
