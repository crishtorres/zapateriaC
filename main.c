#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int promedio (float num,float num1){
    float res=0.00;

    res=(num+num1)/2;

    return(res);
}

int main(){
    char respuesta[2];
    char nombre[25];
    int diaNac = 0;
    int prod = 0;
    int ret = 0;
    int marca = 0;
    float precio = 0;
    int cantidad = 0;
    int i=0;
    float talle=0;
    
    do{       
        printf("¿Desea comenzar a atender? Ingrese SI o NO\n");
        scanf("%s",respuesta);    
        if(respuesta!="SI" && respuesta!="NO"){
            printf("Respuesta incorrecta.Solo se admite SI o NO. Presione enter para continuar\n");   
        }
    }while(respuesta!="SI" && respuesta!="NO");
    
    ret = strcmp("SI",respuesta);

    while(ret==0){

        system("clear");
        printf("Ingrese Nombre del cliente \n");
        scanf("%s",nombre);

        system("clear");
        printf("Ingrese dia de nacimiento \n");
        scanf("%i",&diaNac);

        do{
            system("clear");
            printf("Seleccione el Producto a comprar \n1.Zapatillas \n2.Botines \n3.Zapatos\n");
            scanf("%d",&prod);

            system("clear");
            switch(prod){
                case 1:
                    printf("Seleccione Marca de la Zapatilla \n1.Nike \n2.Adadis \n3.New Balance\n");
                    scanf("%d",&marca);
                    switch(marca){
                        case 1: precio=800; break;
                        case 2: precio=900; break;
                        case 3: precio=1200; break;
                    }
                    break;
                case 2:
                    printf("Seleccione Marca de los Botines \n1.Topper \n2.Nike \n3.Adidas\n");
                    scanf("%d",&marca);
                    switch(marca){
                        case 1: precio=1200; break;
                        case 2: precio=2100; break;
                        case 3: precio=1800; break;
                    }
                    break;
                case 3:
                    printf("Seleccione Marca de los Zapatos \n1.Topper \n2.Nike \n3.Adidas\n");
                    scanf("%d",&marca);
                    switch(marca){
                        case 1: precio=2200; break;
                        case 2: precio=3100; break;
                        case 3: precio=2800; break;
                    }
                    break;
            }

            system("clear");
            
            do{
                printf("Ingrese la cantidad de pares a adquirir\n");
                scanf("%d",&cantidad);
                
                if(cantidad<=0){
                    printf("La cantidad ingresada es incorrecta! Presione enter e intente nuevamente\n");
                }
            }while (cantidad!=0);
                
            //printf("Ingrese la cantidad de pares a adquirir\n");
            //scanf("%d",&cantidad);

            system("clear");
            for(i=0;i<cantidad;i++){
                printf("ingrese el talle para el par nº %d \n",i);
                scanf("%f",&talle);

                if(talle>44){
                    precio = precio * 1.10;
                }
                system("clear");
            }

            printf("Precio final %f \n",precio);

            //system("clear");
            printf("¿Desea seguir comprando? Ingrese SI o NO\n");
            scanf("%s",respuesta);
            ret = strcmp("SI",respuesta);

        }while(ret==0);

        system("clear");
        printf("¿Desea seguir atendiendo? Ingrese SI o NO\n");
        scanf("%s",respuesta);

    }

    return 0;

}
