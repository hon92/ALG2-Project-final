#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "Program.h"

Program::Program()
{
  size=2;
	maxsize=2;
	j=0;
	pole=new string[size];
	celkovypocetslov=0;
}
Program::~Program()
{
	delete []pole;
}
void Program::NacteniSouboru(string nazev)
{
	fstream Soubor;
	Soubor.open(nazev + ".txt",ios::in);
	
	if(!Soubor.is_open())
	{
		stavsouboru=false;
		cout<<"Nelze otevrit soubor"<<endl;
		return;
	}
	else
	{	stavsouboru=true;
		getline(Soubor,text,'\0');
	}
}
void Program::RozdeleniNaSlova()
{
	vector<char> poleznaku;

	for(unsigned int i=0;i<text.length();i++)
	{
		if(isalpha(text[i]))
		{
			poleznaku.push_back(text[i]);
		}
		else 
		{
			string temp;
			while(!poleznaku.empty())
			{

			temp+=poleznaku.front();
			poleznaku.erase(poleznaku.begin());
			
			}
			if(temp.length()!=0)
			{

				

				if(j>=maxsize)
				{
					Realokace();
				}
				pole[j]=temp;
				j++;
			}
		}
	}
	if(!poleznaku.empty())
	{
		string temp;
		while(!poleznaku.empty())
		{

		temp+=poleznaku.front();
		poleznaku.erase(poleznaku.begin());
			
		}
		if(temp.length()!=0)
		{
			if(j>=maxsize)
			{
				Realokace();
			}
			pole[j]=temp;
		}
	}
	celkovypocetslov=j+1;
}
int Program::CelkemSlov()
{
	return this->celkovypocetslov;
}
void Program::Realokace()
{
	maxsize*=2;
	string * temppole=new string [maxsize];
	for(int i=0;i<size;i++)
	{
		temppole[i]=pole[i];
	}
	delete []pole;
	pole=temppole;
	size*=2;
}
void Program::VypisSlov()
{
	for(int i=0;i<j;i++)
	{
		cout<<pole[i]<<endl;
	}
}
double Program::EntropieCelkem()
{
	return celkovaentropie;
}
double Program::celkovaentropie=0;

