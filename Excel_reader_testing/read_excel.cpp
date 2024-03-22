#include <iostream> 
#include <fstream>
#include <string>
#include <cstring>
using namespace std;



void testTakingString(string a,string b){
    if(a == b){
        cout<<"Work!!!"<<endl;
    }
}

int main(){
ifstream ip("Book1.csv");

if(!ip.is_open()) {cout <<"Error"<<endl;}

string name;
string dialogue;
string picture;

string temp_read;
string scene = "scene1";

cin>>scene;

while(ip.good()){
    getline(ip,temp_read,',');
    //cout<< temp_read<<endl;
    if(temp_read == scene){   //temp_read == "poop never die"
        getline(ip,name,',');
        getline(ip,dialogue,',');
        getline(ip,picture,',');
         if(name!="\0"){
            cout<<" print name:"<<name;
        }
        if(dialogue!="\0"){
            cout<<" ,print words:"<<dialogue;
        }
        if(picture!="\0"){
            cout<<" ,loaded picture:"<<picture;
        }
        while(name!="end"){
            ip.ignore(1, ',');
            getline(ip,name,',');
            getline(ip,dialogue,',');
            getline(ip,picture,',');
            if(name!="end"){
                //cout<< name <<":"<<dialogue<<":"<<picture<<endl;
                if(name!="\0"){
                    cout<<" print name:"<<name;
                }
                if(dialogue!="\0"){
                    cout<<" ,print words:"<<dialogue;
                }
                if(picture!="\0"){
                    cout<<" ,loaded picture:"<<picture;
                }
                cout<<endl;
            }
        }
    }
}


ip.clear();
ip.seekg(0, ip.beg);
//ip.open("Book1.csv");
while(ip.good()){
    getline(ip,temp_read,',');
    cout<<temp_read;
}
//printf("hello hell");
}