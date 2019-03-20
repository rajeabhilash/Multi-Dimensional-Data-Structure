/*

	+-------------------------------------+
	  Program Name : Graph (Adjucency List).
	  Date : 03/01/18 Tuesday.
	  Developer : Abhilash Chavhan.
	  Roll No : SE-B 10.
	+--------------------------------------+
	
	+------------------------------------------------------------------------------------+
	  Graph : Airport Management (Adjucency List).
	
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
#include<stdlib.h>
#include<conio.h>
#include<cstring>

#define CITY_COUNT 50

using namespace std;

struct interData
{
	int distance;
	int fuel;
	int time;
};

class WorldMap
{
	protected : 
		int graph[CITY_COUNT][CITY_COUNT];
		int cities[CITY_COUNT];
		
	public :
		
		WorldMap()
		{
				
		}
};

int main()
{
	WorldMap map;
	cout<<"+---------------------------------------------------------------+"<<endl;
	cout<<"|\t\tAirport Management System\t\t\t|"<<endl;
	cout<<"+---------------------------------------------------------------+"<<endl;
	
	return 0;
}
