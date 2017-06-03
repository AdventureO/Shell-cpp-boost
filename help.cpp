#include <iostream>

void help(int option) {
    if (option == 0) {
        printf("-------==========WELCOME TO THE SHELL==========-------\n"
                       "   Here are some help for you that you can do\n"
                       "   with this shell. You just should write command\n"
                       "   to run some function you want.\n"
                       "   1.'pwd' to check current directory.\n"
                       "   2.'cd <path>' to move to some directory.\n"
                       "   3.'exit' to stop program. \n"
                       "   4.'ls' to see list of files.\n"
                       "   5.'cp <file1> <file2> ' to copy files.\n"
                       "   6.'mv <oldfile> <newfile>' to move/rename files.\n"
                       "   7.'rm <file1> <file2>' to remove files.\n"
                       "   8.'mkdir <dirname>' to create directory.\n"
                       "-==Created by Syvokhip M. &  Pryhoda O. & Karabyn P.==-\n");
    }
    else if (option == 2){
        printf("cd <path> -- goes to path <path>.\n");
    }
    else if (option == 1){
        printf("pwd -- shows current path.\n");
    }
    return;
}
