#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "validacion.h"
#include "administracion.h"
#include "clientes.h"

enum op_menu_principal {OPMP_MODO_CLIENTES = 1, OPMP_MODO_ADMINISTRACION, OPMP_SALIR_DEL_PROGRAMA};

int menu_principal();

int main()
{
    switch (menu_principal())
    {
        case OPMP_MODO_CLIENTES:

            switch (menu_cliente())
            {
                case OPMC_ORDENAR:

                break;

                case OPMC_BUSCAR_CLIENTE:
                break;

                case OPMC_VOLVER_ATRAS:
                break;
            }

        break;

        case OPMP_MODO_ADMINISTRACION:
            bool volver;
            do
            {
                  switch (menu_administracion())
                  {
                    case OPMA_INVENTARIO:
                        volver = switch_inventario(inventario);
                    break;

                    case OPMA_GESTION_DE_CLIENTES:
                    break;

                    case OPMA_GESTION_DE_PERSONAL:
                    break;

                    case OPMA_GESTION_DE_MENUS:
                    break;

                    case OPMA_VOLVER_ATRAS:
                    break;
                }
            } while (volver == true);

        break;

        case OPMP_SALIR_DEL_PROGRAMA: 
        exit(0);
    }

    return 0;
}

int menu_principal()
{
    int opcion = 0;

    limpiar_pantalla();
    printf("\nSeleccine el modo del programa.\n\n");
    printf("1 --> Modo Clientes.\n");
    printf("2 --> Modo Administracion.\n");
    printf("3 --> Salir del programa.\n");
    printf("Introduzca su opcion: "); scanf("%d", &opcion);

    return opcion;
}