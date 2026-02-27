
#include <stdio.h>

struct pizza {
        float precio;
        char toppings[5];
        int tamano;
};

int main () {
        float costoTotal =0, numPizzas;
        int primero = 1;
        int promosTam[4] = {0,0,0,0};
        char input;
        int toppingNum, *toppuntador, intInput; //intput :)
        struct pizza *pizzapuntador, pizzaActual, pizzas[10];

        pizzapuntador = &pizzas[0];
        do {
                pizzaActual.precio = 0.;
                do {    //ciclo while pide opcion tamaño valida
                        if (!primero) printf("\nOpcion invalida\n");
                        primero = 0;
                        printf("\nIngrese tamaño: \n(1) Chica\n(2)Mediana\n(3)Grande\n(4)Familiar \n(5)Cancelar\t");
                        scanf("%d", &intInput);
//printf("%d", intInput);
                } while (intInput>5 || intInput<1);
                pizzaActual.tamano = intInput;
                switch (intInput) {
                        case 1:
                        pizzaActual.precio += 10;
                        break;
                        case 2:
                        pizzaActual.precio += 15;
                        break;
                        case 3:
                        pizzaActual.precio += 20;
                        break;
                        case 4:
                        pizzaActual.precio += 25;
                }
                if (intInput == 5) break;
                promosTam[intInput-1] ++;
                printf("%d", intInput-1);

                primero = 1;

                toppingNum = 0;
                do {    //pedir toppings
                        if (!primero) printf("\nOpcion invalida\n");
                        primero = 1;

                        printf("\nIngrese topping deseado (en minuscula):\n (p)Pepperoni\n (h)Champiñones\n (j)Jamon");
                        printf("\n (s)Salchicha \n (c)Cebolla\n (x)Listo\t");
                        scanf (" %c", &input);

                        toppingNum ++;
                        switch (input) {
                                case 'p':
                                pizzaActual.precio += 5;
                                break;
                                case 'h':
                                pizzaActual.precio += 6;
                                break;
                                case 'j':
                                pizzaActual.precio += 4;
                                break;
                                case 's':
                                pizzaActual.precio += 7;
                                break;
                                case 'c':
                                pizzaActual.precio += 3;
                                break;
                                case 'x':
                                //toppingNum = 10;
                                break;
                                default:
                                primero = 0;
                                toppingNum --;
                        }
                        if (primero) pizzaActual.toppings[toppingNum-1] = input;
                        if (input=='x') break;
                        //printf(":%c, %c:", pizzaActual.toppings[toppingNum-1], input);
                        //printf("%d", toppingNum);
                } while (toppingNum < 5 );

                pizzapuntador->precio = pizzaActual.precio;
                pizzapuntador->tamano = pizzaActual.tamano;

                for (int i = 0; 5>i; i++) {
                //printf("|%c %d %d|", pizzaActual.toppings[i], i, pizzaActual.tamano);
                pizzapuntador->toppings[i] = pizzaActual.toppings[i];
                //printf("%c", pizzaActual.toppings[i]);
                }
                pizzapuntador++;

                printf("\nDesea ordenar otra pizza? S/N\t");
                scanf(" %c", &input);
        } while (input == 's' || input == 'S');

        printf("|%d %d %d %d|", promosTam[0], promosTam[1], promosTam[2], promosTam[3]);
        //Impresion de ticket
        numPizzas = promosTam[0]+promosTam[1]+promosTam[2]+promosTam[3];
        printf("\nTicket de compra-------------------\n");
        for (int i=(numPizzas-1); i>=0; i--) {
                //printf("%p", &pizzaActual + i);
                pizzapuntador = &pizzas[0] +i;
                //pizzapuntador = &pizzas + i;
                printf("\nPizza ");
                switch (pizzapuntador->tamano) {
                        case 1:
                        printf("Chica");
                        break;
                        case 2:
                        printf("Mediana");
                        break;
                        case 3:
                        printf("Grande");
                        break;
                        case 4:
                        printf("Familiar");
                }
                printf(".............%.2f", pizzapuntador->precio);
                if (!promosTam[pizzapuntador->tamano-1]%2) printf("---cancelado por 2x1");
                else costoTotal += pizzapuntador->precio;
                promosTam[pizzapuntador->tamano-1] --;


                for (int j=0; 5>=j; j++) {
                        //printf("%c", pizzapuntador->toppings[j]);
                        if (pizzapuntador->toppings[j] == 'x') break;
//                      printf("\n\t");
                        switch (pizzapuntador->toppings[j]) {
                                case 'p':
                                printf("\n\t-Pepperoni");
                                break;
                                case 'h':
                                printf("\n\t-Champiñones");
                                break;
                                case 'j':
                                printf("\n\t-Jamón");
                                break;
                                case 's':
                                printf("\n\t-Salchicha");
                                break;
                                case 'c':
                                printf("\n\t-Cebolla");
                                break;
                        }
                }
                printf("\n");
        }
        printf("\nTOTAL: %.2f\n", costoTotal);
}
