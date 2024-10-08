#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

/*FALTA TODAVÍA PONER LA CONDICIÓN DEL TAMAÑO DEL NÚMERO LO DE SI ES MAYOR A 2^31-1 
redonderalo a 2^31-1 y si es menor a -2^31 */
int myatoi(char arr[100]);

int main(){
	char arr[100];  // Arreglo para almacenar la cadena del usuario
	int numero;

   
    printf("Ingresa un número: ");
    scanf("%s", arr); 

    numero = myatoi(arr);
    printf("El número es: %d", numero);

	
	return 0;
}

int myatoi(char arr[100]){
	char signo = 1;
	int i=0;
	int num = 0;


	while (arr[i] == ' '){
		i++;
	}

	if (arr[i] == '+' || arr[i] == '-'){
		signo = (arr[i] == '+') ? 1 : -1;
		i++;
	}

	while(arr[i]>= '0' && arr[i]<='9'){
		// Comprobar si al multiplicar por 10 va a desbordar
		//INT_MAX Es el límite superior (2^31)-1
		if (num > (INT_MAX / 10) || (num == (INT_MAX / 10) && (arr[i] - '0') > 7)) {
            return (signo == 1) ? INT_MAX : INT_MIN;
        }
		num = num * 10 + (arr[i] - '0');
		i++;
	}

	

	
	return signo * num;
}


