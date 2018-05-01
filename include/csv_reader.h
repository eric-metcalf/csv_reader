//
// Created by ehm216 on 4/30/18.
//

#ifndef PROJECT_CSV_READER_H
#define PROJECT_CSV_READER_H


#include <fstream>
#include <vector>
using namespace std;


class CSVReader{

private:
    //Properties of the csv
    int number_atts;
    bool openned_file = false;
    // 1 for int, 0 for float,
    vector<int> attribute_type;


    vector<std::string> attribute_name;

    int lineCount;

    //path to file
    std::string file_path;
    ifstream csv;

public:

    CSVReader(string s);
    CSVReader(std::vector<int> attribute_type, vector<std::string> attribute_name, std::string file_path);
    std::vector<std::vector<int>> getNextLine();
    std::vector<std::vector<int>> getLines(int num_lines);
    int reset();
    int seek(int line);
    int open();
    int close();
    std::string getFile();
};




#endif //PROJECT_CSV_READER_H
