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

std::vector<std::vector<DataPoint>> CSVReader::getNextLine(){
    return getLines(1);

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

        vect.push_back(d);
    }

    return vect;
}

/*
vector<DataPoint> splitLine(string str)
{
    //std::string str = "1,2,3,4,5,6";
    std::vector<int> vect;

    std::stringstream ss(str);

    int i;

    while (ss >> i)
    {
        vect.push_back(i);

        if (ss.peek() == ',')
            ss.ignore();
    }

    for (i=0; i< vect.size(); i++)
        std::cout << vect.at(i)<<std::endl;



}

        if (ss.peek() == ',')
            ss.ignore();
    }
    int j = 0;
    for (j=0; j < vect.size(); j++)

        std::cout << vect.at(j)<<std::endl;

    return vect;

    //std::cout << "THIS IS THE END" << std::endl;


}

*/
std::vector<std::vector<DataPoint>> CSVReader::getLines(int num_lines){

    if(!openned_file){
        std::vector<std::vector<DataPoint>> a;
        return a;
    }
    //Assuming the max size of a line is 256 bytes
    //TODO Converting a char * to a string
    char v[256];

    for( int i = 0; i < num_lines; i++){
        csv.getline(v, 256);
        split_line(v);
    }
    vector<vector<DataPoint>> a;


    return a;

}



int CSVReader::seek(int line) {

    //TODO
    return 0;
}

