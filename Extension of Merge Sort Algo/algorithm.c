#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int array1[2000];
int array2[2000];
int array3[4000];
int n,m;
int t;

int get_union()
{    
	int i,j,k;
	int inc1,inc2;

	if((n == 1) || (array1[0] < array1[1]))
	{
		i = 0;
		inc1 = 1;
	}
	else
	{
		i = n-1;
		inc1 = -1;
	}

	if((m==1) || (array2[0] < array2[1]))
	{
		j = 0;
		inc2 = 1;
	}
	else
	{
		j = m-1;
		inc2 = -1;
	}

	k = 0;
	t += 18;

	while((i<n) && (j<m) && (i>=0) && (j>=0))
	{
		if(array1[i] < array2[j])
		{
			array3[k] = array1[i];
			i += inc1;
			t += 7;
		}
		else if(array1[i] > array2[j])
		{
			array3[k] = array2[j];
			j += inc2;
			t += 10;
		}
		else
		{
			array3[k] = array1[i];
			i += inc1;
			j += inc2;
			t += 11;
		}

		k++;
		t += 5;
	}

	t += 4;

	while((i<n) && (i>=0))
	{
		array3[k] = array1[i];
		i += inc1;
		k++;
		t += 7;
	}

	t += 2;

	while((j<m) && (j>=0))
	{
		array3[k] = array2[j];
		j += inc2;
		k++;
		t += 7;
	}

	t += 2;
	return t;
}

int get_intersection()
{
	int i,j,k;
	int inc1,inc2;

	if((n == 1) || (array1[0] < array1[1]))
	{
		i = 0;
		inc1 = 1;
	}
	else
	{
		i = n-1;
		inc1 = -1;
	}

	if((m==1) || (array2[0] < array2[1]))
	{
		j = 0;
		inc2 = 1;
	}
	else
	{
		j = m-1;
		inc2 = -1;
	}

	k = 0;
	t += 18;

	while((i<n) && (j<m) && (i>=0) && (j>=0))
	{
		if(array1[i] < array2[j])
		{
			i += inc1;
			t += 4;
		}
		else if(array1[i] > array2[j])
		{
			j += inc2;
			t += 7;
		}
		else
		{
			array3[k] = array1[i];
			i += inc1;
			j += inc2;
			k++;
			t += 12;
		}
		t += 4;
	}

	t += 4;
	return t;
}

int get_ringSum()
{
	int i,j,k;
	int inc1,inc2;

	if((n == 1) || (array1[0] < array1[1]))
	{
		i = 0;
		inc1 = 1;
	}
	else
	{
		i = n-1;
		inc1 = -1;
	}

	if((m==1) || (array2[0] < array2[1]))
	{
		j = 0;
		inc2 = 1;
	}
	else
	{
		j = m-1;
		inc2 = -1;
	}

	k = 0;
	t += 18;

	while((i<n) && (j<m) && (i>=0) && (j>=0))
	{
		if(array1[i] < array2[j])
		{
			array3[k] = array1[i];
			i += inc1;
			k++;
			t += 8;
		}
		else if(array1[i] > array2[j])
		{
			array3[k] = array2[j];
			j += inc2;
			k++;
			t += 11;
		}
		else
		{
			i += inc1;
			j += inc2;
			t += 8;
		}
		t += 5;
	}

	t += 4;

	while((i<n) && (i>=0))
	{
		array3[k] = array1[i];
		i += inc1;
		k++;
		t += 7;
	}

	t += 2;

	while((j<m) && (j>=0))
	{
		array3[k] = array2[j];
		j += inc2;
		k++;
		t += 7;
	}

	t += 2;

	return t;
}

void generate(int x,int y)
{
	srand(time(NULL));

	n = x;
	m = y;

	for(int i=0;i<n;i++)
	{
		array1[i] = i*5 + rand()%5;
	}

	for(int i=0;i<m;i++)
	{
		array2[i] = i*5 + rand()%5;
	}

	int f1 = rand()%2;

	if(!f1)
		qsort(array1,n,sizeof(int),cmpfunc);

	int f2 = rand()%2;

	if(!f2)
		qsort(array2,m,sizeof(int),cmpfunc);
}

int main(int argc, char** argv)
{
	FILE *fp;
	fp = fopen("temp.txt","w");
	
	char* funct = argv[1];
	
    if(argc == 1) {
	    printf("Type './a.out r' for ring-sum, './a.out u' for union, './a.out i' for intersection ");
	}
	
	else if(*funct == 'r') {
	    printf("Performing ringsum of sets\n");
	    for(int i=1;i<=100;i++)
	    {
		    for(int j=1;j<=i;j++)
		    {
			    t = 0;
			    generate(i,j);
			    get_ringSum();

			    int size = i+j;
			    int tim = t;

			    fprintf(fp, "%d %d\n",size,tim);
		    }
	    }
	}
	
	else if(*funct == 'u') {
	    printf("Performing union of sets\n");
	    for(int i=1;i<=100;i++)
	    {
		    for(int j=1;j<=i;j++)
		    {
			    t = 0;
			    generate(i,j);
			    get_union();
			    
			    int size = i+j;
			    int tim = t;

			    fprintf(fp, "%d %d\n",size,tim);
		    }
	    }
	}
	
	else if(*funct == 'i') {
		printf("Performing intersection of sets\n");
	    for(int i=1;i<=100;i++)
	    {
		    for(int j=1;j<=i;j++)
		    {
			    t = 0;
			    generate(i,j);
			    get_intersection();
			    int size = i+j;
			    int tim = t;

			    fprintf(fp, "%d %d\n",size,tim);
		    }
	    }
	}
		
	else {
	    printf("Type './a.out r' for ring-sum, './a.out u' for union, './a.out i' for intersection\n");
	}

}