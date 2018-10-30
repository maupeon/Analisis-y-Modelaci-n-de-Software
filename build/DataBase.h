#ifndef DATABASE_H
#define DATABASE_H
//Se incluyen las librer�as necesarias.
#include <bits/stdc++.h>
#include <sys/stat.h>
#include "opencv2/core.hpp"
#include "opencv2/flann/miniflann.hpp"
#include "opencv2/flann/flann_base.hpp"

using namespace std;
using namespace cv;
using namespace flann;

class DataBase {
    private:
    Mat queries;

    public:
    
    void cargarBase(string archivo);
    Mat getMatrix();
    Mat getColumn(int num);
    Mat getRow(int num);
    Mat KDTree(Mat features,vector<float> elementoaBuscar,int K);

};
#endif