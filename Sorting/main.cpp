#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
    ofstream outfile;
    outfile.open("demo.txt");
    string line;

    while(outfile){
        getline(cin,line);
        outfile<<line<<endl;

        if(line == "-1"){
            break;
        }
    }
    outfile.close();

    ifstream fin;
    fin.open("demo.txt");

    while(getline(fin,line)){
        cout<<line<<endl;
    }
    fin.close();

    return 0;
}