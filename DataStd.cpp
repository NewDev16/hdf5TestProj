#include "DataStd.h"

#include <iostream>
#include <array>
#include <tuple>
#include <ctime>

#include <fstream>
#include <vector>

DataStd::DataStd()
{

}

void DataStd::create(){
    std::srand(100);
    const int ARRAY_SIZE_X = 100000;
    const int ARRAY_SIZE_Y = 10000;
    //int16_t* testArray = (int16_t*)malloc(sizeof(int16_t*ARRAY_SIZE));
    std::vector<std::array<int16_t,ARRAY_SIZE_Y>> container(ARRAY_SIZE_X);


    //std::array<std::array<int16_t,ARRAY_SIZE_Y>,ARRAY_SIZE_X> testArray;

    for (int y = 0; y < ARRAY_SIZE_Y; ++y) {
        for (int x = 0; x < ARRAY_SIZE_X; ++x) {
            container[x][y] =(int16_t)rand()%INT16_MAX+0;
        }
    }

    std::ofstream testFile("test.csv");


    if (testFile.is_open()) {
        for (int y = 0; y < ARRAY_SIZE_Y; ++y) {
            for (int x = 0; x < ARRAY_SIZE_X; ++x) {
                testFile << container[x][y]  << ";";
            }
            testFile << "\n";
        }

        testFile.close();
    }

    else std::cerr << "Unable to open file!!!" << std::endl;


}
