#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <stdexcept>
#include <iomanip>
#include <cstring>

using namespace std;


/////////////////////////////////////////////
/////////////////////////////////////////////
class NodeEdges
{
	public:
	int length(void);
	int first(void);
	int last(void);
    void initial_length(int);
	void initial_first(int);
	void initial_last(int);
	int info[3];

};

//NodeEdges::NodeEdges
//{}

void NodeEdges::initial_length(int length)
{
	info[2] = length;
}
void NodeEdges::initial_last(int last)
{
	info[1] = last;
}

void NodeEdges::initial_first(int first)
{
	info[0] = first;
}

int NodeEdges::length()
{
	return info[2];
}

int NodeEdges::first()
{
	return info[0];
}

int NodeEdges::last()
{
	return info[1];
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////
class ArrayEdge
{
	public:
	NodeEdges *arrayedges;
    int size;
	ArrayEdge(int edges);
	~ArrayEdge(void);
    int getsize(void);
	NodeEdges* get(int position);
};

ArrayEdge::ArrayEdge(int edges)/////Get input for roads
{

	size = edges;
	arrayedges = new NodeEdges[edges];
	int length,first, last,temp;
	for(int i=0;i<edges;i++)
	{
		cin >> first;
		cin>> last;
		cin>> length;
		if(first > last)
		{
			temp = first;
			first = last;
			last = temp;
		}

		arrayedges[i].initial_first(first);
		arrayedges[i].initial_last(last);
		arrayedges[i].initial_length(length);
	}
};

ArrayEdge::~ArrayEdge(void)
{
 delete [] arrayedges;
}

NodeEdges* ArrayEdge::get(int position) //Point to list of edges
{
	NodeEdges* destination = &arrayedges[position];
}

 int ArrayEdge::getsize(void) //Number of edges
{
    //cout<< size;
	return size;
}


///////////////////////////////////////////////
////////////////////////////////////////////////


/////////////////////////////////////////////////
/////////////////////////////////////////////
class MinHeapEdge
{
	public:
	int total;
	int size;
	int whatsize(void);
    int whattotal(void);
	NodeEdges **heap;
	MinHeapEdge(ArrayEdge *base);
	NodeEdges* checksort(void);
	void insert(NodeEdges* edge);
	bool none(void);
	~MinHeapEdge(void);
};

MinHeapEdge::MinHeapEdge(ArrayEdge *base) //construct
{
	total = base->getsize();
	//cout<< total<< endl;
	size = 0;
	heap = new NodeEdges*[total];
	for(int i=0;i<total;i++)
	{
	    heap[i]=NULL;
	}
	for (int i=0;i<total;i++)
	{
		insert(base->get(i));
	}

}

void MinHeapEdge::insert(NodeEdges* edge)
{
	int length = edge->length();
	//cout<< length <<endl;
	int onthenode = size;
	if(onthenode == 0)
	{
		heap[onthenode] = edge;
		//cout << heap[onthenode]->length() << endl; //prints 28
	}
	while((onthenode != 0))
	{
		if(length < heap[(onthenode-1)/2]->length()){
		NodeEdges *anotherpointer = heap[(onthenode-1)/2];
		heap[(onthenode-1)/2] = edge;
		//cout<<heap[(onthenode-1)/2]->length()<<endl; //prints 10,14
		heap[onthenode] = anotherpointer;
		onthenode = (onthenode-1) / 2;
		}

	/*else if((length = heap[(onthenode-1)/2]->length())&&(heap[onthenode] <heap[(onthenode-1)])) {

	    NodeEdges *anotherpointer = heap[(onthenode-1)/2];
		heap[(onthenode-1)/2] = edge;
		//cout<<heap[(onthenode-1)/2]->length()<<endl; //prints 10,14
		heap[onthenode] = anotherpointer;
		onthenode = (onthenode-1) / 2;
		}*/


	else
		{
			heap[onthenode] = edge;
			break;
		}
	}
	size = size + 1;
}

MinHeapEdge::~MinHeapEdge(void)
{
	delete[] heap;
}

NodeEdges* MinHeapEdge::checksort(void) //check if heap go from least to greatest
{
	NodeEdges *information = heap[0];
	//cout<<heap[0]->length()<<endl; //10
	//cout<<heap[1]->length()<<endl; //14
	//cout<<heap[2]->length()<<endl; //16
	//cout<<heap[3]->length()<<endl; //28

	size = size - 1;
	//cout<< size;
	heap[0] = heap[size];// set size of heap
	int child = 1;
	int currentchild = 0;
	while(child <= size)
	{
		//cout << "check first conditional\n";
		if((child < size)&&(heap[child]->length() > heap[child+1]->length()))
		{
		    //cout<<heap[1]->length()<<endl;
		    //cout<<heap[2]->length()<<endl;
			child = child + 1;
		}

		  if(heap[currentchild]->length() >= heap[child]->length())
		{

			NodeEdges* anotherpointer;
			anotherpointer = heap[currentchild];
			heap[currentchild] = heap[child];
			heap[child] = anotherpointer;
			currentchild = child;
			child = (2*currentchild)+1;
		}

		 else if(heap[currentchild]->length() == heap[child]->length())
		{
			break;
		}

else if(heap[currentchild]->length() <heap[child]->length())
		{
			break;
		}
		else
		{
		    //cout<<heap[currentchild]->length();
		    //cout<<endl;
		    //cout<<heap[child]->length();
			NodeEdges* anotherpointer;
			anotherpointer = heap[currentchild];
			heap[currentchild] = heap[child];
			heap[child] = anotherpointer;
			currentchild = child;
			child = (2*currentchild)+1;
		}
	}
	return information;
}

bool MinHeapEdge::none(void)// check if heap is empty
{
	if(size < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int MinHeapEdge::whatsize(void)
{
	return size;
}

int MinHeapEdge::whattotal(void) //use to print
{
	return total;
}
//////////////////////////////////////////////
//////////////////////////////////////////////////


//////////////////////////////////////////////////
////////////////////////////////////////////////////
class InitialNode //set up node
{
	public:
	int value;
	NodeEdges* edge;
    InitialNode(void);
	void initial_value(int valuenum);
	void intial_edge(NodeEdges* destination);
	int returnvalue(void);
	NodeEdges* getedge(void);
};

InitialNode::InitialNode(void)
{
	value = -1;
	edge = NULL;

}

void InitialNode::initial_value(int valuenum)
{
	value = valuenum;
}

void InitialNode::intial_edge(NodeEdges* destination)
{
	edge = destination;
}

int InitialNode::returnvalue(void)
{
	return value;
}

NodeEdges* InitialNode::getedge(void)
{
	return edge;
}
///////////////////////////////////////
/////////////////////////////////////////
///////////////////////////////////////////
class Disjoint
{
	public:
	InitialNode *initial;
	int* values;
	int initialnums;
	int arrayedges;
	Disjoint(int cities);
	int search(int destination);
	void together(NodeEdges* base);
	void numcount(void);
	int whatnum(void);
	void intial_values(void);
	int* whatvalues(void);
	int getsize(void);
	NodeEdges* edge(int destination);
	int returnvalue(int destination);
	int returnvaluesize(int destination);
	~Disjoint(void);
//void print(void);
};


int Disjoint::returnvaluesize(int destination)
{
    //cout << -1*initial[destination].returnvalue();
	return -1*initial[destination].returnvalue();
}

int Disjoint::returnvalue(int destination)
{
	//cout<< values[destination];//1,2,3,7,8,9
	return values[destination];
}

NodeEdges* Disjoint::edge(int destination)
{
	return initial[destination].getedge();
}

Disjoint::Disjoint(int cities)
{
	initial = new InitialNode[cities];
	values = NULL;
	initialnums = 0;
	arrayedges = cities;
}

int Disjoint::getsize(void)
{
    //cout<< arrayedges;
	return arrayedges;
}
int Disjoint::search(int destination)
{
	int i = destination;
	for(i;initial[i].returnvalue() >= 0;i=initial[i].returnvalue())
	{
		if (initial[i].returnvalue() < 0)
		{
		    break;
		}
    }
	while(destination != i)
	{
	    int s = initial[destination].returnvalue();
		initial[destination].initial_value(i);
		destination = s;
	}
	return i;
}

void Disjoint::together(NodeEdges* base)
{

	int first = search(base->first());//0,1,1,0,1
	//cout <<search(base->first())<<endl;
	int last = search(base->last()); //5,6,4,1,1
	//cout<<last<<endl;
	if(first != last)
	{
		int temp = initial[first].returnvalue() + initial[last].returnvalue();
		//cout<< initial[first].returnvalue();//-1,-1,-2,-2
		//cout<< initial[last].returnvalue();//-1,-1,-1,-3
		//cout <<temp << endl;//-2,-2,-3,-5
		if(initial[first].returnvalue() > initial[last].returnvalue())
		{
			initial[first].initial_value(last);
			//cout<<initial[first].initial_value(last);
			initial[last].initial_value(temp);
			initial[first].intial_edge(base);
		}
		else//do opposite
		{
			initial[last].initial_value(first);
			initial[first].initial_value(temp);
			initial[last].intial_edge(base);
		}
	}
}

void Disjoint::numcount(void)
{
	for(int i=0;i<arrayedges;i++)
	{
		if(initial[i].returnvalue() < 0)
		{
			initialnums = initialnums + 1;
		}
	}
}

int Disjoint::whatnum(void)
{
	return initialnums;
}

void Disjoint::intial_values(void)
{
	int position2 = 0;
	values = new int[initialnums];
	for(int i=0;i<arrayedges;i++)
	{
		if(initial[i].returnvalue() < 0)
		{
			values[position2]= i;
			position2 = position2 + 1;
		}
	}
}

int* Disjoint::whatvalues(void)
{
	return values;
}


Disjoint::~Disjoint(void)
{
	delete [] initial;
	delete [] values;
}

////////////////////////////////////////
/////////////////////////////////////////


class Nodes
{
	public:
	int size;
	NodeEdges** arrayedges;
	Nodes* next;
	Nodes(int something);
	~Nodes();
	int getsize(void);
	void sort(int L, int R);
	int cityone(void);
	void print(void);
	void intial_next(Nodes* destination);
	Nodes* whatnext(void);
	void stuff(int k, Disjoint* base);
};

Nodes::Nodes(int something)
{
	size = something;
	arrayedges = new NodeEdges*[size];
	next = NULL;
}

Nodes::~Nodes()
{
    delete arrayedges;
}

int Nodes::getsize(void)
{
 return size;
}

int Nodes::cityone(void)
{
    //cout<<arrayedges[0]->first();
	return arrayedges[0]->first();
}

void Nodes::intial_next(Nodes* destination)
{
	next = destination;
}

Nodes* Nodes::whatnext(void)
{
	return next;
}

void Nodes::stuff(int k, Disjoint* base)
{
	int area = 0;
	for(int i=0;i< base->getsize();i++)
	{
		int value = base->search(i);
		//cout<<base;
		//cout<<value<< endl;
		if((value==k)&&(i!=k))
		{
			if((base->edge(i) != NULL)&&(base->search(i) == k))
			{
			arrayedges[area] = base->edge(i);
			area = area + 1;
			//cout<<area;
			}
		}
	}
}

void Nodes::print(void)
{
	cout << "<region>\n";
	for(int i=0;i<size;i++)
	{
		cout << "<road>";
		cout << arrayedges[i]->first();
		cout << " " ;
		cout<< arrayedges[i]->last();
		cout << " " ;
		cout<< arrayedges[i]->length();
		cout << "</road>\n";
	}
	cout << "</region>\n";
}



void Nodes::sort(int L,int R)//quicksort
{
	if((R-L) == 1)
	{
		NodeEdges* anotherpointer;
		//cout<<arrayedges[L]->length();//10
		//cout<< endl;
		//cout<<arrayedges[R]->length();//14
		//cout<<arrayedges[L]->first();
		//cout<<endl;
		//cout<<arrayedges[R]->first();

		if(arrayedges[L]->length() >= arrayedges[R]->length())
		{
			if(arrayedges[L]->length() == arrayedges[R]->length())
			{
				if(arrayedges[L]->first() > arrayedges[R]->first())//switch
				{

					anotherpointer = arrayedges[L];
					arrayedges[L] = arrayedges[R];
					arrayedges[R] = anotherpointer;
					//delete anotherpointer;
				}
			}
			else//switch both arrays
			{
				anotherpointer = arrayedges[L];
				arrayedges[L] = arrayedges[R];
				arrayedges[R] = anotherpointer;
			}
		}
	}
  else if((L < R)&&((R-L)!=1))
  {
    NodeEdges* anotherpointer;
    int i = L;
    int j = R-1;
    int piv = arrayedges[L+((R-L)/2)]->length();
    //cout<<arrayedges[L+((R-L)/2)]->length();//16
    anotherpointer = arrayedges[L+((R-L)/2)];
    arrayedges[L+((R-L)/2)] = arrayedges[R];//14
    //cout<<arrayedges[R]->length();
    arrayedges[R] = anotherpointer;

    while(i<j)
    {
      while(arrayedges[i]->length() <= piv)
      {
        if(arrayedges[i]->length() == piv)
        {
          if(arrayedges[i]->first() < arrayedges[R]->first())
          {
              //delete arrayedges[i];
               i++;
            }
          else{
              break;
              }
        }
				else
				{
				    i++;
                }
      }
      while(arrayedges[j]->length() >= piv)
      {
        if(arrayedges[j]->length() == piv)
        {
          if(arrayedges[j]->first() > arrayedges[R]->first())
          {
              j--;
          }
          else{
              break;
              }
        }
				else
				{
				    j--;
                }
      }
      if(i<j)
      {
        anotherpointer = arrayedges[i];
        arrayedges[i] = arrayedges[j];
        arrayedges[j] = anotherpointer;
      }
    }
    anotherpointer = arrayedges[i];
    arrayedges[i] = arrayedges[R];
    arrayedges[R] = anotherpointer;
    sort(L, j);
    sort(i+1, R);
  }

}


//////////////////////////////////////
/////////////////////////////////////////
////////////////////////////////////////////

class Links //Link List
{
	private:
	Nodes* first;
	Nodes* area;
	Nodes* lowest;

	public:
	Links(Disjoint* base);
	void lowestprint(void);
};

Links::Links(Disjoint* base)
{

	int quannodes = base->whatnum();
	if(quannodes> 0){
    first = NULL;
	area = NULL;
	lowest = NULL;
	int k = base->returnvalue(0);
	int size = base->returnvaluesize(k);
	first = new Nodes(size-1);
	first->stuff(k, base);
	area = first;
	for (int i =1;i<quannodes;i++)
	{
		k = base->returnvalue(i);
		size = base->returnvaluesize(k);
		area->intial_next(new Nodes(size-1));
		area = area->whatnext();
		area->stuff(k, base);
	}
	//cout<<"what";
	area = first;
	while(area != NULL)
	{
	   /* if(area->getsize()==4)
	    {
	    area->sort(0,1);
	    area->sort(0,2);
	    area->sort(0,3);
	    area = area->whatnext();
	    }*/
		for(int i=0;i<(area->getsize());i++) //
		{

		area->sort(0,i);
		}
		area = area->whatnext();
	}
	//cout<<"what";
	area = first;
	//cout <<first;
	}
	else
	{
	    area = NULL;
	    first = NULL;
	    lowest = NULL;
	}
}


void Links::lowestprint(void)
{
	while(first != NULL){
	int cities = area->getsize();
	//cout<< cities;
	lowest = area;
	area = area->whatnext();

	while(area != NULL)
	{
		if(area->getsize() <= cities)
		{
			if(area->getsize() == cities)
			{
				if(area->cityone() > lowest->cityone())
				{
				    //cout<<lowest->cityone();
					//lowest = area;
					area = area->whatnext();
				}
				else
				{
					area = area->whatnext();
				}
			}
			else
			{
				lowest = area;
				area = area->whatnext();
			}
		}
		else
		{
			area = area->whatnext();
		}
	}
	lowest->print();
	if( lowest == first)
	{
		first = first->whatnext();
		delete lowest;
		area = first;
		lowest = NULL;
	}
	else
	{
		area = first;
		while(area->whatnext() != lowest)
		{
			area = area->whatnext();
		}
		if (lowest->whatnext() != NULL)
		{
			area->intial_next(lowest->whatnext());
			delete lowest;
			lowest = NULL;
		}
		else
		{
			delete lowest;
			area->intial_next(NULL);
		}
	}
	area = first;
	}
}

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
int main(void)
{
	//input
	int cities,roads;
	cin >> cities;
	cin>> roads;


	ArrayEdge gettingroads(roads);
	//cout << gettingroads.getsize() << endl;
	//cout<< ArrayEdge.initial_last();
	//NodeEdges getlast(last);
    //cout<< getlast.last();
	/*if(last=cities){
		return 0;
		}*/
	Disjoint connect(cities);
	NodeEdges *road;

	ArrayEdge *arrayedges = &gettingroads;
	MinHeapEdge heap(arrayedges);
	while(!heap.none())//while heap not empty
	{
		road = heap.checksort();
		connect.together(road);
	}

	connect.numcount();
    connect.intial_values();
	Disjoint* setptr = &connect;
	Links almostdone(setptr);

    cout << "<?xml version=\"1.4\"?>\n";
	cout << "<country>\n";

	almostdone.lowestprint();

	cout << "</country>\n";

	return 0;
}
