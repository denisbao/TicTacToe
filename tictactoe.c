#include<stdio.h>

main()
{
	int velha[3][3];		//Matriz Orientação: com o número das posições;
	char velhac[3][3];		//Matriz Jogo: com as jogadas X ou O;
	char valor1=' '; 		//inicializa a matriz com as jogadas em branco;
	int inicio=0; 			//armazena escolha de novo jogo ou sair do programa;
	int l, c, p; 			//contadores (linhas, colunas e players);
	int jogada;				//Armazena a jogada;
	int vencedor1=0;		//Define a vitório do jogador 1;
	int vencedor2=0; 		//Define a vitória do jogador 2;
	int ver_empate=0;		//Contador para verificação de empate;
	int empate=0;			//Define o empate;
	int putz=0, putz2=0;	//Contador para exibição de erro ao jogada uma posição já ocupada;
	int cont_p1=0;			//Contador de vitórias do jogador 1;
	int cont_p2=0;			//contador de vitórias do jogador 2;
	int cont_em=0;			//contador de empates;
	int cont_tot=0;			//contador de partidas;
	int n;					//contador para retorno ao Novo jogo;
	printf("\n");  
	printf("  ##   ###     ###    ####      #####     ###    ##  ##  ### ##   ##  ##   ### \n");             
	printf("  ##  #####   ####   ######     ######   #####   ##  ## #### ##   ##  ##  #####\n");              
	printf("  ## #######  ####   #######    ####### ######   ##  ## #### ##   ##  ## ######\n");             
    printf("  ## ##   ##  ##     ##   ##    ##   ## ##  ##   ##  ## ##   ##   ##  ## ##  ##\n");             
	printf("  ## ##   ##  ##     ##   ##    ##   ## ##  ##   ##  ## #### ##   ###### ##  ##\n");             
	printf("  ## ##   ##  ##  ## ##   ##    ##   ## ##  ##   ##  ## #### ##   ###### ##  ##\n");             
	printf("  ## ##   ##  ## ### ##   ##    ##   ## ######   ##  ## ##   ##   ##  ## ######\n");             
	printf(" ### #######  ###### #######    ## #### ##  ##   ##  ## #### ##   ##  ## ##  ##\n");             
	printf(" ### ######   #####  ######     ######  ##  ##    #  #  #### #### ##  ## ##  ##\n");             
	printf(" ##   ####    ####   ####       #####   ##  ##     ##   ###  ###  ##  ## ##  ##\n");   
	printf("\n\n\n");
	printf("                                  Novo jogo [1]");
	printf("\n\n");
	printf("                                    Sair [2]");
	do{ //loop para definição de Novo Jogo ou Sair.
		scanf("%i", &inicio);
		fflush(stdin);
		if(inicio==2){	//Encerra o programa.
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tOBRIGADO POR JOGAR\n\n\n\n\n\n\n\n\n\n\n");
		return(0);
		}
		if(inicio!=1 && inicio!=2){	//Exibe msg de erro.
			printf("\n\n\t\t  Escolha [1] para Novo Jogo ou [2] para Sair");
		}
		if(inicio==1){ //Limpa a tela e rompe o laço, iniciando a partida.
			system("cls");
		}
	}while(inicio!=1);	
//------------------------------------------------------------------------------------------------------------------ ((INICIALIZAÇÃO DA MATRIZ ORIENTAÇÃO))
	for(n=1; n<=2; n++){ //Retorna ao início do jogo se a opção Novo Jogo for escolhida no Menu Final ou no Menu Placar.
		for (l=0; l<3; l++) {
			for(c=0; c<3; c++) {			//Foi somado um valor ao contador para que a sequencia numérica 
				if(l==0){					//coincidisse com a do teclado alfanumérico.
					velha[l][c]=c+7;				
				}									
				if(l==1){							
					velha[l][c]=c+4;
				}
				if(l==2){
					velha[l][c]=c+1;
				}
			}
		}
	//------------------------------------------------------------------------------------------------------------------ ((INICIALIZAÇÃO DA MATRIZ JOGO))
		for (l=0; l<3; l++) {
			for(c=0; c<3; c++) {
				velhac[l][c]=valor1;
			}
		}	
	//--------------------------------------------------------------------------------------------------------------------------------- (((JOGADAS)))
		do{
			for(p=1; p<3; p++){	//Alterna entre jogador1 e jogador2.
				printf("\n\n");
	//------------------------------------------------------------------------------------------ Exibe a matriz orientação
				for (l=0; l<3; l++) {
					for(c=0; c<3; c++) {
						if(c==0){
							printf("\t\t\t\t\t\t      %i | ", velha[l][c]);
						}
						if(c==1){
							printf("%i | ", velha[l][c]);
						}
						if(c==2){
							printf("%i ", velha[l][c]);
						}	
					}
					printf("\n");
					if(l<2){
						printf("\t\t\t\t\t\t      --+---+--\n");
					}
					else{
					}
				}
				printf("\n\t\t\t\t\t        Posicoes Disponiveis\n");
	//------------------------------------------------------------------------------------------ Exibe a matriz jogo
				printf("\t\t#####################\n ");
				printf("\t\t##                 ##\t\t      Sair [0]\n");
				for (l=0; l<3; l++) {
					for(c=0; c<3; c++) {
						if(c==0){
						printf("\t\t##    %c | ", velhac[l][c]);
						}
						if(c==1){
							printf("%c | ", velhac[l][c]);
						}
						if(c==2){
							printf("%c    ##", velhac[l][c]);
						}	
					}
					printf("\n");
					if(l<2){
						printf("\t\t##   ---+---+---   ##\n");
					}
					else{
					}
				}
	//------------------------------------------------------------------------------------------ Entrada da jogada e medidas preventivas
				printf("\t\t##                 ##\t\t      JOGADOR %i: ", p);
				printf("\n");
				printf("\t\t#####################\n  ");
				printf("\t\t\t\t\t\t Escolha sua jogada:");
				if(putz==1){	//Exibe a msg de erro caso a entrada anterior tenha sido inválida.
					printf(" \n\n\t\t    !! ATENCAO !!\n\n     Esta posicao ja esta ocupada, jogue novamente\n");
					putz=0;
				}
				if(putz2==1){	//Exibe a msg de erro caso a entrada anterior tenha sido inválida.
					printf(" \n\n\t\t    !! ATENCAO !!\n\n     Esta posicao nao existe, jogue novamente\n");
					putz2=0;	
				}		
				scanf("%i", &jogada);
				if(jogada==0){	//Encerra o programa.
					system("cls");
					printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tOBRIGADO POR JOGAR\n\n\n\n\n\n\n\n\n\n\n");
					return(0);
				}
	//------------------------------------------------------------------------------------------ Armazenagem da jogada na matriz jogo
				for (l=0; l<3; l++) {
					for(c=0; c<3; c++) {
						if(jogada==velha[l][c]){
							if(velhac[l][c]=='X' || velhac[l][c]=='O'){	//Erro - Jogada em posição já ocupada:
								putz=1;									//Retorna a exibição das matrizes e a entrada da jogada para o mesmo jogador, 
								p--;									//alterando o valor da variável "putz" para exibição da msg de erro.
								system("cls");					
							}
							else{ //Marca a jogada.
								if(p==1){
									velhac[l][c]='X';
								}
								if(p==2){
									velhac[l][c]='O';
								}
								system("cls");
							}
						}
					}
				}
				if(jogada<=0 || jogada>=10){ //Erro - Jogada em posição inexistente:
					putz2=1;				 //Retorna a exibição das matrizes e a entrada da jogada para o mesmo jogador,  
					p--;					 //alterando o valor da	variável "putz2" para exibição da msg de erro.
					system("cls");
				}
	//------------------------------------------------------------------------------------------------------------------ ((VERIFICAÇÃO DO VENCEDOR))
	//------------------------------------------------------------------------------------------ Linhas
				if (velhac[0][0]=='X'&&velhac[0][1]=='X'&&velhac[0][2]=='X'){
					vencedor1=99;
					break;
				}
				if (velhac[0][0]=='O'&&velhac[0][1]=='O'&&velhac[0][2]=='O'){
					vencedor2=99;
					break;
				}
				if (velhac[1][0]=='X'&&velhac[1][1]=='X'&&velhac[1][2]=='X'){
					vencedor1=99;
					break;
				}
				if (velhac[1][0]=='O'&&velhac[1][1]=='O'&&velhac[1][2]=='O'){
					vencedor2=99;
					break;
				}
				if (velhac[2][0]=='X'&&velhac[2][1]=='X'&&velhac[2][2]=='X'){
					vencedor1=99;
					break;
				}
				if (velhac[2][0]=='O'&&velhac[2][1]=='O'&&velhac[2][2]=='O'){
					vencedor2=99;
					break;
				}
	//------------------------------------------------------------------------------------------ Colunas
				if (velhac[0][0]=='X'&&velhac[1][0]=='X'&&velhac[2][0]=='X'){
					vencedor1=99;
					break;
				}
				if (velhac[0][0]=='O'&&velhac[1][0]=='O'&&velhac[2][0]=='O'){
					vencedor2=99;
					break;
				}
				if (velhac[0][1]=='X'&&velhac[1][1]=='X'&&velhac[2][1]=='X'){
					vencedor1=99;
					break;
				}
				if (velhac[0][1]=='O'&&velhac[1][1]=='O'&&velhac[2][1]=='O'){
					vencedor2=99;
					break;
				}
				if (velhac[0][2]=='X'&&velhac[1][2]=='X'&&velhac[2][2]=='X'){
					vencedor1=99;
					break;
				}
				if (velhac[0][2]=='O'&&velhac[1][2]=='O'&&velhac[2][2]=='O'){
					vencedor2=99;
					break;
				}
	//------------------------------------------------------------------------------------------ Diagonais
				if (velhac[0][0]=='X'&&velhac[1][1]=='X'&&velhac[2][2]=='X'){
					vencedor1=99;
					break;
				}
				if (velhac[0][0]=='O'&&velhac[1][1]=='O'&&velhac[2][2]=='O'){
					vencedor2=99;
					break;
				}
				if (velhac[2][0]=='X'&&velhac[1][1]=='X'&&velhac[0][2]=='X'){
					vencedor1=99;
					break;
				}
				if (velhac[2][0]=='O'&&velhac[1][1]=='O'&&velhac[0][2]=='O'){
					vencedor2=99;
					break;
				}
	//------------------------------------------------------------------------------------------ Verificação de empate
				for (l=0; l<3; l++) {
					for(c=0; c<3; c++) {
						if(velhac[l][c]=='X' || velhac[l][c]=='O'){ //Variável "ver_empate" conta o número de posições que já foram utilizadas.
							ver_empate++;
						}
					}
				}
				if(ver_empate<=8){ //Se a contagem não for igual ao total de posições disponível, a variável é zerada para a próxima passagem pelo loop.
					ver_empate=0;
				}
				if(ver_empate==9){ //Se nenhuma das condições para vitória for verdadeira e a contagem de casas utilizadas for igual ao total 
					empate=99;	   //de casas disponíveis, a variável "empate" é alterada, rompendo o laço de repetição.
					break;
				}
			}
		}while(vencedor1==0 && vencedor2==0 && empate==0);
	//------------------------------------------------------------------------------------------------------------------ ((RESULTADO DA PARTIDA))
		printf("\n\n");
	    printf("         ##### ## ###   ###   #####  ######      ## ###### ####### ######\n");                                                                          
	    printf("         ##    ##  ##   ###   ##  ## ##  ##      ## ##  ## ##  ### ##  ##\n");                                                                        
	    printf("         ####  ##  ### ####   ##  ## ##  ##      ## ##  ## ##      ##  ##\n");                                                                          
	    printf("         ##    ##  ### ####   ##  ## ##  ##      ## ##  ## ## #### ##  ##\n");                                                                          
	    printf("         ##    ##  # ### ##   ##  ## ##  ##  ##  ## ##  ## ##  ### ##  ##\n");                                                                          
	    printf("         ##    ##  #  #  ##   #####  ######  ###### ###### ####### ######\n");                                                                          
	    printf("\n");                                      
	//------------------------------------------------------------------------------------------ Exibe a matriz jogo com o resultado da partida                                                                                                    
		printf("\t\t\t       #####################\n ");
		printf("\t\t\t       ##                 ##\n");
		for (l=0; l<3; l++) {
			for(c=0; c<3; c++) {
				if(c==0){
				printf("\t\t\t       ##    %c | ", velhac[l][c]);
				}
				if(c==1){
					printf("%c | ", velhac[l][c]);
				}
				if(c==2){
					printf("%c    ##", velhac[l][c]);
				}	
			}
			printf("\n");
			if(l<2){
				printf("\t\t\t       ##   ---+---+---   ##\n");
			}
			else{
			}
		}
		printf("\t\t\t       ##                 ##\n");
		printf("\t\t\t       #####################\n\n  ");
	//------------------------------------------------------------------------------------------ Exibe a msg do vencedor e faz a contagem para o placar
		if(empate==99){
			printf("\t\t\t\t PARTIDA  EMPATADA ");
			cont_em++;
			cont_tot++;
		}
		if(vencedor1==99){
			printf("\t\t\t\tVENCEDOR: JOGADOR 1 ");
			cont_p1++;
			cont_tot++;
		}
		if(vencedor2==99){
			printf("\t\t\t\tVENCEDOR: JOGADOR 2 ");
			cont_p2++;
			cont_tot++;
		}
	//------------------------------------------------------------------------------------------ Exibe o Menu Final
		printf("\n\n");
		printf("\n\t\t    Nova Partida [1]    Sair [2]    Placar [3]");	
		for(l=0; l<1; l++){ //Laço de repetição para verificação de opção inválida.
			scanf("%i", &inicio);
			if(inicio==1){     //Retorna ao inicio do laço principal, em caso de Novo Jogo,
				system("cls"); //zerando todas as variáveis de verificação.
				vencedor1=0;
				vencedor2=0;
				empate=0;
				n--; 
			}
			if(inicio==2){	//Encerra o programa.
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tOBRIGADO POR JOGAR\n\n\n\n\n\n\n\n\n\n\n");
				return(0);
			}
			if(inicio!=1 && inicio!=2){ //Exibe msg de erro e retorna ao início do laço para nova escolha de opção.
				printf("\n\t\t\t          Opcao invalida");
				l--; 
			}
	//------------------------------------------------------------------------------------------ Exibe o o Placar
			if(inicio==3){
				system("cls");
				printf("\n\n");
			    printf("\t\t ######  ##       ##    #######    ##    #######\n");                                                                                                  
		        printf("\t\t ##  ##  ##      ####   ##   ##   ####   ##   ##\n");                                                                                                  
		        printf("\t\t ##  ##  ##     ######  ##       ######  ##   ##\n");                                                                                                  
		        printf("\t\t ##  ##  ##     ##  ##  ##       ##  ##  ## ####\n");                                                                                                  
		        printf("\t\t ######  ##     ##  ##  ##       ##  ##  ## ##  \n");                                                                                                  
		        printf("\t\t ##      ##     ######  ##   ##  ######  ##  ## \n");                                                                                                  
		        printf("\t\t ##      #####  ##  ##  #######  ##  ##  ##  ###\n");                                                                                                  
		        printf("\t\t ##      #####  ##  ##   #####   ##  ##   #   ##\n\n\n");                                                                                                  
				printf("\t     #######################################################\n");
				printf("\t     ##                                                   ##\n");
				printf("\t     ##       JOGADOR 1:   [%i]  X  [%i]   : JOGADOR 2      ##\n", cont_p1, cont_p2);
				printf("\t     ##                                                   ##\n");
				printf("\t     ##       Empates: [%i]   Total de Partidas: [%i]       ##\n", cont_em, cont_tot);
				printf("\t     ##                                                   ##\n");
				printf("\t     #######################################################\n\n");
				printf("\n\t\t\t  Nova Partida [1]    Sair [2]");
				for(l=0; l<1; l++){ //Laço de repetição para verificação de opção inválida.
					scanf("%i", &inicio);
					if(inicio==1){		//Retorna ao inicio do laço principal, em caso de Novo Jogo,
						system("cls");	//zerando todas as variáveis de verificação.
						vencedor1=0;
						vencedor2=0;
						empate=0;
						n--; 
					}
					if(inicio==2){	//Encerra o programa.
						system("cls");
						printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tOBRIGADO POR JOGAR\n\n\n\n\n\n\n\n\n\n\n");
						return(0);
					}
					if(inicio!=1 && inicio!=2){	//Exibe msg de erro e retorna ao início do laço para nova escolha de opção.
						printf("\n\t\t\t          Opcao invalida");
						l--; //Retorna ao início do loop para nova escolha de opção.
					}
				}
			}
		}
	}
}
