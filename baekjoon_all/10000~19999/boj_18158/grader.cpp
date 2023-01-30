#include<stdio.h>
#include"WAEP.h"
static int T,P,i,j;
int main(){
	scanf("%d",&T);
	init(T);
	for(i=0;i<T;i++){
		scanf("%d",&P);
		j=janken(P);
		printf("%d\n",j);
	}
	return 0;
}