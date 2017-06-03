//
// Created by theoriginms7 on 01.04.17.
//


#include <boost/filesystem.hpp>
#include <iostream>
using namespace std;
namespace fs = boost::filesystem;

#ifndef NEWSHELL_CP_H

#define NEWSHELL_CP_H
#endif //NEWSHELL_CP_H

void copyToDirectory(vector<string> filesArray, int f_trig) {

    int checker;
    if (filesArray.size() > 2) {
        checker = filesArray.size();
    } else {
        checker = filesArray.size() - 1;
    }

    for (int i = 0; i < checker; i++) {
        if (!fs::exists(filesArray[i])) {
            cout << "Error: No such file or directory!" << endl;
            return;
        }
    }


    fs::path start_path(fs::current_path());
    string startPath = start_path.c_str();


    string copyToDir = filesArray.back().c_str();

    for (int i = 0; i < filesArray.size() - 1; i++) {

        while(1) {
            if(fs::is_directory(copyToDir)) {
                fs::current_path(copyToDir);
                if(f_trig || !fs::exists(filesArray[i])) {
                    fs::current_path(startPath);
                    fs::copy_file( filesArray[i], copyToDir + "/" + filesArray[i], fs::copy_option::overwrite_if_exists);
                    break;
                } else  {
                    cout << "File " << filesArray[i] << " already exists. Rewrite[Y/n]? :";
                    string option;
                    cin >> option;
                    if (option == "Y" || option == "y") {
                        fs::current_path(startPath);
                        fs::copy_file(filesArray[i], copyToDir + "/" + filesArray[i], fs::copy_option::overwrite_if_exists);
                        break;
                    } else if (option == "n") {
                        break;
                    } else {
                        cout << "Type Y/y or n!" << endl;
                    }
                }
            } else {
                if (f_trig || !fs::exists(copyToDir)) {
                    fs::copy_file(filesArray[i], copyToDir, fs::copy_option::overwrite_if_exists);
                    break;
                } else {
                    if (fs::exists(copyToDir)) {
                        cout << "File " << copyToDir << " already exists. Rewrite[Y/n]? :";
                        string option;
                        cin >> option;
                        if (option == "Y" || option == "y") {
                            fs::copy_file(filesArray[i], copyToDir, fs::copy_option::overwrite_if_exists);
                            break;
                        } else if (option == "n") {
                            break;
                        } else {
                            cout << "Type Y/y or n!" << endl;
                        }
                    }
                }
            }
        }
    }

}

void cp(int argc, const char *argv[]) {

    int h_trig = 0;
    int f_trig = 0;
    vector<string> filesArray;

    for(int i = 1; i < argc; i++) {
        if (string(argv[i]) == "-h" || string(argv[i]) == "--help") {
            h_trig++;
        } else if (string(argv[i]) == "-f") {
            f_trig++;
        } else {
            filesArray.push_back(string(argv[i]));
        }
    }

    if (h_trig > 1 || f_trig > 1 || filesArray.size() < 2) {
        cout << "Wrong arguments!" << endl;
        return;
    }

    if (h_trig) {
        cout << "cp - copy file from one directory to another.\n"
                "Here are two options : \n"
                "1. Copy from file1 to file 2 -- cp [-f] <file1> <file2>;\n"
                "2. All files copy to directory dir -- cp [-f]  <file1> <file2> <file3>... <dir>."
                "Option -f -- copy without asking.\n";
        return;
    }

    copyToDirectory(filesArray, f_trig);
}