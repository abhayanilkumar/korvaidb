#ifndef KDB_MENU_H
#define KDB_MENU_H

#include <iostream>

namespace kdb{
    const unsigned int MAX_MENU_ITEMS = 20;

    class MenuItem{
        const char* description;

        bool isEmpty() const; // returns true if description is nullptr or empty string
        MenuItem(); // constructor - set description to nullptr
        MenuItem(const char*); // constructor - set description to parameter string
        MenuItem(const MenuItem&); // blocks copy constructor
        operator bool() const; // bool cast overload - returns true if MenuItem not empty
        operator const char*(); // const char* cast overload - returns address of description
        MenuItem& operator=(const MenuItem&); // blocks copy assignment
        std::ostream& display(std::ostream& os = std::cout) const; // displays description, returns ostream object
        ~MenuItem(); // destructs memory allocated for description

        friend class Menu;
    };

    class Menu{
        MenuItem title;
        MenuItem* items[MAX_MENU_ITEMS+1];
        int index;

        Menu(const Menu&); // blocks copy constructor
        Menu& operator=(const Menu&); // blocks copy assignment
        void initialize(); // sets menu to safe empty state

        public:
        Menu(); // initializes
        Menu(const char*); // constructor, sets title
        bool isEmpty() const; // returns true if MenuItems are empty
        std::ostream& displayTitle(std::ostream& os = std::cout) const; // prints title MenuItem's description if not empty
        std::ostream& display(std::ostream& os = std::cout) const; // prints title and all MenuItems
        Menu& operator<<(const char*); // allows MenuItems to be created and inserted into a Menu object
        unsigned int operator~() const; // runs getSelection
        operator unsigned int() const; // overload unsigned int cast - returns number of menuitems
        operator int() const; // overload int cast - returns number of menuitems
        operator bool() const; // overload bool cast - returns true if menu is not empty
        const char* operator[](int) const; // overload array index/subscript - returns char description of menuitems array's index element
        unsigned int getSelection() const; // accepts user input for a number selection from the menu, returns the selection
        ~Menu(); // destructor - frees allocated dynamic memory
    };

    std::ostream& operator<<(std::ostream&, const Menu&); // displays menu object's title
}

#endif