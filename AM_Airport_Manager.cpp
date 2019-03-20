/*

	+-------------------------------------+
	  Program Name : Graph (Adjucency Matrix).
	  Date : 03/01/18 Tuesday.
	  Developer : Abhilash Chavhan.
	  Roll No : SE-B, 22110.
	+--------------------------------------+

	+------------------------------------------------------------------------------------+
	  Graph : Airport Management (Adjucency Matrix).
	
			1) Edges of Graph can be Distance from Source to Destination cities.
			2) This also hold information such as time and fuel needed to travel from source to destination.
			3) Nodes are the City Airport Names.
			4) Create and Store information using
				A : Adjucency Matrix (2-Dimentional Array).
				B : Adjucency List (Linked List).
			5) Display total information as Graph.
			6) Justify storage representation used.
	+------------------------------------------------------------------------------------+
	
*/	

#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>
#include<conio.h>

#define CITIES 50

using namespace std;

/*
struct interData
{
	char city[10];
	int fuel;
	int time;
};
*/

class WorldMap
{
	protected : 
		int cityCount;
		int graph[CITIES][CITIES];
		string cities[CITIES];
		int shadeCount;
	
	public :
			string messageBar;
		
		WorldMap()
		{
			cityCount = 0;
		}
		
		void addCity()
		{
			string getCityName;
			cout<<"Enter City Name : ";
			cin>>getCityName;
			if(validCity(getCityName)==-1)
			{
				cities[cityCount] = getCityName;
				graph[cityCount][cityCount];
				messageBar = cities[cityCount]+" is added to Map.";
				cityCount++;
			}
			else
			{
				messageBar = getCityName+" is Already Present...";
			}			
		}
		
		void shadeLine(int getShade)
		{
			//	176 -> 178 : Light -> Dark
			//	219 -> for Non-Shade
			for(shadeCount=0;shadeCount<96;shadeCount++)
			{
				cout<<(char)getShade;
			}
			cout<<endl;
		}
		void diplayCities()
		{
			if(cityCount==0)
			{
				cout<<" INFORMATION "<<(char)175<<" SELECT ADD CITIES TO START FLIGHTS. MAXIMUM NO OF CITIES IS "<<CITIES<<"."<<endl;
			}
			else
			{
				int countIt = 1;
				cout<<" CITIES -> ";
				for(int i=0;i<cityCount;i++)
				{
					if(i+1==cityCount)
					{
						cout<<countIt<<"> "<<cities[i];
						countIt++;
					}
					else
					{
						cout<<countIt<<"> "<<cities[i];
						countIt++;
						cout<<", ";
					}	
					if((i%8==0)&&(i>0))
					{
						cout<<endl<<"\t    ";
					}				
				}
				cout<<"."<<endl;
			}
		}
		
		void insertData()
		{
			string source,destination;
			int source_index,destination_index;
			char choice;
			if(cityCount>1)
			{
				cout<<"Enter Source City : ";
				cin>>source;
				cout<<"Enter Destination City : ";
				cin>>destination;
				source_index = validCity(source);
				destination_index = validCity(destination);
				if((source_index!=-1) && (destination_index!=-1))
				{
					if(graph[source_index][destination_index]==0)
					{
						cout<<"Enter Distance in from "<<source<<" to "<<destination<<" : ";
						cin>>graph[source_index][destination_index];
						messageBar = "Flights are added in between "+source+" and "+destination+".";
					}
					else
					{
						messageBar = "Distance from "+source+" to "+destination+" is already available.";
					}
				}
				else
				{
					if(source_index==-1)
					{
						messageBar = "City "+source+" is not Available...";
					}
					else if(destination_index==-1)
					{
						messageBar = "City "+destination+" is not Available...";
					}
				}
			}
			else
			{
				messageBar = "Two Cities require to insert Distnce in a MAP...";
			}
		}
		void updateData()
		{
			string source,destination;
			int source_index,destination_index;
			if(cityCount>1)
			{
				cout<<"Enter Source City : ";
				cin>>source;
				cout<<"Enter Destination City : ";
				cin>>destination;
				source_index = validCity(source);
				destination_index = validCity(destination);
				if((source_index!=-1) && (destination_index!=-1))
				{
					cout<<"Enter New Distance in from "<<source<<" to "<<destination<<" : ";
					cin>>graph[source_index][destination_index];
					messageBar = "Distance from "+source+" to "+destination+" is updated.";
				}
				else
				{
					if(source_index==-1)
					{
						messageBar = "City "+source+" is not Available...";
					}
					else if(destination_index==-1)
					{
						messageBar = "City "+destination+" is not Available...";
					}
				}
			}
			else
			{
				messageBar = "No Flights to update in between "+source+" and "+destination+" in a MAP...";
			}
		}
		
		void deleteData()
		{
			string source,destination;
			int source_index,destination_index;
			if(cityCount>1)
			{
				cout<<"Enter Source City : ";
				cin>>source;
				cout<<"Enter Destination City : ";
				cin>>destination;
				source_index = validCity(source);
				destination_index = validCity(destination);
				if((source_index!=-1) && (destination_index!=-1))
				{
					graph[source_index][destination_index] = 0;
					messageBar = "Distance form "+source+" to "+destination+" Deleted Successfully.";
				}
				else
				{
					if(source_index==-1)
					{
						messageBar = "City "+source+" is not Available...";
					}
					else if(destination_index==-1)
					{
						messageBar = "City "+destination+" is not Available...";
					}
				}
			}
			else
			{
				messageBar = "No Flights to delete in between "+source+" and "+destination+" in a MAP...";
			}
		}
		void addTab(int size)
		{
			if(size<=6)
			{
				cout<<"\t\t";
			}
			else
			{
				cout<<"\t";
			}
		}
		void addDistance(int getDistance)
		{
			if(getDistance-100>0)
			{
				cout<<" KMS\t";
			}
			else
			{
				cout<<" KMS\t\t";
			}
			
		}
		int validCity(string getCityName)
		{
			int i = 0;
			bool isFound = false;
			while(i<cityCount)
			{
				if(cities[i] == getCityName)
				{
					isFound = true;
					break;
				}
				i++;
			}
			if(isFound)
			{
				return i;
			}
			else
			{
				return -1;
			}
		}
		
		void diplayData()
		{
			//cout<<"| SR \t|\t SOURCE \t|\t DESTINATION \t|\t DISTANCE \t|\tTIME\t|"<<endl;
			int row,col;
			int countIt = 1;
			for(row=0;row<cityCount;row++)
			{
				for(col=0;col<cityCount;col++)
				{
					if(graph[row][col]>0)
					{
						cout<<(char)179<<"  "<<countIt<<" \t"<<(char)179<<"\t "<<cities[row]; addTab(cities[row].length());
						cout<<(char)179<<"\t "<<cities[col]; addTab(cities[col].length());
						cout<<(char)179<<"\t "<<graph[row][col]; addDistance(graph[row][col]);
						cout<<(char)179<<"\t "<<(graph[row][col])/60<<" HRS\t"<<(char)179<<endl;
						countIt++;
						//cout<<"+-----------------------------------------------------------------------------------------------+"<<endl;
						cout<<(char)197;
						drawLine();
						cout<<(char)197<<endl;
						
					}
				}
			}
		}
		
		void drawLine()
		{
			for(int i=0;i<95;i++)
			{
				cout<<(char)196;
			}
		}
};

int main()
{
	WorldMap map;
	int choice;
	bool loopIt;
	do
	{	
		system("CLS");
		system("COLOR 74");
		cout<<"+-----------------------------------------------------------------------------------------------+"<<endl;
		cout<<"|\t\t\t\t\t AIRPORT MANAGEMENT SYSTEM \t\t\t\t|"<<endl;
		cout<<"+-----------------------------------------------------------------------------------------------+"<<endl;
		cout<<endl;
		map.diplayCities();
		cout<<endl;
		//cout<<"+-----------------------------------------------------------------------------------------------+"<<endl;
		cout<<(char)197;
		map.drawLine();
		cout<<(char)197<<endl;
		cout<<(char)179<<" SR \t"<<(char)179<<"\t SOURCE \t"<<(char)179<<"\t DESTINATION \t"<<(char)179<<"\t DISTANCE \t"<<(char)179<<"\tTIME\t"<<(char)179<<endl;
		cout<<(char)197;
		map.drawLine();
		cout<<(char)197<<endl;
		//cout<<"+-----------------------------------------------------------------------------------------------+"<<endl;
		map.diplayData();
		cout<<"+-----------------------------------------------------------------------------------------------+"<<endl;
		cout<<" MESSAGE "<<(char)175<<" "<<map.messageBar;
		cout<<endl;
		cout<<"+-----------------------------------------------------------------------------------------------+"<<endl;
		cout<<"| MENU | 1}> ADD CITY  2}> INSERT DISTANCE  3}> UPDATE DISTANCE  4}> DELETE DISTACNE  5}> EXIT  |"<<endl;
		cout<<"+-----------------------------------------------------------------------------------------------+"<<endl;
		cout<<" Enter Your Choice > ";
		choice = getche();
		cout<<"\n+-----------------------------------------------------------------------------------------------+"<<endl;
		switch(choice)
		{
			case 49: system("COLOR 71");
					map.addCity();
					loopIt = true;
					break;
			case 50: system("COLOR 75");
					map.insertData();
					loopIt = true;
					break;
			case 51: system("COLOR 0D");
					map.updateData();
					loopIt = true;
					break;
			case 52: system("COLOR 72");
					map.deleteData();
					loopIt = true;
					break;
			case 53: system("COLOR 0C");
					loopIt = false;
					break;
			default :
					map.messageBar = " ENTER CORRECT CHOICE...";
					loopIt = true;
					break;			
		}
	}while(loopIt);
	return 0;
}

