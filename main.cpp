#include <iostream>

#define BOOST_NO_CXX11_SCOPED_ENUMS

#include <sys/wait.h>

#include <boost/filesystem.hpp>
#include <boost/function.hpp>
#include <boost/algorithm/string.hpp>
#include "help.h"
#include "headers/ls.h"
#include "proccess.h"
#include "filescript.h"
#include "builtin.h"
#include <sstream>
#include <vector>
#include <iterator>
#include <unistd.h>


#include <fstream>

#undef BOOST_NO_CXX11_SCOPED_ENUMS

namespace fs = boost::filesystem;
using namespace std;
string command = "";
string sub = "";

int check_myfile = 0;

vector<string> commands = {"ls", "rm", "mv", "cp", "mkdir"};
vector<string> builtin = {"help", "pwd", "cd"};


void findArguments(string input){
    int i = 0;
    while(i != sizeof(input)){
        if(input[i] == ' '){
            command = input.substr(0, (unsigned long) i);
            sub = input.substr((unsigned long) (i + 1), input.length() - 1);
            break;
        }
        else{
            command = input;
        }
        i++;
    }
    //cout << command << endl;
    //cout << sub << endl;
}

void builtin_func(string command) {
    vector<const char *> c_str;
    istringstream iss(command);
    vector<string> commands{istream_iterator<string>{iss}, istream_iterator<string>{}};
    string function = commands[0];
    if (function == string("cd")) {
        for (auto &s: commands) {
            if (string(s) == "-h" || string(s) == "--help") {
                return help(2);
            }
        }
        if (commands.size() != 1) {
            cd(commands[1]);
        } else {
            cd("");
        }
        return;
    } else if (function == string("pwd")){
        for (auto &s: commands) {
            if (string(s) == "-h" || string(s) == "--help") {
                return help(1);
            }
        }
        pwd();
        return;
    } else if (function == "help") {
        return help(0);
    }
}



int proccessFork(string command){
    istringstream iss(command);
    vector<string> comms{istream_iterator<string>{iss}, istream_iterator<string>{}};

    if (find(builtin.begin(), builtin.end(), comms[0]) != builtin.end()) {
        builtin_func(command);
        return 1;
    }


    pid_t pid = fork();

    if (pid == 0) {
        // child process
        vector<const char *> c_str;
        istringstream iss(command);
        vector<string> commandss{istream_iterator<string>{iss}, istream_iterator<string>{}};
        if (find(commands.begin(), commands.end(), commandss[0]) != commands.end()) {
            proccess(command);
        }else if(check_myfile == 1){
          proccess(command);
        } else{
            cout << "Command not found" << endl;
        }

        _exit(EXIT_SUCCESS);
    }
    else if (pid > 0) {
        // parent process
        int status;
        (void) waitpid(pid, &status, 0);
    }
    else {
        // fork failed
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}

int main() {
    bool check = true;
    cout << "Welcome in our SHELL!" << endl;
    //bool check2 = true;
    while (check) {
        string cmd;
        cout << "~$ ";
        //cin.getline(cmd, 128);
        getline(cin, cmd);
        std::regex comments("#+.*");
        cmd = regex_replace(cmd, comments, "");
        findArguments(cmd);

        istringstream iss(cmd);
        vector<string> commandss{istream_iterator<string>{iss}, istream_iterator<string>{}};
        string script_file;
        string extension;
        int check_script = 0;
        for (int i = 0; i < commandss.size(); i++){
            size_t found = commandss[i].find(".");
            if(found != std::string::npos && string(command) != "cp" && string(command) != "mkdir" && string(command) != "help"
                 && string(command) != "mv" && string(command) != "rm" && string(command) != "ls" && string(command) != "pwd"
                    && string(command) != "cd" && string(command) != "exit"){
                check_script++;
                script_file = commandss[i];
            }
        }

        if (check_script > 0) {
            size_t found2 = cmd.find(".");
            if (found2 != std::string::npos) {
                // Split a filename by "." if "." is found
                vector<string> x = split(script_file, '.');
                // Get the extension.
                extension = x[1];
                cout << "Extension: " << extension << '\n';
            } else {
                cout << "Incorrect file." << '\n';
            }
            bool fileExists = false;
            // if the extension is "msh" check if the file exists in the current directory.
            // else print "Incorrect file extension."
            if (string(extension) == "msh" || string(extension) == "txt") {
                cout << "Correct file extension -- msh." << '\n';
                // Check if file is present in the current directory
                fileExists = exists(script_file);
            } else {
                cout << "Incorrect file extension." << '\n';
            }

            if (fileExists) {
                cout << "File exists." << "\n";
                // READ FILE AND START SCRIPT EXECUTION HERE
                ifstream file(script_file);
                string str;
                string file_contents;
                while (std::getline(file, str)) {
                    // Printing file contents.
                    check_myfile = 1;
                    cout << str << '\n';
                    file_contents += str;
                    file_contents.push_back('\n');

                    vector<string> x = split(str, ' ');
                    string command1 = x[0];
                    if (string(command1) == "mkdir" || string(command1) == "cp" || string(command1) == "mv"
                            || string(command1) == "rm" || string(command1) == "ls" || string(command1) == "cd"
                            || string(command1) == "pwd")  {
                        proccessFork(str);
                    }
                    if (string(command1) == "help") {
                        help(0);
                    }
                    if (string(command1) == "exit") {
                        return 0;
                    }
                }
            } else {
                cout << "File doesn't exist in your current directory" << '\n';
            }
        }
        //std::vector<std::string> str;
        //boost::split(str, sub, boost::is_any_of(" "));
        //istringstream iss(cmd);
        //vector<string> commands{istream_iterator<string>{iss}, istream_iterator<string>{}};
        //vector<char*> args;
        //char* prog = strtok(cmd, " ");
        //char* tmp = prog;
        //while (tmp!= NULL) {
        //    args.push_back(tmp);
        //    tmp = strtok(NULL, " ");
        //}
        //char** argv = args.data();
        if (command == "exit") {
            return 0;
        }
        if (check_myfile != 1){
            proccessFork(cmd);
        }
    }
    //return 0;
}
