#include <iostream>
#include "questionAnswers.h"
#include "menu.h"

using namespace std;

namespace kdb{

    void definitions(){
        
    }

    void notation(){

    }

    void about(){

    }

    void questionAnswers(){
        Menu questionMenu("FAQ and more info");
        questionMenu <<
        "Definitions" <<
        "How do I read the notation?" << 
        "About this program";

        bool done = false;
        while(!done){
            switch(~questionMenu){
            case 1:
                definitions();
                break;
            case 2:
                notation();
                break;
            case 3:
                about();
                break;
            default:
                done = true;
                break;
            }
        }
    }
}