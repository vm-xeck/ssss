#include <stdio.h>
#include <ncurses.h>
#include <locale.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "");

    for(int i=1; i<argc; i++){
        char *option = argv[i];
        if(option == "-h" || option == "--help"){
            printf("Soreha So Screensaver\nUsage: ssss [options]\nOptions: \n    -h --help       Display this page and exit.\n    -v --version    Display version and exit.\n    -s --sound      Sound mode.\n");
        }
    }

    initscr();
    cbreak();
    noecho();
    timeout(1);
    curs_set(0);

    int height, width;
    getmaxyx(stdscr, height, width);

    int cursor[2] = {0, 0}, direction[2] = {1, 1};
    int input = 0;

    while(!input){
        erase();

        cursor[0] += direction[0];
        cursor[1] += direction[1];

        if(cursor[0] == 0 || cursor[0] == height - 3){
            direction[0] *= -1;
        } else if(cursor[1] == 0 || cursor[1] == width - 18){
            direction[1] *= -1;
        }

        mvaddstr(cursor[0], cursor[1], "＿人人人人人人人＿");
        mvaddstr(cursor[0] + 1, cursor[1], "＞　それはそう　＜");
        mvaddstr(cursor[0] + 2, cursor[1], "￣Y^Y^Y^Y^Y^Y^Y￣");
        //input = c.getch();
        refresh();
        usleep(100000);
    }
    endwin();
    return 0;
}
