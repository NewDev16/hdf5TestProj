#include <iostream>
#include <array>
#include <tuple>
#include <ctime>
//#include <malloc.h>

#include <fstream>
#include <hdf5.h>

int main()
{
    std::srand(100);
    const int ARRAY_SIZE_X = 1000;
    const int ARRAY_SIZE_Y = 1000;
    //int16_t* testArray = (int16_t*)malloc(sizeof(int16_t*ARRAY_SIZE));
    std::array<std::array<int16_t,ARRAY_SIZE_Y>,ARRAY_SIZE_X> testArray;

    for (int y = 0; y < ARRAY_SIZE_Y; ++y) {
        for (int x = 0; x < ARRAY_SIZE_X; ++x) {
            testArray[x][y] =(int16_t)rand()%INT16_MAX+0;
        }
    }

    std::ofstream testFile("test.csv");


    if (testFile.is_open()) {
        for (int y = 0; y < ARRAY_SIZE_Y; ++y) {
            for (int x = 0; x < ARRAY_SIZE_X; ++x) {
                testFile << testArray[x][y]  << ";";
            }
            testFile << "\n";
        }

        testFile.close();
    }
    else std::cerr << "Unable to open file!!!" << std::endl;

    return 0;
}
