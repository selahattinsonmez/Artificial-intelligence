#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main(){
	
	int i,j,k,temp,temp2;
	float p[20][3],f[20],pb[20][3],pbf[20],gb[3],gbf,ww[2],w=1.15,f1=2,f2=1.05,random,random1,random2,v[20][3],keep,sign,keepp;
	srand(time(NULL));
	//1<=x<=5 10<=y<=20 2<=z<=8
	ww[0]=1.15;ww[1]=-0.2;
	gb[0]=100; gb[1]=1; gb[2]=1;    gbf=(pow(gb[0],2)-pow(gb[1],2))/gb[2];

	for(i=0;i<20;i++){
		random=rand()%100;random=random/100;
		p[i][0]=1+4*random;
		random=rand()%100;random=random/100;
		p[i][1]=10+10*random;
		random=rand()%100;random=random/100;
		p[i][2]=2+6*random;
		
		pb[i][0]=p[i][0];pb[i][1]=p[i][1];pb[i][2]=p[i][2];
		

		f[i]=(pow(p[i][0],2)-pow(p[i][1],2))/pow(p[i][2],2);
		pbf[i]=f[i];
		
		if(f[i]<gbf){
			gb[0]=p[i][0];gb[1]=p[i][1];gb[2]=p[i][2];gbf=f[i];
		}
		//printf("%f %f %f %f\n",p[i][0],p[i][1],p[i][2],f[i]);
		v[i][0]=5;v[i][1]=5;v[i][2]=5;
	
	}
	//printf("%f %f %f",p[0][0],p[0][1],p[0][2]); 9,26958916
	for(i=0;i<100000;i++){
		w=ww[i%2];
		for(j=0;j<20;j++){
			
			random=rand()%100; random=random/100;    random1=rand()%100; random1=random1/100;
			keep=v[j][0]*w+(f1*random*(gb[0]-p[j][0]))+(f2*random1*(pb[j][0]-p[j][0]));
			
			
			keepp=p[j][0];

			p[j][0]=p[j][0]+keep;
			temp=p[j][0]*10000000-10000000;
			p[j][0]=abs(temp%40000000)+10000000;
			p[j][0]=p[j][0]/10000000;
			
			v[j][0]=(p[j][0]-keepp);

			
			//
			random=rand()%100; random=random/100;    random1=rand()%100; random1=random1/100;
			keep=v[j][1]*w+(f1*random*(gb[1]-p[j][1]))+(f2*random1*(pb[j][1]-p[j][1]));
			
			keepp=p[j][1];
			
			p[j][1]=p[j][1]+keep;
			temp=p[j][1]*10000000;
			p[j][1]=abs(temp%100000000)+100000000;
			p[j][1]=p[j][1]/10000000;
			
			v[j][1]=(p[j][1]-keepp);
			//p[j][1]=abs(((p[j][1]+keep)%10))+10;
			

			random=rand()%100; random=random/100;    random1=rand()%100; random1=random1/100;			
			keep=v[j][2]*w+(f1*random*(gb[2]-p[j][2]))+(f2*random1*(pb[j][2]-p[j][2]));
			
			keepp=p[j][2];
			
			p[j][2]=p[j][2]+keep;
			temp=p[j][2]*10000000-20000000;
			p[j][2]=abs(temp%60000000)+20000000;
			p[j][2]=p[j][2]/10000000;
			
			v[j][2]=(p[j][2]-keepp);
			//p[j][2]=abs((p[j][2]+keep-2)%6)+2;
			
			
			
			

						
			f[j]=(pow(p[j][0],2)-pow(p[j][1],2))/pow(p[j][2],2);
			
			//printf("%f %f %f %f\n",p[j][0],p[j][1],p[j][2],f[j]);
			
			if(f[j]<pbf[j]){
				pb[j][0]=p[j][0];pb[j][1]=p[j][1];pb[j][2]=p[j][2];pbf[j]=f[j];
				if(f[j]<gbf){
					gb[0]=p[j][0];gb[1]=p[j][1];gb[2]=p[j][2];gbf=f[j];
				}
			}												
		}
	}
	printf("\nGlobal best =%f %f %f %f",gb[0],gb[1],gb[2],gbf);	

	return 0;
}
