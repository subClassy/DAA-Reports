#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int t;
int array1[1000];
int array2[1000];
int array3[2000];
int n,m;

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

void generate_best_case_union(int x,int y)
{
	srand(time(NULL));

	n = x;
	m = 1;

	array1[0] = rand()%10000;

	for(int i=1;i<n;i++)
	{
		array1[i] = array1[i-1] + rand()%10000 + 1;
	}

	for(int i=0;i<m;i++)
	{
		array2[i] = array1[i];
	}

}

void generate_worst_case_union(int x,int y)
{
	srand(time(NULL));

	m = ((x+y)/2);
	n = (x+y)-m;

	array1[0] = rand()%10000;

	for(int i=1;i<n;i++)
	{
		array1[i] = array1[i-1] + rand()%10000 + 50;	}
	int l;
	if(m == n) {
		l = m - 1;
	}
	else {
		l = m;
	}
	for(int i=0;i<l;i++)
	{	
		array2[i] = array1[i] + rand()%(array1[i+1] - array1[i] - 1) + 1 ;
	}
	if(m == n){
		array2[m-1] = array1[n-1] + rand()%10000 + 1;
	}

	qsort(array1,n,sizeof(int),cmpfunc);
	qsort(array2,m,sizeof(int),cmpfunc);
}

int main()
{
	FILE *fp1, *fp2;
	fp1 = fopen("best-case-ringsum.txt","w");
	fp2 = fopen("worst-case-ringsum.txt","w");


	    printf("Performing best case ringsum of sets\n");
	    for(int i=1;i<=199;i++)
	    {
		    for(int j=1;j<=i;j++)
		    {
			    t = 0;
			    generate_best_case_union(i,j);
			    get_ringSum();

			    int size = m+n;
			    int tim = t;

			    fprintf(fp1, "%d %d\n",size,tim);
		    }
	    }


	    printf("Performing worst case ringsum of sets\n");
	    for(int i=1;i<=100;i++)
	    {
		    for(int j=1;j<=i;j++)
		    {
			    t = 0;
			    generate_worst_case_union(i,j);
			    get_ringSum();

			    int size = m+n;
			    int tim = t;

			    fprintf(fp2, "%d %d\n",size,tim);
		    }
	    }
	
}
