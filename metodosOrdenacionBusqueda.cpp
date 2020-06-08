#include <iostream>
#include <cstdlib>
#include <time.h> 

using namespace std;

// prototipos de funciones

void crearVector(int n,int *vector);
void imprimirVector(int n,int *vector);
void ordenarBurbuja(int n,int *vector);
void ordenaBurbujaSenal(int n,int *vector);
void shakersort(int n,int *vector);
void baraja(int n,int *vector);
void seleccionDirecta(int n,int *vector);
void insercionBinaria(int n,int *vector);
void shell(int n,int *vector);
void quicksort(int *vector,int inicio,int final);
void mezclaDirecta(int n,int *vector);
void mezclar(int n1,int *vec1,int n2,int *vec2,int *vector);
void busquedaSecuencial(int n,int *vector,int buscado);
int busquedaBinaria(int n,int *vector,int buscado);

// Función principal

int main(int argc, char *argv[]) {
	int *vec; // vector a ordenar
	int n; // tamaño del vector
	int op; // opción del menu seleccionada
	int x; // valor a buscar en el vector
	int loc; // posición de un elemento para la búsqueda binaria
	while(true){
		system("cls");
		cout<<"\n\tMETODOS DE ORDENAMIENTO Y BUSQUEDA"<<endl<<endl;
		cout<<"\tCrear vector aleatorio......................[01]"<<endl;
		cout<<"\tMostrar vector..............................[02]"<<endl;
		cout<<"\n\tOrdenarmientos"<<endl;
		cout<<"\tBurbuja.....................................[03]"<<endl;
		cout<<"\tBurbuja con señal...........................[04]"<<endl;
		cout<<"\tMetodo de la sacudida.......................[05]"<<endl;
		cout<<"\tMetodo de insercion directa (baraja)........[06]"<<endl;
		cout<<"\tSeleccion directa...........................[07]"<<endl;
		cout<<"\tInsercion binaria...........................[08]"<<endl;
		cout<<"\tMetodo de Shell.............................[09]"<<endl;
		cout<<"\tQuicksort...................................[10]"<<endl;
		cout<<"\tMezcla directa..............................[11]"<<endl;
		cout<<"\n\tBusquedas"<<endl;
		cout<<"\tBusqueda secuencial.........................[12]"<<endl;
		cout<<"\tBusqueda binaria............................[13]"<<endl;
		cout<<"\n\tSalir.......................................[0]"<<endl;
		cout<<"\n\tDigita tu eleccion: ";
		cin>>op;
		switch(op){
			case 1:
				cout<<"\tCantidad de elementos: ";
				cin>>n;
				vec = new int[n];
				crearVector(n,vec);
				break;
			case 2:
				imprimirVector(n,vec);
			break;
			case 3:
				ordenarBurbuja(n,vec);
				break;
			case 4:
				ordenaBurbujaSenal(n,vec);
			break;
			case 6:
				cout<<"\n\tOrdenando vector..."<<endl;
				baraja(n,vec);
				cout<<"\n\tMetodo de insercion directa terminado..."<<endl;
			break;
			case 5:
				shakersort(n,vec);
			break;
			case 7:
				seleccionDirecta(n,vec);
			break;
			case 8:
				insercionBinaria(n,vec);
			break;
			case 9:
				cout<<"\n\tOrdenando vector..."<<endl;
				shell(n,vec);
				cout<<"\n\tMetodo de Shell terminado..."<<endl;
			break;
			case 10:
				cout<<"\n\tOrdenando vector..."<<endl;
				quicksort(vec,0,n-1);
				cout<<"\n\tMetodo de Quicksort terminado..."<<endl;
			break;
			case 11:
				cout<<"\n\tOrdenando vector..."<<endl;
			    mezclaDirecta(n,vec);
				cout<<"\n\tMetodo de mezcla directa terminado..."<<endl;
			break;
			case 12:
				cout<<"\n\tIntroduce el valor a buscar: ";
				cin>>x;
				busquedaSecuencial(n,vec,x);
			break;
			case 13:
				cout<<"Introduce el valor a buscar: ";
			    cin>>x;
			    loc = busquedaBinaria(n,vec,x);
			    if(loc>-1){
			    	cout<<"El elemento esta en la posicion "<<loc<<endl;
				}else{
					cout<<"No se encontro el elemento"<<endl;
				}
			break;
			case 0:
				return 0;
			break;
		}
		cout<<"\n\t";
		system("PAUSE");
	}
}

// Implementación de funciones

/*	Consiste en dividir el intervalo de búsqueda en dos partes, comparando
	el elemento buscado con el que ocupa la posición central en el arreglo. 
	Si no son iguales, la mitad en la cual el valor no puede estar es eliminada
	y la búsqueda continua en la mitad restante hasta que el valor se encuentre.
	Funciona exclusivamente con arreglos ORDENADOS. */
int busquedaBinaria(int n,int *vector,int buscado){
	int inicio = 0;
	int fin = n-1;
	int medio;
	while(inicio<fin){
		medio = (inicio + fin)/2;
		if(vector[medio]==buscado){
			return medio;
		}else{
			if(buscado>vector[medio]){
				inicio = medio + 1;
			}else{
				fin = medio - 1;
			}
		}
	}
	if(vector[inicio]==buscado){
		return inicio;
	}else{
		return -1;
	}
}

/*	Recorre el vector elemento a elemento buscando el valor 
	proporcionado por el usuario. Si lo encuentra muestra la posición en la
	que está. */
void busquedaSecuencial(int n,int *vector,int buscado){
	int posicion=-1;
	for(int i=0;i<n;i++){
		if(vector[i]==buscado){
			posicion=i;
			break;	
		}
	}
	if(posicion!=-1){
		cout<<"\n\tEl valor esta en la posicion "<<posicion+1<<endl;
	}else{
		cout<<"\n\tEl valor no se encontro."<<endl;
	}	
}

/*  Consiste en la realización sucesiva de una partición y una fusión que produce
	secuencias ordenadas de longitud cada vez mayor. Es proceso se repite hasta que
	la longitud de la secuencia para la partición es (n+1)/2, donde n es el 
	número de elementos del archivo original.*/
void mezclaDirecta(int n,int *vector){
	int *v1,*v2; // vectores auxiliares
	int n1,n2; // tamaño de los vectores auxiliares
	int i,j; // contadores para recorrer los vectores
	if(n>1){
		if(n%2==0){
			n1 = n2 = n/2;
		}else{
			n2 = n/2;
			n1 = n2+1;
		}
		v1 = new int[n1];
		v2 = new int[n2];
		// separar el vector original en dos partes
		for(i=0;i<n1;i++){
			v1[i] = vector[i];
		}
		for(j=0;j<n2;i++,j++){
			v2[j] = vector[i];
		}
		mezclaDirecta(n1,v1);
		mezclaDirecta(n2,v2);
		mezclar(n1,v1,n2,v2,vector);
		
		// liberar el espacio de los vectores auxiliares
		delete v1;
		delete v2;
	}
}

void mezclar(int n1,int *vec1,int n2,int *vec2,int *vector){
	int c1 = 0,c2 = 0,c3 = 0; // variables para recorrer los vectores
	while(c1<n1&&c2<n2){
		if(vec1[c1]<vec2[c2]){
			vector[c3] = vec1[c1];
			c1++;
		}else{
			vector[c3] = vec2[c2];
			c2++;
		}
		c3++;
	}
	while(c1<n1){
		vector[c3] = vec1[c1];
		c1++;
		c3++;
	}
	while(c2<n2){
		vector[c3] = vec2[c2];
		c2++;
		c3++;
	}
}

/*	Es una mejora sustancial del método de intercambio directo.
	Consiste en tomar un elemento x de una posición cualquiera del arreglo.
	Se trata de ubicar a x en la posición correcta del arreglo, de tal forma 
	que todos los elementos que se encuentren a su izquierda sean menores o iguales a x
	y todos los que se encuentran a su derecha sean mayores o iguales a x.
	Se repiten los pasos para los conjuntos de datos que se encuentran a la izquierda y
	a la derecha del pivote (x). El proceso mientras los segmentos analizados tengan
	más de un elemento. */
void quicksort(int *vector,int inicio,int final){
	int pivote; 
	int izq; // indice que busca el primer elemento mayor que el pivote
	int der; // indice que busca el primer elemento menor que el pivote
	int temp;
	if(inicio<final){		
		pivote = vector[inicio];
    	izq = inicio;
    	der = final;
 	   // Mientras no se crucen los índices
    	while (izq<der) {
        	while(vector[der]>pivote){
            	der--;
        	}
    	    while ((izq<der)&&(vector[izq]<=pivote)){
            	izq++;
        	}
        	// Si todavía no se cruzan los indices seguimos intercambiando
	        if (izq<der) {
	            temp = vector[izq];
	            vector[izq] =vector[der];
	            vector[der] = temp;
	        }
    	}
    	// Si los índices se cruzan, se pone el pivote en el lugar que le corresponde
	    temp = vector[der];
	    vector[der] = vector[inicio];
	    vector[inicio] = temp;		
		pivote = der; // La nueva posición del pivote
        quicksort(vector,inicio,pivote-1); // Ordenar los elementos que se encuentran antes del pivote
        quicksort(vector,pivote+1,final); // Ordenar los elementos que se encuentran despues del pivote
    }
}

/*	Se conoce tambien como inserción con elementos decrecientes.
	Propone que las comparaciones entre elementos se efectúen con saltos de mayor tamaño,
	pero con incrementos decrecientes; así, los elementos quedarán ordenados en el arreglo 
	más rápidamente. */
void shell(int n,int *vector){
	int k; // tamaño del salto
	int aux; // variable para hacer el intercambio entre posiciones
	k = n/2; // calcular el tamaño del salto inicial
	while(k>1){
		for(int i=0;(i+k)<n;i++){
			if(vector[i]>vector[i+k]){
				aux = vector[i];
				vector[i] = vector[i+k];
				vector[i+k] = aux;
			}
		}
		k = k/2;
	}
	// En los saltos donde k=1, se utiliza un método de inserción directa
	baraja(n,vector);
}

/* Búsqueda binaria o de intercambio medio, no secuencial.
   Hace la mitad de las comparaciones que se harían con la inserción directa.
   Compara cada uno de los elementos con los elementos de su izquierda, a partir del punto medio. */
void insercionBinaria(int n,int *vector){
	int medio; // punto medio en donde se empiezan a hacer los intercambios
	int temp;
	if(vector[0]>vector[1]){
		temp = vector[0];
		vector[0] = vector[1];
		vector[1] = temp;	
	}
	for(int i=2;i<n;i++){
		medio = i/2; // definir el punto medio
		if(vector[i]<vector[medio-1]){ // el recorrido se debe hacer desde el principio
			medio = 0;
		}
		for(int j=medio;j<i;j++){
			if(vector[j]>vector[i]){
				temp = vector[i];
				vector[i] = vector[j];
				vector[j] = temp;	
			}
		}
	}
}

/*	Busca el menor elemento del arreglo y lo coloca en la primer posición. Luego
	busca el segundo elemento más pequeño y lo coloca en la segunda posición. El
	proceso continua hasta que todos los elementos hayan sido ordenados*/
void seleccionDirecta(int n,int *vector){
	int menor; // valor más pequeño del arreglo
	int posicion; // posicion de menor
	int temp;
	cout<<"\n\tOrdenando vector..."<<endl;
	for(int i=0;i<n;i++){ 
		menor = vector[i];
		posicion = i;
		for(int j=i+1;j<n;j++){ // buscar el elemento menor
			if(menor>vector[j]){
				menor = vector[j];
				posicion = j;
			}
		}
		if(posicion != i){
			temp = vector[i];
			vector[i] = vector[posicion];
			vector[posicion] = temp;
		}
	}
	cout<<"\n\tMetodo de seleccion directa terminado..."<<endl;
}

/*	Consiste en insertar un elemento del arreglo en su parte izquierda que ya 
	se encuentra ordenada. El proceso se repite desde el segundo hasta el n-ésimo
	elemento
*/
void baraja(int n,int *vector){
	int temp; // guarda de forma temporal un valor para hacer el intercambio
	for(int i=1;i<n;i++){
		for(int j=i;j>=1;j--){
			if(vector[j]<vector[j-1]){
				temp = vector[j-1];
				vector[j-1] = vector[j];
				vector[j] = temp;
			}
		}
	}
}

/*	Optimización del método de intercambio directo. Cada pasada tiene 2 etapas:
	en la 1° (derecha a izquierda) se trasladan los elementos más pequeños hacia
	la parte izquierda del arreglo almacenando la posición del último elemento
	intercambiado. En la 2° etapa (izquierda a derecha) se trasladan los 
	elementos más grandes hacia la parte derecha del arreglo, almacenando tambien
	la posición del último elemento intercambiado. Las sucesivas pasadas trabajan
	con los componentes del arreglo que se encuentran entre las posiciones almacenadas.
*/
void shakersort(int n,int *vector){
	int izq = 0, der = n-1; // ultima posición de intercambio izquiero y derecho, respectivamente
	int posicion; // variable de apoyo que indica cuál es la última posición en la que se hace un cambio
	int aux; // guarda de forma temporal el valor de una posición miestras se realiza el intercambio
	cout<<"\n\tOrdenando vector..."<<endl;
	while(der>izq){
		for(int i=der;i>izq;i--){ // Ciclo descendente (derecha a izquierda)
			if(vector[i-1]>vector[i]){
				aux = vector[i-1];
				vector[i-1] = vector[i];
				vector[i] = aux;
				posicion = i;
			}
		}
		izq = posicion;
		for(int i=izq;i<der;i++){
			if(vector[i]>vector[i+1]){
				aux = vector[i+1];
				vector[i+1] = vector[i];
				vector[i] = aux;
				posicion = i;
			}
		}
		der = posicion;
	}
	cout<<"\n\tMetodo de la sacudida terminado..."<<endl;
}

/*	Es una modificación del método de intercambio directo (burbuja),
	pero utiliza una marca o señal para indicar que no se ha producido ningún intercambio
	en una pasada. Es decir, se comprueba si el arreglo está totalmente ordenado despues
	de cada pasada, terminando su ejecución en caso afirmativo.
*/
void ordenaBurbujaSenal(int n,int *vector){
	int tmp; // valor temporal para el intercambio de números
	int i,j; // contadores para recorrer el vector
	bool band; // bandera que indica si se realizan intercambios en el vector
	cout<<"\n\tOrdenando vector...";
	while(i<=n && band==false){
		band = true;
		for(j=0;j<n-1;j++){
			if(vector[j]>vector[j+1]){
				tmp = vector[j];
				vector[j] = vector[j+1];
				vector[j+1] = tmp;
				band = false;
			}
		}
	}
	cout<<"\n\tMetodo de burbuja con señal terminado..."<<endl;
}

/*	Compara pares de elementos adyacentes y los intercambia entre si
	hasta que todos se encuentran ordenados
*/
void ordenarBurbuja(int n,int *vector){ // ordena de menor a mayor
	int tmp; // guarda un valor temporal en el intercambio de números
	cout<<"\n\tOrdenando vector...";
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(vector[j]<vector[i]){
				tmp=vector[j];
            	vector[j]=vector[i];
            }
			vector[i]=tmp;
        }
	}
	cout<<"\n\tMetodo de burbuja terminado..."<<endl;
}

/* Mostrar el vector en pantalla*/
void imprimirVector(int n,int *vector){
	cout<<"\n\t";
	for(int i=0;i<n;i++){
		cout<<"["<<vector[i]<<"] ";
	}
	cout<<endl;
}

/* Crear el vector según el tamaño especificado*/
void crearVector(int n,int *vector){
	srand(time(NULL));
	for(int i=0;i<n;i++){
		vector[i]=rand()%100;
	}
}
