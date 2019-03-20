/*

	+-------------------------------------+
	  Program Name : Binary Search Tree.
	  Date : 26/12/17 Tuesday.
	  Developer : Abhilash Chavhan.
	  Roll No : SE-B 10.
	+--------------------------------------+
	
	+------------------------------------------------------------------------------------+
	  Binary Search Tree : Dictionary.
	
			1) Creating a Dictionary using Binary Tree.
			2) Inserting Words and their Meanings in a Binary Tree and sorting them.
			3) Updating Old Word with new Meaning.
			4) Searching Meaning of Specific Word.
			5) Displaying Whole Dictionary.
			6) Deleting Word From Dictionary and Sorting it out.
	+------------------------------------------------------------------------------------+
	
*/
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<stdio.h>
#include<iomanip>
#include<conio.h>


using namespace std;

struct node
{
	char key[50];
	char meaning[100];
	node *leftnode;
	node *rightnode;
};

class Dictionary
{		
	
	public :
			
			bool isFoundToDelete;
			int countAll;
			node *root;

	Dictionary()
	{
			isFoundToDelete = false;
			root = NULL;
			countAll = 0;
	}
	
	void Create()
	{
		char choice;
		cout<<endl;
		do
		{
			cout<<"+-------------------------------------------------------+"<<endl;
			cout<<"  ADD WORD & IT's MEANING : "<<endl;
			cout<<"+-------------------------------------------------------+"<<endl;
			node *temp;
			temp = new node;
			temp->rightnode = NULL;
			temp->leftnode = NULL;
			cout<<"> Enter Word : ";
			cin>>temp->key;
			cout<<"> Enter Meaning : ";
			cin>>temp->meaning;
			if(root==NULL)
			{
				root = temp;
				cout<<"~> Dictionary is Created"<<endl;
				cout<<"~> First Word is "<<root->key<<" Added to Dictionary."<<endl;
				cout<<"+---------------------------------------------------------------------------------------[ CREATED ]"<<endl;
			}
			else
			{
				Insert(temp);				
			}
			cout<<"> Want to add New Word (y/n): ";
			cin>>choice;
			cout<<"+-------------------------------------------------------+"<<endl;
			cout<<endl;
		}while((choice=='y')||(choice=='Y'));
	}
	
	void Insert(node *getNode)
	{
		node *temp;
		getNode->leftnode = NULL;
		getNode->rightnode = NULL;
		bool insertEnd = true;
		temp = root;
		while(insertEnd)
		{
			if(strcmp(temp->key,getNode->key)>0)
			{
				
				if(temp->leftnode==NULL)
				{
					temp->leftnode = getNode;
					cout<<"~> "<<temp->leftnode->key<<" is added to Dictionary at left side ["<<temp->leftnode->key<<" <-- "<<temp->key<<"]."<<endl;
					insertEnd = false;
					cout<<"+---------------------------------------------------------------------------------------[ INSERTED ]"<<endl;
				}
				else 
				{
					temp = temp->leftnode;
					insertEnd = true;
				}
			}
			else if(strcmp(temp->key,getNode->key)<0)
			{
				if(temp->rightnode==NULL)
				{
					temp->rightnode = getNode;
					cout<<"~> "<<temp->rightnode->key<<" is added to Dictionary at right side of ["<<temp->key<<" --> "<<temp->rightnode->key<<"]."<<endl;
					insertEnd = false;
					cout<<"+---------------------------------------------------------------------------------------[ INSERTED ]"<<endl;
				}
				else 
				{
					temp = temp->rightnode;
					insertEnd = true;
				}
		 	}
			else if(strcmp(temp->key,getNode->key)==0)
			{
				cout<<"x> '"<<getNode->key<<"' is already exists."<<endl;
				cout<<"+-------------------------------------------------------+"<<endl;
				insertEnd = false;
			}	
	
		}		
	}
	
	void Search()
	{
		cout<<"+-------------------------------------------------------+"<<endl;
		cout<<"  SEARCH WORD : "<<endl;
		cout<<"+-------------------------------------------------------+"<<endl;	
		char word[50];
		cout<<"> Enter Word to search : ";
		cin>>word;
		node *temp;
		temp = root;
		int count = 0;
		if(root==NULL)
		{
			cout<<"x> Dictionary is Empty.\nx> Please select Create Dictionary first."<<endl;
		}
		else
		{
			bool loopIt = true;
			while(loopIt)
			{
				if(strcmp(temp->key,word)==0)
				{
					cout<<"~> Meaning of "<<temp->key<<" is : "<<temp->meaning<<endl;
					cout<<"~> Count Required to get word is : "<<count<<endl;
					loopIt = false;
				}
				else if(strcmp(temp->key,word)>0)
				{
					temp = temp->leftnode;
					loopIt = true;
				}
				else
				{
					temp = temp->rightnode;
					loopIt = true;
				}
				if(temp==NULL)
				{
					cout<<"x> '"<<word<<"' is not Found in Dictionary."<<endl;
					loopIt = false;
				}
				count++;
			}
		}
		cout<<"+-------------------------------------------------------+"<<endl;	
	}
	
	void Update()
	{
		cout<<"+-------------------------------------------------------+"<<endl;
		cout<<"  UPDATE WORD : "<<endl;
		cout<<"+-------------------------------------------------------+"<<endl;	
		char word[50];
		cout<<"> Enter Word to Update : ";
		cin>>word;
		node *temp;
		temp = root;
		int count = 0;
		if(root==NULL)
		{
			cout<<"x> Dictionary is Empty.\nx> Please select Create Dictionary first."<<endl;
		}
		else
		{
			bool loopIt = true;
			while(loopIt)
			{
				if(strcmp(temp->key,word)==0)
				{
					cout<<"~> Enter new meaning for word "<<temp->key<<" : ";
					cin>>temp->meaning; 
					loopIt = false;
				}
				else if(strcmp(temp->key,word)>0)
				{
					temp = temp->leftnode;
					loopIt = true;
				}
				else
				{
					temp = temp->rightnode;
					loopIt = true;
				}
				if(temp==NULL)
				{
					cout<<"x> '"<<word<<"'' word not found in Dictionary."<<endl;
					loopIt = false;
				}
			}
		}
		cout<<"+---------------------------------------------------------------------------------------[ UPDATED ]"<<endl;
	}
	
	void Display(node *getRoot)
	{
		//Displaying Word using INORDER DEPTH FIRST SEARCH
		if(getRoot!=NULL)
		{
			Display(getRoot->leftnode);
			cout<<": "<<countAll<<" >  "<<getRoot->key<<" : "<<getRoot->meaning<<endl;
			countAll++;
			Display(getRoot->rightnode);			
		}
	}

	void Delete()
	{
		char word[50];
		cout<<"Enter Word to Delete : ";
		cin>>word;
		cout<<"Getting inside the Recursion for delete"<<endl;		
		struct node *temp = deleteNode(root,word);
		cout<<word<<" is Deleted From Dictionary"<<endl;
		cout<<"+---------------------------------------------------------------------------------------[ DELETED ]"<<endl;
	}
	
	node* deleteNode(node *getRoot, char key[])
	{
		if (getRoot == NULL) return getRoot;
			
			if (strcmp(getRoot->key,key)>0){
					getRoot->leftnode = deleteNode(getRoot->leftnode, key);
			}
			
			else if (strcmp(getRoot->key,key)<0) {
					getRoot->rightnode = deleteNode(getRoot->rightnode, key);
			}
			else {
				
					if (getRoot->leftnode == NULL)
					{
						struct node *temp = getRoot->rightnode;
						free(getRoot);
						return temp;
					}
					else if (getRoot->rightnode == NULL)
					{
						struct node *temp = getRoot->leftnode;
						free(getRoot);
						return temp;
					}

					struct node* temp = minValueNode(getRoot->rightnode);
					strcpy(getRoot->key,temp->key);
					getRoot->rightnode = deleteNode(getRoot->rightnode, temp->key);
			}
			
			return getRoot;
	}		 
	
	node* minValueNode(node *getNode)
	{
		node *temp = getNode;
		while(temp->leftnode!=NULL)
		{		
			temp = temp->leftnode;
		}
		return temp;
	}
};

int main()
{
	Dictionary dict;
	bool loopIt = false;
	int choice;
	do {
		//system("CLS");
		cout<<"+-------------------------------------------------------+"<<endl;
		cout<<"|\t\t  OXFORD DICTIONARY  \t\t\t|"<<endl;
		cout<<"+-------------------------------------------------------+"<<endl;
		cout<<"|\t\t1) Create a new Dictionary\t\t|"<<endl;
		cout<<"|\t\t2) Insert Word in Dictionary\t\t|"<<endl;
		cout<<"|\t\t3) Search Word in Dictionary\t\t|"<<endl;
		cout<<"|\t\t4) Update Word of Dictionary\t\t|"<<endl;
		cout<<"|\t\t5) Display Dictionary\t\t\t|"<<endl;
		cout<<"|\t\t6) Delete Word from Dictionary\t\t|"<<endl;
		cout<<"|\t\t\t7) Exit.\t\t\t|"<<endl;
		cout<<"+-------------------------------------------------------+"<<endl;
		cout<<" Enter Your Choice -> ";
		cin>>choice;
		cout<<"+-------------------------------------------------------+"<<endl;
		switch(choice)
		{
			case 1:	dict.Create(); loopIt = true; break;
			
			case 2: dict.Create(); loopIt = true; break;
			
			case 3: dict.Search(); loopIt = true; break;
			
			case 4: dict.Update(); loopIt = true; break;
			
			case 5: dict.countAll=1;
					cout<<endl;
					cout<<"+-------------------------------------------------------+"<<endl;
					cout<<"|\t\t\t DICTIONARY \t\t\t|"<<endl;
					cout<<"+-------------------------------------------------------+"<<endl;
					dict.Display(dict.root); 
					cout<<"+-------------------------------------------------------+"<<endl;
					loopIt = true;
					break;
			
			case 6:	dict.Delete(); 
					loopIt = true; 
					break;
			
			case 7: loopIt = false;	break;
			
			default : cout<<"|\t\t---> Enter Correct Choice <---\t\t|"<<endl; 
					  cout<<"+-------------------------------------------------------+"<<endl;
					  loopIt = true;
					  break;
		}
					
	} while (loopIt);
	return choice;
}	
