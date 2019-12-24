#include <iostream>
#include "menu.h"
#include "ioTools.h"

using namespace std;

namespace kdb{

    bool MenuItem::isEmpty() const{
        return (description == nullptr||description[0] == '\0');
    }

    MenuItem::MenuItem(){
        description = nullptr;
    }

    MenuItem::MenuItem(const char* d){
        description = new char[strlen(d)+1];
        strcpy(const_cast<char*>(description), d);
    }

    MenuItem::operator bool() const{
        return !isEmpty();
    }

    MenuItem::operator const char*(){
        return &*description;
    }

    ostream& MenuItem::display(ostream& os) const{
        if(!isEmpty())
            os << const_cast<char*>(description);
        return os;
    }

    MenuItem::~MenuItem(){
        if(description != nullptr)
            delete[] description;
    }
    
    /* MENU CLASS FROM HERE */

    void Menu::initialize(){
        for(int i=0; i<static_cast<int>(MAX_MENU_ITEMS); i++){
            items[i] = nullptr;
        }
        index = 0;
    }

    Menu::Menu(){
        initialize();
    }

    Menu::Menu(const char* d){
        initialize();
        title.description = new char[strlen(d)+1];
        strcpy(const_cast<char*>(title.description), d);
    }

    bool Menu::isEmpty() const{
        return !index;
    }

    ostream& Menu::displayTitle(ostream& os) const{
        if(!title.isEmpty())
            title.display(os);
        return os;
    }

    ostream& Menu::display(ostream& os) const{
        if(!isEmpty()){
            if(!title.isEmpty())
                displayTitle(os) << ":" << endl;
            os.setf(ios::right);
            for(int i=0; i<index; i++){
                os.width(2);
                os << i+1 << "- ";
                items[i]->display(os) << endl;
            }
            os << " 0- Exit" << endl;
            os << "> ";
        }
        return os;
    }

    Menu& Menu::operator<<(const char* d){
        if(index<(static_cast<int>(MAX_MENU_ITEMS))){
            if(items[index] != nullptr){
                if(items[index]->description != nullptr)
                    delete[] items[index]->description;
                delete[] items[index];
            }
            items[index] = new MenuItem(d);
            index++;
        }
        return *this;
    }

    unsigned int Menu::operator~() const{
        return getSelection();
    }

    Menu::operator unsigned int() const{
        return index;
    }

    Menu::operator int() const{
        return index;
    }

    Menu::operator bool() const{
        return !isEmpty();
    }

    const char* Menu::operator[](int num) const{
        int temp = num;
        if(temp>=index){
            temp -= index;
        }
        return (items[temp]->description);
    }

    unsigned int Menu::getSelection() const{
        display();
        int selection = 0;
        read(selection, 0, index, "Invalid Selection, try again: ");
        return selection;
    }

    Menu::~Menu(){
        for(int i=0; i<(static_cast<int>(MAX_MENU_ITEMS)); i++){
            if(items[i] != nullptr)
                delete items[i];
        }
    }

    ostream& operator<<(ostream& os, const Menu& m){
        if(!m.isEmpty())
            m.displayTitle(os);
        return os;
    }
}