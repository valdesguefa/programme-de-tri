#include <stdio.h>
#include <stdlib.h>
void permuter(float *tab,int p,int r)
{
    float tmp;
    tmp=tab[p];
    tab[p]=tab[r];
    tab[r]=tmp;
}
int partition(float *tab, int p,int r)
{
    float X;
    int i,j;
    X=tab[r];
    i=p-1;
    for(j=p;j<=r-1;j++)
    {
        if(tab[j]<X)
        {
            i=i+1;
            permuter(tab,j,i);
        }
    }
    permuter(tab,i+1,r);
    return i+1;
}
void tri_rapide(float *tab,int p,int r)
{
    int q;
    if(p<r)
    {
        q=partition(tab,p,r);
        tri_rapide(tab,p,q-1);
        tri_rapide(tab,q+1,r);
    }
}
int main()
{

   int i,r,j;
   int p=0;
   float* tab;
   printf("---------------------------------------------------------------------------------------------------------------\n");
   printf("CE PROGRAMME TRI UN TABLEAU A L'AIDE DU TRI RAPIDE DANS L'ORDRE CROISSANT \n");
    printf("------------------------------------------------------------------------------------------------------------\n");
 printf("\n");
 printf("entrer le nombre d'elements de votre tableau\n");
  printf("--------------------------------------------------------------------------------------------------------------\n");
   scanf("%d",&r);
   tab=malloc(r*sizeof(float));
   for(i=p;i<r;i++)
   {
       printf("entrer le %d er/eme element\n",i+1);
       scanf("%f",&tab[i]);
   }
   tri_rapide(tab,p,r-1);
   printf("-------------------------------------------------------------------------------------------------------------\n");
   for(j=p;j<r;j++)
   {
       printf("  %f",tab[j]);
   }
   printf("\n");
   printf("-------------------------------------------------------------------------------------------------------------");
   free(tab);
    return 0;
}
