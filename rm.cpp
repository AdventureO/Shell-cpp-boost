//
// Created by theoriginms7 on 02.04.17.
//

#include <boost/filesystem.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>

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

char removeR() {
    char type;
    while (type != 'y' && type != 'n'){
        cout << "Do you really want to delete your directory(ies)? (y/n)" << endl;
        cin >> type;
    }
    if (type == 'y'){
        return true;
    }
    else{
        return false;
    }

}

int main(int argc, const char *argv[]) {
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

    vector<const char *> el_to_rm;
    for (int i = 1; i < argc; i++){
        if (string(argv[i]) != "-f" && string(argv[i]) != "-R"){
            el_to_rm.push_back(argv[i]);
        }
    }
    if (argc > 2 && check_f == 1 && check_r == 1) {
        try {
            for (int i = 0; i < el_to_rm.size(); i++) {
                if (fs::is_directory(el_to_rm[i])) {
                    boost::filesystem::remove_all(el_to_rm[i]);
                    cout << "Directory called - '" <<el_to_rm[i] << "' was removed successfully!" << endl;
                }
            }
        }
        catch (...) {
            cout << "There is no such directory..." << endl;
        }
    }
    if (argc > 2 && !check_f == 1 && check_r == 1) {
        if (removeR()) {
            try {
                for (int i = 0; i < el_to_rm.size(); i++) {
                    if (fs::is_directory(el_to_rm[i])) {
                        boost::filesystem::remove_all(el_to_rm[i]);
                        cout << "Directory called - '" << el_to_rm[i] << "' was removed successfully!" << endl;
                    }
                }
            }
            catch (...) {
                cout << "There is no such directory..." << endl;
            }
        }
    }
    if (argc > 1 && !check_f == 1 && !check_r == 1) {
        if (removeF()) {
            try {
                for (int i = 0; i < el_to_rm.size(); i++) {
                    if (boost::filesystem::exists(el_to_rm[i])) {
                        boost::filesystem::remove(el_to_rm[i]);
                        cout << "File called - '" << el_to_rm[i] << "' was removed successfully!" << endl;
                    }
                }
            }
            catch (...) {
                cout << "There is no such file..." << endl;
            }
        }
    }
    if (argc > 2 && check_f == 1 && !check_r == 1) {
        try {
            for (int i = 0; i < el_to_rm.size(); i++) {
                if (boost::filesystem::exists(el_to_rm[i])) {
                    boost::filesystem::remove(el_to_rm[i]);
                    cout << "File called - '" << el_to_rm[i] << "' was removed successfully!" << endl;
                }
            }
        }
        catch (...) {
            cout << "There is no such file..." << endl;
        }
    }
}