#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mProductos(); //Aqui devolvemos el codigo de producto para saber que menu de marcas mostrar
float mMarcas(int); //Aqui establecemos el precio base del producto
int mostrarPedido(); //Para mostrar el numero de pedido y nombre de cliente
int mostrarMP(); //Para mostrar los medios de pago
float descuentoDia(int); //Calcual si tiene descuento promocion por dia de nacimiento

//Variables Globales
char nombre[25];
int nroPedido = 0;
float descuentos = 0;
float recargos = 0;
float precio = 0;
int cZapatos=0;
int cZapatillas=0;
int cBotines=0;

int main(){
    char respuesta[2];
    char apellido[25];
    char nCompleto[50];
    int diaNac = 0;
    int prod = 0;
    int ret = 0; 
    int ret1 = 0;
    int cantidad = 0;
    int i=0;
    float talle=0;
    float impRecibido=0;
    float total =0 ;
    float vuelto =0;
    float totZapatos=0;
    float totZapatillas=0;
    float totBotines=0;
    float totFinal=0;
    

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

        nroPedido++;

        do{
        	
            mostrarPedido();
        	prod = mProductos();    

            mostrarPedido();
            mMarcas(prod);
         
            mostrarPedido();
            do{
                printf("Ingrese la cantidad de pares a adquirir\n");
                scanf("%d",&cantidad);
                
                if(cantidad<=0){
                    printf("La cantidad ingresada es incorrecta! Intente nuevamente. \n");
                }
            }while (cantidad<0);
                
            for(i=0;i<cantidad;i++){
                mostrarPedido();
                printf("ingrese el talle para el par nº %d \n",i+1);
                scanf("%f",&talle);

                if(talle>44){
                    //precio = precio * 1.10;
                    recargos+= (10*precio) /100;
                }
            }

            system("clear");
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
        //SI PONE QUE NO DESEA SEGUIR ATENDIENDO A EL CLIENTE ACTUAL PREGUNTO MEDIOS DE PAGO    
        mostrarPedido();

        descuentoDia(diaNac);
        mostrarMP();

        system("clear");
        printf("*********************************************************************\n");
        printf("\n");
        printf("PEDIDO DE %s \n", nombre);
        printf("\n");
        printf("IMPORTE ****************************************************** %-3.2f \n",precio);
        printf("\n");
        printf("DESCUENTOS *************************************************** %-3.2f \n",descuentos);
        printf("\n");
		printf("RECARGO ****************************************************** %-3.2f \n",recargos);
        printf("\n");        
        total = (precio - descuentos) + recargos;
        printf("TOTAL ******************************************************** %-3.2f \n",total); 
        printf("\n");
        printf("*********************************************************************\n \n");

        printf("Ingrese importe recibido \n");
        scanf("%f",&impRecibido);

        totFinal+=total; 
        vuelto = (impRecibido - total);

        printf("El vuelto es %-3.2f \n \n",vuelto);


        precio=0;
        recargos=0;
        descuentos=0;
        total=0;
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

    //Muestro cierre de día
    //Total recaudado
    //Total recaudado por producto
    //Producto que más se vendio
    //Total de Zapatillas, Zapatos y Botines vendidos

    system("clear");
    printf("Total cantidad vendida de Zapatillas : %d \n", cZapatillas);
    printf("Total cantidad vendida de Zapatos : %d \n", cZapatos);
    printf("Total cantidad vendida de cBotines : %d \n", cBotines);

    printf("Total recaudado : %-3.2f \n",totFinal); 


    return 0;

}

float descuentoDia(int dia){
	//Si nacio entre el 11 y el 20 tiene 5% de descuento
	if(dia>10 && dia<=20){
		descuentos+=(5*precio) /100;
	}
}

int mostrarMP(){

	int opcion=0;

	printf("Seleccione el Medio de Pago \n1) Efectivo \n2) Tarjeta de Crédito\n");
    scanf("%d",&opcion);
    system("clear");
    if(opcion==2){
    	//Es Tarjeta
    	printf("Ingrese cantidad de cuotas : \n1) 3 Cuotas (Sin interés) \n2) 6 Cuotas (10%% de interés) \n3) 12 Cuotas (20%% de interés)\n");
    	scanf("%d",&opcion);

    	switch(opcion){
    		case 2: recargos+=(10*precio) /100; break;
    		case 3: recargos+=(20*precio) /100; break;
    	}
    }

}

int mostrarPedido(){
	system("clear");
	printf("Pedido Nº %d de %s \n \n",nroPedido,nombre);
}

int mProductos(){
	int opcion=0;

	printf("Seleccione el Producto a comprar \n1) Zapatillas \n2) Botines \n3) Zapatos\n");
    scanf("%d",&opcion);

	return opcion;

}

float mMarcas(int menu){
	float precioB = 0;
	int marca = 0;

	switch(menu){
        case 1:
        	cZapatillas++;      
            printf("Seleccione Marca de la Zapatilla \n1) Nike \n2) Adadis \n3) New Balance\n");
            scanf("%d",&marca);
            switch(marca){
                case 1: precioB=800; break;
                case 2: precioB=900; break;
                case 3: precioB=1200; break;
            }
            break;
        case 2:
        	cBotines++;
            printf("Seleccione Marca de los Botines \n1) Topper \n2) Nike \n3) Adidas\n");
            scanf("%d",&marca);
            switch(marca){
                case 1: precioB=1200; break;
                case 2: precioB=2100; break;
                case 3: precioB=1800; break;
            }
            break;
        case 3:
        	cZapatos++;
            printf("Seleccione Marca de los Zapatos \n1) Topper \n2) Nike \n3) Adidas\n");
            scanf("%d",&marca);
            switch(marca){
                case 1: precioB=2200; break;
                case 2: precioB=3100; break;
                case 3: precioB=2800; break;
            }
            break;
    }
    precio+= precioB;
    //return precio;
}
