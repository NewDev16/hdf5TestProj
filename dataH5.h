#ifndef DATAH5_H
#define DATAH5_H

#include <hdf5.h>
#include <string>

class dataH5
{
public:
    dataH5();

    void setFilename(const std::string& fn);
    void setDatasetpath(const std::string& dsetPath);
    void setDatasetpath2(const std::string& destPath);
    void setDatasetDim(hsize_t d[]);
    void setDatasetDim2(hsize_t d[]);
    void setRankDSet1(int r);
    void setRankDSet2(int r);
    bool createTestData();

    bool fillWithRndValues();

private:
    hid_t file_id, dataset_id, dataset2_id, dataspace1_id, dataspace2_id;
    int rank1,rank2;
    hsize_t dims[2], dims2[2];
    herr_t status;
    std::string filename, datasetPath, datasetPath2;
    bool checkRequiredData();
};

#endif // DATAH5_H
