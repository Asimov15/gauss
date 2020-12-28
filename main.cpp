#include "shared.h"

int main()
{
	int i,j;
	double e[SIZE][SIZE + 1];
	
	srand (time(NULL));
		
	for (j = 0; j < SIZE; j++)
	{
		for (i = 0; i < SIZE + 1; i++)
		{
			e[j][i] = (double) (rand() % 101 - 50);
		}
	}
		 //= { 
									//{1, 1, -2,  1, 3, -1 , 4},
									//{2, -1, 1, 2,  1, -3, 20},
									//{1, 3,-3, -1, 2, 1, -15},
									//{5, 2, -1, -1, 2, 1, -3},
									//{-3, -1, 2, 3, 1 , 3 ,16},
									//{4,3,1,-6,-3,-2, -27}
								//};
	
	forma *equation;
	endodatio *b;
	equation = new forma((double *)e);
	b = new endodatio();
	equation->output_matrix();
	equation->eliminate();
	equation->substitute(b);
	equation->output_matrix();
	b->output();
	equation->test_solution(b);
	return 0;
}
