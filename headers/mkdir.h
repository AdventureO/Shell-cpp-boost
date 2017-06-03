//
// Created by theoriginms7 on 02.04.17.
//

#include <sstream>

int mkdir(int argc, const char *argv[]) {
    if (argc == 0){
        cout << "Incorrect input! You need to write arguments. \n";
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        if (argv[i] == string("-h") || argv[i] == string("--help")) {
            printf("mkdir <dirname> -- creates new directory.\n");
            return 0;
        }
    }
    string dir_name = argv[1];
    fs::path dir(dir_name);
    if (fs::create_directory(dir)) {
        cout << "Directory named '" << dir_name << "' was created successfully." << endl;
    } else {
        cout << "Failed to create new directory.\nDirectory named '" << dir_name << "' already exists." << endl;
    }
}