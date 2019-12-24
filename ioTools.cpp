#include <iostream>
#include <cstring>
#include <iomanip>
#include "ioTools.h"

using namespace std;

namespace kdb{

    ostream& line(const char* str, int num){
        int n = num/strlen(str);
        int c = 0;
        for(int i = 0; i < n; i++){
            cout << str;
            c++;
        }
        c = num - c*strlen(str);
        if(c){
            for(int i = 0; i < c; i++){
                cout << str[i];
            }
        }
        cout << endl;
        return cout;
    }

    ostream& center(const char* str, int width){
        int size = (width - strlen(str))/2;
        if(size >= 0){
            cout << setw(size) << "" << str << endl;
        }else{
            size *= -1;
            for(int i = size; i < (size+width); i++){
                cout << str[i];
            }
            cout << endl;
        }
        return cout;
    }

    void read(int& val, int min, int max, const char* ErrorMess, istream& is){
		bool ok;
		char newline;
		do{
			is >> val;
			newline = is.get();
			if(is.fail() || newline != '\n'){
				ok = false;
				is.clear();
				is.ignore(1000, '\n');
			}else{
				ok = (val <= max && val >= min);
			}
		}while(!ok && cout << ErrorMess);
	}

	void read(long long& val, long long min, long long max, const char* ErrorMess, istream& is){
		bool ok;
		char newline;
		do{
			is >> val;
			newline = is.get();
			if(is.fail() || newline != '\n'){
				ok = false;
				is.clear();
				is.ignore(1000, '\n');
			}else{
				ok = (val <= max && val >= min);
			}
		}while(!ok && cout << ErrorMess);
	}

	void read(char* str, int len, const char* errorMessage, istream& is) {
		bool ok;
		do {
			ok = true;
			is.getline(str, len + 1, '\n');
			if (is.fail()) {
				is.clear();
				is.ignore(1000, '\n');
				ok = false;
			}
			else if (strlen(str) == 0)
				ok = false;
		} while (!ok && cout << errorMessage);
	}
}