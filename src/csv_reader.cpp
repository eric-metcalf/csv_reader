//
// Created by ehm216 on 4/30/18.
//

using namespace std;

#include "../include/csv_reader.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>


/*
 *
 * This is just storing everything as an integer... NEED to improve the
 * programability of this system.
 *
 */
CSVReader::CSVReader(string s) {

    this->file_path = s;
    this->open();
    attribute_name = this->getAttributes();
    for(int i = 0; i < attribute_name.size(); i++){
        attribute_type.push_back(0);
    }

}



std::vector<std::string> CSVReader::getAttributes(){

    std::string val;

    std::getline(csv, val);

    //std::cout << val << std::endl;

    std::vector<DataPoint> atts_dp;
    atts_dp = split_line(val);
    std::vector<std::string> atts;
    for(auto i:atts_dp){
        atts.push_back(i.str_value);
        //std::cout << i.str_value << std::endl;
    }
    return atts;
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

std::vector<DataPoint> CSVReader::getNextLine(){
    auto a = getLines(1);
    return a[0];
}


/* this is a function that splits the line up*/

vector<DataPoint> split_line(string str) {

    std::vector<DataPoint> vect;

    std::stringstream ss(str);

    string i;

    while (std::getline(ss, i, ',')) {
        DataPoint d;
        int k;
        int min_len;
        min_len = std::min( (int) i.length(), 16);
        for (k = 0; k < min_len; k++) {
            d.str_value[k] = i[k];
        }
        d.str_value[k] = '\0';

        vect.push_back(d);
    }

    return vect;
}


std::vector<std::vector<DataPoint>> CSVReader::getLines(int num_lines){

    if(!openned_file){
        std::vector<std::vector<DataPoint>> a;
        return a;
    }
    //Assuming the max size of a line is 256 bytes
    //TODO Converting a char * to a string

    std::string v;
    vector<std::vector<DataPoint>> data;

    for( int i = 0; i < num_lines; i++){
        getline(csv, v);
        auto a = split_line(v);
        data.push_back(a);
    }

    return data;

}



int CSVReader::seek(int line) {

    //TODO
    return 0;
}

