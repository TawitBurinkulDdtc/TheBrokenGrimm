#include "talkClass.h"


void talkClass::d(string d){
	dialogue = d;
}
void talkClass::dp(string d, string p){
	dialogue = d;
	pictureFileName = p;

}
void talkClass::p(string p){
	pictureFileName = p;
}


void talkClass::ndp(string n, string d, string p){
	name = n;
	dialogue = d;
	pictureFileName = p;
}

void talkClass::nd(string n, string d){
	name = n;
	dialogue = d;
}

void talkClass::np(string n, string p){
	name = n;
	pictureFileName = p;
}
void talkClass::n(string n) {
	name = n;
}





