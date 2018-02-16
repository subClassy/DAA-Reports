#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

long long num;
int t;

void genrate(int n)
{
	num = 0;
	int sig = 0;
	for(int i=0;i<n;i++)
	{
		if(!sig)
		{
			sig = sig + 1;
			num = num*10 + 1 + rand()%9;
		}
		else
			num = num*10 + rand()%10;
	}
}

long long power(long long a,long long b)
{
    long long ret=1;
    t++;

    while(b)
    {
        if(b&1){
            ret = ret*a;
            t+=2;
        }
        a = a*a;
        b >>= 1;
        t += 5;
    }

    t++;
    return ret;
}

void check()
{
	long long sum = 0;
	int size = 0;
	long long temp = num;

	t += 3;

	while(temp)
	{
		temp = temp/10;
		size++;
		t += 4;
	}

	t++;

	while(num)
	{
		sum += power(num%10,size);
		num /= 10;
		t += 4;
	}

	t++;
}

int main()
{
	srand(time(NULL));
	FILE *fp;
	fp = fopen("temp.txt","w");

	for(int n=1;n<=18;n++)
	{
		for(int i=0;i<10;i++)
		{
			t = 0;
			genrate(n);
			check();
			fprintf(fp,"%d %d\n",n,t);
		}
	} 

	fclose(fp);
	return 0;
}
