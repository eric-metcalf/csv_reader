//
// Created by eric on 4/30/18.
//



/*
 *
 * This is the file that is going to test the csv reader
 *
 *
 */

#include <iostream>
#include "../include/csv_reader.h"

int main(){
    /* this is a fucction that prints out hello world.
     *
     */

    std::cout << "Hello World!!"<<std::endl;

    std::string s = "hello";

    CSVReader csv(s);

    std::cout << csv.getFile() << std::endl;



}