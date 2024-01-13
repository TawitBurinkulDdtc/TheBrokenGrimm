#pragma once


#include <string>
#include <iostream>
//#include "sdl.h"
using namespace std;

class talkClass {
	

public:
	bool talking = false;
	int count = 0;
	string event = " ";

	string pictureFileName = " ";
	string dialogue = " ";
	
	void d(string d);
	void dp(string d,string p);
	void p(string p);

};

