#include<stdio.h>
int maxx(int a,int b);
int main(){
	char cr[20];
	int a=0,b=0,c=0,an=0;
	freopen("dian1.in","r",stdin);
	freopen("dian1.out","w",stdout);
	scanf("%s %d %d %d",&cr,&c,&a,&b);
	printf("%d 0 0\n",c);
	an=maxx(a-c,c-a);
	printf("%d %d 1\n",a,an);
	printf("%d %d 0",b,an+maxx(a-b,b-a));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
int maxx(int a,int b){
	if(a>=b)return a;
	return b;
}
