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

 //   getLine("hello,hello,hell,geet,");

    /* this is a fucction that prints out hello world.
     *
     */



    std::cout << "Hello World!!"<<std::endl;

    std::string s = "hello";

    CSVReader csv(s);

    std::cout << csv.getFile() << std::endl;

    int i = 0;
    i = testReadLine(csv);


}



