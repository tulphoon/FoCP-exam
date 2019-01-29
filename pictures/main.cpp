#include <string>
#include <fstream>
#include <iomanip>

#define W 10
#define K 10

void read(const std::string & fileName, int picture[W][K], int & rows, int & columns) {
    std::ifstream inStream(fileName);
    if(inStream) {
        int pixel;
        inStream >> rows >> columns;
        if(rows > W or columns > K) return;
        else if(rows < 0 or columns < 0) return;
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                inStream >> pixel;
                picture[i][j] = pixel;
            }
        }
        inStream.close();
    }
}

void write(const std::string & fileName, int picture[W][K], const int & rows, const int & columns) {
    std::ofstream outStream(fileName);
    if(outStream) {
        outStream << std::setw(5) << rows << std::setw(5) << columns << std::endl;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                outStream << std::setw(5) << picture[i][j];
            }
            outStream << std::endl;
        }
        outStream.close();
    }
}

int main(int argc, char const *argv[])
{
    int rows = -1;
    int columns = -1;
    int array[W][K];
    read("picture.txt", array, rows, columns);
    write("outputPicture.txt", array, rows, columns);
    return 0;
}
