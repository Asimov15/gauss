#include "gauss.h"

forma::forma()
{
	int i;
	x = (double *) malloc(12 * sizeof(double));
	for(i = 0; i < 12; i++)
	{
		x[i] = 0;
	}
}

forma::forma(double m[][4])
{
	int i, j;
	x = (double *) malloc(12 * sizeof(double));
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 4; i++)
		{
			x[j*4 + i] = m[j][i];  //[row][col] j = row number i = col number
		}
	}
}

forma::~forma()
{
	delete[] x;
}

double forma::get(int i, int j)
{
	assert(i >= 0 && i < 4);
	assert(j >= 0 && j < 3);
	return x[j*4 + i]; // i = column number j = row number
}

void forma::put(int i, int j, double value)
{
	assert(i >= 0 && i < 4);
	assert(j >= 0 && j < 3);
	x[j*4 + i] = value;
}

void forma::eliminate()
{
	int i, j, k, max;
	double t;
	for (i = 0; i < 3; i++)
	{
		max = i;
		for (j = i + 1; j < 3; j++)
		{
			if (abs(get(i,j)) > abs(get(i,max))) 
			{
				max = j;
			}
		}
		for (k = i; k < 4; k++)
		{
			t = get(k,i);
			put(k,i, get(k,max));
			put(k, max, t);
		}
		for (j = i + 1; j < 3; j++)
		{
			for (k = 3; k >= i; k--)
			{
				put(k,j, get(k,j) - get(k,i) * get(i,j) / get(i,i));
			}
		}
		output_matrix();
	}
}

void forma::substitute(endodatio *c)
{
	int j, k;
	double t;
	for ( j = 2; j >=0; j--)
	{
		t = 0.0;
		for ( k = j + 1; k <= 2; k++)
		{
			t += get(k,j) * c->get(k);
		}
		c->put(j, (get(3,j) - t) / get(j,j));
	}
}

void forma::output_matrix()
{
	int i,j;
	double val;
	
	for (j = 0; j < 3; j++)
	{
		cout << "[ ";
		for (i = 0; i < 4; i++)
		{
			val = get(i,j);
			cout << val << " ";
		}
		cout << "]" << endl;
	}
	cout << "_______________________" << endl;
}

endodatio::endodatio()
{
	int i;
	solution = (double *) malloc(3 * sizeof(double));
	for(i = 0; i < 3; i++)
	{
		solution[i] = 0;
	}
}

double endodatio::get(int i)
{
	assert(i >= 0 && i < 3);
	return solution[i];
}

void endodatio::put(int i, double value)
{
	assert(i >= 0 && i < 3);
	solution[i] = value;
}

void endodatio::output()
{
	cout << solution[0] << "," << solution[1] << "," << solution[2] << endl;
}

endodatio::~endodatio()
{
	delete[] solution;
}


