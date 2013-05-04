#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Program
{
public:
  Program();
	~Program();
	void NacteniSouboru(string nazev);	//nacte z txt souboru do retezce a rozdeli na slova
	void RozdeleniNaSlova();			//rozdeli retezec na slova
	int CelkemSlov();					//pocet slov v textu
	void VypisSlov();					//vypise vsechna slova z textu
	double EntropieCelkem();			//vrati hodnotu celkove entropie
	
protected:
	string * pole;		//pole jednotlivych slov
	static double celkovaentropie;	//celkova entropie slov-pri vypisu jednotlivych uzlu ji pripoctitavam hodnotu 
	bool stavsouboru;	//true kdyz je nacten existujici soubor,jinak false
	int celkovypocetslov;	//pocet slov v souboru
private:
	void Realokace();	//realokace pole do ktereho ukladam slova
	int size;			//velikost pole
	int maxsize;		//max velikost pole
	int j;				//index pole na ktery se ma vlozit nove slovo
	string text;		//nacteny retezec textu ze souboru txt
};

