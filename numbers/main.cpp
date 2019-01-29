#include <string>
#include <fstream>

#define COLUMN_NUMBER 5

// merge two sorted arrays
void merge(double arr1[], double arr2[], double sortedarray[]) {
    int i = 0, j = 0, k = 0;
    while(i < COLUMN_NUMBER and j < COLUMN_NUMBER) {
        if(arr1[i] < arr2[j])
            sortedarray[k++] = arr1[i++];
        else
            sortedarray[k++] = arr2[j++];
    }

    while(i < COLUMN_NUMBER) {
        sortedarray[k++] = arr1[i++];
    }

    while(j < COLUMN_NUMBER) {
        sortedarray[k++] = arr2[j++];
    }
}

// sort using bubble sort
void sort(double arr[]) {
    int tmp;
    for(int i = 0; i < COLUMN_NUMBER - 1; i++) {
        for(int j = 0; j < COLUMN_NUMBER - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;    
            }
        }
    }
}

// Funkcja read
void read(const std::string & fileName, double arr[]) {
    std::ifstream is(fileName);
    if(is) { 
        int counter = 0;
        while(!is.eof()) {
            int number;
            for(int i = 0; i < COLUMN_NUMBER; i++) {
                is >> number;
                arr[i] += number;
            }
            counter++;
        }
        for(int i = 0; i < COLUMN_NUMBER; i++) {
            arr[i] = arr[i] / counter;
        }
    }
}

int main(int argc, char const *argv[])
{
    double array[COLUMN_NUMBER] = {};
    // read("read.txt", array);
    // sort(array);

    double arr1[] = {1, 3, 5, 7}; 
  
    double arr2[] = {2, 4, 6, 8}; 
  
    double arr3[8] = {}; 
    
    merge(arr1, arr2, arr3);
    return 0;
}
