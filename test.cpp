#include<iostream>

using namespace std;

typedef struct Node
{
	int data;
	Node *next; //link
}Nodetype;
typedef Nodetype *Nodeptr;

//Ham tao nut
Nodeptr CreateNode(int x)
{
	Nodeptr p;
	p=new Node;
	p->data=x;
	p->next=NULL;
	return p;	
}
void InsertFirst(Nodeptr &Head,Nodeptr &Tail,Nodeptr p)
{
	if(Head==NULL)
	{
		Head=p;Tail=p;
	}
	else
	{
		p->next=Head;
		Head=p;
	}
}
void InsertLast(Nodeptr &Head,Nodeptr &Tail,Nodeptr p)
{
	if(Head==NULL)
	{
		Head=p;
		Tail=p;
	}
	else
	{
		Tail->next=p;
		Tail=p;
	}
}
void InsertAfter(Nodeptr p,Nodeptr q, Nodeptr &Tail)
{
	if(q!=NULL)
	{
		p->next=q->next;
		q->next=p;
		if(q==Tail) Tail=p;
	}
}
void InsertListOrder(Nodeptr &Head,Nodeptr &Tail,Nodeptr p)
{
	Nodeptr a,b;
	if(Head==NULL)
	{
		Head=p;Tail=p;
	}
	else
	{
		a=Head;
		while(a!=NULL)
		{
			if(a->data>=p->data)break;
			b=a;
			a=a->next;
		}
		if(a==Head) InsertFirst(Head,Tail,p);
		else
			InsertAfter(p,b,Tail);
	}
}


int main()
{
	
	Nodeptr Head, Tail,p;
	//khoi tao xau rong
	Head=Tail=NULL;	
	
	int x=0;
	while(1)
	{
		cout<<"\n Nhap x, nhap -1 ket thuc ";
		cin>>x;
		if(x==-1)break;
		p=CreateNode(x);
		//InsertListOrder(Head,Tail,p);
		//InsertFirst(Head,Tail,p);
		InsertLast(Head,Tail,p);
	}
	while(Head!=NULL)
	{
		cout<<Head->data<<"\t";
		Head=Head->next;
	}
	
		return 0;
}