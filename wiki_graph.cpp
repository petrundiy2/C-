#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<string> arr;
    vector<string>::iterator i;
    ifstream ifs;
    string str;

    ifs.open("C:\\home\\student\\ClionProjects\\wiki_graph\\file1.txt");
    if ( !ifs.is_open() ) {
        cerr << "Can't open file" << endl;
        return 1;
    }

    while ( !ifs.eof() ){
        getline(ifs, str);
        arr.push_back(str);
    }

    ifs.close();

    for ( i = arr.begin(); i != arr.end(); i++ )
        cout << *i << endl;

    return 0;
}
