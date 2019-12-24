/*
Korvai Database System developed by Abhay Anil Kumar, 2019
*/

#include <iostream>
#include "ioTools.h"
#include "menu.h"
#include "arudhi.h"
#include "korvai.h"
#include "questionAnswers.h"

using namespace std;
using namespace kdb;

void start(){
    Menu mainMenu("Main Menu");
    mainMenu <<
    "Generate an arudhi" <<
    "Search for a korvai" <<
    "View all korvais" <<
    "Enter a new korvai" <<
    "FAQ";

    Menu sureMenu("Do you really want to exit the program?");
    sureMenu << 
    "No";

    bool done = false;
    while(!done){
    switch(~mainMenu){
        case 1:
            loadArudhis();
            break;
        case 2:
            searchKorvai();
            break;
        case 3:
            getAllKorvais();
            break;
        case 4:
            writeKorvai();
            break;
        case 5:
            questionAnswers();
            break;
        default:
            if(~sureMenu == 0){
                done = true;
            }
            break;
        }
    }
}

int main(){

    line("~");
    center("Korvai Database System");
    center("Designed and built by Abhay Anil Kumar, 2019");
    line("~");
    line();

    start();

    return 0;
}