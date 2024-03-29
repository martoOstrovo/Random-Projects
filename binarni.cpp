// A simple program that can eather transform a word or sentence into strings of binary numbers for each letter(letter->ascii number->binary) or does the opposite.
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
void toArray(int *arr,int &bi);
void toDecimal(int *arr,int &dek);
void toAlfa(int &dek,char *str,int &count);
void toBinary(char c,int *arr);
using namespace std;
int main()
{
	int counter=0;
	int brBin;
	int bi[8];
	int dek;
	char al[100];
	int n;
	cout<<"Ako sakas da kodiras zbor ili recenica pritisni 'k',ako sakas da dekodiras zbor pritisni 'd'"<<endl;
	cout<<"If you want to encode a word or sentence press 'k',if you want to decode a word press 'd'"<<endl;
	char izbor;
	cin>>izbor;
	if(izbor=='d')
	{
	cout<<"Kolku binarni broevi sakas da dekodiras?"<<endl;
	cout<<"How many binary numbers do you want to decode?"<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>brBin;
		toArray(bi,brBin);
		toDecimal(bi,dek);
		toAlfa(dek,al,counter);
	}
	al[counter]='\0';
	cout<<al;
	}
	else if(izbor=='k')
	{
		cout<<"Vnesi nekoj zbor ili recenica:"<<endl;
		cout<<"Enter a word or sentence:"<<endl;
		cin.ignore();
		cin.getline(al,100);
		int m=strlen(al);
		for(int j=0;j<m;j++)
		{
			toBinary(al[j],bi);
		}
	}
	else
	{
		cout<<"Error vo izborot!";
		cout<<"Error in choice!";
		exit(-1);
	}
	return 0;
}
void toArray(int *arr,int &brBin)
{
	int n=8;
	while(brBin>0)
	{
		for(int i=0;i<n;i++)
		{
			arr[n-i-1]=brBin%10;
			brBin/=10;
		}
	}
}
void toDecimal(int *arr,int &dek)
{
	dek=0;
	int n=8;
	for(int i=0;i<n;i++)
	{
		dek+=(arr[i]*pow(2,n-1-i));
	}
}
void toAlfa(int &dek,char *str,int &count)
{
	int n=dek;
	int br=count;
	str[br]=(char)n;
	br++;
	count=br;
}
void toBinary(char c,int *arr)
{
	int n=8;
	for(int i=0;i<n;i++)
	{
		arr[n-1-i]=c%2;
		c/=2;
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i];
	}
	cout<<endl;
}
