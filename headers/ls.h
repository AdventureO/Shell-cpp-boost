
#include <dirent.h>


#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/function.hpp>
#include <boost/regex.hpp>
#include <unordered_map>
#include <boost/algorithm/string/predicate.hpp>
#include <regex>
#include <iomanip>
#ifndef NEWSHELL_LS_H
#define NEWSHELL_LS_H

#endif //NEWSHELL_LS_H


namespace fs = boost::filesystem;
namespace ba = boost::algorithm;
using namespace std;

void printListWithDetails(vector<string> filesList, int is_reverse) {
    cout << setw(30) << left << "Name";
    cout << setw(30) << left << "Size";
    cout << setw(30) << left << "Last modified time" << endl;
    cout << setfill('-') << setw(90) << "-" << endl;
    cout << setfill(' ');
    if(is_reverse) {
        for (vector<string>::reverse_iterator i = filesList.rbegin(); i != filesList.rend(); ++i) {
            if (fs::is_regular_file(*i)) {
                cout << setw(30) << left << *i;
                cout << setw(30) << left << fs::file_size(*i);
                cout << setw(30) << left << fs::last_write_time(*i)<< endl;

            } else if (fs::is_directory(*i)) {
                cout << setw(30) << left << "/" + *i;
                cout << setw(30) << left << "No permission";
                cout << setw(30) << left << fs::last_write_time(*i)<< endl;
            }
        }
    } else {
        for (auto &&x : filesList) {
            if (fs::is_regular_file(x)) {
                cout << setw(30) << left << x;
                cout << setw(30) << left << fs::file_size(x);
                cout << setw(30) << left << fs::last_write_time(x) << endl;
            } else if (fs::is_directory(x)) {
                cout << setw(30) << left << "/" + x;
                cout << setw(30) << left << "No permission";
                cout << setw(30) << left << fs::last_write_time(x)<< endl;
            }
        }
    }
}


void printList(vector<string> filesList, int is_reverse) {
    cout << "Name" << endl;
    cout << setfill('-') << setw(40) << "-" << endl;
    if (is_reverse) {
        for (vector<string>::reverse_iterator i = filesList.rbegin(); i != filesList.rend(); ++i) {
            if (fs::is_directory(*i)) {
                cout << "/" + *i << endl;
            } else {
                cout << *i << endl;
            }
        }
    } else {
        for (auto &&x : filesList) {
            if (fs::is_regular_file(x))
                cout << x << endl;
            else if (fs::is_directory(x))
                cout << "/" + x << endl;
        }
    }

}

vector<string> goToPath(string path, string mask) {
    vector<string> v;
    fs::path curPath = fs::current_path();
    if (!fs::is_directory(path)) {
        v.push_back(path);
        return v;
    }
    fs::current_path(path);
    fs::path p(fs::current_path());
    fs::directory_iterator end_iter;


    if (mask != "") {
        try {
            char a = '?';
            string b = "[A-Za-z0-9]";


            string mask_reg = "";
            if (mask.substr(0, 1) == "*") {
                mask_reg = "(" + mask.substr(1) + ")";
            } else {
                for (string::size_type i = 0; i < mask.size(); ++i) {
                    if (mask[i] == a) {
                        mask_reg += b;
                    } else {
                        mask_reg += mask[i];
                    }

                    if (mask[i + 1]) {
                        if (mask[i + 1] == '.') {
                            mask_reg += "(";
                        }
                    } else {
                        mask_reg += ")";
                    }
                }
            }

            regex re(mask_reg);
            smatch match;

            for (fs::directory_iterator dir_itr(p); dir_itr != end_iter; ++dir_itr) {
                string word = dir_itr->path().filename().string();
                if (std::regex_search(word, match, re) && match.size() > 1) {
                    v.push_back(word);
                }
            }
        } catch (std::regex_error& e) {
            cout << "Wrong mask!" << endl;
        }

    } else {
        for (fs::directory_iterator dir_itr(p); dir_itr != end_iter; ++dir_itr) {
            string word = dir_itr->path().filename().string();
            v.push_back(word);
        }
    }

    return v;
}

void myLs(int argc, const char *argv[]) {

    int l_trig = 0;
    int sort_trig = 0;
    int u_trig = 0;
    int s_trig = 0;
    int x_trig = 0;
    int t_trig = 0;
    int r_trig = 0;
    int h_trig = 0;
    int m_trig = 0;
    int n_trig = 0;
    string mask_trig = "";


    fs::path full_path(fs::current_path());
    string path_trig = full_path.c_str();


    for(int i = 1; i < argc; i++) {

        if (fs::exists(string(argv[i]))) {
            path_trig = string(argv[i]);
        } else if (string(argv[i]) == "-l") {
            l_trig++;
        } else if (string(argv[i]) == "N") {
            n_trig++;
        } else if (string(argv[i]) == "--sort") {
            sort_trig++;
        } else if (string(argv[i]) == "U") {
            u_trig++;
        } else if (string(argv[i]) == "S") {
            s_trig++;
        } else if (string(argv[i]) == "t") {
            t_trig++;
        } else if (string(argv[i]) == "X") {
            x_trig++;
        } else if (string(argv[i]) == "-r") {
            r_trig++;
        } else if (string(argv[i]) == "--help" || string(argv[i]) == "-h") {
            h_trig++;
        } else {
            mask_trig += string(argv[i]);
            m_trig++;
        }

    }

    if (l_trig > 1 || sort_trig > 1 || u_trig > 1 || s_trig > 1 || x_trig > 1 || t_trig > 1 || r_trig > 1 || h_trig > 1 || m_trig > 1 || n_trig > 1) {
        cout << "Wrong arguments!" << endl;
        return;
    }


    vector<string> v = goToPath(path_trig, mask_trig);

    vector<string> dirV;
    vector<string> regFileV;
    for (int i = 0; i < v.size(); i++) {
        if (fs::is_directory(v[i])) {
            dirV.push_back(v[i]);
        } else {
            regFileV.push_back(v[i]);
        }
    }


    if (h_trig) {
        cout << "\"Usage: ls [path|mask] [-l] [-h|--help] [--sort U|S|t|X] [-r]\\n\"\n"
                "                \"List information about the FILEs (the current directory by default).\\n\"\n"
                "                \"mask types examples: *.txt, ab??.dat, xy[klm].sh.\\n\"\n"
                "                \"Sort entries alphabetically if none of -tSUX nor --sort is specified.\\n\"\n"
                "                \"\\n\"\n"
                "                \"Mandatory arguments to long options are mandatory for short options too.\\n\"\n"
                "                \"  -N                         sort by name\\n\"\n"
                "                \"  -l                         use a long listing format\\n\"\n"
                "\n"
                "                \"  -S                         sort by file size, largest first\\n\"\n"
                "                \"  -t                         sort by modification time, newest first\\n\"\n"
                "                \"  -U                         do not sort; list entries in directory order\\n\"\n"
                "                \"  -X                         sort alphabetically by entry extension\\n\"\n"
                "                \"  -r                         sort in reverse order\\n\"\n"
                "                \"      --help/ -h     display this help and exit\\n\"\n"
                "                \"\\n\"\n"
                "                \"Exit status:\\n\"\n"
                "                \" 0  if OK,\\n\"\n"
                "                \" 1  if minor problems (e.g., cannot access subdirectory),\\n\"\n"
                "                \" 2  if serious trouble (e.g., cannot access command-line argument).\\n\"\n"
                "                \"\\n\"\n";;
        return;
    }


    if (sort_trig) {
        if (u_trig) {

        } else if (s_trig) {
            sort(regFileV.begin(), regFileV.end(),  [] (const fs::path& lhs, const fs::path& rhs) {
                return fs::file_size(lhs) < fs::file_size(rhs);
            });

        } else if (x_trig) {
            sort(regFileV.begin(), regFileV.end(), [] (const fs::path& lhs, const fs::path& rhs) {
                return lhs.extension() < rhs.extension();
            });

        } else if (t_trig) {
            sort(regFileV.begin(), regFileV.end(), [] (const fs::path& lhs, const fs::path& rhs) {
                return fs::last_write_time(lhs) < fs::last_write_time(rhs);
            });

        } else {
            sort(v.begin(), v.end());

        }
    }

    if (s_trig || x_trig || t_trig) {
        for (int i = 0; i < dirV.size(); i++) {
            regFileV.push_back(dirV[i]);
        }
        v = regFileV;
    }

    if (l_trig) {
        printListWithDetails(v, r_trig);

    } else {
        printList(v, r_trig);
    }
}