#include <iostream>

#define BOOST_NO_CXX11_SCOPED_ENUMS

#include <unistd.h>
#include <boost/filesystem.hpp>
#include <boost/function.hpp>

#undef BOOST_NO_CXX11_SCOPED_ENUMS
namespace fs = boost::filesystem;

using namespace std;


int cd(string path){
    cout << "lol" << endl;
    fs::path curr_dir(fs::current_path());
    if (path == ""){
        if (fs::current_path() != "/usr/bin") {
            fs::current_path( "/usr/bin" );
            curr_dir = get_current_dir_name();
            cout << "Current directory -- " << curr_dir << endl;
        }
    } else{
        fs::current_path(path);
        curr_dir = get_current_dir_name();
        cout << "Current directory -- " << curr_dir << endl;
    }

    return chdir(curr_dir.c_str());
}

fs::path pwd() {
    fs::path curr_dir(fs::current_path());
    cout << "Current directory -- " << curr_dir<< endl;
    return curr_dir;
}