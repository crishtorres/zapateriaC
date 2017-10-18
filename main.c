#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mProductos();               //Aqui devolvemos el codigo de producto para saber que menu de marcas mostrar
float mMarcas(int);             //Aqui establecemos el precio base del producto
int mostrarPedido();            //Para mostrar el numero de pedido y nombre de cliente
int mostrarMP();                //Para mostrar los medios de pago
float descuentoDia(int);        //Calcula si tiene descuento promocion por dia de nacimiento
int borrarPantalla();           //Para Borrar la pantalla
int sumaCantidades(int,int);    //Va acumulando las cantidades vendidas por producto y marca

//Variables Globales
char nCompleto[50];
int nroPedido = 0;
float descuentos = 0;
float recargos = 0;
float precio = 0;
int cZapatos=0;
int cZapatillas=0;
int cBotines=0;
int zNike=0;
int zAdidas=0;
int zNbalance=0;
int bTopper=0;
int bUmbro=0;
int bDiadora=0;
int zaTimberland=0;
int zaCat=0;
int zaMerrell=0;
int marcaSel=0;
float totDescuentos=0;

int main(){

    char respuesta[2];
    char apellido[25];
    char nombre[25];
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
    float recTalle=0;
    int mpSelecionado =0;
    float pLocal=0;

    do{

        printf("¿Desea comenzar a atender? Ingrese SI o NO\n");
        fflush(stdin);
        scanf("%s",respuesta);

        ret = strncmp("SI",respuesta,2);
        ret1 = strncmp("NO",respuesta,2);

        if(ret!=0 && ret1!=0){
            printf("Respuesta incorrecta. Solo se admite SI o NO. Intente Nuevamente.\n \n");
        }

    }while(ret==0 && ret1==0);

    ret = strcmp("SI",respuesta);

    nroPedido = 0;

    while(ret==0){

        borrarPantalla();
        strcpy(nCompleto,"");

        printf("Ingrese Nombre del cliente :\n");
        fflush(stdin);
        scanf("%s",nombre);

        printf("\nIngrese Apellido del cliente :\n");
        fflush(stdin);
        scanf("%s",apellido);

        strcat(nombre," ");
        strcat(nCompleto,nombre);
        strcat(nCompleto,apellido);

        printf("\nIngrese dia de nacimiento :\n");
        fflush(stdin);
        scanf("%i",&diaNac);

        nroPedido++;

        do{
            mostrarPedido();
        	prod = mProductos();
            mostrarPedido();
            pLocal = mMarcas(prod);

            mostrarPedido();

            do{

                printf("Ingrese la cantidad de pares a adquirir\n");
                fflush(stdin);
                scanf("%d",&cantidad);

                if(cantidad<=0){
                    printf("La cantidad ingresada es incorrecta! Intente nuevamente. \n");
                }

            }while (cantidad<0);

            for(i=0;i<cantidad;i++){

                mostrarPedido();

                printf("Ingrese el talle para el par nº %d \n",i+1);
                fflush(stdin);
                scanf("%f",&talle);

                if(talle>44){
                    recTalle+= (10*pLocal) /100;
                }
            }

            pLocal=pLocal * cantidad;
            pLocal +=recTalle;

            precio+=pLocal;
            switch(prod){
            	case 1: cZapatillas+=cantidad; totZapatillas+=pLocal; break;
            	case 2: cBotines+=cantidad; totBotines+=pLocal; break;
            	case 3: cZapatos+=cantidad; totZapatos+=pLocal; break;
            }

            sumaCantidades(prod, cantidad);

            pLocal=0;
            recTalle=0;

            mostrarPedido();

            do{

		        printf("¿Desea seguir comprando para el cliente %s? Ingrese SI o NO\n",nCompleto);
		        fflush(stdin);
		        scanf("%s",respuesta);

		        ret = strncmp("SI",respuesta,2);
		        ret1 = strncmp("NO",respuesta,2);

		        if(ret!=0 && ret1!=0){
		            printf("Respuesta incorrecta. Solo se admite SI o NO. Intente Nuevamente.\n \n");
		        }

		    }while(ret==0 && ret1==0);

            ret = strncmp("SI",respuesta,2);
        }while(ret==0);

        mostrarPedido();
        descuentoDia(diaNac);
        mpSelecionado = mostrarMP();
        borrarPantalla();

        printf ("\n\n\t\t\t\t*********************");
        printf ("\n\n\t\t\t\t MUNDO DEPORTIVO GG");
        printf ("\n\n\t\t\t\t*********************\n\n");

        printf("*********************************************************************\n");
        printf("\n");
        printf("PEDIDO DE %s \n", nCompleto);
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

        if(mpSelecionado==1){
        	do{
        		printf("Ingrese importe recibido \n");
	        	scanf("%f",&impRecibido);

	        	if(impRecibido<total){
		            printf("El dinero recibido es menor al importe total. Ingrese nuevamente\n \n");

		        }
        	}while(impRecibido<total);

	        vuelto = (impRecibido - total);

	        printf("El vuelto es %-3.2f \n \n",vuelto);
        }
		//Total recaudado
		totFinal+=total;

        precio=0;
        recargos=0;
        totDescuentos+=descuentos;
        descuentos=0;
        total=0;
        recTalle=0;
        cantidad=0; mpSelecionado=0;
        marcaSel=0;

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

    //Cierre de día

    borrarPantalla();
    printf ("\n\n\t\t\t\t*********************");
    printf ("\n\n\t\t\t\t MUNDO DEPORTIVO GG");
    printf ("\n\n\t\t\t\t*********************\n\n");

    printf("Total cantidad vendida de Zapatillas : %d ($ %-3.2f)\n", cZapatillas,totZapatillas);
    printf("Total cantidad vendida de Zapatos : %d ($ %-3.2f)\n", cZapatos,totZapatos);
    printf("Total cantidad vendida de Botines : %d ($ %-3.2f)\n", cBotines,totBotines);

    printf("\nSe detalla de la siguiente manera:\nZapatillas:\n\tNike: %i\n\tAdidas: %i\n\tNew Balance: %i\nZapatos:\n\tTimberland: %i\n\tCAT: %i\n\tMerrell: %i\nBotines:\n\tTopper: %i\n\tUmbro: %i\n\tDiadora: %i\n",zNike,zAdidas,zNbalance,zaTimberland,zaCat,zaMerrell,bTopper,bUmbro,bDiadora);

    printf("\nTotal descuentos efectuados : %-3.2f \n",totDescuentos);
    printf("Total recaudado : %-3.2f \n",totFinal);


    return 0;
}

float descuentoDia(int dia){
	//Si nacio entre el 11 y el 20 tiene 5% de descuento
	if(dia>10 && dia<=20){
		descuentos+=(5*precio) /100;
	}

	return (descuentos);
}


int mostrarMP(){

	int opcion=0;
	int opcionSel=0;

	printf("Total a pagar $ %-3.2f \n\n",precio);

	do{
		printf("Seleccione el Medio de Pago \n1) Efectivo \n2) Tarjeta de Crédito\n");
    	scanf("%d",&opcionSel);

	    if(opcionSel!=1 || opcionSel!=2){
        	borrarPantalla();
            printf("Respuesta incorrecta. Intente Nuevamente.\n \n");
        }
	}while(opcionSel!=1 && opcionSel!=2);

    borrarPantalla();

    if(opcionSel==2){
    	//Es Tarjeta
    	do{
			printf("Ingrese cantidad de cuotas : \n1) 3 Cuotas (Sin interés) \n2) 6 Cuotas (10%% de interés) \n3) 12 Cuotas (20%% de interés)\n");
    		scanf("%d",&opcion);

		    if(opcion!=1 || opcion!=2 || opcion!=3){
	        	borrarPantalla();
	            printf("Respuesta incorrecta. Intente Nuevamente.\n \n");
	        }
		}while(opcion!=1 && opcion!=2 && opcion!=3);

    	switch(opcion){
    		case 2: recargos+=(10*precio) /100; break;
    		case 3: recargos+=(20*precio) /100; break;
    	}
    }

    return opcionSel;
}

int mostrarPedido(){

	borrarPantalla();
    printf ("\n\n\t\t\t\t*********************");
	printf ("\n\n\t\t\t\t MUNDO DEPORTIVO GG");
	printf ("\n\n\t\t\t\t*********************\n\n");
	printf("Pedido Nº %d de %s ($ %-3.2f)\n \n",nroPedido,nCompleto,precio);
}

int mProductos(){

	int opcion=0;

	do{

		printf("Seleccione el Producto a comprar \n1) Zapatillas \n2) Botines \n3) Zapatos\n");
	    scanf("%d",&opcion);

	    if(opcion!=1 || opcion!=2 || opcion!=3){
        	borrarPantalla();

            printf("Respuesta incorrecta. Intente Nuevamente.\n \n");
        }
	}while(opcion!=1 && opcion!=2 && opcion!=3);

	return opcion;
}

float mMarcas(int menu){

	float precioB = 0;
	int marca = 0;

	switch(menu){

        case 1:
        	do{
            	printf("Seleccione Marca de la Zapatilla \n1) Nike \n2) Adidas \n3) New Balance\n");
            	scanf("%d",&marca);

		        if(marca!=1 || marca!=2 || marca!=3){

		        	system("cls");
		            printf("Respuesta incorrecta. Intente Nuevamente.\n \n");
		        }
			}while(marca!=1 && marca!=2 && marca!=3);

            switch(marca){
                case 1: precioB=1200; break;
                case 2: precioB=1300; break;
                case 3: precioB=1900; break;
            }
            break;

        case 2:
        	do{
	            printf("Seleccione Marca de los Botines \n1) Topper \n2) Umbro \n3) Diadora\n");
	            scanf("%d",&marca);

            	if(marca!=1 || marca!=2 || marca!=3){

		        	system("cls");
		            printf("Respuesta incorrecta. Intente Nuevamente.\n \n");
		        }
			}while(marca!=1 && marca!=2 && marca!=3);

            switch(marca){
                case 1: precioB=1600; break;
                case 2: precioB=1900; break;
                case 3: precioB=2500; break;
            }
            break;
        case 3:
        	do{
	            printf("Seleccione Marca de los Zapatos \n1) Timberland \n2) CAT \n3) Merrell\n");
	            scanf("%d",&marca);

	            if(marca!=1 || marca!=2 || marca!=3){

		        	borrarPantalla();
		            printf("Respuesta incorrecta. Intente Nuevamente.\n \n");
		        }
			}while(marca!=1 && marca!=2 && marca!=3);

            switch(marca){
                case 1: precioB=3500; break;
                case 2: precioB=3100; break;
                case 3: precioB=2800; break;
            }
            break;
    }

    marcaSel=marca;
    //precio+= precioB;

    return precioB;
}

int sumaCantidades(int prod,int cant){

    switch(prod){
        case 1:
            switch(marcaSel){
                case 1: zNike+=cant; break;
                case 2:  zAdidas+=cant; break;
                case 3:  zNbalance+=cant; break;
            }
            break;
        case 2:
            switch(marcaSel){
                case 1: bTopper+=cant; break;
                case 2: bUmbro+=cant; break;
                case 3: bDiadora+=cant; break;
            }
            break;
        case 3:
            switch(marcaSel){
                case 1: zaTimberland+=cant; break;
                case 2: zaCat+=cant; break;
                case 3: zaMerrell+=cant; break;
            }
            break;
    }
}

int borrarPantalla(){
	system("clear");
}
