#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validar_cadena();

int validar_alfabeto(char *alfabeto, char *cadena, int alfabeto_len);
int validar_primer_digito(char *cadena);
int validar_puntos(char *cadena);
int validar_matricula(char *cadena);
int validar_subcadena(char *cadena, char *subcadena);

void imprimir_datos(char *alfabeto, int alfabeto_len);
int leer_opcion();

int main()
{
	int opc = 1;
	while (opc != 2)
	{
		if (validar_cadena() == 0)
			printf("\nLA CADENA INGRESADA ES INVALIDA.\n");

		printf("\nDesea ingresar una nueva cadena?\n1.Si\n2.No\n-> ");
		opc = leer_opcion();
		system("cls");
	}
	return 0;
}

// Retorna 0 si es invalida. Retorna 1 si es valida
int validar_cadena()
{
	int i = 0, j = 0, valida;
	char alfabeto[] = {'s', 'e', 'b', 'a', 't', 'i', 'n', 'c', 'l', 'd', 'r', 'o', '2', '0', '8', '7', '4', '.'};
	char cadena[100];

	// Se almacena len en variable, ya que cuando se pasa alfabeto a funcion
	//  como puntero, pierde totalmente esta informacion. strlen falla debido a condicional '/0'
	int alfabeto_len = sizeof(alfabeto);

	// Imprimir nombre, matricula y alfabeto
	imprimir_datos(alfabeto, alfabeto_len);

	// Solicitar cadena
	printf("Ingrese una cadena para verificar (case-sensitive): ");
	gets(cadena);

	// valida que todos los datos de la cadena esten contenidos en el alfabeto
	if (validar_alfabeto(alfabeto, cadena, alfabeto_len) != 1)
	{
		printf("\nNo cumple: CONDICION 2");
		return 0;
	}

	// valida que el primer digito sea caracter
	if (validar_primer_digito(cadena) != 1)
	{
		printf("\nNo cumple: CONDICION 1");
		return 0;
	}

	// valida que la cadena no contenga 2 puntos consecutivos
	if (validar_puntos(cadena) != 1)
	{
		printf("\nNo cumple: CONDICION 5");
		return 0;
	}

	// valida que la cadena termine con la matricula
	if (validar_matricula(cadena) != 1)
	{
		printf("\nNo cumple: CONDICION 4");
		return 0;
	}

	// valida que las iniciales se encuentren en la cadena
	if (validar_subcadena(cadena, "scc") != 1)
	{
		printf("\nNo cumple: CONDICION 3");
		return 0;
	}

	printf("\nCUMPLE CON TODAS LAS CONDICIONES\nLA CADENA ES VALIDA\n");
	return 1;
}

// Retorna 1 si todos los caracteres de cadena estan en alfabeto
int validar_alfabeto(char *alfabeto, char *cadena, int alfabeto_len)
{
	int valida = 1, i = 0, j = 0, en_alfabeto;

	while (cadena[j] != '\0' && valida != 0)
	{
		en_alfabeto = 0;
		for (i = 0; i < alfabeto_len; i++)
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
		return 1;

	return 0;
}

// funcion para validar que el primer caracter sea digito
// retorna 0 si la cadena no es valida y 1 si es valida
int validar_primer_digito(char *cadena)
{
	if (cadena[0] < 48 || cadena[0] > 57)
		return 0;

	return 1;
}

// funcion para validar si en la cadena se encuentran 2 puntos seguidos o  mas
// retorna 0 si la cadena no es valida y 1 si es valida
int validar_puntos(char *cadena)
{
	int i, encontrado = 0;
	for (i = 0; i < strlen(cadena) - 1; i++)
	{
		if (cadena[i] == 46 && cadena[i + 1] == 46)
		{
			encontrado = 1;
			break;
		}
	}

	if (encontrado)
		return 0;

	return 1;
}

// funcion para validar si en la cadena termina con un punto seguido de la matricula
// retorna 0 si la cadena no es valida y 1 si es valida
int validar_matricula(char *cadena)
{
	char mat[] = "2087472";
	int i, j;

	// Verifica si la cadena puede al menos contener la matricula con punto
	if (strlen(cadena) < (strlen(mat)) + 1)
		return 0;

	// Verifica que la matricula sea precedida por un punto
	if (cadena[strlen(cadena) - strlen(mat) - 1] != '.')
		return 0;

	// Verifica que la matricula coincida con la cadena
	for (i = strlen(cadena) - strlen(mat), j = 0; i < strlen(cadena); i++, j++)
	{
		if (cadena[i] != mat[j])
			return 0;
	}

	// La condicion es valida
	return 1;
}

// funcion para validar una subcadena dentro de la cadena principal
// devuelve 1 si esta y 0 si no se encuentra
int validar_subcadena(char *cadena, char *subcadena)
{
	int i, j, cont = 0, encontrado = 0;

	for (i = 0; i < strlen(cadena); i++)
	{
		cont = 0;
		if (cadena[i] == subcadena[0])
		{
			for (j = 0; j < strlen(subcadena); j++)
			{
				if (cadena[i + j] == subcadena[j])
					cont = cont + 1;
				else
					break;
			}
		}
		if (cont == strlen(subcadena))
		{
			encontrado = 1;
			break;
		}
	}

	if (encontrado)
		return 1;

	return 0;
}

// imprime los datos
void imprimir_datos(char *alfabeto, int alfabeto_len)
{
	int i;
	printf("\nNombre: Sebastian Calderon Carrillo\nMatricula: 2087472\nAlfabeto: {");
	for (i = 0; i < alfabeto_len - 1; i++)
		printf("%c,", alfabeto[i]);
	printf("%c}\n\n", alfabeto[alfabeto_len - 1]);

	printf("CONDICIONES:\n"
		   "1) Que el primer simbolo sea un digito del alfabeto.\n"
		   "2) Que tenga cualquier combinacion de letras y digitos intermedia, validos en el alfabeto.\n"
		   "3) Que la cadena contenga tus iniciales en forma consecutiva al menos una vez.\n"
		   "4) Que la cadena contenga como ultimos simbolos un punto seguido de tu numero de matricula completo.\n"
		   "5) Que acepte puntos intermedios, pero no en forma consecutiva.\n\n");
}

// validar numeros enteros binarios
int leer_opcion()
{
	int valor;
	int valido = 0;

	do
	{
		if (scanf("%d", &valor) == 1 && (valor == 2 || valor == 1))
			valido = 1;
		else
		{
			printf("\nIngrese una opcion valida\n-> ");
			valido = 0;
		}
		while (getchar() != '\n')
			;
	} while (!valido);

	return valor;
}
