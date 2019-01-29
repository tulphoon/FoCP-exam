#include <string>
#include <fstream>

#define W 10
#define K 10

void read(const std::string & fileName, int picture[W][K], int & rows, int & columns) {
    std::ifstream inStream(fileName);
    if(inStream) {
        int pixel;
        inStream >> rows >> columns;
        if(rows > W or columns > K) return;
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                inStream >> pixel;
                picture[i][j] = pixel;
            }
        }
        inStream.close();
    }
}

int main(int argc, char const *argv[])
{
    int rows, columns;
    int array[W][K];
    read("picture.txt", array, rows, columns);
    return 0;
}
