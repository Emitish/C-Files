/*Sort an array of complex numbers by absolute value.*/

#include <stdio.h>
#include <math.h>

#define NSIZE 20



typedef struct {
  double real,
    imag;
} complex_t;

void swap_largest(complex_t *array[], int n, int max_index);
void select_sort_rec(complex_t *array[], int n);
int find_biggest(complex_t *array[], int n, int start, int curmax);

double abs_complex(complex_t c);
int scan_complex(FILE *fp,complex_t *c);
void print_complex(complex_t c);

int
main()
{
    complex_t *array[NSIZE];
    int size,  i;
    complex_t entry[NSIZE];
    complex_t cno;
    FILE *fp;

    fp = fopen("cdata.txt", "r");
    size = 0;

    while(scan_complex(fp, &cno) == 1) {
	entry[size]=cno;
	array[size]=&entry[size];
	size++;
    }


    printf("array before sorting  = \n");
   	for(i=0;i<size;i++)
	{
	print_complex(entry[i]);
	}


    printf("***end of array****\n");


    select_sort_rec(array, size);


    printf("\narray after sorting   = \n");
    for(i=0;i<size;i++)
        {
        print_complex(*array[i]);
        }


    printf("***end of array****\n");
    fclose(fp);
    return 0;
}


void select_sort_rec(complex_t *array[], int n)
{
  int themax = 0;

	if(n==0)
	{
	return;
	}
	themax = find_biggest(array,n,0,themax);
	swap_largest(array, n, themax);
	select_sort_rec(array, n-1);

}



void swap_largest(complex_t *array[], int n,int max_index)
{
	complex_t *temp;
	temp=array[max_index];
	array[max_index]=array[n-1];
	array[n-1]=temp;


int find_biggest(complex_t *array[], int n, int start, int curmax) {

	double  cabs2;
	cabs2= abs_complex(*array[start+1]);

	if (start == n-1);
	{
	return(curmax);
	}

	if (cabs2>abs_complex(*array[curmax]))
	{
	curmax=start+1;
	}
	return(find_biggest(array,n,start+1,curmax));
        }

}



/*
 *  Complex number input function returns standard scanning error code
 *    1 => valid scan, 0 => error, negative EOF value => end of file
 */
int scan_complex(FILE *input, complex_t *c) /* output - address of complex variable to fill*/
{

  int status;

  status = fscanf(input,"%lf%lf", &c->real, &c->imag);

  //    status = scanf("%lf%lf", &((*c).real),
  //                             &((*c).imag));
  if (status == 2)
    status = 1;
  else if (status != EOF)
    status = 0;

  return (status);
}


/*
 *  Complex output function displays value as (a + bi) or (a - bi),
 *  dropping a or b if they round to 0 unless both round to 0
 */
void
print_complex(complex_t c)
  double a, b;

  char   sign;

  a = c.real;
  b = c.imag;

  printf("(");

  if (fabs(a) < .005  &&  fabs(b) < .005) {
    printf("%.2f", 0.0);
  } else if (fabs(b) < .005) {
    printf("%.2f", a);
  } else if (fabs(a) < .005) {
    printf("%.2fi", b);
  } else {
    if (b < 0)
      sign = '-';
    else
      sign = '+';
    printf("%.2f %c %.2fi", a, sign, fabs(b));
  }

  printf(")\n");
}


/*
 *  Absolute value abs(c)
 */

double abs_complex(complex_t c)
	complex_t cabs;
	cabs.real=sqrt(((c.real*c.real) + (c.imag*c.imag)));
	cabs.imag=0.0;
	return (cabs.real);

}



