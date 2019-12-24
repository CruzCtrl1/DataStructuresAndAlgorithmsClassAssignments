//Sample output at the bottom

#include <iostream>
#include <cstdlib> // For using rand and srand functions
#include <ctime> // For calling the time function
using namespace std;

int selectionSortCount = 0;
int mergeCount = 0;
int countingSortCount = 0;

void initializeArray(int array[], int min, int max, int size);
void selectionSort(int array[], int size);
void intSwapper(int &x, int &y);//Need to make sure you include the &
                                //for the parameters, otherwise only
                                //copies are made of the parameters, but a
                                //switch wont happen!

                                //Also make sure prototype and definition
                                //match! Otherwise, compiler thinks its an overloaded
                                //function
void displayArray(int array[], int size);
void mergeSort(int theArray[], int first, int last);
void merge(int theArray[], int first, int mid, int last);
void countingSort(int theArray[], int size);

int main()
{
    //Gets the system time everytime the program is run. Is unsigned
    //to be only positive numbers and zero
    unsigned seed = time(0);

    /*
    This seeds the random generator. Since time returns the number
    of seconds since midnight, this seed value should be different
    everytime the user runs the program.    
    */
    srand(seed);

    cout << "For task 1, here is the array unsorted: ";
    int dataSize = 10,
        dataStart = 0,
        dataEnd = 10;
    int data[dataSize];
    initializeArray(data, dataStart, dataEnd, dataSize);
    displayArray(data, dataSize);
    cout << "Now going to sort the array with selection sort: ";
    selectionSort(data, dataSize);
    displayArray(data, dataSize);
    cout << "The array was accessed " << selectionSortCount << " times "
         << "with selectionSort\n";   

    cout << "\nFor task 2, here is another array unsorted: ";
    int data2Size = 5,
        data2Start = 20,
        data2End = 40,
        startIndex = 0;
    int data2[data2Size];
    initializeArray(data2, data2Start, data2End, data2Size);
    displayArray(data2, data2Size);
    cout << "Now going to sort the array with mergeSort: ";
    mergeSort(data2, startIndex, data2Size - 1);
    displayArray(data2, data2Size);
    cout << "The array was accessed " << mergeCount << " times "
         << "with mergeSort\n";

    cout << "\nFor task 3, here is another array unsorted: ";
    int data3Size = 10,
        data3Start = 0,
        data3End = 100;
    int data3[data3Size];
    initializeArray(data3, data3Start, data3End, data3Size);
    displayArray(data3, data3Size);
    cout << "Now going to sort the array with countingSort: ";
    countingSort(data3, data3Size);
    displayArray(data3, data3Size);
    cout << "The array was accessed " << countingSortCount 
         << " times with countingSort\n";

    cout << "\nStarting task 4: ";
    int task4RangeStart = 1,
        task4RangeEnd = 100,
        task4len8 = 8,
        task4len32 = 32,
        task4len128 = 128;

    cout << "\nSelection sort with array size 8:\n";
    for(int arrayPass = 1; arrayPass <= 3; arrayPass++)
    {
        cout << "Pass " << arrayPass << ": ";
        selectionSortCount = 0; //Reseting to 0 to get accurate count
        int data4[task4len8];
        initializeArray(data4, task4RangeStart, task4RangeEnd, task4len8);
        displayArray(data4, task4len8);
        cout << "Now going to sort the array with selection sort: ";
        selectionSort(data4, task4len8);
        displayArray(data4, task4len8);
        cout << "The array was accessed " << selectionSortCount << " times "
             << "with selectionSort\n";  
    }
 

    cout << "\nSelection sort with array size 32:\n";
    for(int arrayPass = 1; arrayPass <= 3; arrayPass++)
    {
        cout << "Pass " << arrayPass << ": ";
        selectionSortCount = 0; //Reseting to 0 to get accurate count
        int data5[task4len32];
        initializeArray(data5, task4RangeStart, task4RangeEnd, task4len32);
        displayArray(data5, task4len32);
        cout << "Now going to sort the array with selection sort: ";
        selectionSort(data5, task4len32);
        displayArray(data5, task4len32);
        cout << "The array was accessed " << selectionSortCount << " times "
             << "with selectionSort\n";   
    }

    cout << "\nSelection sort with array size 128:\n";
    for(int arrayPass = 1; arrayPass <= 3; arrayPass++)
    {
        cout << "Pass " << arrayPass << ": ";
        selectionSortCount = 0; //Reseting to 0 to get accurate count
        int data6[task4len128];
        initializeArray(data6, task4RangeStart, task4RangeEnd, task4len128);
        displayArray(data6, task4len128);
        cout << "Now going to sort the array with selection sort: ";
        selectionSort(data6, task4len128);
        displayArray(data6, task4len128);
        cout << "The array was accessed " << selectionSortCount << " times "
             << "with selectionSort\n"; 
    }

    cout << "\nMerge sort with array size 8:\n";
    for(int arrayPass = 1; arrayPass <= 3; arrayPass++)
    {
        cout << "Pass " << arrayPass << ": ";
        mergeCount = 0;
        int data7[task4len8];
        initializeArray(data7, task4RangeStart, task4RangeEnd, task4len8);
        displayArray(data7, task4len8);
        cout << "Now going to sort the array with mergeSort: ";
        mergeSort(data7, startIndex, task4len8 - 1); //need length - 1 so doesn't write out of bounds
                                                    //eliminates max value of array otherwise.
        displayArray(data7, task4len8);
        cout << "The array was accessed " << mergeCount << " times "
             << "with mergeSort\n";
    }

    cout << "\nMerge sort with array size 32:\n";
    for(int arrayPass = 1; arrayPass <= 3; arrayPass++)
    {
        cout << "Pass " << arrayPass << ": ";
        mergeCount = 0;
        int data8[task4len32];
        initializeArray(data8, task4RangeStart, task4RangeEnd, task4len32);
        displayArray(data8, task4len32);
        cout << "Now going to sort the array with mergeSort: ";
        mergeSort(data8, startIndex, task4len32 - 1);
        displayArray(data8, task4len32);
        cout << "The array was accessed " << mergeCount << " times "
             << "with mergeSort\n";
    }

    cout << "\nMerge sort with array size 128:\n";
    for(int arrayPass = 1; arrayPass <= 3; arrayPass++)
    {
        cout << "Pass " << arrayPass << ": ";
        mergeCount = 0;
        int data9[task4len128];
        initializeArray(data9, task4RangeStart, task4RangeEnd, task4len128 - 1);
        displayArray(data9, task4len128);
        cout << "Now going to sort the array with mergeSort: ";
        mergeSort(data9, startIndex, task4len128);
        displayArray(data9, task4len128);
        cout << "The array was accessed " << mergeCount << " times "
             << "with mergeSort\n";
    }
    
    cout << "\nCounting sort with array size 8:\n";
    for(int arrayPass = 1; arrayPass <= 3; arrayPass++)
    {
        cout << "Pass " << arrayPass << ": ";
        countingSortCount = 0;
        int data10[task4len8];
        initializeArray(data10, task4RangeStart, task4RangeEnd, task4len8);
        displayArray(data10, task4len8);
        cout << "Now going to sort the array with countingSort: ";
        countingSort(data10, task4len8);
        displayArray(data10, task4len8);
        cout << "The array was accessed " << countingSortCount 
             << " times with countingSort\n";
    }
    
    cout << "\nCounting sort with array size 32:\n";
    for(int arrayPass = 1; arrayPass <= 3; arrayPass++)
    {
        cout << "Pass " << arrayPass << ": ";
        countingSortCount = 0;
        int data11[task4len32];
        initializeArray(data11, task4RangeStart, task4RangeEnd, task4len32);
        displayArray(data11, task4len32);
        cout << "Now going to sort the array with countingSort: ";
        countingSort(data11, task4len32);
        displayArray(data11, task4len32);
        cout << "The array was accessed " << countingSortCount 
             << " times with countingSort\n";
    }
    
    cout << "\nCounting sort with array size 128:\n";
    for(int arrayPass = 1; arrayPass <= 3; arrayPass++)
    {
        cout << "Pass " << arrayPass << ": ";
        countingSortCount = 0;
        int data12[task4len128];
        initializeArray(data12, task4RangeStart, task4RangeEnd, task4len128);
        displayArray(data12, task4len128);
        cout << "Now going to sort the array with countingSort: ";
        countingSort(data12, task4len128);
        displayArray(data12, task4len128);
        cout << "The array was accessed " << countingSortCount 
             << " times with countingSort\n";
    }

    return 0;
}

void initializeArray(int array[], int min, int max, int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = (rand() % (max - min + 1)) + min; 
    }
}

void selectionSort(int array[], int size)
{   
    for(int i = 0; i < size - 1; i++)
    {
        int minInt = array[i];
        selectionSortCount += 1;
        int minIndex = i;
        for(int j = i + 1; j < size; j++)
        {
            if(minInt > array[j]) //Dont use array[i] when comparing!
                                  //Malfunctions for some reason
            {
                selectionSortCount += 2;
                minInt = array[j];
                selectionSortCount += 1;
                minIndex = j;
            }
        
        }
        intSwapper(array[i], array[minIndex]);
        selectionSortCount += 2;
    }
}

void intSwapper(int &x, int &y) //Need to make sure you include the &
                              //for the parameters, otherwise only
                              //copies are made of the parameters, but a
                              //switch wont happen!
{
    int temp = x;
    x = y;
    y = temp;
}

void displayArray(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }   
    cout << endl;
}

// perform mergeSort on theArray between indices first and last
void mergeSort(int theArray[], int first, int last) 
{
    if (first < last) 
    {
        // Sort each half
        int mid = first + (last - first) / 2; // Sort left half theArray[first..mid]
                                              // Index of midpoint
        mergeSort(theArray, first, mid);
        // Sort right half theArray[mid+1..last]
        mergeSort(theArray, mid + 1, last);
        // Merge the two halves
        merge(theArray, first, mid, last); 
    } // end if
} // end mergeSort

void merge(int theArray[], int first, int mid, int last) 
{
    int arraySize = last;
    int tempArray[arraySize]; // Temporary array
    // Initialize the local indices to indicate the subarrays
    int first1 = first; // Beginning of first subarray 
    int last1 = mid; // End of first subarray
    int first2 = mid + 1; // Beginning of second subarray
    int last2 = last; // End of second subarray

    // While both subarrays are not empty, copy the
    // smaller item into the temporary array
    int index = first1; // Next available location in tempArray 
    while ((first1 <= last1) && (first2 <= last2))
    {
    // At this point, tempArray[first..index-1] is in order
    if (theArray[first1] <= theArray[first2]) 
        {
            mergeCount += 2; //For the if statement above
            tempArray[index] = theArray[first1];
            mergeCount += 1; //for accessing theArray[first1]
            first1++; 
        }
    else
        {
            tempArray[index] = theArray[first2]; 
            mergeCount += 1; //for accessing theArray[first2]
            first2++;
        } // end if
        index++;
    } // end while
    // Finish off the first subarray, if necessary
    while (first1 <= last1) 
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first1]; 
        mergeCount += 1; //for accessing theArray[first1]
        first1++;
        index++;
    }// end while
    // Finish off the second subarray, if necessary
    while (first2 <= last2) 
    {
        // At this point, tempArray[first..index-1] is in order
        tempArray[index] = theArray[first2];
        mergeCount += 1; //for accessing theArray[first2]
        first2++;
        index++;
    } // end for
    // Copy the result back into the original array
    for (index = first; index <= last; index++) 
    {
        theArray[index] = tempArray[index];
        mergeCount += 1; //Writing to theArray[]
    }
} // end merge

void countingSort(int theArray[], int size)
{
    int arraySize = size;
    int countSize = 101; //Because 0 - 100 inclusive, so size = 101
    int count[countSize];
    //Initialize the array elements to 0
    for(int i = 0; i < countSize; i++)
    {
        count[i] = 0;
    }

    for(int i = 0; i < arraySize; i++)
    {
        count[theArray[i]]++; 
        //Count is incremented by 1 at the index that
        //theArray[i] identifies

        countingSortCount += 1; //accessing theArray[i]
    }

    int i = 0;
    for(int j = 0; j < countSize; j++)
    {
        for(int k = count[j]; k > 0; k--)
        {
            theArray[i] = j;
            countingSortCount += 1; //Writing to theArray[i]
            i++;
        }
    }
}

/*
Sample output:
[ccruz9@hills CS110C]$ ./a.out
For task 1, here is the array unsorted: 8 7 4 2 3 7 6 5 8 0 
Now going to sort the array with selection sort: 0 2 3 4 5 6 7 7 8 8 
The array was accessed 60 times with selectionSort

For task 2, here is another array unsorted: 23 22 40 37 25 
Now going to sort the array with mergeSort: 22 23 25 37 40 
The array was accessed 32 times with mergeSort

For task 3, here is another array unsorted: 1 98 96 22 0 100 62 63 68 6 
Now going to sort the array with countingSort: 0 1 6 22 62 63 68 96 98 100 
The array was accessed 20 times with countingSort

Starting task 4: 
Selection sort with array size 8:
Pass 1: 23 48 34 76 94 72 69 43 
Now going to sort the array with selection sort: 23 34 43 48 69 72 76 94 
The array was accessed 45 times with selectionSort
Pass 2: 99 81 58 67 73 45 13 41 
Now going to sort the array with selection sort: 13 41 45 58 67 73 81 99 
The array was accessed 54 times with selectionSort
Pass 3: 63 75 84 99 47 65 22 96 
Now going to sort the array with selection sort: 22 47 63 65 75 84 96 99 
The array was accessed 51 times with selectionSort

Selection sort with array size 32:
Pass 1: 25 85 78 32 30 61 71 5 60 4 32 54 28 100 48 26 32 5 92 4 2 56 44 64 31 80 62 29 44 36 25 21 
Now going to sort the array with selection sort: 2 4 4 5 5 21 25 25 26 28 29 30 31 32 32 32 36 44 44 48 54 56 60 61 62 64 71 78 80 85 92 100 
The array was accessed 339 times with selectionSort
Pass 2: 72 2 4 1 14 74 57 74 78 40 79 5 40 26 82 23 83 73 27 84 81 22 99 11 1 13 91 97 100 67 69 71 
Now going to sort the array with selection sort: 1 1 2 4 5 11 13 14 22 23 26 27 40 40 57 67 69 71 72 73 74 74 78 79 81 82 83 84 91 97 99 100 
The array was accessed 276 times with selectionSort
Pass 3: 69 72 23 82 45 80 7 74 71 85 30 62 11 11 85 45 84 11 80 64 84 78 26 37 90 68 33 89 35 53 11 3 
Now going to sort the array with selection sort: 3 7 11 11 11 11 23 26 30 33 35 37 45 45 53 62 64 68 69 71 72 74 78 80 80 82 84 84 85 85 89 90 
The array was accessed 312 times with selectionSort

Selection sort with array size 128:
Pass 1: 24 34 36 20 65 43 94 35 79 23 97 89 34 81 85 69 43 64 84 26 42 9 62 83 76 46 24 62 98 34 16 73 67 52 93 31 46 86 18 24 60 14 65 93 46 49 13 88 13 96 65 6 56 79 40 84 76 15 45 26 1 61 98 67 64 42 50 9 79 19 84 39 32 100 83 29 1 96 16 13 43 32 70 99 10 61 82 38 76 26 63 76 86 12 94 49 54 95 9 84 13 45 22 96 44 57 24 44 4 39 8 46 23 29 44 32 90 25 21 65 3 83 92 40 95 85 89 100 
Now going to sort the array with selection sort: 1 1 3 4 6 8 9 9 9 10 12 13 13 13 13 14 15 16 16 18 19 20 21 22 23 23 24 24 24 24 25 26 26 26 29 29 31 32 32 32 34 34 34 35 36 38 39 39 40 40 42 42 43 43 43 44 44 44 45 45 46 46 46 46 49 49 50 52 54 56 57 60 61 61 62 62 63 64 64 65 65 65 65 67 67 69 70 73 76 76 76 76 79 79 79 81 82 83 83 83 84 84 84 84 85 85 86 86 88 89 89 90 92 93 93 94 94 95 95 96 96 96 97 98 98 99 100 100 
The array was accessed 1572 times with selectionSort
Pass 2: 80 49 83 44 93 57 40 89 13 63 84 16 54 44 61 76 24 57 59 13 81 80 29 35 62 72 75 8 57 15 7 88 63 90 31 8 46 70 48 10 33 83 25 38 26 37 13 50 93 71 14 26 50 95 60 64 66 34 71 74 48 30 61 63 71 44 22 68 13 69 77 97 51 1 34 29 89 98 30 82 69 95 7 70 89 18 85 7 4 56 80 51 37 93 65 7 36 38 74 100 6 2 97 9 2 82 89 42 80 18 23 100 12 81 21 53 99 6 59 2 13 38 4 49 82 21 7 17 
Now going to sort the array with selection sort: 1 2 2 2 4 4 6 6 7 7 7 7 7 8 8 9 10 12 13 13 13 13 13 14 15 16 17 18 18 21 21 22 23 24 25 26 26 29 29 30 30 31 33 34 34 35 36 37 37 38 38 38 40 42 44 44 44 46 48 48 49 49 50 50 51 51 53 54 56 57 57 57 59 59 60 61 61 62 63 63 63 64 65 66 68 69 69 70 70 71 71 71 72 74 74 75 76 77 80 80 80 80 81 81 82 82 82 83 83 84 85 88 89 89 89 89 90 93 93 93 95 95 97 97 98 99 100 100 
The array was accessed 1548 times with selectionSort
Pass 3: 58 32 17 16 33 65 76 86 46 64 27 77 81 2 28 44 82 1 96 32 6 6 85 70 96 41 70 77 13 76 94 70 7 62 37 91 26 12 76 23 75 2 52 7 3 31 3 37 31 50 68 88 56 5 57 3 45 78 79 57 53 24 78 11 85 15 53 62 78 28 85 53 30 88 11 84 18 13 20 49 63 40 88 70 96 97 72 92 74 2 100 79 26 77 41 62 43 94 24 21 21 60 25 2 99 35 86 16 100 57 16 62 48 4 83 95 52 54 86 25 7 37 3 32 66 44 46 8 
Now going to sort the array with selection sort: 1 2 2 2 2 3 3 3 3 4 5 6 6 7 7 7 8 11 11 12 13 13 15 16 16 16 17 18 20 21 21 23 24 24 25 25 26 26 27 28 28 30 31 31 32 32 32 33 35 37 37 37 40 41 41 43 44 44 45 46 46 48 49 50 52 52 53 53 53 54 56 57 57 57 58 60 62 62 62 62 63 64 65 66 68 70 70 70 70 72 74 75 76 76 76 77 77 77 78 78 78 79 79 81 82 83 84 85 85 85 86 86 86 88 88 88 91 92 94 94 95 96 96 96 97 99 100 100 
The array was accessed 1545 times with selectionSort

Merge sort with array size 8:
Pass 1: 37 21 80 9 80 56 11 78 
Now going to sort the array with mergeSort: 9 11 21 37 56 78 80 80 
The array was accessed 64 times with mergeSort
Pass 2: 91 48 45 90 56 13 3 4 
Now going to sort the array with mergeSort: 3 4 13 45 48 56 90 91 
The array was accessed 58 times with mergeSort
Pass 3: 16 37 50 67 42 88 43 48 
Now going to sort the array with mergeSort: 16 37 42 43 48 50 67 88 
The array was accessed 70 times with mergeSort

Merge sort with array size 32:
Pass 1: 24 46 80 89 41 77 49 77 97 28 85 28 84 95 5 26 94 1 67 50 13 21 5 80 57 54 98 98 41 41 45 65 
Now going to sort the array with mergeSort: 1 5 5 13 21 24 26 28 28 41 41 41 45 46 49 50 54 57 65 67 77 77 80 80 84 85 89 94 95 97 98 98 
The array was accessed 450 times with mergeSort
Pass 2: 86 76 53 26 52 53 54 100 81 90 27 16 37 31 41 30 84 59 79 96 79 83 76 35 89 73 32 29 65 28 45 2 
Now going to sort the array with mergeSort: 2 16 26 27 28 29 30 31 32 35 37 41 45 52 53 53 54 59 65 73 76 76 79 79 81 83 84 86 89 90 96 100 
The array was accessed 422 times with mergeSort
Pass 3: 4 50 79 7 2 32 7 34 22 33 49 10 16 41 39 99 99 70 46 77 52 73 63 92 46 46 73 62 74 17 64 29 
Now going to sort the array with mergeSort: 2 4 7 7 10 16 17 22 29 32 33 34 39 41 46 46 46 49 50 52 62 63 64 70 73 73 74 77 79 92 99 99 
The array was accessed 452 times with mergeSort

Merge sort with array size 128:
Pass 1: 18 42 35 20 26 93 5 47 78 6 8 45 46 46 43 97 15 40 25 19 13 40 10 10 85 82 71 58 51 34 86 68 76 73 39 1 17 96 99 94 1 6 38 98 3 32 46 70 72 71 88 84 62 49 93 46 83 15 4 33 49 41 52 76 65 43 28 82 38 78 27 90 35 17 87 37 48 33 6 71 55 45 6 16 94 50 61 76 65 16 60 13 9 63 40 73 5 67 54 94 44 33 83 30 49 70 18 96 54 76 19 60 20 24 75 65 74 87 92 38 55 51 2 63 14 93 35 0 
Now going to sort the array with mergeSort: 0 1 1 2 3 4 5 5 6 6 6 6 8 9 10 10 13 13 14 15 15 16 16 17 17 18 18 19 19 20 20 24 25 26 27 28 30 32 33 33 33 34 35 35 35 37 38 38 38 39 40 40 40 41 42 43 43 44 45 45 46 46 46 46 47 48 49 49 49 50 51 51 52 54 54 55 55 58 60 60 61 62 63 63 65 65 65 67 68 70 70 71 71 71 72 73 73 74 75 76 76 76 76 78 78 82 82 83 83 84 85 86 87 87 88 90 92 93 93 93 94 94 94 96 96 97 98 99 
The array was accessed 2570 times with mergeSort
Pass 2: 70 59 41 16 54 73 98 83 21 19 52 68 24 27 86 83 47 62 57 11 87 96 3 76 50 5 29 12 70 21 46 40 79 38 55 84 10 4 18 82 23 69 50 46 96 87 81 42 100 37 4 86 32 58 61 81 63 89 44 32 61 42 23 39 79 77 74 89 33 91 70 7 60 71 4 7 58 84 48 9 21 3 95 4 61 7 37 75 48 80 6 8 21 81 99 100 9 72 40 41 15 9 47 74 32 51 32 41 34 79 49 6 33 43 10 45 2 98 19 49 29 77 8 2 57 6 1 0 
Now going to sort the array with mergeSort: 0 1 2 2 3 3 4 4 4 4 5 6 6 6 7 7 7 8 8 9 9 9 10 10 11 12 15 16 18 19 19 21 21 21 21 23 23 24 27 29 29 32 32 32 32 33 33 34 37 37 38 39 40 40 41 41 41 42 42 43 44 45 46 46 47 47 48 48 49 49 50 50 51 52 54 55 57 57 58 58 59 60 61 61 61 62 63 68 69 70 70 70 71 72 73 74 74 75 76 77 77 79 79 79 80 81 81 81 82 83 83 84 84 86 86 87 87 89 89 91 95 96 96 98 98 99 100 100 
The array was accessed 2584 times with mergeSort
Pass 3: 65 30 92 6 44 52 4 69 83 54 100 23 40 30 72 45 62 66 6 7 67 55 25 67 84 1 75 85 9 32 37 74 61 80 79 56 31 34 24 66 88 23 88 79 4 11 75 66 29 33 24 47 87 100 66 22 53 40 6 61 23 94 34 84 73 64 39 56 98 15 21 37 89 60 15 93 23 41 10 51 73 33 49 60 84 14 33 36 5 91 97 28 84 82 63 9 98 53 64 95 67 36 83 56 95 49 48 17 89 9 19 62 41 68 73 76 81 5 12 38 95 60 65 31 93 27 39 0 
Now going to sort the array with mergeSort: 0 1 4 4 5 5 6 6 6 7 9 9 9 10 11 12 14 15 15 17 19 21 22 23 23 23 23 24 24 25 27 28 29 30 30 31 31 32 33 33 33 34 34 36 36 37 37 38 39 39 40 40 41 41 44 45 47 48 49 49 51 52 53 53 54 55 56 56 56 60 60 60 61 61 62 62 63 64 64 65 65 66 66 66 66 67 67 67 68 69 72 73 73 73 74 75 75 76 79 79 80 81 82 83 83 84 84 84 84 85 87 88 88 89 89 91 92 93 93 94 95 95 95 97 98 98 100 100 
The array was accessed 2606 times with mergeSort

Counting sort with array size 8:
Pass 1: 90 79 54 36 98 89 18 53 
Now going to sort the array with countingSort: 18 36 53 54 79 89 90 98 
The array was accessed 16 times with countingSort
Pass 2: 35 66 52 4 7 60 22 20 
Now going to sort the array with countingSort: 4 7 20 22 35 52 60 66 
The array was accessed 16 times with countingSort
Pass 3: 52 89 92 27 22 48 38 59 
Now going to sort the array with countingSort: 22 27 38 48 52 59 89 92 
The array was accessed 16 times with countingSort

Counting sort with array size 32:
Pass 1: 43 49 75 25 42 53 15 31 31 68 19 28 8 36 32 94 54 83 97 60 94 19 79 45 59 22 72 32 69 61 42 63 
Now going to sort the array with countingSort: 8 15 19 19 22 25 28 31 31 32 32 36 42 42 43 45 49 53 54 59 60 61 63 68 69 72 75 79 83 94 94 97 
The array was accessed 64 times with countingSort
Pass 2: 62 16 87 55 68 1 85 51 20 3 30 79 91 62 73 44 96 21 55 90 39 85 86 50 6 9 81 26 22 23 89 83 
Now going to sort the array with countingSort: 1 3 6 9 16 20 21 22 23 26 30 39 44 50 51 55 55 62 62 68 73 79 81 83 85 85 86 87 89 90 91 96 
The array was accessed 64 times with countingSort
Pass 3: 90 27 37 58 80 73 8 51 28 89 30 70 50 54 13 98 74 19 87 65 3 72 66 60 33 46 85 54 20 25 36 10 
Now going to sort the array with countingSort: 3 8 10 13 19 20 25 27 28 30 33 36 37 46 50 51 54 54 58 60 65 66 70 72 73 74 80 85 87 89 90 98 
The array was accessed 64 times with countingSort

Counting sort with array size 128:
Pass 1: 52 24 67 83 96 26 33 75 14 14 44 16 67 8 13 93 26 51 9 80 22 74 39 54 19 76 59 91 100 94 100 3 69 18 85 65 43 70 91 8 83 35 23 2 94 87 94 20 37 54 99 11 27 90 16 97 65 75 87 64 20 86 19 89 3 55 5 97 24 95 57 59 81 79 60 75 18 5 46 54 58 44 64 36 85 80 32 49 54 19 65 73 56 83 61 11 37 65 59 13 12 15 71 92 46 30 66 63 86 11 16 43 7 80 30 43 11 61 92 64 31 8 88 39 42 49 49 30 
Now going to sort the array with countingSort: 2 3 3 5 5 7 8 8 8 9 11 11 11 11 12 13 13 14 14 15 16 16 16 18 18 19 19 19 20 20 22 23 24 24 26 26 27 30 30 30 31 32 33 35 36 37 37 39 39 42 43 43 43 44 44 46 46 49 49 49 51 52 54 54 54 54 55 56 57 58 59 59 59 60 61 61 63 64 64 64 65 65 65 65 66 67 67 69 70 71 73 74 75 75 75 76 79 80 80 80 81 83 83 83 85 85 86 86 87 87 88 89 90 91 91 92 92 93 94 94 94 95 96 97 97 99 100 100 
The array was accessed 256 times with countingSort
Pass 2: 65 59 42 28 74 12 20 71 93 37 33 78 100 100 72 58 31 1 100 41 14 43 56 44 2 44 34 43 44 82 73 60 93 66 88 18 30 59 88 22 95 72 52 94 71 75 3 2 28 3 94 41 97 2 36 99 97 70 41 40 3 65 51 95 31 38 12 12 96 99 85 43 70 88 88 93 63 91 46 90 45 91 82 41 92 17 39 88 86 32 79 41 48 30 35 30 19 99 41 67 49 26 9 71 13 48 63 27 90 60 16 34 50 49 27 42 66 17 29 3 48 60 43 48 89 30 77 7 
Now going to sort the array with countingSort: 1 2 2 2 3 3 3 3 7 9 12 12 12 13 14 16 17 17 18 19 20 22 26 27 27 28 28 29 30 30 30 30 31 31 32 33 34 34 35 36 37 38 39 40 41 41 41 41 41 41 42 42 43 43 43 43 44 44 44 45 46 48 48 48 48 49 49 50 51 52 56 58 59 59 60 60 60 63 63 65 65 66 66 67 70 70 71 71 71 72 72 73 74 75 77 78 79 82 82 85 86 88 88 88 88 88 89 90 90 91 91 92 93 93 93 94 94 95 95 96 97 97 99 99 99 100 100 100 
The array was accessed 256 times with countingSort
Pass 3: 28 18 73 76 95 33 98 59 81 60 86 70 19 53 56 69 2 82 62 67 50 42 69 98 1 64 97 41 93 73 48 72 42 72 99 36 57 97 95 89 8 80 10 27 32 65 47 85 98 60 51 48 1 72 97 54 35 93 94 79 17 93 50 59 65 100 46 73 96 40 61 4 71 70 82 55 35 80 39 84 39 42 31 39 13 27 92 99 71 38 29 88 30 30 46 94 29 91 66 77 83 78 80 5 48 13 11 34 92 50 17 30 43 48 20 7 26 64 5 97 1 85 36 30 14 81 76 94 
Now going to sort the array with countingSort: 1 1 1 2 4 5 5 7 8 10 11 13 13 14 17 17 18 19 20 26 27 27 28 29 29 30 30 30 30 31 32 33 34 35 35 36 36 38 39 39 39 40 41 42 42 42 43 46 46 47 48 48 48 48 50 50 50 51 53 54 55 56 57 59 59 60 60 61 62 64 64 65 65 66 67 69 69 70 70 71 71 72 72 72 73 73 73 76 76 77 78 79 80 80 80 81 81 82 82 83 84 85 85 86 88 89 91 92 92 93 93 93 94 94 94 95 95 96 97 97 97 97 98 98 98 99 99 100 
The array was accessed 256 times with countingSort
[ccruz9@hills CS110C]$ exit

*/