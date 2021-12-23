#pragma once
#include <iostream>
#include <fstream>




class UI {
private:

public:

	void load(ifstream& , int [] /*queue<event> event*/);// takes events list, rovers list to load values from the file to it
	void save(ofstream&, int[] /*queue<mission>completed missions*/,int[],int[],int,int,int);


};


