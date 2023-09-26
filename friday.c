#include <stdio.h>
#include <stdlib.h>

void calc(int *, int *, int *, int , int *, int *);
int easter(int , int *);

int main(int argc, char * argv[])
{
	int day, month, year, i, j=0, easter_m, easter_d, loops;
	char *a[3] ={"Ageli", "Omada", "Koinotita"};
	if(argc < 4){
		day = 1;
		month = 10;
		year = 2010;
		loops = 20;
	}
	else{
		day = atoi(argv[1]);
		month = atoi(argv[2]);
		year = atoi(argv[3]);
		loops = atoi(argv[4]);
	}
	easter_d = easter(year, &easter_m);
	for(i=0;i<loops;i++){
		calc(&day, &month, &year, 7, &easter_m, &easter_d);
		if(month==easter_m && easter_d-day<4){
			i--;
			continue;
		}
		if((day==28 && month==10) || (day==25 && month==3) || (day==1 && month==5) || (day >= 24 && month==12) || (day <= 5 && month==1)){
			i--;
			continue;
		}
		if(j==3)
			j=0;
		printf("Friday %d %d %d    ->    %s\n", day, month, year, a[j]);
		j++;
	}	
	return 0;
}


void calc(int *day, int *month, int *year, int diff, int *easter_m, int *easter_d)
{
	int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	if((!(*year%4) && (*year%100)) || (!(*year%400)))
		days[1]=29;
	if(*day + diff > days[(*month)-1]){
		diff -= (days[*month-1]) - (*day) + 1;
		*day = 1;
		if(*month ==12){
			*month = 1;
			(*year) ++;
			*easter_d = easter(*year, easter_m);
		}
		else
			(*month) ++;
	}
	*day += diff; 
	return;
}

int easter(int year, int *month)
{ 
	int a, b, c, d, e;
    a = year % 19;
    b = year % 4;    
    c = year % 7;
    d = (19*a+15) % 30;
    e = (2*b+4*c+6*d+6) % 7;
    if (d+e+4 > 30)                
	  {
		*month = 5;
		return d+e-26;
	  }
    else   
	  {
		*month = 4;
		return d+e+4;
	  }
}

