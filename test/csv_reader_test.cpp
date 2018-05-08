/*
 *
 * This is the file that is going to test the csv reader
 *
 *
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "../include/csv_reader.h"


int testReadLine(CSVReader & csv){
    auto a = csv.getNextLine();

    for(auto b:a){
        std::cout << b.str_value << std::endl;

    }

}


int testReadAtts(CSVReader & csv){

    auto a = csv.getAttributes();

    for(auto b:a){
        std::cout << b << std::endl;

    }

    return 0;

}





int main(){
    /*
     * Creating all the different CSV file intializations that we need to create.
     *
     */

    std::vector<int> attribute_type = {1, 2, 3, 4 ,5};

    vector<std::string> attribute_name = {"hello1","hell2","hello3","hello4"};

    std::string file_path;
    file_path = "../test_data/gps.csv";
    //   getLine("hello,hello,hell,geet,");￼

    /* this is a fucction that prints out hello world.
     *
     */



    std::cout << "Hello World!!"<<std::endl;

    std::string s = "hello";

    CSVReader csv(file_path);

    //csv.open();

    std::cout << csv.getFile() << std::endl;

    int i = 0;
    //i = testReadLine(csv);
    //i = testReadLine(csv);
    //i = testReadLine(csv);
    i = testReadAtts(csv);

}



