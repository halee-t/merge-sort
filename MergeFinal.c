/*
    Merge Sort Extra Credit
    Halee Tisler
*/

#include <stdio.h>                                              //input output
#include <stdlib.h>                                             //allows random number generator

//this function put back together the split arrays
void Merge(int array[], int start, int mid, int end) {
    int i, j, k;
    int aSize = mid - start + 1;                                //arrayA is the first half
    int bSize = end - mid;                                      //arrayB is the second half
    int arrayA[aSize];
    int arrayB[bSize];

    for (i = 0; i < aSize; i++) {                              //populate arrayA with the first half of array
        arrayA[i] = array[start + i];
    }

    for (j = 0; j < bSize; j++) {                              //populate arrayB with the second half of array
        arrayB[j] = array[mid + 1 + j];
    }

    //reset from for loops
    i = 0;
    j = 0;
    k = start;



    while ((i < aSize) && (j < bSize)) {                      //populate sorted array while i and j are less than the size of their respective arrays      
        
        if (arrayA[i] <= arrayB[j]) {
            array[k] = arrayA[i];
            i++;                                              //INCREASE THE COUNT
        }

        else {
            array[k] = arrayB[j];
            j++;                                              //INCREASE THE COUNT
        }

        k++;                                                  //INCREASE THE COUNT

    }

    while (i < aSize) {                                       //In case anything is left over, fill it in
        array[k] = arrayA[i];
        i++;
        k++;
    }

    while (j < bSize) {                                       //In case anything is left over, fill it in
        array[k] = arrayB[j];
        j++;
        k++;
    }

}

void MergeSort(int a, int b, int array[]) {

    if (a < b) {

        int distance = b - a;                                   //calculate the distance between start and end of array
        int halfDistance = a + ((distance) / 2);                //find the midpoint

        MergeSort(a, halfDistance, array);                      //first half recurrsion
        MergeSort(halfDistance + 1, b, array);                 //second half recurrsion

        Merge(array, a, halfDistance, b);                      //when recurrsion is done, call merge
    }
}


void print(int Array[], int Size) {                             //prints the arrays, makes main neater
    for (int i = 0; i < Size; i++) {
	printf("%d ", Array[i]);
    }
    
    printf("\n");
}

void main() {
    const int size = 250;                                       //size of unsorted array
    int i = 0;
    int array[size];                                            //declare unsorted array

    for (i = 0; i < size; i++) {                                //populate the array with random numbers 
        array[i] = rand() % 100;
    }

    printf("Unsorted array: \n");                                

    print(array, size);                                         //print array

    printf("\n");

    i = 0;                                                      //reset i after the for loop
    int j = size;
    MergeSort(i, j - 1, array);                                 //j - 1 is used to stay within bounds 0 until size

    printf("Sorted array: \n");

    print(array, size);                                         //print array

}