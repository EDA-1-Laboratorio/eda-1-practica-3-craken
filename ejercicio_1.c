#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define total 52
#define jugadores 2

struct cartas {
	int puntaje;
	int palo;
};

void crear(struct cartas baraja[]){
	int k=0;
	for(int i=1; i<=4; i++){
		for (int j=1; j<=13; j++){
			baraja[k].puntaje= j;
			baraja[k].palo= i;
			k++;
		}
	}
}

void mezclar(struct cartas baraja[]){
	struct cartas temp;
	int j;
	for(int i=0;i<total; i++){
		j= rand() %total;
		temp = baraja[i];
		baraja[i] = baraja[j];
		baraja[j] = temp;
	}
}

void mostrar(struct cartas c){
	printf("Puntaje: %d \n Palo: %d \n", c.puntaje, c.palo);
}

int pregunta (){
	char respuesta[3];
	printf("¿Siguen el juego?\n");
	scanf("%s", respuesta);
	if(strcmp(respuesta, "si")==0 || strcmp(respuesta, "Si")==0 || strcmp(respuesta, "SI")==0){
		return 1;
	}
	else {
		return 0;
	}
}

int mano(struct cartas cartass[]) {

    int conteopuntaje[15] = {0};
    int conteopalo[5] = {0};

    for(int i = 0; i < 7; i++) {
        conteopuntaje[cartass[i].puntaje]++;
        conteopalo[cartass[i].palo]++;
    }

    int pares = 0, tercia = 0, poker = 0;
    int color = 0, escalera = 0;

    for(int i = 1; i <= 13; i++) {
        if(conteopuntaje[i] == 4) poker = 1;
        if(conteopuntaje[i] == 3) tercia = 1;
        if(conteopuntaje[i] == 2) pares++;
    }

    for(int i = 0; i < 4; i++) {
        if(conteopalo[i] >= 5)
            color = 1;
    }

    int consecutivos = 0;
    for(int i = 1; i <= 13; i++) {
        if(conteopuntaje[i] > 0) {
            consecutivos++;
            if(consecutivos >= 5)
                escalera = 1;
        } else {
            consecutivos = 0;
        }
    }

    if(conteopuntaje[10] && conteopuntaje[11] &&
       conteopuntaje[12] && conteopuntaje[13] &&
       conteopuntaje[1] && color)
        return 9;

    if(escalera && color) return 8;
    if(poker) return 7;
    if(tercia && pares) return 6;
    if(color) return 5;
    if(escalera) return 4;
    if(tercia) return 3;
    if(pares == 2) return 2;
    if(pares == 1) return 1;

    return 0;
}
int main()
{
	int i=0, in=0, g=0;
	int respuesta, resultado[jugadores];
	srand(time(NULL));
	struct cartas baraja[total];
	crear(baraja);
	mezclar(baraja);
	
	printf("Bienvenido a Texas Hold'em\n");
	struct cartas jugador[jugadores][2];
	for (i=0; i<jugadores; i++){
	printf("Las cartas del jugador %d son: \n", i+1);
		
		jugador[i][0] = baraja[in++];
		jugador[i][1] = baraja[in++];

		mostrar(jugador[i][0]);
		mostrar(jugador[i][1]);
	}
	
	respuesta= pregunta();
	if (respuesta==1){
		printf("Continuamos\n");
		printf("Las nuevas cartas son: \n");
		struct cartas mesa[5];
		mesa[0] = baraja[in++];
		mesa[1] = baraja[in++];
		mesa[2] = baraja[in++];
		mostrar(mesa[0]);
		mostrar(mesa[1]);
		mostrar(mesa[2]);
		respuesta= pregunta();
		if(respuesta==1){
			printf("Continuamos\n");
			printf("La nueva carta es: \n");
			mesa[3] = baraja[in++];
			mostrar(mesa[3]);
			respuesta= pregunta();
			if(respuesta==1){
				printf("Continuamos\n");
				printf("La nueva carta es: \n");
				mesa[4] = baraja[in++];
				mostrar(mesa[4]);
				for (i=0; i<jugadores; i++) {
					struct cartas totalcartas[7];
					totalcartas[0] = jugador[i][0];
					totalcartas[1] = jugador[i][1];

					for(int k=0; k<5; k++){
						totalcartas[k+2] = mesa[k];
					}

				resultado[i] = mano(totalcartas);
				}
				for(i=1;i<jugadores;i++){
					if (resultado[i]>resultado[g]){
						g=i;
					}
				}
				printf("El ganador es el jugador %d", g+1);
			}
			else {
				printf("El juego acabó");
			}
		}
		else {
			printf("El juego acabó");
		}
	}
	else {
		printf("El juego acabó");
	}
}

