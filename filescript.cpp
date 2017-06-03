#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <unistd.h>
#include <fstream>

using namespace std;

// SPLIT METHODS START 0
template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}
// SPLIT METHODS END 0

// method for checking if a file exists.
inline bool exists (const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

// Script support
void filescript() {
    // Get a user imput
    string filename;
    cout << "Enter a file name: ";
    cin >> filename;
    cout << "The value you entered is " << filename << '\n';

    // Check if the input contains "."
    size_t found = filename.find(".");
    string extension;
    if (found != std::string::npos) {
        cout << "Period found at: " << found << '\n';
        // Split a filename by "." if "." is found
        vector<string> x = split(filename, '.');
        // Get the extension.
        extension = x[1];
        cout << "Extension: " << extension << '\n';
    }
    else {
        cout << "Incorrect file." << '\n';
    }

    bool fileExists = false;
    // if the extension is "msh" check if the file exists in the current directory.
    // else print "Incorrect file extension."
    if(extension == "msh") {
        cout << "Correct file extension. msh." << '\n';
        // Check if file is present in the current directory
        fileExists = exists(filename);
    }
    else {
        cout << "Incorrect file extension." << '\n';
    }

    // if the file is present in the current directory - start its execution.
    if(fileExists) {
        cout << "File exists." << "\n";
        // READ FILE AND START SCRIPT EXECUTION HERE
        ifstream file(filename);
        string str;
        string file_contents;
        while (std::getline(file, str))
        {
            // Printing file contents.
            cout << str << '\n';
            file_contents += str;
            file_contents.push_back('\n');

            vector<string> x = split(str, ' ');
            string command = x[0];
            cout <<"First command: " + command << '\n';

            //if(command == "rm" || command == "ls") {
            //    // EXECUTE THIS COMMAND HERE
            //}
        }
    }
    else {
        cout << "File doesn't exist in your current directory" << '\n';
    }

    return;
}