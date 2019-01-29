#include <string>
#include <fstream>

#define COLUMN_NUMBER 5

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
    read("read.txt", array);
    sort(array);
    return 0;
}
