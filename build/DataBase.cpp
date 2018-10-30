#include "DataBase.h"

void DataBase::cargarBase(string archivo){
   int rows = 0;
    std::string line;
    fstream arch;
    arch.open(archivo);
    while (getline(arch, line)) {  
        line+=',';
        std::istringstream stream(line);

        char sep; //comma!
        float x;
        // read *both* a number and a comma:
        while (stream >> x && stream >> sep) {

            queries.push_back(x);
        }
        rows ++;
    } 

    // reshape to 2d:
    queries = queries.reshape(1,rows);
}

 Mat DataBase::getMatrix(){
    return queries;
 }

 Mat DataBase::getColumn(int num){
    return queries.col(num);
 }

 Mat DataBase::getRow(int num){
    return queries.row(num);
 }

 Mat DataBase::KDTree(Mat db,vector<float> elementoaBuscar,int K){
     cout << db.rows << " " << db.cols << " " << db.type() << endl;
     cv::flann::Index flann_index(
        db, cv::flann::KDTreeIndexParams());
    
    cout << "xxxxx" << endl;
     Mat indices,dists;
     Mat x = db.row(6).clone();//= Mat::zeros(1, 129, CV_32FC1);
     cout << x.type() << endl;

     flann_index.knnSearch(elementoaBuscar,indices,dists,K);
     /*Index kdtree(db, KDTreeIndexParams());

     Mat indices,dists;
     kdtree.knnSearch(db,indices,dists,K);*/
    // cout << indices << endl;
     //cout << dists << endl;
    return indices;
 }