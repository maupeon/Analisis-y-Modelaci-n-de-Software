#include "DataBase.h"

int main()
{
    DataBase db("Data.txt","biometrics.txt","N.txt","e.txt");
    //DataBase db;
    

float data[] = {-0.052, -0.268, -0.668, 0.174,
 -0.065, -0.404, 0.73, -0.542, -0.156, 0.953, 0.953, 0.333,
  -0.427, 0.307, -0.787, -0.751, 0.717, 0.304, 0.559, 0.607,
   0.389, -0.996, -0.821, -0.717, 0.497, 0.124, -0.169, -0.642, 
   -0.332, 0.592, -0.175, -0.525, -0.917, -0.073, -0.344, 0.903,
    0.297, -0.217, -0.674, -0.413, 0.782, -0.579, 0.107, 0.475, -0.403,
    -0.286, 0.837, -0.924, 0.59, -0.817, -0.928, 0.818, -0.767, 0.962, 
    -0.719, 0.127, -0.571, -0.127, 0.119, -0.829, 0.536, 0.206, -0.005, 
    -0.464, -0.289, 0.94, 0.551, 0.525, -0.312, -0.718, 0.022, 0.39, 0.606,
    -0.579, -0.069, -0.27, -0.915, 0.33, 0.644, 0.613, -0.665, 0.372, 0.16,
    0.934, -0.986, -0.325, -0.674, 0.371, 0.787, 0.63, -0.104, -0.732, 0.599,
    -0.07, 0.288, 0.046, -0.992, -0.101, 0.218, -0.903, 0.901, -0.094, -0.437,
    0.292, -0.227, -0.528, -0.32, 0.36, 0.205, -0.925, 0.225, -0.262, 0.113, 
    0.742, 0.791, 0.388, -0.834, 0.893, 0.252, -0.762, -0.603, -0.19, 0.962, -0.631, -0.95, 0.537, 0.103,0.56}; 
    cv::Mat feat(cv::Size(128, 1), CV_32F, data);
    Mat m;
    
    /*BiographicalData bio;
    
    bio.matricula = "A01030486";
    bio.name = "Mauricio";
    bio.lastName = "Peón";
    bio.mail = "maup@gmail.com";
    bio.age = 22;*/
    //std::cout<<"Nombre:: "<<db.getUserInfoByMatricula("A01030486").name<<std::endl;
    
    //cout<<feat(0)(0)<<endl;
    //cout << feat.at<float>(0,1);
    //cout << feat << endl;
   //db.saveUserBiometricDataInAFile(feat);
    //std::cout<<db.getBiometricByMatricula("A01020736")<<std::endl;
    /*db.getN();
    db.saveUserDataInAFile(bio);
    db.updateDataBase();*/
    //cout<<db.search(feat,100)<<endl;
    //cout<<db.getRow(0)[0]<<endl;
   // cout << db.getMatrix().at<float>(0,1);
  // cout<<db.getMatrix()<<endl;

    return 0;
}
