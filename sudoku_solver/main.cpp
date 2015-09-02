#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include <string>

using namespace std;


//See if more than same number in a row
bool chkrow(int puzzle[9][9], int num, int rownum,  int colnum) {
    for (int i=0; i<9; i++) {
        if (i != colnum) {
            if (num == puzzle[rownum][i])
                return true;
        }
    }
    return false;
}

//See if more than same number in a column
bool chkcol(int puzzle[9][9], int num, int rownum, int colnum) {
    for (int i=0; i<9; i++) {
        if (i != rownum) {
            if(num == puzzle[i][colnum]) {
                return true;
            }
        }
    }
    return false;
}

//See if more than same number in box
bool chkbox(int puzzle[9][9], int num, int rownum, int colnum, int a, int b) {
    for (int i=3*a; i < 3*(a+1); i++) {
        for (int j=3*b; j < 3*(b+1); j++) {
            if (i != rownum || j !=  colnum)
                 if ( num ==puzzle[i][j] )
                    return true;
        }
    }
    return false;
}

//check the numbers in the square
bool chkboard(int puzzle[9][9], int rownum, int colnum, int num) {

    int a = 0;
    int b = 0;

//finding which box num is in

    if((rownum == 0) || (rownum == 1) || (rownum == 2))
        a = 0;
    else if ((rownum == 3) || (rownum ==4) || (rownum ==5))
        a = 1;
    else //if ((rownum = 7) || (rownum = 8) || (rownum = 9))
        a = 2;
    if((colnum == 0) || (colnum == 1) || (colnum == 2))
        b = 0;
    else if ((colnum ==3) || (colnum ==4) || (colnum ==5))
        b = 1;
    else //if ((colnum =7) || (colnum =8) || colnum = 9))
        b = 2;

    /*if(rownum < 3)
        a = 0;
    else if (rownum < 6)
        a = 1;
    else
        a = 2;
    if (colnum < 3)
        b = 0;
    else if (colnum < 6)
        b = 1;
    else
        b = 2;*/

    bool test1 = chkrow(puzzle, num, rownum, colnum);


    bool test2 = chkcol(puzzle, num, rownum, colnum);


    bool test3 = chkbox(puzzle, num, rownum, colnum, a, b);

    if (test1 || test2 || test3){

     return true; }//num passes all the test
	else{
	
    return false;
	}
}

//Forward a cell
void cellfor(int *i, int *j){
    *j = *j + 1;
    if (*j == 9) {
        *j = 0;
        *i =*i + 1;
    }
}


//Reverse a cell
void cellrev(int *i, int *j){
    *j = *j - 1;
    if(*j < 0) {
        *j = 8;
        *i = *i - 1;
    }
}


int main() {
    int puzzle[9][9];
    char c;
int counter;	
//while(!cin.eof()){
for (int i=0; i < 9; i++)
{
	for(int j=0; j < 9; j++)
	{
		//cin.get(c);
		counter++;
	if(!cin.eof())
	{
		cin.get(c);

	if( c == '1')
			{
			puzzle[i][j] = 1;
			}
      else  if( c =='2')
            {
			puzzle[i][j] = 2;
			}
      else  if( c == '3')
			{
			puzzle[i][j] = 3;
			}
      else  if( c =='4')
            {
			puzzle[i][j] = 4;
			}
      else  if( c == '5')
			{
			puzzle[i][j] = 5;
			}
       else  if( c =='6')
            {
			puzzle[i][j] = 6;
			}
       else  if( c =='7')
            {
            puzzle[i][j] = 7;
            }
       else  if( c =='8')
            {
			puzzle[i][j] = 8;
			}
        else if( c =='9')
            {
			puzzle[i][j] = 9;
			}
         else if (c == '.')
        {
            puzzle[i][j] = 0;
        }
         else if (c == '0')
        {
                cout<< "ERROR: expected <value> saw "<< 0 <<"\n";
                exit(0);
        }
	else if (c == '\n')
        {
                cout<< "ERROR: expected <value> saw \\n";
		cout<<endl;
                exit(0);
        }
	else if (cin.eof())
        {
                cout<< "ERROR: expected <value> saw <eof>";
                cout<<endl;
                exit(0);
        }
	else if (!isprint(c))
        {
       	 cout<< "ERROR: expected <value> saw "<< "\\x"<< setw(2)<<setfill('0')<<hex<< int (c)<< endl;
	       exit(0);
        }
	else
	{
		cout<<"ERROR: expected <value> saw "<<c;
		cout<<endl;
		exit(0);
	}
}
	else
	{
		cout<<"ERROR: expected <value> saw <eof>";
                cout<<endl;
                exit(0);
	}
}
}
	if((counter==81)&&(!cin.eof()))
	{
		cin.get(c);
		if(c!='\n')
		{
			if(cin.eof())
			{
			cout<<"ERROR: expected \\n saw <eof>";
                	cout<<endl;
                	exit(0);
			}
			if(!isprint(c))
			{
			 cout<< "ERROR: expected \\n saw "<< "\\x"<< setw(2)<<setfill('0')<<hex<< int (c)<< endl;
	                 exit(0);

			}
			else
			{
			cout<<"ERROR: expected \\n saw "<<c;
			cout<<endl;
                        exit(0);
			}
		}
	}
	
	cin.get(c);
/*	if(!cin.eof())
	{
		if(c=='\n')
		{
		cout<<"ERROR: expected <eof> saw \\n";
                        cout<<endl;
                        exit(0);
		}
		if(!isprint(c))
                {
			cout<< "ERROR: expected <eof> saw "<< "\\x"<< setw(2)<<setfill('0')<<hex<< int (c)<< endl;

                        exit(0);
                }
		
		else
		{
		cin.get(c);	
		}
	}*/

/*	else if((counter<82) && (isprint(c)))
	{	
		cout<< "ERROR: expected <value> saw "<< c;
		cout << endl;
		exit(0);
	}
	 else if((counter<82) && (isprint(c)))
        {
                cout<< "ERROR: expected <value> saw "<< c;
                cout << endl;
                exit(0);
        }
	 else if((counter<82) && (!isprint(c)))
        {
		cout<< "ERROR: expected <value> saw "<< "\\x"<< setw(2)<<setfill('0')<<hex<< int (c)<< endl;
		exit(0); 
        }
	else if((counter <82) && (c=='\n'))
	{
		cout<< "ERROR: expected <value> saw \\n";
                cout << endl;
                exit(0);
	}
	else if((counter== 81) && (isprint(c)))
        {
                cout<< "ERROR: expected \\n saw "<<c ;
                cout << endl;
                exit(0);
        }
	else if((counter== 81) && (!isprint(c)))
        {
		cout<< "ERROR: expected \\n saw "<< "\\x"<< setw(2)<<setfill('0')<<hex<< int (c)<< endl;
                exit(0);
        }
	 else if((counter== 81) && (cin.eof()))
        {
                cout<< "ERROR: expected \\n saw "<<c ;
                cout << endl;
                exit(0);
        }
}
	cin.get(c)
	if(!cin.eof())
	{
	 if((isprint(c)))
	{
		cout<< "ERROR: expected <eof> saw "<<c;
		cout<<endl;
		exit(0);
	}	
	 if((!isprint(c)))
        {
		cout<< "ERROR: expected <eof> saw "<< "\\x"<< setw(2)<<setfill('0')<<hex<< int (c)<< endl;
                exit(0);
        }
	if ((c=='\n'))
        {
                cout<< "ERROR: expected <eof> saw "<<c;
                cout<<endl;
                exit(0);
        }
	}

}


	//else 
	
      
}
}


//}*/
    bool puzzle2[9][9];
    int i = 0, j = 0;
    bool chkcell;


    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (puzzle[i][j] == 0)
                puzzle2[i][j] = false;
            else puzzle2[i][j] = true;	
        }
    }



    while (i != 9 && j != 9) {
        if (!puzzle2[i][j]) {
            if (puzzle[i][j] == 9)
		{
                puzzle[i][j] = 0;
                	do {
                    		cellrev(&i, &j);
                		}
		 while (puzzle2[i][j]);
                continue;
            	}

            puzzle[i][j]++;
	counter++;
	if (counter >100000000 ){
	break;
	}

            chkcell = chkboard(puzzle, i, j, puzzle[i][j]);

            if(!chkcell)
                do {
                    cellfor(&i, &j);
                } while (puzzle2[i][j]);
        }

            
			
	else
            cellfor(&i, &j);
}        
if(counter > 100000000)
{
	cout<< "No solutions.";
	cout<< endl;
	exit(0);
}   
//Print the solved puzzle

    for (int i = 0; i< 9; i++)
     {
            for (int j=0; j< 9; j++)
            {
               cout << puzzle[i][j];

            }
    }
cout<< endl;


    return 0;


}
