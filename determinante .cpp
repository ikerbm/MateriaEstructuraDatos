/*no sabia hacerlo solo entonces saque ayuda de:
https://algoritmosyalgomas.com/determinante-de-una-matriz-de-cualquier-orden-c/
 https://www.youtube.com/watch?v=JqC53ppOgd0
*/
#include <iostream>
#include <cmath>
#include<stdlib.h>
#include<time.h>
using namespace std;
//cambiar max para el tamaño de la matriz
#define max 5

void mostrar(int matriz[][max],int orden);
int determinante(int matriz[][max],int orden);
int cofactor(int matriz[][max],int orden,int fila, int columna);

int main(){
  int orden=max;
  int i;
  int j;
  int num;
  int matriz[max][max];
  /*crear la matriz*/
  srand(time(NULL));
  for(i=0;i<orden;i++){

    for(j=0;j<orden;j++){
      num=1+rand()%(11-1);
      matriz[i][j]=num;
    }
  }
  /*mostrar la matriz*/
  //mostrar(matriz,orden);
  /*determinante de la matriz*/
  int deter=determinante(matriz,orden);
  cout<<"determinante = "<<deter<<endl;

  return 0;
}

void mostrar(int matriz[][max],int orden){
  for(int i=0;i<orden;i++){
    for(int j=0;j<orden;j++){
      cout<<matriz[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
}
int cofactor(int matriz[][max],int orden,int fila, int columna){
  int submatriz[max][max];
  int n=orden-1;
  int x=0;
  int y=0;

  for(int i=0;i<orden;i++){
    for(int j=0;j<orden;j++){
      if(i!=fila && j!=columna){
        submatriz[x][y]=matriz[i][j];
        y++;
        if(y>=n){
          x++;
          y=0;
        }
      }
    }
  }
  return pow(-1,(fila+columna))*determinante(submatriz,n);
}
int determinante(int matriz[][max],int orden){
  mostrar(matriz,orden);
  int det=0;
  if (orden==1){
    det=matriz[0][0];
  }else{
    for(int j=0;j<orden;j++){
      det=det + matriz[0][j] * cofactor(matriz,orden,0,j);
    }
  }
  return det;
}
