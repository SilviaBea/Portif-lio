#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    do{
    	int contador;
		int invalido = 0;
    	float num1,num2,resultado; //num1 e num2 vão ser os valores digitados pelo usuário e resultado a resposta de algo relacionado a num1 e num2
    	char oper, continuar; //oper vai ser o caracter que vai ser relacionado posteriormente para executar as operações
        contador++;
        printf("Digite a expressão: "); //mensagem exibida ao usuário quando executar o programa
        scanf("%f %c %f",&num1,&oper,&num2); //valores de entrada recebidos e armazenados nas variáveis correspondentes
        if(oper == '+'){ //A logica utilizada para o operador " + " é a mesma para os demais, se o caracter for igual aos símbolos das operações, então ele vai executar a operação informada
            resultado=num1+num2; //resultado é o que vai ser mostrado para o usuário no printf como resultado das operações.
        }else if(oper == '-'){ //O mesmo vale para o operador " - "
            resultado=num1-num2;
        }else if(oper ==  '/'){ //O mesmo vale para o operador "\\"
            resultado=num1/num2;
        }else if(oper == '*' || oper == 'x'){ //No caso do operador de multiplicação, conforme o enunciado,a calculadora deve reconhecer * e x, logo se o operador for igual a * ou x, deve-se executar uma multiplicação
            resultado=num1*num2;
        }else if(oper == '^'){ //O mesmo vale para a potenciação
            resultado=pow(num1,num2);
        }else{
        	invalido = 1;
            if(contador != 0){
                contador --;
            }
            printf("Operador inválido"); //Se o usuário digitar qualquer caracter diferente dos mencionados nos if/else a resposta será de operador invalido.
        }
        if(invalido == 0){
        	int converterInteiro = resultado;
            float resto = resultado - converterInteiro; 
            if(resto != 0.00){
            	 printf("Resultado: %.2f",resultado);
			}else{
				 printf("Resultado: %.f",resultado);
			}
		}
		while(1){
			printf("\nVocê deseja seja digitar outra expressão (s/n)? ");
        	scanf(" %c",&continuar);
        	if(continuar == 's' || continuar == 'S' || continuar == 'n' || continuar == 'N'){
        		break;
			}
		}
        if(continuar == 'n' || continuar == 'N'){
        	printf("\n\nForam calculadas %d expressões válidas.\nTchau!",contador);
        	break;
        }
    }while(1);
return 0;
}