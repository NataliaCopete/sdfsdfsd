#include <iostream>
#include<math.h>


using std::cout;
using std::endl;


int main(){

double c2=4; 
double dx=0.4;
double dt=0.1;
double *u1;
double L=100.0;
/*double *equis;*/
double *uant;
double xmin=0.0;
double xmax=L;
int N=(xmax-xmin)/dx;
double Y=(c2*dt*dt)/(dx*dx);
double pi=acos(-1);
double **g= new double *[N];
int iteraciones=200/dt;

for (int i=0;i<N;i++){
g[i]= new double[iteraciones];
}

/*for(int i=0;i<N;i++){
equis[i]=i*dx;

}*/

for (int i=0;i<iteraciones;i++){
g[0][i]=0;
g[N-1][i]=0;

}

u1=new double[N];

uant=new double[N];


u1[0]=0.0;
uant[0]=0.0;
u1[N-1]=0.0;
uant[N-1]=0.0;

for(int i=1;i<N-1;i++){
     double x=i*dx;
     if(x<=0.8*L){
     u1[i]=1.25*x/L;
     uant[i]=1.25*x/L;
     }
else{
    u1[i]=5-(5*x/L);
    uant[i]=5-(5*x/L);
    }
 }

for(int i=1;i<N-1;i++){
g[i][0]=u1[i];
g[i][1]=u1[i]+(Y/2)*(u1[i+1]-2*u1[i]+u1[i-1]);
}

for(int i=0;i<N;i++){
u1[i]=g[i][1];

}

for (int k=2;k<iteraciones;k++){

for(int i=1;i<N-1;i++){
 
  g[i][k]= Y*(u1[i+1]+u1[i-1]-2*u1[i])+2*u1[i]-uant[i];
  
}

for (int i=0;i<N;i++)
{
uant[i]=u1[i];
u1[i]=g[i][k];
}
}

/*for(int i=0;i<N;i++){

cout<<g[i][0]<<" "<<g[i][500]<<" "<<g[i][1000]<<" "<<g[i][1500]<<" "<<g[i][2000]<<endl;
}*/

for (int j=0;j<iteraciones;j++){
for (int i=0;i<N;i++){
cout<<g[i][j]<<" ";
cout<<endl;
}
}
return 0;
}

