#include <stdio.h>
#include <string.h>
typedef struct _schedule
{
	char name[99];
	int date;
}schedule;
int main(void) {
	int n;
	schedule s[100];
	scanf("%d", &n);
	for(int i=0; i<n; i++)
    {
		int y, m, d;
		scanf("%s %d %d %d", s[i].name, &y, &m, &d);
		s[i].date = y*10000+m*100+d;
	}
	for(int i=n-1; i>0; i--)
    {
		for(int j=0; j<i; j++)
        {
			if(s[j].date>s[j+1].date)
            {
				schedule tmp = s[j];
				s[j]=s[j+1];
				s[j+1]=tmp;
			}
		}
	}
	for(int i=n-1; i>0; i--)
    {
		for(int j=0; j<i; j++)
        {
			if(s[j].date == s[j+1].date && strcmp(s[j].name, s[j+1].name)>0)
            {
				schedule tmp = s[j];
				s[j]=s[j+1];
				s[j+1]=tmp;
			}
		}
	}
	for(int i=0; i<n; i++)
    {
		printf("%s\n", s[i].name);
    }
	return 0;
}