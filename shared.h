#ifndef SHARED_INCLUDES_HEADER
	#define SHARED_INCLUDES_HEADER
	#define SIZE 1000

	#include <stdio.h>		// printf 
	#include <stdlib.h>		// abs 
	#include <assert.h>
	#include <math.h>		// pow
	#include <time.h>		// time
	#include <iostream>
	
	using namespace std;

	int main();
	
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

	#include "forma.h"
#endif
