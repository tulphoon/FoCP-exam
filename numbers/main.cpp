#include <string>
#include <fstream>

#define COLUMN_NUMBER 5

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
    return 0;
}
