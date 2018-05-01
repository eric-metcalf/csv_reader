//
// Created by ehm216 on 4/30/18.
//

using namespace std;

#include "../include/csv_reader.h"
#include <string>

CSVReader::CSVReader(string s) {

    this->file_path = s;

}


CSVReader::CSVReader(std::vector<int> attribute_type,
                     vector<std::string> attribute_name,
                     std::string file_path){

    //intiializing all the different values
    this->number_atts = attribute_type.size();
    this->attribute_name = attribute_name;
    this->file_path = file_path;
    this->attribute_type = attribute_type;
    lineCount= 0;


}

std::string CSVReader::getFile(){
    return this->file_path;

}

int CSVReader::open(){

    csv.open(file_path);
    openned_file = true;

}

int CSVReader::close(){

    csv.close();
    openned_file = false;

}

std::vector<std::vector<int>> CSVReader::getNextLine(){
    //TODO
    return getLines(1);

}



std::vector<std::vector<int>> CSVReader::getLines(int num_lines){
    //TODO
    vector<vector<int>> a;
    return a;

}

int CSVReader::seek(int line) {

    //TODO
    return 0;
}

