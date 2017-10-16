#include<iostream>
#include<conio.h>
#include<string.h>
#include<graphics.h>
using namespace std;
struct station
{
	int ctr3;
	int lon,lat;
	int utility;
	int no;
	int edgewt[100];
	char name[50];
	int ptr[20];
	int wei;
}st[50];
int scnt=0,a,ccnt=0;
int tem[10];
char dmat[50][50];
void calwei()
{int i,j;
//	for(i=0;i<scnt;i++)
	//{st[i].wei=
	//	}
}
void dnet()
{int i,j,index;
	for(int jh=0;jh<scnt;jh++)
	{
		circle(st[jh].lon,st[jh].lat,20);
		outtextxy(st[jh].lon,st[jh].lat,st[jh].name);
		for(int fg=0;fg<st[jh].ctr3;fg++)
		{
			line(st[jh].lon,st[jh].lat,st[st[jh].ptr[fg]].lon,st[st[jh].ptr[fg]].lat);
		}
	}
	setcolor(4);
	for(j=0;j<ccnt;j++)
	{index=tem[j];
		for(i=0;i<st[index].ctr3;i++)
		line(st[index].lon,st[index].lat,st[st[index].ptr[i]].lon,st[st[index].ptr[i]].lat);
	}
	setcolor(15);
}


int checkpendant(station temp)
{
	if(temp.ctr3==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void distmat()
{
	int i,j,k,u,g,l;
	for(i=0;i<scnt;i++)
	{
		for(j=0;j<scnt;j++)
		{
			dmat[i][j]='0';
		}
	}
	for(l=0;l<scnt;l++)
	{
		for(k=0;k<st[l].ctr3;k++)
		{
			a=st[l].ptr[k];
			dmat[l][a]='1';
			dmat[a][l]='1';
		}
	}
	int t;
	for(int n=0;n<ccnt;n++)
	{
		t=tem[n];
		for(int z=0;z<scnt;z++)
		{
			dmat[z][t]='X';
			dmat[t][z]='X';
		}
	}
	cout<<"    ";
	for(int y=0;y<scnt;y++)
	{
			cout<<st[y].name[0]<<st[y].name[1]<<st[y].name[2]<<"  ";
	}
	cout<<endl;
	for(u=0;u<scnt;u++)
	{
				cout<<st[u].name[0]<<st[u].name[1]<<st[u].name[2]<<" ";
				for(g=0;g<scnt;g++)
				{
					cout<<dmat[u][g]<<"    ";
				}
				cout<<endl;
	}
}
void setutil(station t)
{
	t.utility=0;
	for(int h=0;h<t.ctr3;h++)
	{
		if(st[t.ptr[h]].ctr3==1)
		{
			t.utility+=6;
		}
		else
		{
			t.utility+=1;
		}
	}
}
void addstation()
{
	int gh;
	cout<<"\n 1)Open a Station \n 2)Add new \n";
	cin>>gh;
	if(gh==2)
	{
		cout<<"\n Enter Station name:-";
		cin>>st[scnt].name;
		cout<<"\n Enter Station longitude:-";
		cin>>st[scnt].lon;
		cout<<"\n Enter Station latitude:-";
		cin>>st[scnt].lat;
		st[scnt].no=scnt;
		st[scnt].ctr3=0;
		char ans='y';
		int x;
		while(ans=='y')
		{
			cout<<"\nEnter Connected Station Number";
			cin>>st[scnt].ptr[st[scnt].ctr3];
			st[scnt].ctr3++;
			cout<<"\nEnter more connected stations?(y/n)";
			cin>>ans;
		}
		setutil(st[scnt]);
		scnt++;
	}
	else if(gh==1)
	{
		int index1;
		int temp1[10];
		int ctr2=0;
		cout<<"\nEnter the station number to be added";
		cin>>index1;
		for(int fd=0;fd<ccnt;fd++)
		{
			if(index1==tem[fd])
			{
				continue;
			}
			else
			{
				temp1[ctr2]=tem[fd];
				ctr2++;
			}
		}
		for(int tr=0;tr<ctr2;tr++)
		{
			tem[tr]=temp1[tr];
		}
		for(int er=ctr2;er<10;er++)
		{
			tem[er]=99;
		}
	}
	dnet();
}
void delstation()
{
	int index;
	cout<<"\nEnter the number of the station to be closed:-";
	cin>>index;
	cout<<"\n Station details:-\nName:-"<<st[index].name<<"\n";
	if(st[index].utility<=3)
	{
		cout<<"\n Minor Station. Safe to closed \n";
	}
	else
	{
		cout<<"\n Warning. Major Station. Closing may result in disruption of network. \n";
	}
	char ans;	int i;
	cout<<"\n Do you really wish to close the station?(y/n)";
	cin>>ans;
	if(ans=='y')
	{setcolor(4);
		tem[ccnt]=index;
		for(i=0;i<st[index].ctr3;i++)
		line(st[index].lon,st[index].lat,st[st[index].ptr[i]].lon,st[st[index].ptr[i]].lat);
		ccnt++;
	}

		setcolor(15);
}

int main()
{initwindow( 1000 , 1000 , "WinBGIm" );
	int ch;
	char an='y';
	//Name and location of Pre-existing stations
	st[0].no=0;st[0].lat=400;st[0].lon=400;strcpy(st[0].name,"Delhi");st[0].utility=1;st[0].ptr[0]=1;st[0].ctr3=1,st[0].edgewt[1]=5;
	st[0].no=1;st[1].lat=500;st[1].lon=600;strcpy(st[1].name,"Kolkata");st[1].utility=8;st[1].ptr[0]=0;st[1].ptr[1]=2;st[1].ptr[2]=5;st[1].ctr3=3;st[1].edgewt[2]=6;st[1].edgewt[0]=5;st[1].edgewt[5]=7;
	st[0].no=2;st[2].lat=550;st[2].lon=480;strcpy(st[2].name,"Lucknow");st[2].utility=3;st[2].ptr[0]=1;st[2].ptr[1]=5;st[2].ptr[2]=4;st[2].ctr3=3;st[2].edgewt[1]=3;st[2].edgewt[5]=8;st[2].edgewt[4]=4;
	st[0].no=3;st[3].lat=600;st[3].lon=550;strcpy(st[3].name,"Chennai");st[3].utility=3;st[3].ptr[0]=4;st[3].ptr[1]=9;st[3].ptr[2]=8;st[3].ptr[3]=5;st[3].ctr3=4;st[3].edgewt[4]=2;st[3].edgewt[5]=9;st[3].edgewt[9]=6;st[3].edgewt[8]=5;
	st[0].no=4;st[4].lat=500;st[4].lon=100;strcpy(st[4].name,"Mumbai");st[4].utility=3;st[4].ptr[0]=2;st[4].ptr[1]=3;st[4].ptr[2]=5;st[4].ctr3=3;st[4].edgewt[2]=9;st[4].edgewt[3]=6;st[4].edgewt[5]=3;
	st[0].no=5;st[5].lat=300;st[5].lon=180;strcpy(st[5].name,"Ahmedabad");st[5].utility=5;st[5].ptr[0]=2;st[5].ptr[1]=3;st[5].ptr[2]=4;st[5].ptr[3]=9;st[5].ptr[4]=1;st[5].ctr3=5;st[5].edgewt[2]=1;st[5].edgewt[3]=2;st[5].edgewt[4]=6;st[5].edgewt[9]=8;st[5].edgewt[1]=5;
	st[0].no=6;st[6].lat=650;st[6].lon=100;strcpy(st[6].name,"Bangalore");st[6].utility=2;st[6].ptr[0]=8;st[6].ptr[1]=9;st[6].ctr3=2;st[6].edgewt[8]=6;st[6].edgewt[9]=4;
	st[0].no=7;st[7].lat=350;st[7].lon=250;strcpy(st[7].name,"Jaipur");st[7].utility=1;st[7].ptr[0]=8;st[7].ctr3=1;st[7].edgewt[8]=6;
	st[0].no=8;st[8].lat=150;st[8].lon=350;strcpy(st[8].name,"Jammu");st[8].utility=9;st[8].ptr[0]=3;st[8].ptr[1]=6;st[8].ptr[2]=7;st[8].ptr[3]=9;st[8].ctr3=4;st[8].edgewt[3]=9;st[8].edgewt[6]=6;st[8].edgewt[7]=1;st[8].edgewt[9]=7;
	st[0].no=9;st[9].lat=450;st[9].lon=402;strcpy(st[9].name,"Agra");st[9].utility=14;st[9].ptr[0]=3;st[9].ptr[1]=5;st[9].ptr[2]=6;st[9].ptr[3]=8;st[9].ctr3=4;st[9].edgewt[3]=7;st[9].edgewt[8]=2;st[9].edgewt[5]=9;st[9].edgewt[6]=5;
	scnt=10;
	while(an=='y')
	{
		cout<<"Menu \n 1)Display Network \n 2)Add Station \n 3)Close Station \n";
		cin>>ch;
		if(ch==1)
		{
			dnet();
			distmat();
			cout<<"Do you wish to continue?(y/n)";
			cin>>an;
		}
		else if(ch==2)
		{
			addstation();
			cout<<"Do you wish to continue?(y/n)";
			cin>>an;
		}
		else if(ch==3)
		{
			delstation();
			cout<<"Do you wish to continue?(y/n)";
			cin>>an;
		}
	}
}
