#pragma once


#include <string>
#include <iostream>
//#include "sdl.h"
using namespace std;

class talkClass {
	

public:
	bool talking = false;
	int count = 0;
	int f = 100;
	int nf = 70;
	string event = " ";
	string eventz = " ";  //add if(talk.event != " "){    over excel stuff for this to work  

	string name = " ";
	string pictureFileName = " ";
	string dialogue = " ";
	
	void d(string d);
	void dp(string d,string p);
	void p(string p);

	void ndp(string n,string d, string p);
	void nd(string n, string d);
	void np(string n, string p);
	void n(string n);

};

