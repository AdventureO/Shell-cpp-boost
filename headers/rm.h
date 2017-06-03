//
// Created by theoriginms7 on 02.04.17.
//

#include <boost/filesystem.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <vector>
#ifndef NEWSHELL_RM_H
#define NEWSHELL_RM_H

#endif //NEWSHELL_RM_H

using namespace std;
namespace fs = boost::filesystem;

char removeF() {
    char type;
    while (type != 'y' && type != 'n'){
        cout << "Do you really want to delete your files? (y/n)" << endl;
        cin >> type;
    }
    if (type == 'y'){
        return true;
    }
    else{
        return false;
    }

}

int rm(int argc, const char *argv[]) {
    if (argc == 0){
        cout << "Incorrect input! You need to write arguments. \n";
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == string("-h") || string(argv[i]) == string("--help")) {
            printf("rm [-f] [-R] <file1> <file2> <file3> --  removes files.\n"
                           "Option -f -- remove without asking.\n"
                           "Option -R -- remove directory.\n");
            return 0;
        }
    }

    int check_r = false;
    int check_f = false;

    for (int i = 1; i < argc; i++) {
        if (argv[i] == string("-R")) {
            check_r = true;
        }
        if (argv[i] == string("-f")) {
            check_f = true;
        }
    }


    if (argc > 2 && check_f && check_r) {
        try {
            for (int i = 1; argc; i++) {
                if (boost::filesystem::exists(argv[i]) && argv[i]) {
                    boost::filesystem::remove_all(argv[i]);
                    cout << "Directory called - '" << argv[i] << "' was removed successfully!" << endl;
                }
            }
        }
        catch (...) {
            cout << "There is no such file or directory..." << endl;
        }
    }


    if (argc > 2 && !check_f && check_r) {
        if (removeF()) {
            try {
                for (int i = 1; argc; i++) {
                    if (boost::filesystem::exists(argv[i]) && argv[i]) {
                        boost::filesystem::remove_all(argv[i]);
                        cout << "Directory called - '" << argv[i] << "' was removed successfully!" << endl;
                    }
                }
            }
            catch (...) {
                cout << "There is no such file or directory..." << endl;
            }
        }
    }

    if (argc > 1 && !check_f && !check_r) {
        if (removeF()) {
            try {
                for (int i = 1; argc; i++) {
                    if (boost::filesystem::exists(argv[i])) {
                        boost::filesystem::remove(argv[i]);
                        cout << "File called - '" << argv[i] << "' was removed successfully!" << endl;
                    }
                }
            }
            catch (...) {
                cout << "There is no such file..." << endl;
            }
        }
    }

    if (argc > 2 && check_f && !check_r) {
        try {
            for (int i = 1; argc; i++) {
                if (boost::filesystem::exists(argv[i])) {
                    boost::filesystem::remove(argv[i]);
                    cout << "File called - '" << argv[i] << "' was removed successfully!" << endl;
                }
            }
        }
        catch (...) {
            cout << "There is no such file..." << endl;
        }
    }
}
