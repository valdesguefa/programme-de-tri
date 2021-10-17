#include <stdio.h>
#include <stdlib.h>
void permuter(float *tab,int p,int r)
{
    float tmp;
    tmp=tab[p];
    tab[p]=tab[r];
    tab[r]=tmp;
}
void entasser_max(float *tab,int i,int n)
{
   int  d,g,b;
   int max=i;

 g=2*i+1;
     d=2*i+2;
if((d<=n)&&(tab[d]>tab[i]))
   {
       max=d;
   }
if((g<=n)&&(tab[g]>tab[max]))
   {
       max=g;
   }
 if(max!=i)
   {
       permuter(tab,i,max);
       entasser_max(tab,max,n);
   }
}
void construire_tas_max(float *tab,int n)
{
    int i,c,a;

    c=n-1;
    a=c/2;

    //a=a-1;
    if((n%2)==0)
    {
        for(i=a;i>=0;i--)
     {
        entasser_max(tab,i,n-1);
     }
    }
else if((n%2)!=0)
    {
    for(i=a-1;i>=0;i--)
     {
        entasser_max(tab,i,n-1);
     }
    }

}

void tri_par_tas (float *tab,int n)
{
    int i,taille,a,c;
    construire_tas_max(tab,n);

    taille=n-1;
    for(i=n-1;i>=1;i--)
   {
    permuter(tab,0,i);
    taille=taille-1;
    entasser_max(tab,0,taille);
    //entasser_max(tab,0,n-1);
    }
}
int main()
{
 int i,n,j;
   float* tab;
   printf("------------------------------------------------------------------------------------------------------------------------\n");
   printf("CE PROGRAMME TRI UN TABLEAU A L'AIDE DU TRI RAPIDE DANS L'ORDRE CROISSANT \n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
 printf("\n");
 printf("entrer le nombre d'elements de votre tableau\n");
  printf("------------------------------------------------------------------------------------------------------------------------\n");
   scanf("%d",&n);
   tab=malloc(n*sizeof(float));
   for(i=0;i<n;i++)
   {
       printf("entrer le %d er/eme element\n",i+1);
       scanf("%f",&tab[i]);
   }
   tri_par_tas(tab,n);
   printf("------------------------------------------------------------------------------------------------------------------------\n");
   for(j=0;j<n;j++)
   {
       printf("  %.2f",tab[j]);
   }
   printf("\n");
   printf("------------------------------------------------------------------------------------------------------------------------");
   free(tab);
    return 0;
}
