#include <stdio.h>
#include <math.h>

struct circunferencia{
    float X; 
    float Y;
    float radio;
};

void Interseccion(struct circunferencia circ1, struct circunferencia circ2){
    float distanciaX;
    float distanciaY;
    distanciaX= circ2.X - circ1.X;
    distanciaY= circ2.Y - circ1.Y;
    
    float dist_centro=sqrt(pow(distanciaX, 2) + pow(distanciaY, 2));
    
    if(dist_centro>fabs(circ2.radio-circ1.radio) && dist_centro<circ2.radio+circ1.radio){
        printf("\nLas dos circunferencias se intersectan dos veces");
    } else if(dist_centro==circ2.radio+circ1.radio){
        printf("\nLas dos cicunferencias se intersectan una vez");
    }else{
        printf("\nLas circunferencias no se intersectan");
    }
    
}

int main()
{
    struct circunferencia C1, C2;
    printf("----Intersección de circunferencias----\n");
    
    printf("\nPara la circunferencia 1:\n");
    printf("Coordenada X del centro: ");
    scanf("%f", &C1.X);
    printf("Coordenada Y del centro: ");
    scanf("%f", &C1.Y);
    printf("Radio: ");
    scanf("%f", &C1.radio);
    
    printf("\nPara la circunferencia 2:\n");
    printf("Coordenada X del centro: ");
    scanf("%f", &C2.X);
    printf("Coordenada Y del centro: ");
    scanf("%f", &C2.Y);
    printf("Radio: ");
    scanf("%f", &C2.radio);
    
    if(C1.radio<=0 || C2.radio<=0){
        printf("\nEl valor del radio debe ser positivo");
        return 1;
    }
    
    Interseccion(C1, C2);
    
    return 0;
}
