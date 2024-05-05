#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <assert.h>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <sstream>
#include <map>

#define ROWS 1000 // number of rows in matrixes
#define COLS 1000 // number of columns in matrixes

using namespace std;

// @brief populates and runs quicksort on array of size 10^magnitude
// @param magritude: number of elements in array (power of 10)
void sort_rand_array(int magnitude);

// @brief populates and multiplies matrixes of size 1^5 x 10^5
void mult_rand_matrix(int rows, int cols);