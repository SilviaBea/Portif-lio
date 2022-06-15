#include <stdio.h>
int main(){
    int m=1,n=1,o,p,soma;
    do {
        p=0;
        scanf("%i %i",&m,&n);
        if (m<=0||n<=0) break;
        if (m>n){
            m+=n;
            n=m-n;
            m-=n;
        }
        for (o=m;o<=n;o++){
            p+=o;
        }
        soma = m+n+o+p;
        printf("%d %d %d %d Sum=%d",m,n,o,p,soma);
    } while (1);
    
    
    return 0;
}
