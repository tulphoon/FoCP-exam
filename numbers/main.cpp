#include <string>
#include <fstream>

#define COLUMN_NUMBER 5

// NOT NEEDED FOR TASK, only for checking values in the binary file
void readBinary(const std::string & fileName) {
    std::ifstream inStream(fileName, std::ios::binary);
    double xd;
    if(inStream) {
        for(int i = 0; i < 2 * COLUMN_NUMBER; i++) {
            inStream.read(reinterpret_cast<char *>(&xd), sizeof(double));
        }
        inStream.close();
    }
}

// write array into binary file
void write(const std::string & fileName, double arr[]) {
    std::ofstream outStream(fileName, std::ios::binary);
    if(outStream) {
        for(int i = 0; i < 2 * COLUMN_NUMBER; i++) {
            outStream.write(reinterpret_cast<char *>(&arr[i]), sizeof arr[i]);
        }
        outStream.close();
    }
}

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
    double tmp;
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

void read(const std::string & fileName, double arr[]) {
    std::ifstream is(fileName);
    
    // if the file does not exist or is empty, fill the array with zeros
    for(int i = 0; i < COLUMN_NUMBER; i++) {
        arr[i] = 0;
    }

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
        is.close();
    }
}

void operation(const std::string & firstFileName, const std::string & secondFileName, const std::string & outputFileName) {
    double firstArray[COLUMN_NUMBER];
    double secondArray[COLUMN_NUMBER];
    double mergedArray[2 * COLUMN_NUMBER];

    read(firstFileName, firstArray);
    read(secondFileName, secondArray);
    sort(firstArray);
    sort(secondArray);
    merge(firstArray, secondArray, mergedArray);
    write(outputFileName, mergedArray);
}

int main(int argc, char const *argv[])
{
    operation("firstinput.txt", "secondinput.txt", "binaryoutput.bin");
    readBinary("binaryoutput.bin"); // this is for debugging purposes only!
    return 0;
}
