#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>


int main(void){

	setlocale(LC_ALL, "Portuguese");
	
	int rodadas, numChutesUsu, numChutesComp,secreto,rodadasJogadas = 1, minusRange, maxRange, flag,qntvitoriasPc,qntvitoriasUsu;
	int pontosComp=0, pontosUsu=0;
	char resposta;
	printf("Digite a quantidade de rodadas desejadas: ");
	scanf("%d",&rodadas);
	
	while(rodadasJogadas <= rodadas){
		
		int tentativa = 0, numChutesUsu=0, numChutesComp=0;
		
		srand(time(0));
		secreto=rand()%21;
		
		printf("\n\nRodada %d\n",rodadasJogadas);
		
		while(1){
			printf("\n\nQual o número secreto gerado pelo computador?\nDigite um número entre 0 até 20: ");
			scanf("%d",&tentativa);
			numChutesUsu++;
			if(tentativa == secreto){
				printf("\nParabéns, você acertou em %d tentativas.\n",numChutesUsu);
				break;
			}else{
				if(tentativa > secreto){
					printf("\nErrou, o número secreto é menor. Tente novamente: ");
				}
				else{
					printf("\nErrou, o número secreto é maior. Tente novamente: ");
				}
			}
		}
		while(1){
			char pensousim;
			printf("\nPense em um número secreto entre 0 e 20. Pensou (s/n)? ");
			scanf(" %c",&pensousim);
			if(pensousim == 's'){
				break;
			}
		}
		while(1){
			
			int resto=0;
			int novoChuteResto=0;
			if(flag == 0){
				srand(time(0));
				minusRange= 1;
				maxRange=20;
				secreto= rand()%21;
				flag = 1;
			}else{
				resto= maxRange - minusRange;
				novoChuteResto = rand()%resto;
				secreto = minusRange + novoChuteResto;
			}
			numChutesComp++;
			printf("\nO número secreto é %d (s/n)? ", secreto);
			scanf(" %c",&resposta);
			if(resposta == 's'){
				printf("\nComputador acertou em %d tentativas",numChutesComp);
				flag=0;
				break;
			}else{
				printf("\nO número é maior que %d (s/n)? ", secreto);
				scanf(" %c",&resposta);
				if(resposta == 's'){
					minusRange = secreto +1;
				}
				else{
					maxRange = secreto;
				}
			}
			
		}
		if(numChutesUsu > numChutesComp){
			pontosComp++;
		}else{
			pontosUsu++;
		}
		printf("\nPlacar das rodadas:\nComputador: %d Usuário: %d",pontosComp,pontosUsu);
		rodadasJogadas++;
		
	}
	if(pontosComp>pontosUsu){
		printf("\n\nComputador Venceu\nPlacar final:\nComputador: %d Usuário: %d", pontosComp,pontosUsu);
	}else{
		printf("\n\nUsuário Venceu\nPlacar final:\nComputador: %d Usuário: %d", pontosComp,pontosUsu);
	}

	FILE *fp;
	int placarsalvoComp;
	int placarsalvoUsu;
	int somaComp=0;
	int somaUsu=0;
	fp = fopen("Historico.txt","r");
	fscanf(fp, "%d %d", &placarsalvoComp, &placarsalvoUsu);

 	somaComp = placarsalvoComp + pontosComp;
	somaUsu = placarsalvoUsu + pontosUsu;

	fp = fopen("Historico.txt","w");
	fprintf(fp,"%d %d",somaComp, somaUsu);
	printf("\nHistoricamente o computador já venceu %d rodadas e o usuário %d rodadas.",somaComp, somaUsu);
	fclose(fp);

return 0;
}