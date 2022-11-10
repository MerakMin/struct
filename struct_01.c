#include <stdio.h>
int main(void){
    int n;
    int a[101],b[10001];
    int temp;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a[i],&b[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]<a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d %d \n", a[i],b[i]);
    }
    return 0;
}