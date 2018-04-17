#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<iomanip.h>
#include<time.h>

class password
{
char pass[10];
public:
int check()
{
for(int i=0;i<5;i++)
{
pass[i]=getch();
cout<<"*";
}
if(!strcmp(pass,"indus"))
return 1;
else
return 0;
}

};

//static int count=0;
int n=12;
class donor
{
char name[80];
int age;
float wt;
char past[80];
char bgrp[80];
char q[80];
public:
void get();
void selection();
};

void donor::get()
{clrscr();
cout<<"\n\n\t\t\t DONOR APPLICATION";
cout<<"\nEnter your Name:";
cin.ignore();
cin.get(name,19);
cout<<"Age:";
cin>>age;
cout<<"Weight:";
cin>>wt;
cout<<"Blood Group:";
cin.ignore();
cin.get(bgrp,79);
cout<<"Any kind of past illness:";
cin.ignore();
cin.get(past,79);
cout<<"Select quantity of blood to donate";
cout<<"\t 1.250 ml \n \t\t\t\t\t 2.350 ml \n \t\t\t\t\t 3.450 ml \n \t\t\t\t\t Choice :";
cin.ignore();
cin>>q;
}

void donor::selection()
{
ofstream fout;
fout.open("donor.txt",ios::app);
if(age<18)
 cout<<"Sorry your age is less than 18, Your application cannot be accepted";
else if(age>60)
 cout<<"Sorry your age is greater than 60, Your application cannot be accepted";
else if(wt>45)
{fout<<name<<endl<<age<<endl<<wt<<endl<<bgrp<<endl<<past<<endl<<q<<endl;
   cout<<"Your application is accepted,you will get notified after verification.";
  }else cout<<"Sorry your weight is less than 45 kg, Your application cannot be accepted";
cout<<"\nPress any key to exit";
fout.close();
cin.ignore();
getch();
}

class admin
{
char data[6][80];
char req[4][80];
int d,m,y;
public:
void login();
void approval();
void manage();
void manage_hos();
void hos_request();
void search();
};

void admin::login()
{clrscr();
/*cin.ignore();
char pass[6];
clrscr();
cout<<"\nWelcome to blood bank";
cout<<"\nEnter password :";
cin>>pass;
//cout<<pass;
if(!strcmp(pass,"indus1"))
{*/
password pass;
cout<<"\n\n\n\n\n\t\t\tEnter password:";
cin.ignore();
if(pass.check())
{
int x;
cout<<"\n\t\t\tAccess granted";
getch();
do
{//cout<<"\nAccess granted";
	clrscr();
	cout<<"\n\nMenu:";
	cout<<"\n 1.View donor applications";
	cout<<"\n 2.Manage Database";
	cout<<"\n 3.Manage list of hospitals";
	cout<<"\n 4.View Hospitals request";
	cout<<"\n 5.Search Hospitals provided with BLOOD";
	cout<<"\n 6.Back";
	cout<<"\n Choice:";
//int x;
cin>>x;
switch(x)
{case 1:approval();
break;
case 2: manage();
break;
case 3:manage_hos();
break;
case 4:hos_request();
break;
case 5:search();
break;
}
}while(x!=6);
}
else
cout<<"\n\t\t\t\t\tAccess Denied";
getch();
}

void admin::approval()
{
char choice;
char x='y';
ofstream fout;
fout.open("admin.txt",ios::out);
ifstream fin;
fin.open("donor.txt",ios::in);

while(1)
{
clrscr();
cout<<"\n\nDonor applications:";
fin.get(data[0],79);
if(data[0][0]=='\0')
{cout<<"\nNo new Entry";
break;
}
cout<<"\nName:"<<data[0];
fin.ignore();
fin.get(data[1],79);
cout<<"\nAge:"<<data[1];
fin.ignore();
fin.get(data[2],79);
cout<<"\nWeight:"<<data[2];
fin.ignore();
fin.get(data[3],79);
cout<<"\nBlood Group:"<<data[3];
fin.ignore();
fin.get(data[4],79);
cout<<"\nAny kind of past illness:"<<data[4];
fin.ignore();
fin.get(data[5],79);
cout<<"\nSelected quantity of blood to donate :"<<data[5]<<" ml";
cout<<"\nWould you like to accept this application ? (Y/N) ";
cin>>choice;
if(choice=='y'||choice=='Y')
{
fout<<data[0]<<endl;
fout<<data[1]<<endl;
fout<<data[2]<<endl;
fout<<data[3]<<endl;
fout<<data[4]<<endl;
fout<<data[5]<<endl;
}

cout<<"\nView next form (Y/N) ?" ;
cin.ignore();
cin>>x;
if(x=='n'||x=='N')
break;
fin.ignore();
}
fin.close();
fout.close();
getch();
}

void admin::manage()
{		clrscr();
		ifstream fin;
		fin.open("admin.txt");
		char data[6][79];
		cout<<"\n\n\t\t\t   Donors List:";
		cout<<"\n\n"<<setw(1.3*n)<<"Name"<<setw(.7*n)<<"Age"<<setw(.7*n)<<"Weight"<<setw(.7*n)<<"B.G"<<setw(2*n)<<"Illness from Past"<<setw(n)<<"Quantity";//<<setw(n)<<"Date";
		while(1)
		{       fin.get(data[0],79);
			if(data[0][0]=='\0')
			{
				getch();
				break;
			}
			fin>>data[1]>>data[2]>>data[3];
			fin.ignore();
			fin.get(data[4],79);
			fin>>data[5];
			cout<<"\n\n"<<setw(1.3*n)<<data[0]<<setw(.7*n)<<data[1]<<setw(.7*n)<<data[2]<<setw(.7*n)<<data[3]<<setw(2*n)<<data[4]<<setw(n)<<data[5];
		 fin.ignore();
		}
		fin.close();
		}

void admin::manage_hos()
{
int b;
char name[2][20];
do
{
clrscr();
cout<<"\n\n 1.Add Hospitals \n 2.View hospitals \n 3.Edit hospitals \n 4.Back \n Choice :";
cin.ignore();
cin>>b;
switch(b)
{ case 1:
       {
       clrscr();
       ofstream fout;
       fout.open("hospital.txt",ios::app);
       cout<<"\n\nEnter ID :" ;
       cin.ignore();
       cin.get(name[0],19);
       cout<<"Enter Name :";
       cin.ignore();
       cin.get(name[1],19);
       fout<<name[0]<<endl<<name[1]<<endl;
       cout<<"\n\nRegistered !";
       getch();
       fout.close();
       }
       break;
case 2: {clrscr();
	ifstream fi;
	fi.open("hospital.txt");
	cout<<"\n\n"<<setw(2*n)<<"ID"<<setw(2*n)<<"Name";
	while(!fi.eof())
	{
	fi.get(name[0],19);
	fi.ignore();
	fi.get(name[1],19);
	cout<<"\n\n"<<setw(2*n)<<name[0]<<setw(2*n)<<name[1];
	fi.ignore();
	}
	fi.close();
	getch();
	}
	break;
case 3: {clrscr();
	ifstream fin;
	fin.open("hospital.txt");
	ofstream temp;
	temp.open("temp.txt");
	char ch[2][20];
	int flag=0,c=0,x=0,y;
	cout<<"\n\nEnter id of hospital :";
	cin>>ch[0];
	while(fin.getline(ch[1],19))
{       if(x==0)
	{if(c==1)
	  { x=1;
	continue;}
	}
	{if(!strcmp(ch[0],ch[1]))
	{    flag=1;
	     cout<<"\nHospital found";
	     cout<<"\n1. Edit \n2. Delete \n Choice :";
	     cin>>y;
	     if(y==1)
	     {
	     cout<<"\n Enter new ID :";
	     cin.ignore();
	     cin.get(ch[1],19);
	     temp<<ch[1]<<endl;
	     cout<<"Enter new Name :";
	     cin.ignore();
	     cin.get(ch[1],19);
	     temp<<ch[1]<<endl;
	     c=1;
	     cout<<"\n\nRecord has been edited";
	     continue;
	     }
	     else if(y==2)
	     {c=1;
	     cout<<"\n\nRecord has been deleted";
	     continue;
	     }
	     getch();
	}
	}
	temp<<ch[1]<<endl;
	}

	if(flag==0)
	cout<<"No hospital found";
	fin.close();
	temp.close();
	remove("hospital.txt");
	rename("temp.txt","hospital.txt");
	getch();
	fin.close();
	temp.close();
	}break;

}
}while(b!=4);
}

void admin::hos_request()
{
char choice;
char x='y';
ofstream date;
date.open("Date.txt");
ofstream fout;
fout.open("Accepted.txt");
ifstream fin;
fin.open("Request.txt",ios::in);

while(1)
{
clrscr();
cout<<"\n\nHospital's Request:";
//clrscr();
fin.get(req[0],79);
if(req[0][0]=='\0')
{cout<<"\n\nNo new Entry";
break;
}
cout<<"\n\nHospital's ID :"<<req[0];
fin.ignore();
fin.get(req[1],79);
cout<<"\nHospital's Name :"<<req[1];
fin.ignore();
fin.get(req[2],79);
cout<<"\nSample required :"<<req[2];
fin.ignore();
fin.get(req[3],79);
cout<<"\nQuantity required :"<<req[3];


cout<<"\nWould you like to accept this request ? (Y/N) ";
cin>>choice;
if(choice=='y'||choice=='Y')
{
time_t current = time(0);
struct tm * now = localtime(&current);
int d,m,y;
y=(now->tm_year+1900 );
m=(now->tm_mon+1);
d=(now->tm_mday);

fout<<req[0]<<endl;
//count++;
date<<d<<endl<<m<<endl<<y<<endl<<req[0]<<endl<<req[1]<<endl<<req[2]<<endl<<req[3]<<endl;
}

cout<<"\nView next request (Y/N) ?" ;
cin.ignore();
cin>>x;
if(x=='n'||x=='N')
break;
fin.ignore();
}
fin.close();
fout.close();
date.close();
getch();
}

void admin::search()
{
clrscr();
long int dd1,mm1,yy1;
long int dd,mm,yy;
long int start,file,end;
long int days;
char data[80];

cout<<"\n\nEnter date 1 to search between as DD/MM/YYYY"<<endl;
cin.ignore();
cin>>dd;
cin>>mm;
cin>>yy;
start=yy*10000+mm*100+dd;

cout<<"\nEnter date 2 to search between as DD/MM/YYYY"<<endl;
cin>>dd1>>mm1>>yy1;
end=(yy1*10000)+(mm1*100)+dd1;

ifstream fin;
fin.open("date.txt");

cout<<"\nHospitals provided with blood between date "<<dd<<"-"<<mm<<"-"<<yy <<" and "<<dd1<<"-"<<mm1<<"-"<<yy1<<" are:";
cout<<"\n\n"<<setw(n)<<"ID"<<setw(2*n)<<"Name"<<setw(n)<<"Sample"<<setw(n)<<"Qunatity"<<setw(n)<<"On Date";
//long int d,m,y;
while(1)
{
fin>>dd;
fin>>mm;
fin>>yy;
file=(yy*10000)+(mm*100)+dd;
if(fin.eof())
break;
if(file>=start&&file<=end)
{
fin.ignore();
fin.get(data,79);
cout<<"\n\n"<<setw(n)<<data;
fin.ignore();
fin.get(data,79);
cout<<setw(2*n)<<data;
fin.ignore();
fin.get(data,79);
cout<<setw(n)<<data;
fin.ignore();
fin.get(data,79);
cout<<setw(n)<<data;
cout<<setw(.5*n)<<dd<<"-"<<mm<<"-"<<yy;
}
else
{
fin.get(data,79);
fin.get(data,79);
fin.get(data,79);
fin.get(data,79);
}
}
fin.close();
getch();
}


class hospital
{
char name[80];
char id[80];
char sample[80],quan[80];

public:
void menu();
void request();
void status();
};

void hospital:: menu()
{
clrscr();
int x;
cout<<"\n\nWelcome:";
cout<<"\n1.Request for blood sample";
cout<<"\n2.Check status";
cout<<"\nChoice :";
cin>>x;
switch(x)
{
case 1:request();
	break;
case 2:status();
	break;
}
getch();
}

void hospital::request()
{       clrscr();
cout<<"\n\nEnter ID of your hospital:";
cin.ignore();
cin.get(id,79);
cout<<"Enter name of your hospital:";
cin.ignore();
cin.get(name,79);
cout<<"Enter sample required:";
cin.ignore();
cin.get(sample,79);
cout<<"Enter quantity required:";
cin.ignore();
cin.get(quan,79);
ofstream fout;
fout.open("Request.txt",ios::app);
fout<<id<<endl<<name<<endl<<sample<<endl<<quan<<endl;
cout<<"\n\nYour request has been saved, Kindly check your status 24 hours later";
fout.close();
}

void hospital::status()
{ clrscr();
int flag=0;
	ifstream fin;
	fin.open("Accepted.txt");
	char ch[2][20];
	cout<<"\n\nEnter id of hospital ";
	cin.ignore();
	cin>>ch[0];
	//for(int i=0;i<count;i++)
	while(1)
	{       if(fin.eof())
		break;
		fin.get(ch[1],19);
		if(!strcmp(ch[0],ch[1]))
		{cout<<"\n\nRequest Accepted";
		flag=1;
		break;
		}
		fin.ignore();
	}
	if(flag==0)
	cout<<"\n\nSorry, We couldn't fulfil your demands, Please try somewhere else...";
	getch();
	fin.close();
}
/*char id[80];
char check[80];
cout<<"Enter your hospital id";
cin.ignore();
cin.get(id,79);
cout<<id;
ifstream fin;
fin.open("Accepted.txt");
while(1)
{
fin.get(check,79);
if(check[0]=='\0')
{cout<<"Not accepted ! ";
break;
}
if(!strcmp(id,check))
cout<<"Found";
else
cout<<"not found";
fin.ignore();
}
getch();
fin.close();
*/




main()
{
int c;
do
{
clrscr();
cout<<"\n\n \t\t\tWelcome to BLOOD BANK \n" ;
cout<<" 1.Donor\n 2.Admin\n 3.Hospital\n 4.Exit";
cout<<"\n Select by pressing the number:";
cin>>c;
switch (c)
{
case 1:donor s;
       s.get();
       s.selection();
       break;

case 2:admin x;
       x.login();
       break;

case 3:hospital y;
       y.menu();
       break;

}
}while(c!=4);
clrscr();
cout<<"\n\n\n\n\n\n\n\n\t\t\t\t   THANK YOU";
getch();
}




