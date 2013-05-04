#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "program.h"

struct Uzel
  {
	
	string slovo;
	int cetnost;
	Uzel * levy;
	Uzel * pravy;
	};

class BinarniStrom :public Program
{
public:
	BinarniStrom();
	~BinarniStrom();
	void Pridat(string);	//prida uzel do stromu
	bool Najit(string);		//vyhleda uzel stromu
	void Vypis();			//vypise strom
	void VlozeniSlovdoStromu();	//vlozi slovo do stromu
	void VypisPolozku(Uzel *p);	//vypise polozku stromu
	void Rozhrani();			//funkce pro vypis polozek
private:
	void Vlozit(Uzel *&koren, string);	//rekurzivni vkladani uzlu
	bool Vyhledat(Uzel * koren, string);	//rekurzivni hledani uzlu
	void VypisKorenu(Uzel * koren);			//inorder - rekurzivni vypis
	void smazanistromu(Uzel *p);		//postorder - rekurzivni smazani uzlu
	Uzel * root;	//koren
};

