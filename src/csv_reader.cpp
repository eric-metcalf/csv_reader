//
// Created by ehm216 on 4/30/18.
//

#include "../include/csv_reader.h"


CSVReader::CSVReader(std::vector<int> attribute_type,
                     vector<std::string> attribute_name,
                     std::string file_path){

    //intiializing all the different values
    this->number_atts = attribute_type;
    this->attribute_name = attribute_name;
    this->file_path = file_path;
    lineCount= 0;


}

int CSVReader::open(){

    csv.open(file_path);
    opened_file = true;

}

int CSVReader::close(){

    csv.close();
    openned_file = false;

}

std::vector<std::vector> CSVReader::getNextLine(){
    //TODO
    return getLines(1);

}



std::vector<std::vector> CSVReader::getLines(int num_lines){
    //TODO
    vector<vector<int>> a;
    return a;

}

int CSVReader::seek(int line) {

    //TODO
}

