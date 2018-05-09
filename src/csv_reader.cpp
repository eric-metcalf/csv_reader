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
    if(!attribute_name.empty()){

        return attribute_name;

    }
    else if(lineCount != 0){

        this->close();
        this->open();
        lineCount = 0;
    }

    std::vector<DataPoint> atts_dp;
    atts_dp = split_line(val);
    std::vector<std::string> atts;
    for(auto i:atts_dp){
        atts.push_back(i.str_value);
        //std::cout << i.str_value << std::endl;
    }
    attribute_name = atts;
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



void split(const string& s, char delim,vector<string>& v) {
    auto i = 0;
    auto pos = s.find(delim);
    while (pos != string::npos) {
        v.push_back(s.substr(i, pos-i));
        i = ++pos;
        pos = s.find(delim, pos);

        if (pos == string::npos)
            v.push_back(s.substr(i, s.length()));
    }
}

/* this is a function that splits the line up*/

vector<DataPoint> split_line(const string & str) {

    std::vector<string> vect1;
    std::vector<DataPoint> vect2;
    split(str, ',', vect1);
    /*std::stringstream ss(str);
    std::cout << "Hello"<< std::endl;
    std::string hello;


    while (std::getline(ss, hello, ',')) {

        DataPoint d;
        int k;
        int min_len;
        min_len = std::min( (int) hello.length(), 16);
        for (k = 0; k < min_len; k++) {
            d.str_value[k] = hello[k];
        }

        d.str_value[k] = '\0';

        vect.push_back(d);
    }
    */
    for( int i =0; i < vect1.size(); i++){
        DataPoint d;
        int j;
        for(j = 0; j < std::min((int)(vect1.at(i).size()),255) ; j++){
            d.str_value[j] = (vect1.at(i))[j];
        }
        d.str_value[j] = '\0';
        vect2.push_back(d);
    }

    return vect2;
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
    cout<< "1 "<<endl;
    for( int i = 0; i < num_lines; i++){
        getline(csv, v);
        auto a = split_line(v);
        data.push_back(a);
        lineCount++;
    }

    cout<< "2 "<<endl;
    return data;

}



int CSVReader::seek(int line) {

    //TODO
    return 0;
}

