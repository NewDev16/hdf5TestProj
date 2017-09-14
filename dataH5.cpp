#include "dataH5.h"

#include <iostream>
#include <ctime>
#include <malloc.h>


dataH5::dataH5()
    :filename("")
    ,datasetPath("")
    ,datasetPath2("")
    ,rank1(2)
    ,rank2(2)
{
    std::srand(0);
}

void dataH5::setFilename(const std::string &fn){
    filename = fn;
}

void dataH5::setDatasetpath(const std::string &dsetPath){
    datasetPath = dsetPath;
}

void dataH5::setDatasetpath2(const std::string &destPath){
    datasetPath2 = destPath;
}

void dataH5::setDatasetDim(hsize_t d[]){
    for (int idx = 0; idx < 2; ++idx) {
        dims[idx] = d[idx];
    }
}

void dataH5::setDatasetDim2(hsize_t d[]){
    for (int idx = 0; idx < 2; ++idx) {
        dims2[idx] = d[idx];
    }
}

void dataH5::setRankDSet1(int r){
    rank1 = r;
}

void dataH5::setRankDSet2(int r){
    rank2 = r;
}

bool dataH5::createTestData(){
    if (!checkRequiredData()) return false;

    file_id = H5Fcreate(filename.c_str(),H5F_ACC_TRUNC,H5P_DEFAULT, H5P_DEFAULT);


    dataspace1_id = H5Screate_simple(rank1, dims, NULL);
   // dataspace2_id = H5Screate_simple(rank2, dims2, NULL);

    dataset_id = H5Dcreate2(file_id, datasetPath.c_str(), H5T_NATIVE_INT, dataspace1_id,
                            H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);
   // dataset2_id = H5Dcreate2(file_id, datasetPath2.c_str(), H5T_NATIVE_INT16, dataspace2_id,H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT);
    status = H5Dclose(dataset_id);
   // status = H5Dclose(dataset2_id);

    status = H5Sclose(dataspace1_id);
    //status = H5Sclose(dataspace2_id);

    status = H5Fclose(file_id);

    std::cout << status << std::endl;

    return true;
}

bool dataH5::checkRequiredData(){
    if (filename=="") {
        std::cerr << "Empty filename!" << std::endl;
        return false;
    }
    else if (datasetPath == "" || datasetPath2 == "") {
        std::cerr << "Empty dataset path" << std::endl;
        return false;
    }

    return true;
}

bool dataH5::fillWithRndValues(){
    file_id = H5Fopen(filename.c_str(), H5F_ACC_RDWR,H5P_DEFAULT);
    dataset_id = H5Dopen2(file_id,datasetPath.c_str(),H5P_DEFAULT);
    dataspace1_id = H5Dget_space(dataset_id);

    int** dataSet = (int**)malloc(sizeof(int*)*dims[1]);
    for (int idx = 0; idx < dims[1]; ++idx) {
        dataSet[idx] = (int*)malloc(sizeof(int)*dims[0]);
    }

    for (int y = 0; y < dims[1]; ++y) {
        for (int x = 0; x < dims[0]; ++x) {
            dataSet[y][x] =(rand()%9+0);
            std::cout << dataSet[y][x] << " ";
        }
        std::cout << "\n";
    }

    status = H5Dwrite (dataset_id, H5T_NATIVE_INT, H5S_ALL, dataspace1_id,
                      H5P_DEFAULT, dataSet);

    int** rdata = (int**)malloc(sizeof(int*)*dims[1]);
    for (int idx = 0; idx < dims[1]; ++idx) {
        rdata[idx] = (int*)malloc(sizeof(int)*dims[0]);
    }

    for (int y = 0; y < dims[1]; ++y) {
        for (int x = 0; x < dims[0]; ++x) {
            std::cout << rdata[y][x] << " ";
        }
        std::cout << "\n";
    }

    status = H5Dread (dataset_id, H5T_NATIVE_INT, H5S_ALL, H5S_ALL, H5P_DEFAULT, rdata);

    status = H5Sclose(dataspace1_id);
    status = H5Dclose(dataset_id);
    status = H5Fclose(file_id);


    return true;
}
