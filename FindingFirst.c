#include"ctype.h"  
#include"string.h"  
#include"stdio.h"  
char gram[10][10],vFirst[5];  
int elem[10],size,fPt,k=0;  
int getGram(){  
  char ch; int i,j,k;       
  printf("\nEnter Number of Rule : ");  
  scanf("%d",&size);  
  printf("\nEnter Grammar as E=E+B \n");  
  for(i=0;i<size;i++){  
    scanf("%s%c",gram[i],&ch);  
    elem[i]=strlen(gram[i]);  
  }  
  printf("\nGrammar is :\n");  
  for(i=0;i<size;i++)  
    printf("\n%s",gram[i]);  
}  
int funcFirst(char victim){  
  int j,i;  
  if(!(isupper(victim)))  
    vFirst[k++]=victim;  
  else  
  for(j=0;j<size;j++){  
    if(gram[j][0]==victim){  
      if(gram[j][2]=='$')  
        vFirst[k++]='$';  
      else if(islower(gram[j][2]))  
        vFirst[k++]=gram[j][2];  
      else  
        funcFirst(gram[j][2]);  
    }  
  }  
}  
int main(){  
  int i,j,k;  
  getGram();  
  printf("\nEnter the Non Terminal : ");  
  char nt;  
  scanf("%c",&nt);  
  funcFirst(nt);  
  printf("\n{ ");  
  for(i=0;i<strlen(vFirst);i++)  
    printf(" %c",vFirst[i]);  
  printf(" }\n");  
}