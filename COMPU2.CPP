//for Turbo C++
//#include<fstream.h>
// #include<conio.h>
// #include<string.h>
// #include<ctype.h>
// #include<stdlib.h>
// #include<process.h>
// #include<stdio.h>
// #include<dos.h>
#include<bits/stdc++ .h>
#include <iostream>
using namespace std;
//prototyping
void rstt(void);
void admini(int);
void memberf(int);
void homepage();
void login();
void guest();
char ent;int i,j;//to enter
char room[7][10];
int dd2=10, dd=10, ds2=10, ds=10, d2=10, d=10, s=10;
//structures
struct adminsto
{	char pass[10][20],phno[10][10],name[10][50];
	int age[10];
}adm={{"abhi17","12345","0000"},{"9709605487","2456787895","3354871678"},{"Abhishek","Anjali","Arshal"},{16,16,18}};
struct balance
{	double hot,cas,rest;
}bal={0.0,0.0,0.0};
struct membero
{       	char name[10][20],phno[10][10];
	int age[10],id[10];
}memb={{"DAV XII","A3"},{"1234567890","4567851789"},{16,18},{1,2}};
struct guesto
{	char name[70][100],rtype[70][4],phno[70][10];
}gst={{"VIJAY MALIYA"},{"dd2"},{"9876789540"}};
int gno=0;
double gt=0.0;
struct rev
{	float star;
	char revs[150],name[50];
}re;
//functions
void homepage()
{	clrscr();
	cout<<"\n\n\n\n\t\tH O T E L";
	cout<<"\n\t\t\t V    V";
	cout<<"\n\t\t\t   V  V";
	cout<<"\n\t\t\t      V       A      K      A      N       D       A";
	getch();
	login();
}//home
void login()
{	login: clrscr();      int p=0;
	cout<<"\n\n\n\n\t\t\t\tW E L C O M E   TO  HOTEL V A K A N D A\n\n\n";
	cout<<"\t\t\t\toptions:\n\n\t\t\t\t1.Administrator login";
	cout<<"\n\t\t\t\t2.Member login\n\t\t\t\t3.Guest login\n\t\t\t\t4.exit...";
	cout<<"\n\n\t\t\t\t Enter your choice:  ";cin>>ent;
	switch(ent)
	{	case '1':	char pass[20];
			 cout<<"\nadmin_password:";gets(pass);
			 for(i=0;i<10;i++)
			 if(strcmpi(pass,adm.pass[i])==0)
				{admini(i);p++;}
			 if(p==0)
			 {
				cout<<"\n SorrY! ID not found";
				cout<<"\nenter any key..";
				getch();
				goto login;
			 }
			break;
		case '2':	cout<<"\n Enter your ID: ";cin>>j;
			 for(i=0;i<10;i++)
			 if(j==memb.id[i])
				{memberf(j);p++;}
			 if(p==0)
			 {
				cout<<"\n Member not present";
				cout<<"\n Enter any key..";
				getch();
				goto login;
			 }
			break;
		case '3':	guest();
			break;
		case '4':	cout<<"\nHOPE YOU LIKED YOUR VISIT";
			getch(); exit(0);
		default: 	cout<<"\n\nOops! Wrong Choice,Try Again";getch();
			goto login;
	}
}//login
//display of room status
void rstt()
{ clrscr();
   for(i=1;i<=7;i++)
  {    int k;
	switch(i)
	{ case 1:k=dd2;break;
	  case 2:k=dd;break;
	  case 3:k=ds2;break;
	  case 4:k=ds;break;
	  case 5:k=d2;break;
	  case 6:k=d;break;
	  case 7:k=d;break;
	  default: k=0;

	}
	for(j=1;j<=10;j++)
	{if(j<=k)room[i-1][j-1]='x';
	 else room[i][j]='o';
	}
  }
}
void rst()
{   for(i=1;i<=7;i++)
  {     switch(i)
	{ case 1:cout<<"DELUX 2 DOUBLE\t ";break;
	  case 2:cout<<"DELUX DOUBLE\t ";break;
	  case 3:cout<<"DELUX 2 SINGLE\t ";break;
	  case 4:cout<<"DELUX SINGLE\t ";break;
	  case 5:cout<<"2 DOUBLE\t ";break;
	  case 6:cout<<"DOUBLE\t ";break;
	  case 7:cout<<"SINGLE\t ";break;
	  default: ;}
    for(j=1;j<=10;j++)
	cout<<room[i][j]<<"\t";cout<<"\n";
   }
   cout<<"\n\nENTER ANY KEY:";
}
//administrator class   //check it from here
class ADMI
{
public:
void admadm();
void admmem();
void admgst();
void admbal();
void admrev();
void admmsg();
};
void ADMI::admadm()
{       admad:	clrscr();
	cout<<"1.ADD A NEW ADMINISTRATOR"<<endl;
	cout<<"2.REMOVE AN ADMINISTRATOR"<<endl;
	cout<<"3.VIEW ADMINISTRATOR(s) LIST"<<endl;
	cout<<"4.exit"<<endl;
	cin>>ent; char s[20];
	if(ent=='1'){	clrscr();
			for(i=0;adm.age[i]!='\0';i++);
			error:
			cout<<"\nAdmin Name:";gets(adm.name[i]);
			cout<<"\nAdmin phno.:";gets(adm.phno[i]);
			cout<<"\nAdmin age:";cin>>adm.age[i];
			cout<<"\nPassword-";gets(adm.pass[i]);
			for(j=0;j<10;j++)
			 {if(strcmp(adm.pass[j],adm.pass[j])==0)
				{cout<<"Password matched...Error";
				goto error;
				}
			  }
			clrscr();
			cout<<"RE-enter the password to conform:";
			gets(s);
			if(strcmp(s,adm.pass[i])==0)cout<<"\nREGISTERED.";
			else {cout<<"error";goto error;}
			cin>>ent;goto admad;
		    }
	else if(ent=='2'){	clrscr();
			cout<<"\nEnter administrator's password to be removed:";
			gets(s);
			error2: int k=0;
			for(i=0;i<10;i++);
			if(strcmp(adm.pass[i],s)==0)
			{ 	k++;
				for(j=i+1;adm.pass[i]!='\0';j++,i++)//shifting
				{ strcpy(adm.pass[i],adm.pass[j]);
				strcpy(adm.name[i],adm.name[j]);
				strcpy(adm.phno[i],adm.phno[j]);
				adm.age[i]=adm.age[j];
				}
			}
			if (k==0)
			{cout<<"\nNo Such Member\nre-enter the pass word:";
			 gets(s);goto error2;}
			else cout<<"\nREMOVED";
			cin>>ent;goto admad;
			     }
	else if(ent=='3'){	clrscr();
			cout<<"\tNAME:\tAge\tPh.no.";
			for(i=0;adm.age[i]!='\0';i++)
			    cout<<i+1<<adm.name[i]<<"\t"<<adm.age[i]<<"\t"<<adm.phno[i]<<endl;
			cin>>ent;goto admad;
			     }
	else if(ent=='4') exit(0);
	else {cout<<"Wrong choice";cin>>ent;goto admad;}
}
void ADMI::admmem()
{	admm:
	clrscr();
	cout<<"1.ADD A NEW MEMBER"<<endl;
	cout<<"2.REMOVE A MEMBER"<<endl;
	cout<<"3.VIEW MEMBER(s) LIST"<<endl;
	cout<<"4.exit"<<endl;
	cin>>ent; char s[20];
	if(ent=='1'){clrscr();
		   for(i=0;memb.age[i]!='\0'||memb.id[i]==0;i++);
		   cout<<"\nMember Name:";gets(memb.name[i]);
		   cout<<"\nMember phno.:";gets(memb.phno[i]);
		   cout<<"\nMember age:";cin>>memb.age[i];
		   cout<<"\nMember ID:"<<(i+1);memb.id[i]=(i+1);
		   cout<<"\n\nMember Registered";
		   cin>>ent;goto admm;
		   }
	else if(ent=='2'){clrscr();
			cout<<"\nEnter member's name to be removed:";
			gets(s);
			error2:int k=0;
			for(i=0;i<10;i++)
			{	if(strcmpi(memb.name[i],s)==0)
				{	k++;
					for(j=i+1;memb.name[i]!='\0';j++,i++)//shifting
					{ strcpy(memb.name[i],memb.name[j]);
					  strcpy(memb.phno[i],memb.phno[j]);
					   memb.age[i]=memb.age[j];
					   memb.id[i]=memb.id[j];
					 }break;
				}
			}
			if (k==0)
			{cout<<"\nNo Such Member\nre-enter the name:";
			 gets(s);goto error2;
			 }
			else cout<<"REMOVED";
			cin>>ent;goto admm;
			     }
	else if(ent=='3'){clrscr();
			cout<<"iD:\tNAME:\tAge\tPh.no.";
			for(i=0;memb.age[i]!='\0';i++)
			    cout<<endl<<memb.id[i]<<"\t"<<memb.name[i]<<"\t"<<memb.age[i]<<"\t"<<memb.phno[i];
			cin>>ent;goto admm;
			     }
	else if(ent=='4') exit(0);
	else {	cout<<"Wrong choice";
		cin>>ent;goto admm;
		}
}

void ADMI::admgst()
{	adg:clrscr();
	cout<<"HOTEL GUEST LIST:";
	cout<<"\nName:\t\tPh.no.\tBill:";
	for(i=0;gst.name[i]=='\0';i++)
	cout<<gst.name[i]<<"\t\t"<<gst.phno[i]<<"\t"<<endl;
	cout<<"\nno. of guests:"<<gno;
	cout<<"\nENTER any key go back";cin>>ent;
}
void ADMI::admbal()
{       	clrscr();
	cout<<"ECONOMY:";
	cout<<"\nHOTEL VAKANDA\t\t"<<bal.hot;
	cout<<"\nTHE ROYAL MALABAR\t\t"<<bal.cas;
	cout<<"\nTHE BLUE MOON RESTAURANT\t\t"<<bal.rest;
	cout<<"\nTOTAL ECONOMY"<<(bal.hot+bal.cas+bal.rest);
	cout<<"\nENTER any key go back";cin>>ent;
}
void ADMI::admrev()
{       clrscr();char sent[150];
	ifstream fin("reviews.dat",ios::binary);
	rev er;
	while(fin.read((char*)&er,sizeof(er)))
	{cout<<"\nName: "<<er.name;
	  cout<<"\nRating: "<<er.star<<" / 5";
	  cout<<"\nReviews: "<<er.revs<<"\n\n";
	}fin.close();
	cout<<"ENTER ANY KEY TO GO BACK";cin>>ent;
}
void ADMI::admmsg()
{       clrscr();ent='y';
	char msgf[150];
	ofstream fout("messages.txt",ios::app);
	fout.seekp(0,ios::end);
	while(ent=='y'||ent=='Y')
	{cout<<"\nwanna leave some message(s) for the faculty";cin>>ent;
	fout<<"\n*"<<msgf;}
	fout.close();
	cout<<"ENTER ANY KEY TO GO BACK";cin>>ent;
}
void admini(int h)
{	ads:clrscr();
	cout<<"Welcome  "<<adm.name[h]<<endl;
	cout<<"1.Administration\n2.Members\n3.Guest list\n";
	cout<<"4.rooms status\n5.Today's Economy\n6.REVIEWS\n7.Message to your faculty\n";
	cout<<"8.EXIT";
	cout<<"enter your choice,sir:";cin>>ent; ADMI ad;
	switch(ent)
	{	case '1':ad.admadm();goto ads;
		case '2':ad.admmem();goto ads;
		case '3':ad.admgst();goto ads;
		case '4':rst(); goto ads;
		case '5':ad.admbal();goto ads;
		case '6':ad.admrev();goto ads;
		case '7':ad.admmsg();goto ads;
		case '8':login();
		default:cout<<"wrong choice, sir";cin>>ent;goto ads;
	}
}

void memberf(int mid)
{       memfu:
	clrscr();
	cout<<"HELLO, "<<memb.name[mid];
	cout<<"\nMENU:\n1.Your details\n2.nRoom Status\n3.Administrater messages\n4.Exit\n";
	cin>>ent;
	switch(ent)
	{	case '1':clrscr();
			 cout<<"Name:"<<memb.name[mid]<<endl;;
			 cout<<"Age:"<<memb.age[mid]<<endl;
			 cout<<"Ph.no."<<memb.phno[mid]<<endl;
			 cout<<"Faculty ID:"<<memb.id[mid]<<endl;
			 cout<<"enter a key:";cin>>ent;goto memfu;
		case '2':rst();goto memfu;
		case '3':clrscr();
			 ifstream gin("messages.txt",ios::in);
			 while(!gin.eof())
			 { gin.get(ent);
			   cout<<ent;}
			   cout<<"ENTER ANY KEY TO GO BACK";cin>>ent;
			  gin.close();goto memfu;
		case '4':login();
		default: cout<<"\nWrong choice";
			 cin>>ent;goto memfu;
	}
}
class GUES
{
public:
long chkin();
void chkout();
long bluemoon();
double hangman(char sd[20]);
void show(int g,int n);
int offer();
double change(double f,double sta,int off);
char result(int u1,int u2,int u3,int p1,int p2,int p3,int gr,int med,int sm);
int disp(int g,int re);
double teenpatti(char sd[20]);
double dice(char sd[20]);
long casino();
void srev();
};
long GUES::chkin()
{	long tot=0.0;
	cout<<"\nenter your details:";
		for(i=0;gst.name[i]!='\0';i++);
		gno++;
		cout<<"\nNAME:";gets(gst.name[i]);
		cout<<"\nphone no.";gets(gst.phno[i]);
	menu: clrscr();int day;
		cout<<"\nSl.no.\tTYPES\t\tPRICE/day\tRooms left\n";
		cout<<"\n1.\tDELUXE 2 Double Bed\t\tRs.2400\\t"<<dd2;
		cout<<"\n2.\tDELUXE Double bed\t\tRs.2000\t"<<dd;
		cout<<"\n3.\tDELUXE 2 Single bed\t\tRs.1600\t"<<ds2;
		cout<<"\n4.\tDELUXE Single Bed\t\tRs.1200\t"<<ds;
		cout<<"\n5.\t2 Double Bed\t\tRs.1000\t"<<d2;
		cout<<"\n6.\tDouble Bed\t\tRs.800\t"<<d;
		cout<<"\n7.\tSingle Bed\t\tRs.500\t"<<s;
		cout<<"\nType no.:";cin>>ent;
		cout<<"\nno.of days:";cin>>day;
		cout<<"\nac/non-ac:\t1.AC(rs.600/day)\t2.non-AC:";cin>>j;
	if(ent=='1')
	   { if(dd2!=0)
		 { dd2--;tot+=2400*day;strcpy(gst.rtype[i],"dd2");}
	      else
		 {cout<<"\nno rooms left";cin>>ent;goto menu;}
	    }
	else if(ent=='2')
	   { if(dd!=0)
		 { dd--;tot+=2000*day;strcpy(gst.rtype[i],"dd");}
	     else
		 {cout<<"\nno rooms left";cin>>ent;goto menu;}
	   }
	else if(ent=='3')
	  { if(ds2!=0)
		{ ds2--;tot+=1600*day;strcpy(gst.rtype[i],"ds2");}
	    else
		{cout<<"\nno rooms left";cin>>ent;goto menu;}
	   }
	else if(ent=='4')
	   { if(ds!=0)
		 { ds--;tot+=1200*day;strcpy(gst.rtype[i],"ds");}
	     else
		 {cout<<"\nno rooms left";cin>>ent;goto menu;}
	   }
	else if(ent=='5')
	   {if(d2!=0)
		 { d2--;tot+=1000*day;strcpy(gst.rtype[i],"d2");}
	     else
		 {cout<<"\nno rooms left";cin>>ent;goto menu;}
	   }
	else if(ent=='6')
	   {if(d!=0)
		 { d--;tot+=800*day;strcpy(gst.rtype[i],"d");}
	     else
		 {cout<<"\nno rooms left";cin>>ent;goto menu;}
	    }
	else if(ent=='7')
	   {if(s!=0)
		 { s--;tot+=500*day;strcpy(gst.rtype[i],"s");}
	     else
		 {cout<<"\nno rooms left";cin>>ent;goto menu;}
	    }
	else
	  {cout<<"wrong choice";cin>>ent;goto menu;}
if(j==1)tot+=600*i;
cout<<"\n<<<room booked>>>.";
cout<<"\nwant to book any other room too?(Y/N)";
cin>>ent;
if(ent=='y'||ent=='Y')
goto menu;
else
cout<<"YOUR TOTAL PRICE:"<<tot;cin>>ent;
rstt();
return tot;
}

void GUES::chkout()
{     	chko:clrscr();
	cout<<"CHECK OUT:";
	cout<<"\nEnter your Name:";
	char ge[50];gets(ge);int ko=0;
	for(i=0;gst.name[i]!='\0';i++)
	{	if(strcmp(ge,gst.name[i])==0)
		{	ko++;
			for(j=i+1;gst.name[i]!='\0';j++,i++)
			{ strcpy(gst.name[i],gst.name[j]);
			  strcpy(gst.phno[i],gst.phno[j]);
			  strcpy(gst.rtype[i],gst.rtype[j]);
			} gno--;
			     if(strcmp(gst.rtype[i],"dd2")==0)dd2--;
			else if(strcmp(gst.rtype[i],"dd")==0)dd--;
			else if(strcmp(gst.rtype[i],"ds2")==0)ds2--;
			else if(strcmp(gst.rtype[i],"ds")==0)ds--;
			else if(strcmp(gst.rtype[i],"d2")==0)d2--;
			else if(strcmp(gst.rtype[i],"d")==0)d--;
			else if(strcmp(gst.rtype[i],"s")==0)s--;
		}
	}
	if(ko==0) {cout<<"\nNO SUCH RECORDS!";cin>>ent;goto chko;}
	else {cout<<"CHECKED OUT!";rstt();cin>>ent;guest();}
}
long GUES::bluemoon()
{ 	long tot=0.0;
	foodies:clrscr();
	cout<<"Welcome to BLUEMOON...";cin>>ent;
	ifstream menus("menu.txt");
	  char food[150];
	 while(!menus.eof())
	    { menus.getline(food,150,'$');
	       cout<<"\n";
	     }
	menus.close();
	cout<<"\n\nLIKE TO PLACE YOUR ORDER?(Y/N):";
	cin>>ent;
	if(ent=='y'||ent=='Y')
	{	char mm[40];
		order:
		cout<<"\nEnter Your CHOICE:";
		gets(mm);
		if(strcmp(mm,"veg-manchurian")==0) tot+=100;
		else if(strcmp(mm,"paneer manchurian")==0)tot+=150;
		else if(strcmp(mm,"veggiee noodles")==0)tot+=120;
		else if(strcmp(mm,"hot soup")==0)tot+=60;
		else if(strcmp(mm,"rice")==0)tot+=60;
		else if(strcmp(mm,"roti")==0)tot+=30;
		else if(strcmp(mm,"veg biryani")==0)tot+=250;
		else if(strcmp(mm,"mix veg")==0)tot+=80;
		else if(strcmp(mm,"matar paneer")==0)tot+=130;
		else if(strcmp(mm,"chicken manchurian")==0)tot+=170;
		else if(strcmp(mm,"chicken noodles")==0)tot+=180;
		else if(strcmp(mm,"chicken biryani")==0)tot+=350;
		else if(strcmp(mm,"mutton biryani")==0)tot+=400;
		else if(strcmp(mm,"prawn rice")==0)tot+=380;
		else if(strcmp(mm,"bluemoon spc.")==0)tot+=500;
		else if(strcmp(mm,"ice cream")==0)tot+=80;
		else if(strcmp(mm,"bluemoon spc. sweet")==0)tot+=160;
		else cout<<"\nPlease enter correctly...";
		cout<<"\nYOU like something more?(y/n)";
		if(ent=='y'||ent=='Y')goto order;
	}
	else if(ent=='N'||ent=='n')
	{	cout<<"\n\nyour total bill:"<<tot;
		cin>>ent;
		return tot;}
	else
	{	cout<<"\nERROR";
		goto foodies;}
return tot;
}

double GUES::hangman(char sd[20])
{//function hangman starts here
	double tot2=0.0, full2=0.0,copy2;
	menu_hang :
	clrscr();
	randomize();
	double change=0;
	double bet_amt;char ch[20],alpha;long k;
	cout<<"Enter your full stake(you can not make a stake higher than this):";cin>>full2;copy2=full2;
	cout<<"\n WELCOME "<<sd;
	cout<<"\n\n THE HANGMAN GAME"<<endl;
	cout<<" 1.Let's play"<<endl;
	cout<<" 2.How to play"<<endl;
		cout<<" 3.Exit"<<endl;
	cout<<" Chose your option: ";cin>>ent;
	switch(ent)
	{
	case '1'://case 1 begins here
		amt_enter :
		clrscr();
		cout<<"\n USER: "<<sd<<"\n\n";
		cout<<endl<<" Enter your betting amount ";cin>>bet_amt;
		if(bet_amt>full2)
		{	cout<<" Betting Amount greater than your full stake,Try Again \n\n";
			goto amt_enter;
		}
		char state[10][20]={"Chennai","Jharkhand","Punjab","Uttarakhand","Maharashtra","Gujarat","Odisha","Rajasthan","Mizoram","Kerala"};
		int rand=random(10)+1;int length=strlen(state[rand]);
		cout<<"\n Wait for a few seconds \n\n";for(k=-100000;k<=10000000;k++);
		for(i=0;i<length;i++)
			ch[i]='*';
		cout<<ch[i];
		cout<<endl;
		for(i=0;;i++)
		{	cout<<"\n Type your guessed letter: ";cin>>alpha;cout<<endl;
			for(j=0;j<length;j++)
			{	if(alpha==state[rand][j]||alpha==(state[rand][j]+32))
				{	ch[j]=alpha;}
			}ch[j]='\0';
			for(j=0;j<length;j++)
				cout<<ch[j];
			cout<<endl;
			if(strcmpi(ch,state[rand])==0)
				break;
		}
		clrscr();
		cout<<"\n Wait for a few seconds \n\n";for(k=-100000;k<=10000000;k++);
		if(i<=length)
		{	change=bet_amt*2;
			cout<<" Congo! You are getting rich \n You won: "<<change<<endl;
		}
		else if(i<=length+3)
		{	change=bet_amt*1.5;
			cout<<" Congo! You are getting rich \n You won: "<<change<<endl;
		}
		else if(i<=length+5)
		{	change=bet_amt;
			cout<<" Congo! You are getting rich \n You won: "<<change<<endl;
		}
		else
		{	change=-(bet_amt*2);
			cout<<" Sorry! This time lady luck is not with you \n You lost: "<<change;
		}  full2+=change;
		cout<<"\nYour current amt="<<full2;
		cout<<"\n Thank you for playing"<<endl;
		go :
		cout<<" Do yo wanna go back(Y/N): ";cin>>ent;
		if(ent=='Y'||ent=='y')
		goto menu_hang;
		else
		goto go;
	//case 1 closes here;
	case '2'://case 2 opens here
		clrscr();
		cout<<" Instructions:"<<endl;
		cout<<" I will chose an Indian state randomly \n";
		cout<<" and display it on my screen in the form of stars \n";
		cout<<" You have to enter the alphabet one by one \n";
		cout<<" If the letter will be present I will amend the star with the letter \n";
		cout<<" Your number of attempts will be recorded and according \n";
		cout<<" to it your fate will be decide \n";
		cout<<" Attempts less than or equal to length: You win (bet amt*2) OR \n";
		cout<<" Attempts less than or equal to length+3: You win (bet amt*1.5) OR \n";
		cout<<" Attempts less than or equal to length+5: You win (bet amt*1) OR \n";
		cout<<" Attempts greater than length+5: You lose (bet amt*2) \n";
		cout<<"\n\n\nNOTE: -ve stake indicates your rent amount...";
		cout<<"\n\n ENJOY THE GAME \n\n";
		back3 :
		cout<<" Do you wanna go back(Y/N)";cin>>ent;
		if(ent=='Y'||ent=='y')
		goto menu_hang;
		else
		goto back3;
	case '3':	cout<<"\nYour actual stake was: "<<copy2<<endl;
		cout<<"your present stake: "<<full2<<endl;
		(full2<0)?cout<<"\nyou have insufficient balance. The lend money would be added in your bill.":(full2>copy2)?cout<<"\nyou earned: "<<full2-copy2:cout<<"you lost: "<<copy2-full2;
		tot2=copy2+((full2<0)?(-full2):(full2>copy2)?full2-copy2:full2);
		cout<<"\nenter any key:";cin>>ent;return(tot2);
	default:	cout<<"Wrong choice try again";
		goto menu_hang;
	}//switch closes here
}//function hangman closes here
//teenpatti starts here
void GUES::show(int g,int n)//card showing
{
	cout<<"\n card flip:";
	if(g==1)
		cout<<"\t DIAMOND \t";
	if(g==2)
		cout<<"\t CLUB \t";
	if(g==3)
		cout<<"\t HEART \t";
	if(g==4)
		cout<<"\t SPADE \t";
	if(n<11)
		cout<<n;
	else if(n==14)
		cout<<"A";
	else if(n==11)
		cout<<"J";
	else if(n==12)
		cout<<"Q";
	else
		cout<<"K";
}
int GUES::offer() //altering stake offers
{offs:
	cout<<"\n\nchoose your offer...\n";
	cout<<"1.double the stake\n";
	cout<<"2.triple the stake\n";
	cout<<"3.all in\n";
	cout<<"4.left(-100)\n";
	cin>>i;
	if(i>4||i<1)
	{cout<<"invalid choice...\n";goto offs;}
	else
	{return(i);}
}
double GUES::change(double f,double sta,int off)//stake alter
{
	if(off==1)
		sta*=2;
	if(off==2)
		sta*=3;
	if(off==3)
		sta=f;
	if(off==4)
		sta=0;
	if(sta>f)
		sta=f;
	return sta;
}
char GUES::result(int u1,int u2,int u3,int p1,int p2,int p3,int gr,int med,int sm)//result check
{
	if(u1==u2&&u2==u3)
		return 6;//trail
	else if(u1==u2||u2==u3||u1==u3)
		return 2;//pair
	else if(p1==p2&&p3==p1)
		return 3;//flush
	else
	{
		if(gr-med==1&&med-sm==1)
		{
			if(p1==p2&&p2==p3)
			return 5;//straight flush
			else
			return 4;//straight
		}
		else
		return 1;//highcard
	}
}
int GUES::disp(int g,int re)//winner anouncement
{
	clrscr();
	cout<<"\nRESULT:\n";
	if(g!=2)
	{
		if(g==1)
		   cout<<"\nYOU ";
		else
		   cout<<"\nCOMPUTER ";
		cout<<"won by a ";
	}
	else
		cout<<"\nTIED by a ";

	if(re==6)
		cout<<"TRAIL( 3 of a kind )";
	if(re==5)
		cout<<"STRAIGHT FLUSH";
	if(re==4)
		cout<<"STRAIGHT";
	if(re==3)
		cout<<"FLUSH";
	if(re==2)
		cout<<"PAIR( 2 of a kind)";
	if(re==1)
		cout<<"HIGHCARD";

	if(g==1)
		return 1;
	else if(g==0)
		 return 0;
	else
		 return 2;
}

double GUES::teenpatti(char sd[20])//teenpatti
{	long tot=0;
	double full=0.0,copy;//intro
	casio: clrscr();
	cout<<"WELCOME "<<sd;
	cout<<"\tTEEN PATTI\n\n";
	cout<<"\n\n1.LET's PLAY\n2.HOW TO PLAY\n3.EXIT\n";
	cin>>ent;
	cout<<"\nEnter your total stake:";cin>>full;
	copy=full;
	switch(ent)//switch open
	{ case '1':	play:
		cout<<"\nwanna play(Y/N):";cin>>ent;
		if(ent=='Y'||ent=='y')
			{//playing
				clrscr();randomize();
				cout<<"                    ";
				cout<<"\nthree cards have been provided...";
			//user cards
			int c1=random(13)+2;
			int c2=random(13)+2;
			int c3=random(13)+2;
			int s1=random(4)+1;
			int s2=random(4)+1;
			int s3=random(4)+1;
			//computer cards
			int cc1=random(13)+2;
			int cc2=random(13)+2;
			int cc3=random(13)+2;
			int cs1=random(4)+1;
			int cs2=random(4)+1;
			int cs3=random(4)+1;
			int compst=1000;
				double st;int o;
				cout<<"\nput your stake:";
				cin>>st;
				cout<<"\ncomputer stake:"<<compst;
				for(i=1;i<=3;i++)
				{//for 3 rounds
					randomize();
					if(st>0)
					{if(i==1)
						show(s1,c1);
					 else if(i==2)
						show(s2,c2);
					 else
						show(s3,c3);
					 }o=offer();
					 st=change(full,st,o);
					int compoff=random(2)+1;
					if(compoff==1)
						compst*=2;
					else
						compst*=3;
					cout<<"\n\ncomp stake:"<<compst<<"\nyour stake:"<<st;
					if (o==4)
					{break;}
				}//rounds
				if(o!=4)
				{	cout<<"\ncomp.cards:  \n";
					show(cs1,cc1);
					show(cs2,cc2);
					show(cs3,cc3);
					cout<<"\nenter any key";
					cin>>ent;clrscr();//to find smallest to greatest cards
					int usgr=(c1>c3)?((c1>c3)?c1:c3):((c2>c3)?c2:c3);
					int cogr=(cc1>cc3)?((cc1>cc3)?cc1:cc3):((cc2>cc3)?cc2:cc3);
					int ussm=(c1<c3)?((c1<c3)?c1:c3):((c2<c3)?c2:c3);
					int cosm=(cc1<cc3)?((cc1<cc3)?cc1:cc3):((cc2<cc3)?cc2:cc3);
					int usmd,comd;
					if(c1!=usgr&&c1!=ussm)
					usmd=c1;
					else if(c2!=usgr&&c2!=ussm)
					usmd=c2;
					else
					usmd=c3;
					if(cc1!=cogr&&cc1!=cosm)
					comd=cc1;
					else if(cc2!=cogr&&cc2!=cosm)
					comd=cc2;
					else
					comd=cc3;
					int ep;
					int user=result(c1,c2,c3,s1,s2,s3,usgr,usmd,ussm);
					int comp=result(cc1,cc2,cc3,cs1,cs2,cs3,cogr,comd,cosm);
					if(user==comp)
					{
						if(usgr>cogr)
							ep=disp(1,user);
						else if(usgr<cogr)
							ep=disp(0,comp);
						else
						{
							if(usmd>comd)
								ep=disp(1,user);
							else if(usmd<comd)
								ep=disp(0,comp);
							else
							{
								if(ussm>cosm)
									ep=disp(1,user);
								else if(ussm<cosm)
									ep=disp(0,comp);
								else
									ep=disp(2,comp);
							}
						}
					}
					else if(user<comp)
						ep=disp(0,comp);
					else
						ep=disp(1,user);
					if (ep==1)
					  full+=compst;
					else if(ep==0)
					  full-=st;
					else
					  full+=10;
				}//o!=4
				else
					full-=100;
				cout<<"\nyour total stake: "<<full;
				cout<<"\nwant to play one more round?(Y/N)";cin>>ent;
				if(ent=='y'||ent=='Y')goto play;
				else goto casio;
			}//playing
			else goto casio;
	//case 1 ends here
	case '2':	clrscr();
		cout<<"RULES:\nA >K >Q >J >10 >...> 2\nTRAIL:3 of a kind\nSTRAIGHT FLUSH:three consecutive cards of same suit";
		cout<<"\nSTRAIGHT:three consecutive cards\nFLUSH:same suit\nPAIR:2 of a kind";
		cout<<"\nHIGH CARD:a high valued card\n";
		cout<<"\n\nyou will be provided with 3 random cards\nyour opponent too get three cards\n";
		cout<<"best combination will win\nbefore seeing your cards you have to stake maoney\n";
		cout<<"and after seeing choose the offer(eg. doubling the amt)\nnote:you may get same cards.\n\n BETTER COMBINATION WINS!!!";
		cout<<"\n\n\nNOTE: -ve stake indicates your rent amount...";
		back:
		cout<<"\n\n\nWanna go back?(Y/N)";
		cin>>ent;
		if(ent=='Y'||ent=='y')goto casio;
		else goto back;
	case '3':	cout<<"\nYour actual stake was: "<<copy<<endl;
		cout<<"your presant stake: "<<full<<endl;
		(full<0)?cout<<"\nyou have insufficient balance. The lend money would be added in your bill.":(full>copy)?cout<<"\nyou earned: "<<full-copy:cout<<"you lost: "<<copy-full;
		tot=copy+((full<0)?(-full):(full>copy)?full-copy:full);
		cout<<"\nenter any key:";cin>>ent;return(tot);
	default:cout<<"\ninvalid choice\n re-choose";goto casio;
	}//switch case ends here
}//teenpatti closes

double GUES::dice(char sd[20])
{	long tot=0;
	double full3=0.0,copy3;//intro
	 dices: clrscr();
	cout<<"\t\tWELCOME "<<sd;
	cout<<"\n\t\tDICE ROLL\n\n";
	cout<<"\n\n1.LET's PLAY\n2.HOW TO PLAY\n3.EXIT\n";
	cout<<"\nEnter your total stake:";cin>>full3;
	copy3=full3;
	cout<<"\nenter your choice: ";cin>>ent;
	switch(ent)
	{
	case '1':    play2:randomize();
		clrscr();
		cout<<" \nIT'S ABOUT TO ROLL";
		int n;cout<<"\nenter the no. of possibilities you want to give(max 12):";cin>>n;
		double st[12],temptot=0;int num[12];
		for(i=0;i<n;i++)
		{   cout<<"\nenter possible sum with its stake amount simultaneously";
		     cin>>num[i];cin>>st[i];cout<<"\n";temptot+=st[i];
		 }
		cout<<"\nall filled\n\n";
		for(i=0;i<n;i++)
		{cout<<num[i]<<"\t"<<st[i]<<"\n";}
		cout<<"\n\n\t\tREADY FOR RESULTS";cin>>ent;
		int r=random(12)+1;
		cout<<"\n\n\t\t---> "<<r;
		for(i=0;i<n;i++)
		{    if(r==num[i])
		     {temptot-=st[i]*2;
		       cout<<"\n\t\tYOU Won...-->"<<num[i]<<"->"<<st[i]<<"X2";
		     }
		     else
		     {cout<<"\n\t\tYou loose...-->"<<num[i]<<"--> (-"<<st[i]<<")";
		     }
		}
		if(temptot<0)full3+=(-temptot);
		else full3+=temptot;
		cout<<"\nYour present stake:"<<full3;
		cout<<"\nwant to play once more?(y/n):";cin>>ent;
		if(ent=='y'||ent=='Y')goto play2; else goto dices;
	case '2':	clrscr();
		cout<<"RULES:\nyou have to give 'n' possibilities of the sum of 2 dice";
		cout<<"\nwith each digit you have to stake some amount...";
		cout<<"\neg: 8---rs.400, 12---rs.1300, etc.";
		cout<<"\nfor correct prediction: your respective stake amount would be doubled";
		cout<<"\nincorrect predicted stakes would be lost. So beware.";
		cout<<"\n\n\nNOTE: -ve stake indicates your rent amount...";
		back2:
		cout<<"\n\n\nWanna go back?(Y/N)";
		cin>>ent;
		if(ent=='Y'||ent=='y')goto dices;
		else goto back2;
	case '3':	clrscr();
		cout<<"\nYour actual stake was: "<<copy3<<endl;
		cout<<"your presant stake: "<<full3<<endl;
		(full3<0)?cout<<"\nyou have insufficient balance. The lend money would be added in your bill.":(full3>copy3)?cout<<"\nyou earned: "<<full3-copy3:cout<<"you lost: "<<copy3-full3;
		tot=copy3+((full3<0)?(-full3):(full3>copy3)?full3-copy3:full3);
		cout<<"\nenter any key:";cin>>ent;return(tot);
	default:	cout<<"\ninvalid choice\n re-choose";goto dices;
	}
return tot;}


long GUES::casino()
{	clrscr(); double tot_won=0.0,tot_bill=0.0;
	int choice;char gname[20];
	cout<<"\nenter your name:";gets(gname);
	clrscr();
	menu_gamble:
	cout<<"\n\n \t\tWELCOME ";
	cout<<"\n \t\tLet's try your luck and win big bucks"<<endl;
	cout<<" Press any key to enter: ";cin>>ent;
	cout<<"\n \t\t1.THE HANGMAN GAME "<<endl;
	cout<<"\n \t\t2.TEENPATTI "<<endl;
	cout<<"\n \t\t3.ROLL THE DICE "<<endl;
	cout<<"\n \t\t4.HOMEPAGE"<<endl;
	cout<<"\n Enter your choice: ";cin>>ent;
	if(ent=='1')tot_won+=hangman(gname);
	else if(ent=='2')tot_won+=teenpatti(gname);
	else if(ent=='3')tot_won+=dice(gname);
	else if(ent=='4')return(tot_won);
	else
	{
		cout<<"Oops!Wrong Choice Try again";goto menu_gamble;
	}
}

void GUES::srev()
{ ofstream fo("reviews.dat",ios::binary|ios::app);
   cout<<"enter your name:";gets(re.name);
   cout<<"\nrecommended stars(/5):";cin>>re.star;
   cout<<"\nyour message:\n";gets(re.revs);
   fo.seekp(0,ios::end);
   fo.write((char*)&re,sizeof(re));
   fo.close();
}


void guest()
{	double bill=0.0,bill1=0.0,bill2=0.0,bill3=0.0;GUES gust;
	guest_home: clrscr();
	cout<<"*******We WELCOME you to HOTEL VAKANDA*******\n";
	cout<<"\n\n1. HOTEL REGISTRATION";
	cout<<"\n\n2. BLUE MOON RESTAURANT";
	cout<<"\n\n3. MALABAR'S Royal CASINO";
	cout<<"\n\n4. write a review";
	cout<<"\n\n5. exit.";
	cout<<"\n\nWhere do you want to go, sir?";cin>>ent;
	if(ent=='1') {cout<<"1.check in\n2.check out";
		  cin>>ent;
		  if(ent=='1')bal.hot+=bill1+=gust.chkin();
		  else if(ent=='2')gust.chkout();
		  else goto guest_home;
		  }
	else if(ent=='2'){bal.rest+=bill2+=gust.bluemoon();
			  goto guest_home;
			  }
	else if(ent=='3'){bal.cas+=bill3+=gust.casino();
			  goto guest_home;
			  }
	else if(ent=='4'){gust.srev();}
	else if(ent=='5'){cout<<"Wanna leave us so early???(Y/N)";cin>>ent;
				if(ent=='Y'||ent=='y')
				{	bill=(bill1+bill2+bill3);
					double bi=bill1+bill2+bill3;
					double di=(bill1+bill2+bill3)*0.05;
					double gsto=(bill1+bill2+bill3)*0.13;
					double gt=bill=bi+gsto-di;
					cout<<"\nYOUR BILL:";
					cout<<"\nHotel Charges:\t"<<bill1<<endl;
					cout<<"\nRestraunt Charges:\t"<<bill2<<endl;
					cout<<"\nCasino Charges:\t"<<bill3<<endl;
					cout<<"\n------------------\t"<<bi<<endl;
					cout<<"\nDiscount:  [5%]\t"<<di<<endl;
					cout<<"\nGST:(13%):\t"<<gsto<<endl;
					cout<<"\n\nTOTAL:\t"<<gt<<endl;
					cout<<"\n\t******THANK YOU*****";
					cout<<"\n\n\n\tVISIT AGAIN...";
					cout<<"\n\nenter a key:";cin>>ent;login();
				}
				else {goto guest_home;}
			 }
	else             {goto guest_home;}

}
void main()
{  clrscr();
   homepage();
   getch();
}
