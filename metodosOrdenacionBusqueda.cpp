#include <iostream>
#include <cstdlib>
#include <time.h> 

using namespace std;

// prototipos de funciones
void crearVector(int n,int *vector);
void imprimirVector(int n,int *vector);
void ordenarBurbuja(int n,int *vector);

int main(int argc, char *argv[]) {
	int *vec; // vector a ordenar
	int n; // tamaño del vector
	int op; // opción del menu seleccionada
	int tmp,men,ban,x,sup,inf,pos,med;
	while(true){
		system("cls");
		cout<<"\n\tMETODOS DE ORDENAMIENTO Y BUSQUEDA"<<endl<<endl;
		cout<<"\tCrear vector aleatorio.........[1]"<<endl;
		cout<<"\tMostrar vector.................[2]"<<endl;
		cout<<"\tORDENA BURBUJA.................[3]"<<endl;
		cout<<"\tORDENA SELECCION DIRECTA.......[6]"<<endl;
		cout<<"\tBUSQUEDA BINARIA...............[4]"<<endl;
		cout<<"\tBUSQUEDA SECUENCIAL............[5]"<<endl;
		cout<<"\tSALIR..........................[7]"<<endl;
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
			case 6:
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
				}
				break;
			case 4:
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
			break;
			case 5:
				ban=-1;
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
			break;
			
			case 7:return 0;
			break;
		}
		cout<<"\n\t";
		system("PAUSE");
	}
	return 0;
}

// Implementación de funciones
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

void imprimirVector(int n,int *vector){
	cout<<"\n\t";
	for(int i=0;i<n;i++){
		cout<<"["<<vector[i]<<"] ";
	}
	cout<<endl;
}

void crearVector(int n,int *vector){
	srand(time(NULL));
	for(int i=0;i<n;i++){
		vector[i]=rand()%100;
	}
}
