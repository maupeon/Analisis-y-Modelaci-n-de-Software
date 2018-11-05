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

struct BiographicalData{
    string id,matricula,name,lastName,mail,img;
    int age;
};

struct MatriculaId{
    int ID;
    string matricula;
};

class DataBase {
    private:
        Mat queries,ids,descr;    
        Index *flann_index;
        int n;
        string matricula,name,lastName,mail,age,biographicalFile,biometricFile,nFile,id_matFile;
        fstream biographicalDB,biometricDB,N,Id_Mat;
        vector <vector<MatriculaId> > Id_MatriculaVector;
       

    public:
        DataBase();
        DataBase(string biographicalFile,string biometricFile,string nFile,string id_matFile);
        void cargarBase();
        void cargarId_MatriculaFile();
        Mat getMatrix();
        Mat getColumn(int num);
        Mat getRow(int num);
        Mat search(Mat elementoaBuscar,int K);
        Mat getBiometricByMatricula(string matricula);
        void saveUserDataInAFile(BiographicalData bio);
        void saveUserBiometricDataInAFile(Mat biometric);
        //bool verify(string matricula,Mat vec);
        void getN();
        void updateDataBase(int n);
    
        //~DataBase();
    
};
#endif
