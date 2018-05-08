//
// Created by ehm216 on 4/30/18.
//

#ifndef PROJECT_CSV_READER_H
#define PROJECT_CSV_READER_H


#include <fstream>
#include <vector>
using namespace std;

union DataPoint{

    int int_value;
    double double_value;
    char str_value[16];

};


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

    std::vector<DataPoint> getNextLine();
    std::vector<std::vector<DataPoint>> getLines(int num_lines);
    std::vector<std::string> getAttributes();

    int reset();
    int seek(int line);
    int open();
    int close();
    std::string getFile();
};


vector<DataPoint> split_line(string str);




#endif //PROJECT_CSV_READER_H
