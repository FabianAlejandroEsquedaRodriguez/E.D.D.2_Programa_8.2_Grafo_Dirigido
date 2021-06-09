/* Aplicación de gráficas dirigidas para encontrar ciudades comunicadas
➥entre sí por el sistema ferroviario, así como los costos mínimos para
➥ir de una ciudad a las otras o entre todas las ciudades. */

#include "DiGrafo.h"

int Menu()
{
    int Opc;
    do {
    cout<<"\n\nOpciones\n";
    cout<<"\n(1) Ciudades que están comunicadas entre sí.";
    cout<<"\n(2) Mínimo costo entre todas las ciudades. ";
    cout<<"\n(3) Mínimo costo entre todas las ciudades y ciudades intermedias. ";
    cout<<"\n(4) Mínimo costo entre una ciudad y las otras. ";
    cout<<"\n(5) Finalizar el proceso."; 
    
    cout<<"\n\nIngrese opción elegida: ";
    
    cin>>Opc;

    } while (Opc < 1 || Opc > 5);

    return Opc;
}

int main()
{
    DiGrafica<int> RedFerrov;
    int Opc;

    cout<<"\n\n\nIngrese datos de ciudades y costos de pasajes";
    RedFerrov.Lee();

    RedFerrov.Imprime(0);//Imprimir la matriz de adyacencias o costos

    do {
        Opc= Menu();
            switch (Opc)
            {
                /* El método Warshall permite encontrar todas las ciudades que
                ➥están comunicadas entre sí por medio de la red ferroviaria. */
                case 1: {
                        RedFerrov.Warshall();
                        RedFerrov.Imprime(1);
                        break;
                }

                /* El método Floyd permite encontrar los costos mínimos para
                ➥visitar a todas las ciudades que están comunicadas entre sí
                ➥por medio de la red ferroviaria. */
                case 2: {
                        RedFerrov.Floyd();
                        RedFerrov.Imprime(2);
                        break;
                }

                /* El método FloydVerInt permite encontrar los costos mínimos
                ➥para visitar todas las ciudades que están comunicadas entre
                ➥sí por medio de la red ferroviaria y las ciudades intermedias
                ➥(cuando no existe camino directo, o si éste no fuera el de
                ➥costo mínimo). */
                case 3: {
                        RedFerrov.FloydVerInt();
                        RedFerrov.Imprime(3);
                        break;
                }
                /* El método Dijkstra permite encontrar los costos mínimos
                ➥para ir de una ciudad a todas las otras ciudades con las que
                ➥está comunicada por medio de la red ferroviaria. */
                case 4: {
                        RedFerrov.Dijkstra();
                        RedFerrov.Imprime(4);
                        break;
                }
        }
    } while (Opc < 5 && Opc > 0);

    return 0;
}