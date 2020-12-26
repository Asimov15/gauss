#include "shared.h"

forma::forma()
{
	// constructor
	int i;
	// x is a matrix holding the coefficients of the equations. The last column holds the constants
	x = (double *) malloc((pow(SIZE,2) + SIZE) * sizeof(double));
	for(i = 0; i < (pow(SIZE,2) + SIZE); i++)
	{
		x[i] = 0;
	}
}

forma::forma(double m[][SIZE + 1])
{
	// this constructor takes the address of a 2 D array so that the matrix can be conviently initialized.
	int i, j;
	x = (double *) malloc((pow(SIZE,2) + SIZE) * sizeof(double));
	for (j = 0; j < SIZE; j++)
	{
		for (i = 0; i < SIZE + 1; i++)
		{
			x[j*(SIZE + 1) + i] = m[j][i];  //[row][col] j = row number i = col number
		}
	}
}

forma::~forma()
{
	// destructor
	delete[] x;
}

double forma::get(int i, int j)
{
	// return an element
	assert(i >= 0 && i < (SIZE +1));
	assert(j >= 0 && j < SIZE);
	return x[j*(SIZE + 1) + i]; // i = column number j = row number
}

void forma::put(int i, int j, double value)
{
	// set an elelment
	assert(i >= 0 && i < (SIZE + 1));
	assert(j >= 0 && j < SIZE);
	x[j*(SIZE + 1) + i] = value;
}

void forma::eliminate()
{
	// forward elemination phase
	int i, j, k, max;
	double t;
	for (i = 0; i < SIZE; i++)
	{
		max = i;
		for (j = i + 1; j < SIZE; j++)
		{
			if (abs(get(i,j)) > abs(get(i,max))) 
			{
				max = j;
			}
		}
		
		for (k = i; k < (SIZE + 1); k++)
		{
			t = get(k,i);
			put(k,i, get(k,max));
			put(k, max, t);
		}
		
		for (j = i + 1; j < SIZE; j++)
		{
			for (k = SIZE; k >= i; k--)
			{
				put(k,j, get(k,j) - get(k,i) * get(i,j) / get(i,i));
			}
		}
		output_matrix();
	}
}

void forma::substitute(endodatio *c)
{
	// backward substitution phase
	int j, k;
	double t;
	for ( j = SIZE - 1; j >= 0; j--)
	{
		t = 0.0;
		for ( k = j + 1; k < SIZE; k++)
		{
			t += get(k,j) * c->get(k);
		}
		c->put(j, (get(SIZE,j) - t) / get(j,j));
	}
}

void forma::output_matrix()
{
	int i,j;
	double val;
	
	cout << endl;
	for (j = 0; j < SIZE; j++)
	{
		cout << "[ ";
		for (i = 0; i < SIZE + 1; i++)
		{
			val = get(i,j);
			cout << val << " ";
		}
		cout << "]" << endl;
	}
	cout << "_______________________" << endl;
}
