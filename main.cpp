// Implement and exemplify correctness of bottom-up build heap procedure
//  Implement and exemplify correctness of heapsort
//  Implement and exemplify correctness of top-down build heap procedure
// 1. You are required to compare the two build heap procedures in the average case.
// Remember that for the average case you have to repeat the measurements m times (m=5)
// and report their average; also for the average case, make sure you always use the same
// input sequence for the two methods – to make the comparison fair.
// 2. This is how the analysis should be performed:
// - vary the dimension of the input array (n) between [100…10000], with an increment
// of maximum 500 (we suggest 100).
// - for each dimension, generate the appropriate input sequence for the method; run the
// method, counting the operations (assignments and comparisons, may be counted
// together for this assignment).
// ! Only the assignments and comparisons performed on the input structure and its
// corresponding auxiliary variables matter.
// Generate a chart which compares the two methods under the total number of operations,
// in the average case. If one of the curves cannot be visualized correctly because the other
// has a larger growth rate, place that curve on a separate chart as well. Name your chart
// and the curves on it appropriately.
// code begins here:
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "Profiler.h"
#include <algorithm>


using namespace std;
// global variables
int n; // number of elements in the array
int *a; // array of elements

Profiler profiler("HeapSort");



// function prototypes
void bottom_up_build_heap(int *a, int n);
void top_down_build_heap(int *a, int n);
void heapsort(int *a, int n);
void print_array(int *a, int n);
void swap(int &x, int &y);
void generate_random_array(int *a, int n);
void generate_sorted_array(int *a, int n);
void generate_reversed_array(int *a, int n);
void generate_almost_sorted_array(int *a, int n);
void generate_random_array_with_duplicates(int *a, int n);
void generate_random_array_with_few_unique_values(int *a, int n);
void generate_random_array_with_many_unique_values(int *a, int n);
void array_by_user(int *a, int n);




int main()
{ // main function
int choice;
int *a;
int n;
int i;
int j;

cout << "Enter the number of elements in the array: ";
cin >> n;
a = new int[n];
cout << "Enter the choice of the input array: " << endl;
cout << "1. Random array" << endl;
cout << "2. Sorted array" << endl;
cout << "3. Reversed array" << endl;
cout << "4. Almost sorted array" << endl;
cout << "5. Random array with duplicates" << endl;
cout << "6. Random array with few unique values" << endl;
cout << "7. Random array with many unique values" << endl;
cout << "8. Array by user" << endl;
cout << "9. generate raports" << endl;
cin >> choice;
switch (choice)
{
case 1:
generate_random_array(a, n);
break;
case 2:
generate_sorted_array(a, n);
break;
case 3:
generate_reversed_array(a, n);
break;
case 4:
generate_almost_sorted_array(a, n);
break;
case 5:
generate_random_array_with_duplicates(a, n);
break;
case 6:
generate_random_array_with_few_unique_values(a, n);
break;
case 7:
generate_random_array_with_many_unique_values(a, n);
break;
case 8:
array_by_user(a, n);
break;
case 9: {
int m = 5;
int n = 10;
int increment = 10;
int max = 100;
int *a = new int[n];
int *b = new int[n];
int *c = new int[n];

for (int i = 0; i < m; i++) {
for (int j = n; j <= max; j += increment) {
generate_random_array(a, j);
top_down_build_heap(a, j);
bottom_up_build_heap(a, j);
heapsort(a, j);
}
}



profiler.createGroup("Bottom-up build heap", "Assignments_bottom", "Comparisons_bottom"); // create a group of operations
profiler.createGroup("Top-down build heap", "Assignments_top", "Comparisons_top"); // create a group of operations
profiler.createGroup("Heapsort", "Assignments", "Comparisons"); // create a group of operations 

profiler.divideValues("Assignments", m);
profiler.divideValues("Comparisons", m);
profiler.divideValues("Assignments_bottom", m);
profiler.divideValues("Comparisons_bottom", m);
profiler.divideValues("Assignments_top", m);
profiler.divideValues("Comparisons_top", m);


profiler.showReport();









break;
}

default:
cout << "Invalid choice" << endl;
break;
}
cout << "The input array is: " << endl;
print_array(a, n);
cout << "The bottom-up build heap procedure: " << endl;
bottom_up_build_heap(a, n);
cout << "The top-down build heap procedure: " << endl;
top_down_build_heap(a, n);
cout << "The heapsort procedure: " << endl;
heapsort(a, n);
cout << "The sorted array is: " << endl;
print_array(a, n);
return 0;


} // end main function



void bottom_up_build_heap(int *a, int n)
{ // bottom-up build heap procedure
int i; // index of the current element
int j; // index of the parent of the current element
int k; // index of the largest element
int x; // auxiliary variable
int *b; // auxiliary array
Operation Assignments = profiler.createOperation("Assignments_bottom", n);
Operation Comparisons = profiler.createOperation("Comparisons_bottom", n);
b = new int[n];  // allocate memory for the auxiliary array
for (i = 0; i < n; i++) // copy the elements of the input array into the auxiliary array
{
b[i] = a[i]; // copy the elements of the input array into the auxiliary array
}
for (i = 1; i < n; i++) // for each element in the array
{
j = i; // set the index of the current element
k = (j - 1) / 2; // set the index of the parent of the current element
while (j > 0 && b[k] < b[j]) // while the current element is larger than its parent
{
x = b[j]; // swap the current element with its parent
b[j] = b[k];
b[k] = x;
Assignments.count(3);
Comparisons.count();
j = k; // set the index of the current element
k = (j - 1) / 2; // set the index of the parent of the current element
}
}
cout << "The bottom-up build heap procedure: " << endl;
print_array(b, n); // print the auxiliary array
delete[] b; // deallocate memory for the auxiliary array
} // end bottom-up build heap procedure




void top_down_build_heap(int *a, int n)
{ // top-down build heap procedure
int i; // index of the current element
int j; // index of the largest element
int k; // index of the left child of the current element
int x; // auxiliary variable
int *b; // auxiliary array
Operation Assignments = profiler.createOperation("Assignments_top", n);
Operation Comparisons = profiler.createOperation("Comparisons_top", n);
b = new int[n]; // allocate memory for the auxiliary array
for (i = 0; i < n; i++) // copy the elements of the input array into the auxiliary array
{
b[i] = a[i]; // copy the elements of the input array into the auxiliary array
}
for (i = (n - 2) / 2; i >= 0; i--) // for each element in the array
{
k = 2 * i + 1; // set the index of the left child of the current element
j = i; // set the index of the current element
while (k < n) // while the current element has a left child
{
if (k + 1 < n) // if the current element has a right child
{
if (b[k] < b[k + 1]) // if the left child is smaller than the right child
{
k++; // set the index of the largest element to the index of the right child
}
}
if (b[j] < b[k]) // if the current element is smaller than the largest element
{
x = b[j]; // swap the current element with the largest element
b[j] = b[k];
b[k] = x;
Assignments.count(3);
Comparisons.count();
j = k; // set the index of the current element
k = 2 * j + 1; // set the index of the left child of the current element
}
else
{
break;
}
}
}
cout << "The top-down build heap procedure: " << endl;
print_array(b, n); // print the auxiliary array
delete[] b; // deallocate memory for the auxiliary array
} // end top-down build heap procedure


void heapsort(int *a , int n)
{ // heapsort procedure
int i; // index of the current element
int j; // index of the largest element
int k; // index of the left child of the current element
int x; // auxiliary variable
int *b; // auxiliary array
Operation Assignments = profiler.createOperation("Assignments", n);
Operation Comparisons = profiler.createOperation("Comparisons", n);
b = new int[n]; // allocate memory for the auxiliary array
for (i = 0; i < n; i++) // copy the elements of the input array into the auxiliary array
{
b[i] = a[i]; // copy the elements of the input array into the auxiliary array
}
for (i = (n - 2) / 2; i >= 0; i--) // for each element in the array
{
k = 2 * i + 1; // set the index of the left child of the current element
j = i; // set the index of the current element
while (k < n) // while the current element has a left child
{
if (k + 1 < n) // if the current element has a right child
{
if (b[k] < b[k + 1]) // if the left child is smaller than the right child
{
k++; // set the index of the largest element to the index of the right child
}
}
if (b[j] < b[k]) // if the current element is smaller than the largest element
{
x = b[j]; // swap the current element with the largest element
b[j] = b[k];
b[k] = x;
Assignments.count(3);
Comparisons.count();
j = k; // set the index of the current element
k = 2 * j + 1; // set the index of the left child of the current element
}
else
{
break;
}
}
}
for (i = n - 1; i > 0; i--) // for each element in the array
{
x = b[0]; // swap the first element with the last element
b[0] = b[i];
b[i] = x;
Assignments.count(3);
j = 0; // set the index of the current element
k = 2 * j + 1; // set the index of the left child of the current element
while (k < i) // while the current element has a left child
{
if (k + 1 < i) // if the current element has a right child
{
if (b[k] < b[k + 1]) // if the left child is smaller than the right child
{
k++; // set the index of the largest element to the index of the right child
}
}
if (b[j] < b[k]) // if the current element is smaller than the largest element
{
x = b[j]; // swap the current element with the largest element
b[j] = b[k];
b[k] = x;
Assignments.count(3);
Comparisons.count();
j = k; // set the index of the current element
k = 2 * j + 1; // set the index of the left child of the current element
}
else
{
break;
}
}
}
cout << "The heapsort procedure: " << endl;
print_array(b, n); // print the auxiliary array
delete[] b; // deallocate memory for the auxiliary array
} // end heapsort procedure




void print_array(int *a, int n)
{ // print array procedure
int i; // index of the current element
for (i = 0; i < n; i++) // loop to print the array
{
cout << a[i] << " ";
}
cout << endl;
} // end print array procedure



void print_array(int *a, int n, ofstream &fout)
{ // print array
int i;
for (i = 0; i < n; i++)
fout << a[i] << " ";
fout << endl;
}

void swap(int &x, int &y)
{ // swap two elements
int temp;
temp = x;
x = y;
y = temp;
}

void generate_random_array(int *a, int n)
{ // generate random array
int i;
srand(time(NULL));
for (i = 0; i < n; i++)
a[i] = rand() % 100;
}

void generate_sorted_array(int *a, int n)
{ // generate sorted array
int i;
for (i = 0; i < n; i++)
a[i] = i;
}

void generate_reversed_array(int *a, int n)
{ // generate reversed array
int i;
for (i = 0; i < n; i++)
a[i] = n - i - 1;
}

void generate_almost_sorted_array(int *a, int n)
{ // generate almost sorted array
int i;
for (i = 0; i < n; i++)
a[i] = i;
for (i = 0; i < n / 10; i++)
swap(a[rand() % n], a[rand() % n]);
}

void generate_random_array_with_duplicates(int *a, int n)
{ // generate random array with duplicates
int i;
srand(time(NULL));
for (i = 0; i < n; i++)
a[i] = rand() % 10;
}

void generate_random_array_with_few_unique_values(int *a, int n)
{ // generate random array with few unique values
int i;
srand(time(NULL));
for (i = 0; i < n; i++)
a[i] = rand() % 10;
}

void generate_random_array_with_many_unique_values(int *a, int n)
{ // generate random array with many unique values
int i;
srand(time(NULL));
for (i = 0; i < n; i++)
a[i] = rand() % 100;
}

void array_by_user(int *a, int n)
{ // array by user
int i;
for (i = 0; i < n; i++)
{
cout << "Enter element " << i << ": ";
cin >> a[i];
}
}




