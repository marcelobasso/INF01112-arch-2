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

#define R1 100000 // number of rows in Matrix-1
#define C1 1000 // number of columns in Matrix-1
#define R2 1000 // number of rows in Matrix-2
#define C2 100000 // number of columns in Matrix-2

using namespace std;

// @brief populates and runs quicksort on array of size 10^magnitude
// @param magritude: number of elements in array (power of 10)
void sortRandArray(int magnitude);
void stable_quicksort(vector<pair<int, unsigned long>>& c, int lo, int hi);