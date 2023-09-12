#include<stdio.h>
int maxx(int a,int b);
int n=0,m=0,noww=0,inn[101][3]={};//*,*,未到者，输入记录 
int floo1[11],floo2[11],fx=1,peo=0;//等待，目标，方向，人数<4 
void moni(int ti,int fl);
int main(){
	int i=0;
	scanf("%d %d",&m,&n);
	for(i=1;i<=n;i++){
		scanf("%d %d %d",&inn[i][0],&inn[i][1],&inn[i][2]);
		inn[i][2]+=inn[i-1][2];
	}
	noww=n;
	moni(0,m);
	return 0;
}
int maxx(int a,int b){
	if(a>b)return a;
	return b;
}
void moni(int ti,int fl){//剪枝-更新-等待-转向-下上 
	if(noww<=0||fl<=0||fl>10)return;
	int j=0,a1=1;
	for(j=1;j<=n;j++){
		if(inn[j][2]==ti){
			floo1[inn[j][0]]=j;
		}
	}
	if(floo2[fl]!=0){
		a1=0;
		peo-=floo2[fl];
		noww-=floo2[fl];
		floo2[fl]=0;
	}
	if(floo1[fl]!=0&&peo!=4){
		a1=0;
		peo++;
		floo2[inn[floo1[fl]][1]]++;
		floo1[fl]=0;
	}
	if(a1==0){
		printf("%d %d %d\n",fl,ti,peo);
	}
	a1=1;
	for(j=1;j<=10;j++){
		if((floo1[j]!=0&&peo!=4)||floo2[j]!=0){
			a1=0;
		}
	}
	if(a1==1){
		moni(ti+1,fl);
		return;
	}
	a1=1;
	for(j=1;j<=10;j++){
		if(fx==1&&j>fl&&((floo1[j]!=0&&peo<4)||floo2[j]!=0))a1=0;
		if(fx==-1&&j<fl&&((floo1[j]!=0&&peo<4)||floo2[j]!=0))a1=0;
	}
	if(a1==1){
		if(fx==1){
			fx=-1;
		}else{
			fx=1;
		}
	}
	if(fl==1)fx=1;
	if(fl==10)fx=-1;
	moni(ti+1,fl+fx);
	return;
}
