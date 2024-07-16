#include <iostream>
#include <string>
#include <vector>
// #include <typeinfo>  
#include <filesystem> // 
#include <fstream> // lib usada para manipulacao de files, ler ou escrever

using namespace std;

vector<string> getFilePathList(string absPath){
    vector<string> fileList;
    for(const auto& entry : filesystem::directory_iterator(absPath)){
        fileList.push_back(entry.path().string());
    }

    for(int i =0; i < size(fileList); i++){
        cout << fileList[i] << endl;
    }
    return fileList; 
}

int main(){
    string filePath = "./input_files";
    vector<string> filePathList = getFilePathList(filePath);

    cout << "-----opening file.-----" << endl;
    ifstream inputFile{filePathList[0]};
    if(!inputFile){
        cerr << "can't open file" << '\n';
        return 1;
    }

    cout << "------ collecting file lines ------"<< endl;
    string line;
    vector<string> lines;
    while(getline(inputFile, line)){
        lines.push_back(line);
    }
    cout << "-----closing file.-----" << endl;
    inputFile.close();

    for(const auto& inputLine : lines){
        cout << inputLine << endl;
    }

    return 0;
}