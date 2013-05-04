#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "Program.h"
#include "BinarniStrom.h"
#include <vld.h>
using namespace std;

int main()
{
  BinarniStrom ALG;
	string nazev;
	cout<<"Zadejte nazev souboru: ";
	cin>>nazev;

	ALG.NacteniSouboru(nazev);
	ALG.RozdeleniNaSlova();
	ALG.VlozeniSlovdoStromu();
	ALG.Rozhrani();
	
	return 0;
}
