#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define filas 500
#define columnas 744


int main(void)
{
    double *x=malloc(120877*sizeof(double));
    double *y=malloc(120877*sizeof(double));    
    
    int i;
    int j;
     int **matriz=malloc(filas*sizeof(double*));
     for (i=0;i<filas;++i)
     {
         matriz[i]=malloc(columnas*sizeof(double));
     }
     FILE *datos;
     datos=fopen("map_data.txt","r");
     for (i=0;i<filas;++i)
     {
         for (j=0;j<columnas;++j)
         {
             fscanf(datos,"%d",&matriz[i][j]);
         }
     }
    return 0;
}


void coordinates(double *x, double *y,double **matriz){
    int a=0;
    for (int i=0;i<filas;++i){
        for (int j=0;j<columnas;++j){
            if (matriz[i][j]==1){
                x[a]=i;
                y[a]=j;  
                a++;    
            }
        }
    }
}

//Creo el método que genera números aleatorios
double aleatorio(void)
{
    return (double) rand()/RAND_MAX;
}

//Genero un método que calcula el radio
double radio(double x0, double y0, double *x, double *y)
{
    int i;
    double R;
    double r;
    
    R=pow(pow(x[0]-x0,2.0)+pow(y[0]-y0, 2.0),0.5);
    for(i=1;i<120877;i++)
    {
        r=pow(pow(x[i]-x0,2.0)+pow(y[i]-y0,2.0),0.5);
        if(r<R)
        {
            R=r;
        }
    }
    return R;
}

void MonteCarlo(char *datos)
{
    int i;
    double *x;
    double *y;
    double x1;
    double x2; 
    double y1; 
    double y2; 
    double r1; 
    double r2; 
    double a;

    x2=2*aleatorio()-1;
    y2=2*aleatorio()-1;
    r2=radio(x2,y2,x,y);

    for(i=0; i<1000; i++)
    {

        
        r1=radio(x1,y1,x,y);
        x1=(2*aleatorio()-1)*0.5+x2;
        y1=(2*aleatorio()-1)*0.5+y2;
        a=exp((r1-r2));

        if(a>1)
        {
            a=1;
        }
        if(a>aleatorio())
        {
            r2=r1;
            x2=x1;
            y2=y1;
        }
        printf("%f %f %f\n", x2, y2, r2);
    }
}
