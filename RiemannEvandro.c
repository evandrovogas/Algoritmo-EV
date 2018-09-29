#include<stdlib.h>
#include<math.h>
#include<stdio.h>




void riemann(double ** p,double a, double b, int particoes, int posicao){

int k,l;
double passo=(b-a)/particoes;
double vet[particoes+1];
double integral=0;

for (k=0;k<posicao;k++){
    p[k]=(double*)malloc(2*sizeof(double));
}

for (k=0;k<posicao;k++){

printf("\nEntre com a constante da posicao = ");
scanf("%lf",&p[0][k]);

printf("\nEntre com a potencia da posicao = ");
scanf("%lf",&p[1][k]);
}

vet[particoes]=b;

for (k=particoes-1;k>=0;k--){
    vet[k]=vet[k+1]-passo;

}

for (k=0;k<particoes;k++){

double resultado=0.0;

for (l=0;l<posicao;l++){
resultado=resultado+(pow(vet[k],p[1][l])*p[0][l]);
}
double area=resultado*passo;
integral=integral+area;
}
printf("\nO valor da integral = %f ",integral);
}


int main(){
int pos,particoes;
double a,b;


printf("\n**********************Funcao a ser Integrada***********************");
printf("\nExemplo: Consideremos a funcao 5x+10. A mesma possui duas posicoes, a de 5x e a de 10");
printf("\nA partir de entao entre com o numero de posicoes que a funcao que se quer integrar possui = ");
scanf("%d",&pos);
double **constpot=(double**)malloc(pos*sizeof(sizeof(double*)));
if(constpot==NULL){
    printf("\nOverflow");
    exit(1);
}
printf("\n***********Intervalo de Integracao********* ");
printf("\nPor exemplo, em um intervalo de [1,4], deve-se entrar com o 1 e dar enter, e depois com o 4 e dar enter");
printf("\nEntre com o intervalo de integracao\n");
scanf("%lf",&a);
scanf("%lf",&b);
printf("\nEntre com o numero de particoes que se deseja fazer = ");
scanf("%d",&particoes);

riemann(constpot,a,b,particoes,pos);

return 0;
}
