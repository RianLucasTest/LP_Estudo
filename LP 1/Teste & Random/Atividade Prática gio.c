#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main ()
{
     int teste;
     float kg , volumea , volumeq , volumeg , sa , sq , sg ;
     char tipo;
     
     fflush(stdin);
     
     sa=0;
     sq=0;
     sg=0;
     teste=1;
      
      printf("Refinaria Aparecida: Eficiencia a servico da Energia! \n Bem-vindo(a). Precisamos de algumas informacoes sobre o produto.");
      
     while (teste==1)
     {
          volumea= 0;
          volumeq=0;
          volumeg=0;
          
           printf ("\n\n Digite o peso do seu produto. \n\n");
           scanf("%f", &kg);
           
            fflush(stdin);
            
           printf ("\n\n Digite o tipo do seu produto, sendo: \n a:Alcool;\n g:Gasolina; \n q:Querosene \n\n");
           scanf(" %c", &tipo);
           
           switch (tipo)
           {
                  case 'A': case 'a':
                       {
                         volumea=1.27 * kg;
                         break;
                       }
                         
                  case 'Q': case 'q':
                       {
                         volumeq=1.22 * kg;
                         break;
                       }
           
                  case'G': case'g':
                       {
                         volumeg=1.33 * kg;
                         break;
                       }
                       
                  default:
                       {
                   printf(" \n\n Digite um tipo valido! \n\n");
                   break;   
                       }
           
           }
           
           sa+=volumea;
           sq+=volumeq;
           sg+=volumeg;
           
           printf(" \n\n Reservatorio com Alcool = %f \n\n", sa);
           printf(" \n\n Reservatorio com Gasolina = %f \n\n", sg);
           printf(" \n\n Reservatorio com Querosene = %f \n\n", sq);
           
           printf("Digite 1 para continuar \n\n");
           scanf("%d", &teste);
     }
     
          printf("Refinaria Aparecida: Eficiencia a servico da Energia! \n Volte sempre! \n\n");
           
system ("pause");
           
}
