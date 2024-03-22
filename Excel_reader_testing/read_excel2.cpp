#include <iostream> 
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

//having problem using .h here, also problem with using class and struct

int main(){



vector<string> name;
vector<string> dialogue;
vector<string> picture;


ifstream ip("Book1.csv");
if(!ip.is_open()) {cout <<"Error"<<endl;}

string temp_read;
string scene = "scene1";

cin>>scene;
//recordExcel.name = "Hello";

cout << "recording start" <<endl;
while(ip.good()){
    getline(ip,temp_read,',');
    //cout<< temp_read<<endl;
    if(temp_read == scene){   //temp_read == "poop never die"
        int i = 0;
        name.push_back(" "); dialogue.push_back(" "); picture.push_back(" ");
        getline(ip,name[i],',');
        getline(ip,dialogue[i],',');
        getline(ip,picture[i],',');
        if(name[i]!="\0"){
            cout<<" print name:"<<name[i];
        }
        if(dialogue[i]!="\0"){
            cout<<" ,print words:"<<dialogue[i];
        }
        if(picture[i]!="\0"){
            cout<<" ,loaded picture:"<<picture[i];
        }
        while(name[i]!="end"){
            name.push_back(" "); dialogue.push_back(" "); picture.push_back(" ");
            i=i+1;
            ip.ignore(1, ',');
            getline(ip,name[i],',');
            getline(ip,dialogue[i],',');
            getline(ip,picture[i],',');
            if(name[i]!="end"){
                //cout<< name <<":"<<dialogue<<":"<<picture<<endl;
                if(name[i]!="\0"){
                    cout<<" print name:"<<name[i];
                }
                if(dialogue[i]!="\0"){
                    cout<<" ,print words:"<<dialogue[i];
                }
                if(picture[i]!="\0"){
                    cout<<" ,loaded picture:"<<picture[i];
                }
                cout<<endl;
            }
        }
    }
}
cout << "recording end"<<"\n--------------------------------\n" <<"displaying start"<<endl;

for(int i = 0;i<name.size()&&name[i]!="end";i++){
    if(name[i]!="\0"){
        cout<<"print name:"<<name[i];
    }
    if(dialogue[i]!="\0"){
        cout<<" || print words:"<<dialogue[i];
    }
    if(picture[i]!="\0"){
        cout<<" || loaded picture:"<<picture[i];
    }
}





// ip.clear();
// ip.seekg(0, ip.beg);
// //ip.open("Book1.csv");
// while(ip.good()){
//     getline(ip,temp_read,',');
//     cout<<temp_read;
// }
//printf("hello hell");
}