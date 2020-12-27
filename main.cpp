#include "shared.h"

int main(int argc, char** args)
{
	int i,j;
	double e[][SIZE + 1]	 = { 
									{1, 1, -2,  1, 3, -1 , 4},
									{2, -1, 1, 2,  1, -3, 20},
									{1, 3,-3, -1, 2, 1, -15},
									{5, 2, -1, -1, 2, 1, -3},
									{-3, -1, 2, 3, 1 , 3 ,16},
									{4,3,1,-6,-3,-2, -27}
								};
	
	forma *a;
	endodatio *b;
	a = new forma((double *)e);
	b = new endodatio();
	a->output_matrix();
	a->eliminate();
	//a->output_matrix();
	a->substitute(b);
	a->output_matrix();
	b->output();
	return 0;
}
