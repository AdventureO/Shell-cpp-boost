//
// Created by theoriginms7 on 02.04.17.
//

#include <iostream>

#define BOOST_NO_CXX11_SCOPED_ENUMS

#include <unistd.h>
#include <boost/filesystem.hpp>
#include <boost/function.hpp>
#include <unordered_map>
#include <sstream>
#include "builtin.h"

#include "help.h"

#undef BOOST_NO_CXX11_SCOPED_ENUMS
namespace fs = boost::filesystem;
using namespace std;

fs::path DIRECTORY_PATH = fs::current_path();

vector<const char *> c_string(const vector<string> &tokens, const string &name_of_program) {
    vector<const char *> c_args;
    c_args.push_back(name_of_program.c_str());
    int i = 0;
    for (const auto &s : tokens) {
        if (i == 0) {
            i++;
            continue;
        }
        c_args.push_back(s.c_str());
    }
    c_args.push_back(0);
    return c_args;

}

void proccess(string command){
    vector<const char *> c_str;
    istringstream iss(command);
    vector<string> commands{istream_iterator<string>{iss}, istream_iterator<string>{}};
    string function = commands[0];
    //else if (function == "pwd"){
        //for (auto &s: commands) {
        //    if (s == "-h" || s == "--help") {
          //      return help(1);
        //    }
       // }
      //  pwd();
    //}//else if (function == "cd"){
     //   for (auto &s: commands) {
     //       if (s == "-h" || s == "--help") {
            //    return help(2);
     //       }
    //    }
    //    cd(commands[1]);
    if (string(function) == "rm"){
        if (commands.size() != 1) {
            c_str = c_string(commands, "rm");
        }else {
            cout << "Incorrect input! You need to write arguments.";
        }

    }else if (string(function) == "mkdir") {
        if (commands.size() != 1) {
            c_str = c_string(commands, "mkdir");
        }else {
            cout << "Incorrect input! You need to write arguments.";
        }
    }else if (string(function) == "mv") {
        if (commands.size() != 1) {
            c_str = c_string(commands, "mv");
        }else {
            cout << "Incorrect input! You need to write arguments.";
        }
    }else if (string(function) == "cp"){
        if (commands.size() != 1) {
            c_str = c_string(commands, "cp");
        }else {
            cout << "Incorrect input! You need to write arguments.";
        }
    }else if (string(function) == "ls") {
        //c_str = c_string(commands, "name");
        //int size = sizeof(c_str.data())/sizeof(c_str.data()[0]);
        //myLS(size, c_str.data());
        c_str = c_string(commands, "ls");
    }else{
        c_str = c_string(commands, function);
        execvp(c_str[0], const_cast<char *const *>(c_str.data()));
        perror("FAIL to start, check you input...");
        return;
    }

    string s = DIRECTORY_PATH.string() + "/" + function;

    const char *path = s.c_str();
    execvp(path, const_cast<char *const *>(c_str.data()));
    perror("FAIL--");
}