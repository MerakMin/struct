#include <stdio.h>
int in_num[2][500001]={0}
sort[2][500001]={0};
int main() {
	int i, cnt=0, n, m;
	scanf("%d", &n);
	for(i=0; i<n; i++) 
	{
		scanf("%d", &m);
		in_num[0][i]=m;
		sort[0][m]=m;
	}
	for(i=0; i<500001; i++) 
	{
		if(sort[0][i] != 0){
			sort[1][i] = cnt;
			cnt++;
		}
	}
	for(i=0; i<n; i++) 
	{
		in_num[1][i] = sort[1][in_num[0][i]];
		printf("%d ", in_num[1][i]);
	}
	return 0;
}