#include "BinarniStrom.h"

BinarniStrom::BinarniStrom()
{
  root=NULL;
}
BinarniStrom::~BinarniStrom()
{
	smazanistromu(root);
}
void BinarniStrom::Vlozit(Uzel *&koren, string s)
{
	if(koren==NULL)
	{
		koren=new Uzel;
		koren->slovo=s;
		koren->cetnost=1;
		koren->pravy=NULL;
		koren->levy=NULL;
		return;
	}
	if(s < koren->slovo)
	{
		Vlozit(koren->levy,s);
		return;
	}
	if(s > koren->slovo)
	{
		Vlozit(koren->pravy,s);
		return;
	}
}
bool BinarniStrom::Vyhledat(Uzel * koren, string s)
{
	if(koren==NULL)
	{
		return false;
	}
	if(koren->slovo==s)
	{
		koren->cetnost++;
		return true;
	}
	if(s < koren->slovo)
	{
		return Vyhledat(koren->levy,s);
	}
	else
	{
		return Vyhledat(koren->pravy,s);
	}
}
void BinarniStrom::Pridat(string s)
{
	Vlozit(root,s);
}
bool BinarniStrom::Najit(string s)
{
	return Vyhledat(root,s);
}
void BinarniStrom::VlozeniSlovdoStromu()
{
	for(int i=0;i<this->celkovypocetslov;i++)
	{
		Najit(pole[i]);
		Pridat(pole[i]);
	}
	
}
void BinarniStrom::Vypis()
{
	VypisKorenu(root);
}
void BinarniStrom::VypisKorenu(Uzel * koren)
{
	if(koren!=NULL)
	{
		VypisKorenu(koren->levy);
		VypisPolozku(koren);
		VypisKorenu(koren->pravy);
	}
}
void BinarniStrom::VypisPolozku(Uzel *p)
{
	if(p->slovo.length()==0)
	{
		return;
	}
	double entropie=0;
	entropie=-(log(p->cetnost/(double)celkovypocetslov)/log(2));
	celkovaentropie+=p->cetnost * entropie;
	cout<<p->slovo<<"\t\t"<<p->cetnost<<"\t\t"<<entropie<<endl;
}
void BinarniStrom::smazanistromu(Uzel *p)
{
	if(p!=NULL)
	{
		smazanistromu(p->pravy);
		smazanistromu(p->levy);
		delete p;
	}
}
void BinarniStrom::Rozhrani()
{
	if(stavsouboru)
	{
	cout<<"Slovo"<<setw(15)<<"Cetnost"<<setw(15)<<"Entropie"<<endl;
	cout<<"------------------------------------"<<endl;
	Vypis();
	cout<<"------------------------------------"<<endl;
	cout<<"Celkova entropie: "<<EntropieCelkem()<<endl;
	}
}
