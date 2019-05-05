#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main(){
	float ind[10][3],newind[10][3],f1=1.5,f2=1.7,random,random1,random2,f[10],fn[10],v[3];
	int i,j,best=0,randomint,randomint2,x,randomint3,randomint4;
	srand(time(NULL));
	               //x^2 - y^2 / z^2
	// 1<=x<=5  10<=y<=20 2<=z<=8,
	for(i=0;i<10;i++){
		random=rand()%1000;random=random/1000;
		ind[i][0]=4*random+1;
		
		random=rand()%1000;random=random/1000;	
		ind[i][1]=10*random+10;
		
		random=rand()%1000;random=random/1000;
		ind[i][2]=6*random+2;
		
		f[i]=(pow(ind[i][0],2)-pow(ind[i][1],2))/pow(ind[i][2],2);
		
		if(f[i]<f[best]){
			best=i;
		}	
	}
	//x=xb + f*r*(xr-xr) + f2*r*(xr-xr)
	for(i=0;i<15;i++){
		
		
		if(i%25==0){
			
		}
		printf("%d. iteration\n",i+1);
		for(j=0;j<10;j++){
			randomint=rand()%11;randomint2=rand()%11;randomint3=rand()%11;randomint4=rand()%11;		
			//x	
			random2=rand()%1000;random2=random2/1000;random=rand()%1000;random=random/1000;
			v[0]=ind[best][0]+f1*random2*(ind[randomint][0]-ind[randomint2][0])+f2*random*(ind[randomint3][0]-ind[randomint4][0]);
			x=(v[0])/4;v[0]=abs((v[0])-(4*x))+1;//floatin modunu alarak range e sokma
			//y			
			random2=rand()%1000;random2=random2/1000;random=rand()%1000;random=random/1000;
			v[1]=ind[best][1]+f1*random2*(ind[randomint][1]-ind[randomint2][1])+f2*random*(ind[randomint3][1]-ind[randomint4][1]);
			x=(v[1])/10;v[1]=20-abs(v[1]-(10*x));//floatin modunu alarak range e sokma
			//z
			random2=rand()%1000;random2=random2/1000;random=rand()%1000;random=random/1000;
			v[2]=ind[best][2]+f1*random2*(ind[randomint][2]-ind[randomint2][2])+f2*random*(ind[randomint3][2]-ind[randomint4][2])   ;			
			x=(v[2]-2)/6;v[2]=abs((v[2]-2)-(6*x))+2;//floatin modunu alarak range e sokma
						
			//
			
			
			randomint=rand()%3;//kesin aktarilacak indis
			random1=rand()%100;random1=random1/100;
			if(random1<=0.5){
				newind[j][0]=v[0];
				
			}
			else{
				newind[j][0]=ind[j][0];
			}
			//

			random1=rand()%100;random1=random1/100;
			if(random1<=0.5){
				newind[j][1]=v[1];
				
			}
			else{
				newind[j][1]=ind[j][1];
			}			
			//

			random1=rand()%100;random1=random1/100;
			if(random1<=0.5){
				newind[j][2]=v[2];
				
			}
			else{
				newind[j][2]=ind[j][2];
			}
			//
			newind[j][randomint]=ind[j][randomint];
			
			fn[j]=(pow(newind[j][0],2)-pow(newind[j][1],2))/pow(newind[j][2],2);
			
			if(f[j]<fn[j]){
				newind[j][0]=ind[j][0];
				newind[j][1]=ind[j][1];
				newind[j][2]=ind[j][2];
				fn[j]=f[j];
			}
			else{
			
			}
			printf("%f %f %f %f\n",newind[j][0],newind[j][1],newind[j][2],f[j]);		
		}
		//best=0;
		for(j=0;j<10;j++){
			ind[j][0]=newind[j][0];
			ind[j][1]=newind[j][1];
			ind[j][2]=newind[j][2];
			f[j]=fn[j];
			if(f[j]<f[best]){
				best=j;
			}
		}	
	}
		
	printf("Global Best = %f %f %f %f",ind[best][0],ind[best][1],ind[best][2],f[best]);

	return 0;
}
