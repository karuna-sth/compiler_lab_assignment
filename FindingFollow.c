#include"stdio.h"  
#include"string.h"  
#include"ctype.h"  
int n=0,m=0,i=0,j=0,k=0;  
char vGram[10][10], vFirst[5], vFollow[10];  
int funcFirst(char);  
int funcFirst_F(char);  
int funcFollow(char);  
int funcFirst(char victim){  
  int j,i;  
  if(!(isupper(victim)))  
    vFirst[k++]=victim;  
  for(j=0;j<n;j++){  
    if(vGram[j][0]==victim){  
     if(vGram[j][2]=='$')  
      vFirst[k++]='$';  
     else if(islower(vGram[j][2]))  
      vFirst[k++]=vGram[j][2];  
     else  
      funcFirst(vGram[j][2]);  
    }  
  }  
  printf("\n{ ");  
  for(i=0;i<strlen(vFirst);i++)  
  printf(" %c",vFirst[i]);  
  printf(" }\n");  
}  
int funcFirst_F(char victim){  
  int j;  
  if(!(isupper(victim)))  
    vFollow[k++]=victim;  
  for(j=0;j<n;j++){  
    if(vGram[j][0]==victim){  
      if(vGram[j][2]=='$')  
        funcFollow(vGram[j][0]);  
      else if(islower(vGram[j][2]))  
        vFollow[k++]=vGram[j][2];  
      else  
        funcFirst_F(vGram[j][2]);  
    }  
  }  
}  
int funcFollow(char victim){  
  int i=0,g=0;  
  if(vGram[0][0]==victim)  
    vFollow[m++]='$';  
  for(i=0;i<n;i++){  
    for(j=2;j<strlen(vGram[i]); j++){  
      if(vGram[i][j]==victim){  
        if(vGram[i][j+1]!='\0')  
          funcFirst_F(vGram[i][j+1]);  
        if(vGram[i][j+1]=='\0' && victim!=vGram[1][0])  
          funcFollow(vGram[i][0]);  
      }  
    }  
  }  
  printf("\n{ ");  
  for(g=0;g<strlen(vFollow);g++)  
    printf(" %c",vFollow[g]);  
  printf(" }\n");  
  }  
int main(){  
  printf("\nProgram contains bug in Follow Module. ");  
  printf("\nVisit http://www.csbeans.com/ to submit resolved one.\n\n");  
  int i,z,choice,cont=1;  
  char ch, c;  
  printf("Enter the number of production : ");  
  scanf("%d",&n);  
  printf("Enter production as 'E=AB' and '$' for null\n");  
  for(i=0;i<n;i++)  
    scanf("%s%c",vGram[i],&ch);    
  printf("Enter Victim Character : ");  
  scanf("%c",&c);  
  funcFollow(c);  

} 