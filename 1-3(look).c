#include<stdio.h>
int n=0,m=0,re[11][2]={},tim=0,peo=0;//*,*，输入,时间,人数 
int noww=0,too[11]={};//未到者，[始发]目的 
int floo1[11]={},floo2[11]={};//等待，目的 
int fx=1;//1为上，-1为下
int maxx(int a,int b); 
int main(){
	freopen("dian2.in","r",stdin);
	freopen("dian2.out","w",stdout);
	scanf("%d %d",&n,&m);
	noww=n;
	int upp=0,doo=0,i=0;
	for(i=1;i<=n;i++){
		scanf("%d %d",&re[i][0],&re[i][1]);
		too[re[i][0]]=re[i][1];
		floo1[re[i][0]]=1;
		if(re[i][0]<m)doo++;
		if(re[i][0]>m)upp++;
	}
	if(doo>upp)fx=-1;//始发方向 
	int mov=m,a1=0;
	if(floo1[mov]==0){
		printf("%d 0 0\n",mov);
	}
	while(noww>0){
		a1=1;//1,look
		for(i=mov;i<=10&&i>0;i+=fx){
			if(floo1[i]==1&&peo<=3)a1=0;
			if(floo2[i]!=0&&peo>0)a1=0;
		} 
		if(a1==1&&fx==1){
			fx=-1;
		}else{
			if(a1==1&&fx==-1)fx=1;
		}
		int anss=mov;
		while((floo1[anss]==0||peo==4)&&floo2[anss]==0)anss+=fx;
		tim+=maxx(anss-mov,mov-anss);
		if(floo2[anss]>0){
			peo-=floo2[anss];
			noww-=floo2[anss];
			floo2[anss]=0;
		}
		if(floo1[anss]==1&&peo<4){
			floo1[anss]=0;
			floo2[too[anss]]++;
			peo++;
		}
		printf("%d %d %d\n",anss,tim,peo);
		mov=anss;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
int maxx(int a,int b){
	if(a>b)return a;
	return b;
}
