#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validar_cadena();
void imprimir_datos(char *alfabeto);
int validar_alfabeto(char *alfabeto, char *cadena);
int validar_primer_digito(char *cadena);

int validar_subcadena(char *cadena, char *subcadena);
int validar_matricula(char *cadena);
int validar_puntos(char *cadena);
int leer_opcion();

int main()
{
    int i = 0, opc = 1;

    while(opc == 1){
    	if(validar_cadena() == 0){
    		 printf("\nLA CADENA INGRESADA NO CUMPLE CON TODAS LAS CONDICONES \n");
		}
    	printf("\ndesea ingresar una nueva cadena?\n1-si\n0-no\n-> ");
    	opc = leer_opcion();
	}
    return 0;
}

// Retorna 0 si es invalida. Retorna 1 si es valida
int validar_cadena()
{    
    int i = 0, j = 0, valida;
    char alfabeto[] = {'s', 'e', 'b', 'a', 't', 'i', 'n', 'c', 'l', 'd', 'r', 'o', '2', '0', '8', '7', '4', '.'};
    char cadena[100];
    
    // Imprimir nombre, matricula y alfabeto
    imprimir_datos(alfabeto);
	
	// Solicitar cadena
    printf("Ingrese una cadena para verificar: ");
    gets(cadena);
	
	//valida que todos los datos de la cadena esten contenidos en el alfabeto
	if(validar_alfabeto(alfabeto, cadena) != 1){
		return 0;
	}
	
	//valida que el primer digito sea caracter
    if(validar_primer_digito(cadena) != 1){
   		return 0;
    }

	//valida que las iniciales se encuentren en la cadena
	if(validar_subcadena(cadena, "scc") != 1){
		return 0;
	}
    
    //valida que la cadena termiine con la matricula
    if (validar_matricula(cadena) != 1){
    	return 0;
	}
    
    if(validar_puntos(cadena) != 1){
    	return 0;
	}
    
    printf("\nLA CADENA INGRESADA CUMPLE CON TODAS LAS CONDICONES \n");
    
    system("pause");
    
    return 1;
}

int validar_alfabeto(char *alfabeto, char *cadena){
	int valida = 1,i,j;
    while (cadena[j] != '\0' && valida != 0)
    {
        int en_alfabeto = 0;
        for (i = 0; i < strlen(alfabeto); i++)
        {
            // Comprueba que si este en el alfabeto
            if (cadena[j] == alfabeto[i])
            {
                en_alfabeto = 1;
                break;
            }
        }
        if (en_alfabeto != 1)
        {
            valida = 0;
            break;
        }
        j++;
    }
    if (valida == 1)
    {
        return 1;
    }
    else
    {
         return 0;
    }
}

//imprime los datos
void imprimir_datos(char *alfabeto){
	int i;
	printf("\nNombre: Sebastian Calderon Carrillo\nMatricula: 2087472\nAlfabeto: {");
    for (i = 0; i < strlen(alfabeto) - 1; i++)
    {
        printf("%c,", alfabeto[i]);
    }
    printf("%c}\n\n", alfabeto[sizeof(alfabeto) - 1]);
}

//funcion para validar que el primer caracter sea digito
//retorna 0 si la cadena no es valida y 1 si es valida 
int validar_primer_digito(char *cadena){
	if (cadena[0] < 48 || cadena[0] > 57)
	{
		return 0;
	}
	return 1;
}

//funcion para validar si en la cadena se encuentran 2 puntos seguidos o  mas
//retorna 0 si la cadena no es valida y 1 si es valida 
int validar_puntos(char *cadena){
	int i, encontrado = 0;
	for(i = 0; i < strlen(cadena) - 1 ; i++){
		if(cadena[i] == 46 && cadena[i + 1] == 46){
			encontrado = 1;
			break;
		}
	}
	if (encontrado){
		return 0;
	}
	else{
		return 1;
	}
}

//funcion para validar si en la cadena termina con un punto seguido de la matricula
//retorna 0 si la cadena no es valida y 1 si es valida 
int validar_matricula(char *cadena){
	char mat[] = "2087472";
	int i, j;
	if (strlen(cadena) < (strlen(mat)) + 1) {
        return 0;
    }
	
	if(cadena[strlen(cadena) - strlen(mat) -1] != '.' ){
		return 0;
	}
	
	for(i = strlen(cadena) - strlen(mat), j = 0; i < strlen(cadena); i++, j++){
		if(cadena[i] != mat[j]){
			return 0;
		}
	}
	return 1;
}

//funcion para validar una subcadena dentro de la cadena principal 
//devuelve 1 si esta y 0 si no se encuentra
int validar_subcadena(char *cadena, char *subcadena){
	int i,j,cont=0, encontrado = 0;
	for(i = 0; i < strlen(cadena); i++){
		cont = 0;
		if(cadena[i] == subcadena[0]){
			for(j = 0; j < strlen(subcadena); j++){
				if (cadena[i+j] == subcadena[j]){
					cont = cont + 1;
				}
				else{
					break;
				}
			}
		}
		if(cont == strlen(subcadena)){
			encontrado = 1;
			break;
		}
	}
	if (encontrado){
		return 1;
	}
	else{
		return 0;
	}
}

//validar numeros enteros binarios
int leer_opcion(){
	int valor;
    int valido = 0;
    do {
        if (scanf("%d", &valor) == 1 && (valor == 0 || valor == 1)) {
            valido = 1;
        } else {
            printf("\ningrese una opcion valida\n-> ");
            valido = 0;
        }
        while (getchar() != '\n');
    } while (!valido);
    return valor;
}

