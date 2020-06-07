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

// Funci�n principal

int main(int argc, char *argv[]) {
	int *vec; // vector a ordenar
	int n; // tama�o del vector
	int op; // opci�n del menu seleccionada
	int tmp,men,ban,x,sup,inf,pos,med;
	while(true){
		system("cls");
		cout<<"\n\tMETODOS DE ORDENAMIENTO Y BUSQUEDA"<<endl<<endl;
		cout<<"\tCrear vector aleatorio......................[01]"<<endl;
		cout<<"\tMostrar vector..............................[02]"<<endl;
		cout<<"\n\tOrdenarmientos"<<endl;
		cout<<"\tBurbuja.....................................[03]"<<endl;
		cout<<"\tBurbuja con se�al...........................[04]"<<endl;
		cout<<"\tMetodo de la sacudida.......................[05]"<<endl;
		cout<<"\tMetodo de insercion directa (baraja)........[06]"<<endl;
		cout<<"\tSeleccion directa...........................[07]"<<endl;
		cout<<"\tInsercion binaria...........................[08]"<<endl;
		cout<<"\tMetodo de Shell.............................[09]"<<endl;
		cout<<"\tQuicksort...................................[10]"<<endl;
		cout<<"\tMezcla directa..............................[11]"<<endl;
		cout<<"\tBUSQUEDA SECUENCIAL.........................[]"<<endl;
		cout<<"\tSALIR.......................................[0]"<<endl;
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
			case 6:/*
				for(int i=0;i<n;i++){
					men=vec[i];
					tmp=i;
					for(int j=i+1;j<n;j++){
						if(vec[j]<men){
							men=vec[j];
							tmp=j;
						}
					}
					vec[tmp]=vec[i];
					vec[i]=men;
				}*/
				cout<<"\n\tOrdenando vector..."<<endl;
				baraja(n,vec);
				cout<<"\n\tMetodo de insercion directa terminado..."<<endl;
				break;
			/*case 4:
				inf=0;
    			sup=9;
    			ban=0;
    			cout<<"Introduce el valor a buscar: ";
				cin>>x;
    			while(inf<=sup){
    				ban++;
    				med=(inf+sup)/2;
    				if (vec[med]>x){
			            sup=med-1;
			        }
			        else{
			            if (vec[med]<x)
			                inf=med+1;
			            else{
			                pos=med;
			                inf=sup+1;
			            }
			        }
			        if (pos==-1)
			            cout<<"El valor no se encontro";
    			}
    			cout<<"Despues de "<<ban<<" intentos, el valor se encontro en ["<<pos<<"]="<<vec[pos]<<endl;
			break;*/
			case 5:
				shakersort(n,vec);
				/*ban=-1;
				cout<<"Introduce el valor a buscar: ";
				cin>>x;
				for(int i=0;i<n;i++)
					if(vec[i]==x){
						ban=i;
						break;	
					}
				if(ban!=-1)
					cout<<"El valor esta en la posicion ["<<ban<<"]= "<<vec[ban]<<endl;
				else
					cout<<"El valor no se encontro."<<endl;
					*/
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
				cout<<"\n\tMetodo de Quicksort terminado..."<<endl;
			break;
			case 0:
				return 0;
			break;
		}
		cout<<"\n\t";
		system("PAUSE");
	}
}

// Implementaci�n de funciones

/*  Consiste en la realizaci�n sucesiva de una partici�n y una fusi�n que produce
	secuencias ordenadas de longitud cada vez mayor. Es proceso se repite hasta que
	la longitud de la secuencia para la partici�n es (n+1)/2, donde n es el 
	n�mero de elementos del archivo original.*/
void mezclaDirecta(int n,int *vector){
	int *f1,*f2; // vectores auxiliares
	int segmento; // tama�o del segmento
	int posicion; // posicion del vector original
	int posF1 = 0;
	int posF2 = 0;
	if(n%2==0){ // si el n�mero de elementos del vector es par
		f1 = new int[n/2];
		f2 = new int[n/2];
	}else{ // si es impar
		f1 = new int[n/2];
		f2 = new int[n/2-1];
	}
	for(segmento=1;segmento<=(n+1)/2;segmento*=2){
		posicion = 0;
		while(posicion<n){
			for(int i=1;i<=segmento;i++){
				f1[posF1] = vector[posicion];
				posicion++;
				posF1++;
			}
			for(int i=1;i<=segmento;i++){
				f2[posF2] = vector[posicion];
				posicion++;
				posF2++;
			}
		}
	}
}

/*	Es una mejora sustancial del m�todo de intercambio directo.
	Consiste en tomar un elemento x de una posici�n cualquiera del arreglo.
	Se trata de ubicar a x en la posici�n correcta del arreglo, de tal forma 
	que todos los elementos que se encuentren a su izquierda sean menores o iguales a x
	y todos los que se encuentran a su derecha sean mayores o iguales a x.
	Se repiten los pasos para los conjuntos de datos que se encuentran a la izquierda y
	a la derecha del pivote (x). El proceso mientras los segmentos analizados tengan
	m�s de un elemento. */
void quicksort(int *vector,int inicio,int final){
	int pivote; 
	int izq; // indice que busca el primer elemento mayor que el pivote
	int der; // indice que busca el primer elemento menor que el pivote
	int temp;
	if(inicio<final){		
		pivote = vector[inicio];
    	izq = inicio;
    	der = final;
 	   // Mientras no se crucen los �ndices
    	while (izq<der) {
        	while(vector[der]>pivote){
            	der--;
        	}
    	    while ((izq<der)&&(vector[izq]<=pivote)){
            	izq++;
        	}
        	// Si todav�a no se cruzan los indices seguimos intercambiando
	        if (izq<der) {
	            temp = vector[izq];
	            vector[izq] =vector[der];
	            vector[der] = temp;
	        }
    	}
    	// Si los �ndices se cruzan, se pone el pivote en el lugar que le corresponde
	    temp = vector[der];
	    vector[der] = vector[inicio];
	    vector[inicio] = temp;		
		pivote = der; // La nueva posici�n del pivote
        quicksort(vector,inicio,pivote-1); // Ordenar los elementos que se encuentran antes del pivote
        quicksort(vector,pivote+1,final); // Ordenar los elementos que se encuentran despues del pivote
    }
}

/*	Se conoce tambien como inserci�n con elementos decrecientes.
	Propone que las comparaciones entre elementos se efect�en con saltos de mayor tama�o,
	pero con incrementos decrecientes; as�, los elementos quedar�n ordenados en el arreglo 
	m�s r�pidamente. */
void shell(int n,int *vector){
	int k; // tama�o del salto
	int aux; // variable para hacer el intercambio entre posiciones
	k = n/2; // calcular el tama�o del salto inicial
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
	// En los saltos donde k=1, se utiliza un m�todo de inserci�n directa
	baraja(n,vector);
}

/* B�squeda binaria o de intercambio medio, no secuencial.
   Hace la mitad de las comparaciones que se har�an con la inserci�n directa.
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

/*	Busca el menor elemento del arreglo y lo coloca en la primer posici�n. Luego
	busca el segundo elemento m�s peque�o y lo coloca en la segunda posici�n. El
	proceso continua hasta que todos los elementos hayan sido ordenados*/
void seleccionDirecta(int n,int *vector){
	int menor; // valor m�s peque�o del arreglo
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
	se encuentra ordenada. El proceso se repite desde el segundo hasta el n-�simo
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

/*	Optimizaci�n del m�todo de intercambio directo. Cada pasada tiene 2 etapas:
	en la 1� (derecha a izquierda) se trasladan los elementos m�s peque�os hacia
	la parte izquierda del arreglo almacenando la posici�n del �ltimo elemento
	intercambiado. En la 2� etapa (izquierda a derecha) se trasladan los 
	elementos m�s grandes hacia la parte derecha del arreglo, almacenando tambien
	la posici�n del �ltimo elemento intercambiado. Las sucesivas pasadas trabajan
	con los componentes del arreglo que se encuentran entre las posiciones almacenadas.
*/
void shakersort(int n,int *vector){
	int izq = 0, der = n-1; // ultima posici�n de intercambio izquiero y derecho, respectivamente
	int posicion; // variable de apoyo que indica cu�l es la �ltima posici�n en la que se hace un cambio
	int aux; // guarda de forma temporal el valor de una posici�n miestras se realiza el intercambio
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

/*	Es una modificaci�n del m�todo de intercambio directo (burbuja),
	pero utiliza una marca o se�al para indicar que no se ha producido ning�n intercambio
	en una pasada. Es decir, se comprueba si el arreglo est� totalmente ordenado despues
	de cada pasada, terminando su ejecuci�n en caso afirmativo.
*/
void ordenaBurbujaSenal(int n,int *vector){
	int tmp; // valor temporal para el intercambio de n�meros
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
	cout<<"\n\tMetodo de burbuja con se�al terminado..."<<endl;
}

/*	Compara pares de elementos adyacentes y los intercambia entre si
	hasta que todos se encuentran ordenados
*/
void ordenarBurbuja(int n,int *vector){ // ordena de menor a mayor
	int tmp; // guarda un valor temporal en el intercambio de n�meros
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

/* Crear el vector seg�n el tama�o especificado*/
void crearVector(int n,int *vector){
	srand(time(NULL));
	for(int i=0;i<n;i++){
		vector[i]=rand()%100;
	}
}
