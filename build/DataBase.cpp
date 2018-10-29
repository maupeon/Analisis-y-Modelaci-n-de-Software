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
        double x;
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
     cv::Mat indexMat(db.size(), CV_32FC1);
     cv::flann::Index flann_index(
        indexMat,
        cv::flann::SavedIndexParams("c:\\index.fln"),
        cvflann::FLANN_DIST_EUCLIDEAN
    );
     Mat indices,dists;
     flann_index.knnSearch(db,indices,dists,K);
     /*Index kdtree(db, KDTreeIndexParams());

     Mat indices,dists;
     kdtree.knnSearch(db,indices,dists,K);*/
     
return indices;
 }