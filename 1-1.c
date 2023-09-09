#include<stdio.h>
int maxx(int a,int b);
int main(){
	int a=0,b=0,c=0,an=0;
	scanf("%d %d %d",&a,&b,&c);
	printf("%d 0 0\n",c);
	an=maxx(a-c,c-a);
	printf("%d %d 1\n",a,an);
	printf("%d %d 0",b,an+maxx(a-b,b-a));
	return 0;
}
int maxx(int a,int b){
	if(a>=b)return a;
	return b;
}
