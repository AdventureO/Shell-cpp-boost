//
// Created by theoriginms7 on 01.04.17.
//

#include <boost/filesystem.hpp>
#include <iostream>

using namespace std;
namespace fs = boost::filesystem;

fs::path DIRECTORY_PATH = fs::current_path();

bool check(){
    char check;
    while (check != 'y' && check != 'n'){
        cout << "Do you want to rename your files? (y/n)" << endl;
        cin >> check;
    }
    if (check == 'y') {
        return true;
    } else {
        return false;
    }
}

bool check2(){
    char check2;
    while (check2 != 'y' && check2 != 'n'){
        cout << "Do you want to move your files? (y/n)" << endl;
        cin >> check2;
    }
    if (check2 == 'y') {
        return true;
    } else {
        return false;
    }
}

int main(int argc, const char *argv[]) {
    if (argc == 0){
        cout << "Incorrect input! You need to write arguments. \n";
        return 0;
    }
    bool check_f = false;
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == string("-h") || string(argv[i]) == string("--help")) {
            printf("mv - rename or move files.\n"
                           "mv [-h|--help] [-f] <oldfile> <newfile> - to rename.\n"
                           "mv [-h|--help] [-f] <oldfile1> <oldfile2> <oldfile3>.... <newdir> - to move.\n"
                           "-f - do action without asking.\n");
            return 0;
        }else if (string(argv[i]) == "-f"){
            check_f = true;
        }
    }

    vector<const char *> el_to_move;
    for (int i = 1; i < argc; i++){
        if (string(argv[i]) != "-f"){
            el_to_move.push_back(argv[i]);
        }
    }
    fs::path dest(el_to_move[el_to_move.size() - 1]);
    if (argc == 3) {
        if(check()) {
            fs::path src(argv[argc - 2]);
            fs::path dest(argv[argc - 1]);
            try {
                fs::rename(src, dest);
            }
            catch (...) {
                cout << "There is no such file..." << endl;

            }
        }
    }else if (argc == 4 && check_f) {
        if (string(argv[1]) != "-f" && string(argv[2]) != "-f"){
            fs::path src(argv[1]);
            fs::path dest(argv[2]);
            try {
                fs::rename(src, dest);
                cout << "File renamed successfully." << endl;
            }
            catch (...) {
                cout << "There is no such file..." << endl;
            }
        }else if (string(argv[1]) != "-f" && string(argv[3]) != "-f"){
            fs::path src(argv[1]);
            fs::path dest(argv[3]);
            try {
                fs::rename(src, dest);
                cout << "File renamed successfully." << endl;
            }
            catch (...) {
                cout << "There is no such file..." << endl;
            }
        }else if(string(argv[1]) == "-f"){
            fs::path src(argv[2]);
            fs::path dest(argv[3]);
            try {
                fs::rename(src, dest);
                cout << "File renamed successfully." << endl;
            }
            catch (...) {
                cout << "There is no such file..." << endl;
            }
        }
    }else if (argc > 4 && check_f){
        try {
            for(int i = 0; i < el_to_move.size() - 1; i++){

                fs::copy_file(DIRECTORY_PATH.string() + "/" + el_to_move[i], dest.string() + "/" + el_to_move[i], fs::copy_option::overwrite_if_exists);
                boost::filesystem::remove(el_to_move[i]);
            }
            cout << "Files moved successfully." << endl;
        }
        catch (...) {
            cout << "There is no such file or directory..." << endl;
        }
    } else if (argc >= 4 && !check_f){
        if(check2()){
            try {
                for(int i = 0; i < el_to_move.size() - 1; i++){

                    fs::copy_file(DIRECTORY_PATH.string() + "/" + el_to_move[i], dest.string() + "/" + el_to_move[i], fs::copy_option::overwrite_if_exists);
                    boost::filesystem::remove(el_to_move[i]);
                }
                cout << "Files moved successfully." << endl;
            }
            catch (...) {
                cout << "There is no such file or directory..." << endl;
            }
        }
    }
}