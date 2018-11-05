#include "DataBase.h"


DataBase::DataBase(){
    this->biographicalFile= "Data.txt";
    this->biometricFile = "biometrics.txt";
    this->nFile = "N.txt";
     N.open(nFile,ios::out);
        if(N.is_open()){
            N<<"0\n";
            cout<<"***Fichero N.txt creado con éxito***\n";
            N.close();
        }else cout<< "Unable creating N.txt\n";
        
        if(mkdir("Fotos", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0){
            cout<<"Directory successfully created"<<'\n';
            
        }else cout<<"Error creating directory or the directory already exits"<<'\n';
    
   /* queries =  cargarBase(archivo);
    flann_index = new Index(queries, cv::flann::KDTreeIndexParams());   */
}

DataBase::DataBase(string biographicalFile,string biometricFile,string nFile,string id_matFile){
    this->biographicalFile=biographicalFile;
    this->biometricFile=biometricFile;
    this->nFile=nFile;
    this->id_matFile=id_matFile;
    queries =  cargarBase();
    
    flann_index = new Index(queries, cv::flann::KDTreeIndexParams());
    cout<<"listo"<<endl;
}

Mat DataBase::cargarBase(){
   int rows = 0;
   Mat res;
    std::string line;
    biometricDB.open(biometricFile);
    while (getline(biometricDB, line)) {
        line+=',';
        std::istringstream stream(line);
        char sep; //comma!
        float x;
        while (stream >> x && stream >> sep) {
            res.push_back(x);
        }
        rows ++;
    } 

    // reshape to 2d:
    res = res.reshape(1,rows);

    Rect ids_rect(0,0,1,res.rows);
    Rect descr_rect(1, 0, res.cols-1,res.rows); 
    Mat ids(res, ids_rect);
    ids.clone();
    Mat descr(res, descr_rect);
    //cout<<descr<<endl;
    return descr.clone();
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
 

 Mat DataBase::search(Mat elementoaBuscar,int K){
    clock_t tStart = clock();
    Mat indices,dists;
    flann_index->knnSearch(elementoaBuscar,indices,dists,K);
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return indices; 
 }

void DataBase::saveUserDataInAFile(BiographicalData bio){
    getN();
    int id=n;
    biographicalDB.open(biographicalFile,ios::out | ios::app);
    
    if(biographicalDB.is_open()){
        
        biographicalDB<<id<<","<<bio.matricula<<","<<bio.name<<","<<bio.lastName<<","<<bio.mail<<","<<bio.age<<"\n";
        id++;
        biographicalDB.close();
    }else cout<<"Unable to open file\n";
    updateDataBase(id);
}

void DataBase::saveUserBiometricDataInAFile(Mat biometric){
    string nuevoUsuario = "";
    int id=22;
    biometricDB.open(biometricFile,ios::out | ios::app);
    
    nuevoUsuario+=to_string(id);
    nuevoUsuario+=",";
    for(int i = 0 ; i< biometric.cols;i++){
        float nearest = roundf(biometric.at<float>(0,i) * 100) / 100;
        //cout<<nearest<<" ";
        nuevoUsuario+= to_string(nearest);
        if(i < biometric.cols-1){
            nuevoUsuario+=',';
        }
    }
    cout<<nuevoUsuario<<endl;
    biometricDB<<nuevoUsuario<<endl;
}

/*bool DataBase::verify(string matricula,Mat vec){
    float dmin=0.6,d;
    if(Id<n-1 && Id>=0){
        d=cv::norm(queries.row(Id),vec,cv::NORM_L2);
        if(d>dmin){
            return true;
        }else return false;
    }else cout<<"No existe el ID en la base de datos\n";
    return false;
}*/

void DataBase::getN(){
    N.open(nFile,ios::in);
    
    if(N.is_open()){
        N>>n;
    }else cout<<"Unable to open: "<<nFile<<'\n';
}

void DataBase::updateDataBase(int n){
    N.open(nFile);
    
    if(N.is_open()){
        N<<n;
        N.close();
    }else cout<<"Error updating N.txt file\n";
}







 
