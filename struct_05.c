#include <stdio.h>
typedef struct _student {
	char name[10];
	int a, ar, b, br, c, cr;
}student;
int main(void) {
	int n;
	student s[100];
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%s %d %d %d", s[i].name, &s[i].a, &s[i].b, &s[i].c);
	for(int i=n-1; i>0; i--){
		for(int j=0; j<i; j++) {
			if(s[j].a<s[j+1].a){
				student tmp = s[j];
				s[j]=s[j+1];
				s[j+1]=tmp;
			}
		}
	}
	s[0].ar=1;
	for(int i=n-1; i>0; i--){
		for(int j=0; j<i; j++) {
			if(s[j].b<s[j+1].b){
				student tmp = s[j];
				s[j]=s[j+1];
				s[j+1]=tmp;
			}
		}
	}
	int cnt;
	for(int i=0; i<n; i++){
		if(i>0 && s[i-1].b==s[i].b)
			s[i].br = cnt;
		else {
			cnt = i+1;
			s[i].br = cnt;
		}
	}
	for(int i=n-1; i>0; i--){
		for(int j=0; j<i; j++) {
			if(s[j].c<s[j+1].c){
				student tmp = s[j];
				s[j]=s[j+1];
				s[j+1]=tmp;
			}
		}
	}
	cnt=1;
	for(int i=0; i<n; i++){
		if(i>0 && s[i-1].c==s[i].c){
			s[i].cr = cnt;
		}
		else {
			cnt = i+1;
			s[i].cr = cnt;
		}
	}
	for(int i=0; i<n; i++) 
		if(s[i].ar == 1)
			printf("%s %d %d\n", s[i].name, s[i].br, s[i].cr);
	return 0;
}