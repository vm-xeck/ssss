#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <locale.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "ja_JP.UTF-8");
    int sound = 0;

    for(int i=1; i<argc; i++){
        char *option;
        option = malloc(strlen(argv[i])+1);
        strcpy(option, argv[i]);
        if(!strcmp(option, "-v") || !strcmp(option, "--version")){
            printf("Soreha So Screensaver\nVersion 1.2\n2024-09-19\n");
            return 0;
        } else if(!strcmp(option, "-s") || !strcmp(option, "--sound")){
            sound = 1;
        } else{
            printf("Usage: ssss [options]\nOptions: \n    -h --help       Display this page and exit.\n    -v --version    Display version and exit.\n    -s --sound      Sound mode.\n");
            return 0;
        }
        free(option);
    }

    initscr();
    cbreak();
    noecho();
    timeout(0);
    curs_set(0);

    int height, width;
    getmaxyx(stdscr, height, width);

    int cursor[2] = {0, 0}, direction[2] = {1, 1};
    int input = 0;

    while(input < 1){
        erase();
        input = getch();

        cursor[0] += direction[0];
        cursor[1] += direction[1];

        if(cursor[0] == 0 || cursor[0] == height - 3){
            direction[0] *= -1;
            if(sound){
                printf("\a");
            }
        }
        if(cursor[1] == 0 || cursor[1] == width - 18){
            direction[1] *= -1;
            if(sound){
                printf("\a");
            }
        }

        mvaddstr(cursor[0], cursor[1], "＿人人人人人人人＿");
        mvaddstr(cursor[0] + 1, cursor[1], "＞　それはそう　＜");
        mvaddstr(cursor[0] + 2, cursor[1], "￣Y^Y^Y^Y^Y^Y^Y￣");
        refresh();
        usleep(100000);
    }
    endwin();
    return 0;
}
