#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <wait.h>
#include<stdlib.h>
#include <dirent.h>
#include <cstring>
#include <iostream>
#include <vector>


using namespace std;

char *curr_dir = (char *) "/usr/bin";


int myLs(void) {

    DIR *dp = NULL;
    struct dirent *dptr = NULL;
    unsigned int count = 0;

    // Get the value of environment variable PWD
    if(curr_dir == NULL) {
        printf("\n ERROR : Could not get the working directory\n");
        return -1;
    }

    // Open the current directory
    dp = opendir((const char*)curr_dir);
    if(dp == NULL) {
        printf("\n ERROR : Could not open the working directory\n");
        return -1;
    }

    printf("\n");
    // Go through and display all the names (files or folders contained in the directory.
    for(count = 0; (dptr = readdir(dp)) != NULL; count++) {
        if(dptr->d_name[0] != '.') printf("%s  ",dptr->d_name);

    }
    //printf("\n %u", count);

    return 0;
}

int myCd(char** argv){
    if (argv[1] == NULL)
    {
        chdir("/home/oleksandr/");
        curr_dir = get_current_dir_name();
        //cout << get_current_dir_name();
    }
    else
    {

        chdir (argv[1]);
        //cout << get_current_dir_name();
        curr_dir = get_current_dir_name();
    }
    return 0;

}

int cp(char from[], char to[]) {
    FILE* copyFrom = fopen(from,"r");
    FILE* copyTo = fopen(to,"w");
    for (;;) {
        int caractereActuel = fgetc(copyFrom);
        if (caractereActuel != EOF) {
            fputc(caractereActuel,copyTo);
        }
        else {
            break;
        }
    }
    fclose(copyFrom);
    fclose(copyTo);
    return 1;
}

int doLs(void) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork  failed ");
        exit (EXIT_FAILURE);
    } else if (pid == 0) {
        printf ("Hello from the child process!\n");
        myLs();
        _exit(EXIT_SUCCESS);
    }
    else
    {
        int status ;
        (void) waitpid(pid, &status, 0);
    }
    return EXIT_SUCCESS;
}

int main(int argc, char* argv[], char**env) {

    while(true)  {

        cout << curr_dir << "$";
        char command[128];
        cin.getline( command, 128 );

        vector<char*> args;
        char* prog = strtok( command, " " );
        char* tmp = prog;
        while ( tmp != NULL )
        {
            args.push_back( tmp );
            tmp = strtok( NULL, " " );
        }

        char** argv1 = args.data();
        argv1[args.size()] = NULL;


        if ((string(prog)=="pwd")){
            cout << curr_dir;
        }
        else if ((string(prog)=="ls")){
            doLs();
        }

        else if((string(prog)=="cd")){
            myCd(argv1);
        }

        else if((string(prog)=="exit")){
            break;
        }

        cout << "\n";

    }

    return 0;

}


