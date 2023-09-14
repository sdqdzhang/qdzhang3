#include<stdio.h>
int m1=0,m2=0,tim=0,n=0,noww=0,inn[101][3]={},fx1=0,fx2=0;//0不动，-1下，1上 
int floo11[11]={}, floo12[11]={},floo21[11]={},floo22[11]={},peo1=0,peo2=0;
int main(){
	scanf("%d %d %d",&m1,&m2,&n);
	int i=0,anss[201][3]={0,0,0},ss=0;
	anss[0][0]=m2;
	noww=n;
	for(i=1;i<=n;i++){
		scanf("%d %d %d",&inn[i][0],&inn[i][1],&inn[i][2]);
		inn[i][2]+=inn[i-1][2];
	}
	printf("电梯1:\n%d 0 0\n",m1);
	int sit1=0,sit2=0;
	while(noww>0){
		for(i=1;i<=n;i++){
			if(tim==inn[i][2]){//优先级 
				sit1=4;
				sit2=4;
				if(fx1==1&&inn[i][0]>=m1&&inn[i][1]>=inn[i][0])sit1=1;
				if(fx1==-1&&inn[i][0]<=m1&&inn[i][1]<=inn[i][0])sit1=1;
				if(fx2==1&&inn[i][0]>=m2&&inn[i][1]>=inn[i][0])sit2=1;
				if(fx2==1&&inn[i][0]<=m2&&inn[i][1]<=inn[i][0])sit2=1;
				if(fx1==0)sit1=2;
				if(fx2==0)sit2=2;
				if(fx1==1&&inn[i][0]>m1&&inn[i][1]<inn[i][0])sit1=3;
				if(fx1==-1&&inn[i][0]<m1&&inn[i][1]>inn[i][0])sit1=3;
				if(fx2==1&&inn[i][0]>m2&&inn[i][1]<inn[i][0])sit2=3;
				if(fx2==-1&&inn[i][0]<m2&&inn[i][1]>inn[i][0])sit2=3;
				if(peo1==4)sit1=5;
				if(peo2==4)sit2=5;
				if(sit1<sit2){
					floo11[inn[i][0]]=i;
				}else{
					if(sit1>sit2){
						floo21[inn[i][0]]=i;
					}else{
						if(sit1==sit2&&sit1!=5){
							floo11[inn[i][0]]=i;
						}else{
							inn[i][2]++;
						}
					}
				}
			}
		}
		int an1=0,an2=0;
		if(floo12[m1]!=0){
			an1=1;
			peo1-=floo12[m1];
			noww-=floo12[m1];
			floo12[m1]=0;
		}
		if(floo22[m2]!=0){
			an2=1;
			peo2-=floo22[m2];
			noww-=floo22[m2];
			floo22[m2]=0;
		}//下 
		if(peo1!=4&&floo11[m1]!=0){
			an1=1;
			peo1++;
			floo12[inn[floo11[m1]][1]]++;
			floo11[m1]=0;
		}
		if(peo2!=4&&floo21[m2]!=0){
			an2=1;
			peo2++;
			floo22[inn[floo21[m2]][1]]++;
			floo21[m2]=0;
		}//上
		//转向 
		int upp=0,doo=0;
		for(i=1;i<=10;i++){
			if(i>m1&&floo12[i]!=0)upp++;
			if(i<m1&&floo12[i]!=0)doo++;
			if(i>m1&&floo11[i]!=0&&peo1!=4)upp++;
			if(i<m1&&floo11[i]!=0&&peo1!=4)doo++;
		}
		if(upp>0&&doo==0)fx1=1;
		if(doo>0&&upp==0)fx1=-1;
		if(doo==0&&upp==0)fx1=0;
		upp=0;
		doo=0;
		for(i=1;i<=10;i++){
			if(i>m2&&floo22[i]!=0)upp++;
			if(i<m2&&floo22[i]!=0)doo++;
			if(i>m2&&floo21[i]!=0&&peo2!=4)upp++;
			if(i<m2&&floo21[i]!=0&&peo2!=4)doo++;
		}
		if(upp>0&&doo==0)fx2=1;
		if(doo>0&&upp==0)fx2=-1;
		if(doo==0&&upp==0)fx2=0;
		if(an1==1){
			printf("%d %d %d\n",m1,tim,peo1);
		}
		if(an2==1){
			ss++;
			anss[ss][0]=m2;
			anss[ss][1]=tim;
			anss[ss][2]=peo2;
		}
		tim++;
		m1+=fx1;
		m2+=fx2;
	}
	printf("电梯2：\n");
	for(i=0;i<=ss;i++){
		printf("%d %d %d\n",anss[i][0],anss[i][1],anss[i][2]);
	}
	return 0;
}
