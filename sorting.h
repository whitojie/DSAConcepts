#include <iostream>
#include <string>
#include <vector>

using namespace std;

// SORTING ALGORITHMS //

/* Bubble Sort: index goes through list, if current num is greater than next, you switch them.
   Worst Case = n^2, Best Case = n, lameeeeee
*/

class Bubble {

};

/* Selection Sort: iterates through the whole list to find
smallest number, once it is found it is put at the end of the sublist
and does this until fully sorted, Best Case and Worst Case = n^2 */

class Selection {

};

/* Insertion Sort: creates two arrays, sorted and unsorted,
   it iteratively inserts each element of the unsorted list
   into its correct position
   Best Case = n, Worst Case = n^2
 */

class Insertion {

};

/* Merge Sort: Divide and Conquer, divides a list into
   its smallest unit (sometimes 1 element) and compare
   each element with the array next to it

   Worst Case = nlog(n), Best Case = Omega log(n) (cannot get any faster than that)
 */

class Merge{

};

/*
   Quick Sort: Uses a pivot, pick an number for pivot, used to compare to all
   values into one of each list that is less than, equal to, or greater than
   choose another pivot point to compare in each list, do this recursively

   Worst Case = n^2, Best Case = nlog(n)
*/

class Quick{

};

/*
    Heap Sort: Tree-based data structure, all levels
    are filled except from lowest, filled from left to right, takes a
    unsorted array and builds a max heap by heapify
    Max Heap: highest numbers are at the top

    Best Case = nlog(n), Worst Case = nlog(n)
*/
class Heap{

};

/*

   Shell Sort: Uses intervals, splits in half, compare the
   first of each array, if the first is larger than second,
   switch the other numbers in array, divide it again
   iterate over each using insertion

   Best Case = nlog(n), Worst Case = n^2

*/

class Shell {

};