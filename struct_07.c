#include <stdio.h>
#include <string.h>
typedef struct _student {
	int code;
	char name[10];
}student;
student s[100];
int N;
int cnt = 0;
void I(int code, char name[10]) {
    for(int i=0; i<cnt; i++) 
    {
        if(s[i].code == code) 
        {
            cnt++;
            for(int j=i; j<cnt-1; j++)
                s[j+1]=s[j];
            s[i].code = code;
            strcpy(s[i].name, name);
            return;
        }
    }
    s[cnt].code = code;
    strcpy(s[cnt].name, name);
    cnt++;
    return;
}
void D(int code) {
    for(int i=0; i<cnt; i++)
    {
        if (s[i].code == code){
            for(int j=i; j<cnt-1; j++)
                s[j]=s[j+1];
            cnt--;
            return;
        }
    }
    return;
}
int main(void) {
    int l[5];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
    { 
		char c, name[10];
		int code;
        scanf(" %c %d %s", &c, &code, name);
		if(c == 'I')
            I(code, name);
		else if(c == 'D')
            D(code);
	}
    for(int i=0; i<5; i++) 
    {
        scanf("%d", &l[i]);
    }
    for(int i=cnt-1; i>0; i--) 
    {
        for(int j=0; j<i; j++)
         {
            if(s[j].code > s[j+1].code)
            {
                student tmp = s[j];
                s[j]=s[j+1];
                s[j+1]=tmp;
            }
        }
    }
    for(int i=0; i<5; i++)
        for(int j=0; j<cnt; j++)
            if(l[i]-1 == j)
                printf("%d %s\n", s[j].code, s[j].name);
    return 0;
}