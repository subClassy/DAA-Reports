#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define INT_MAX 1000000000
#define INT_MIN -1

double min(double a,double b)
{
	if(a < b) return a;
	return b;
}

double max(double a,double b)
{
	if(a > b) return a;
	return b;
}

int main()
{
	FILE *fp_min,*fp_max,*fp_avg;

	fp_min = fopen("min.txt","w");
	fp_max = fopen("max.txt","w");
	fp_avg = fopen("avg.txt","w");

	for(int i=1;i<=18;i++)
	{
		int l = i;
		int r = i;

		FILE *fp;
		fp = fopen("temp.txt","r");

		double min_value = INT_MAX;
		double max_value = INT_MIN;
		double avg = 0;
		int count = 0;

		int time;
		int size;

		while(fscanf(fp,"%d %d",&size,&time) != EOF)
		{
			if(size >= l && size <= r)
			{
				min_value = min(min_value,(double)time);
				max_value = max(max_value,(double)time);
				avg += time;
				count++;
			}
		}

		int range = (r-l+1)/2;

		fprintf(fp_min,"%d %lf\n",i+range,min_value);
		fprintf(fp_max,"%d %lf\n",i+range,max_value);
		fprintf(fp_avg,"%d %lf\n",i+range,avg/(double)count);
	}	

	return 0;
}