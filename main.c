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
    char apellido[25];
    char nCompleto[50];
    int diaNac = 0;
    int prod = 0;
    int ret = 0; 
    int ret1 = 0;
    int marca = 0;
    float precio = 0;
    int cantidad = 0;
    int i=0;
    float talle=0;
    int nroPedido = 0;
    float impRecibido=0;
    float total =0 ;
    float descuentos =0;
    float vuelto =0;

    do{       
        printf("¿Desea comenzar a atender? Ingrese SI o NO\n");
        scanf("%s",respuesta);    

        ret = strncmp("SI",respuesta,2);
        ret1 = strncmp("NO",respuesta,2);             

        if(ret!=0 && ret1!=0){
            printf("Respuesta incorrecta. Solo se admite SI o NO. Intente Nuevamente.\n \n");   
        }

    }while(ret==0 && ret1==0);



    ret = strncmp("SI",respuesta,2);
    //VERIFICAR
    //strcomp() no tiene en cuenta mayusculas ni minusculas
    while(ret==0){

    	nroPedido = 0;
        system("clear");
        printf("Ingrese Nombre del cliente :\n");
        scanf("%s",nombre);
        
        
        printf("\nIngrese Apellido del cliente :\n");
        scanf("%s",apellido);
           
        strcat(nombre," ");
        strcat(nombre,apellido);

        printf("\nIngrese dia de nacimiento :\n");
        scanf("%i",&diaNac);

        system("clear");

        do{
        	nroPedido++;
            system("clear");
            printf("Pedido Nº %d de %s \n \n",nroPedido,nombre);

            printf("Seleccione el Producto a comprar \n1.Zapatillas \n2.Botines \n3.Zapatos\n");
            scanf("%d",&prod);

            system("clear");
            printf("Pedido Nº %d de %s \n \n",nroPedido,nombre);
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
            printf("Pedido Nº %d de %s \n \n",nroPedido,nombre);

            do{
                printf("Ingrese la cantidad de pares a adquirir\n");
                scanf("%d",&cantidad);
                
                if(cantidad<=0){
                    printf("La cantidad ingresada es incorrecta! Intente nuevamente. \n");
                }
            }while (cantidad<0);
                
            //printf("Ingrese la cantidad de pares a adquirir\n");
            //scanf("%d",&cantidad);

            system("clear");
            //printf("Pedido Nº %d de %s \n \n",nroPedido,nombre);
            for(i=0;i<cantidad;i++){
                printf("Pedido Nº %d de %s \n \n",nroPedido,nombre);
                printf("ingrese el talle para el par nº %d \n",i+1);
                scanf("%f",&talle);

                if(talle>44){
                    precio = precio * 1.10;
                }
                system("clear");
            }

            do{       
		        printf("¿Desea seguir comprando para el cliente %s? Ingrese SI o NO\n",nombre);
		        scanf("%s",respuesta);    

		        ret = strncmp("SI",respuesta,2);
		        ret1 = strncmp("NO",respuesta,2);             

		        if(ret!=0 && ret1!=0){
		            printf("Respuesta incorrecta. Solo se admite SI o NO. Intente Nuevamente.\n \n");   
		        }

		    }while(ret==0 && ret1==0);

            ret = strncmp("SI",respuesta,2);
            // SI == 0
            // NO != 0
        }while(ret==0);
        //SI PONE QUE NO DESEA SEGUIR ATENDIENDO A EL CLIENTE ACTUAL MUESTRO LOS TOTALES        

        printf("*********************************************************************\n");
        printf("\n");
        printf(" PEDIDO DE %s \n", nombre);
        printf("\n");
        printf("IMPORTE ****************************************************** %-3.2f \n",precio);
        printf("\n");
        printf("DESCUENTOS *************************************************** %-3.2f \n",descuentos);
        printf("\n");
        total = precio - descuentos;
        printf("TOTAL ******************************************************** %-3.2f \n",total); 
        printf("\n");
        printf("*********************************************************************\n");

        printf("Ingrese importe recibido \n");
        scanf("%f",&impRecibido);

        vuelto = (impRecibido - total);

        printf("El vuelto es %-3.2f \n",vuelto);

        //system("clear");
        
        do{       
	        printf("¿Desea seguir atendiendo? Ingrese SI o NO\n");
	        scanf("%s",respuesta);    

	        ret = strncmp("SI",respuesta,2);
	        ret1 = strncmp("NO",respuesta,2);             

	        if(ret!=0 && ret1!=0){
	            printf("Respuesta incorrecta. Solo se admite SI o NO. Intente Nuevamente.\n \n");   
	        }

		}while(ret==0 && ret1==0);

        ret = strncmp("SI",respuesta,2);

    }

    return 0;

}
