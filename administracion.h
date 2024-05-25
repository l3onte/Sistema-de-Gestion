enum op_menu_administracion {
    OPMA_INVENTARIO = 1, OPMA_GESTION_DE_CLIENTES, OPMA_GESTION_DE_PERSONAL, OPMA_GESTION_DE_MENUS, OPMA_GESTION_FINANCIERA, OPMA_REPORTE_Y_ANALISIS, OPMA_VOLVER_ATRAS
};
enum op_inventario {
    OPI_VER_INVENTARIO = 1, OPI_AGREGAR_AL_INVENTARIO, OPI_ELIMINAR_DEL_INVENTARIO, OPI_MODIFICAR_INVENTARIO, OPI_VOLVER_ATRAS 
};

typedef struct 
{
    char nombre_del_producto[100];
    float precio_del_producto;
    int cantidad_de_producto;
} al_chile;

al_chile inventario[100];

int opcion = 0, cantidad_de_productos = 0;

int menu_administracion()
{   
    limpiar_pantalla();

    printf("Menu Administracion\n\n");
    printf("1 --> Inventario.                  4 --> Gestion Financiera.\n");
    printf("2 --> Gestion de clientes.         5 --> Reporte y Analisis.\n");            
    printf("3 --> Gestion de personal.         6 --> Gestion de munus.  \n");                          
    printf("7 --> Volver Atras.\n");
    printf("Ingrese su opcion: "); scanf("%d", &opcion);

    return opcion;
}

int menu_inventario(bool *volver)
{
    limpiar_pantalla();

    printf("Opcione de Iventario.\n\n");
    printf("1 --> Ver Inventario.                     4 --> Modificar Iventario.\n");
    printf("2 --> Agregar al Inventario.              5 --> Volver Atras.       \n");
    printf("3 --> Eliminar del Inventario.\n");
    printf("Introduzca su opcion: \n"); scanf("%d", &opcion);

    if (opcion == 5)
        *volver = true;
    else
        *volver = false;   

    return opcion;
}

bool agregar_al_inventario(al_chile *inventario, int *cantidad_de_productos)
{
    char otra_orden;
    do
    {
        limpiar_pantalla();
        (*cantidad_de_productos)++;
        printf("Agregar al Inventario: \n");
        printf("Ingrese el nombre del producto: "); scanf(" %s", inventario[*cantidad_de_productos].nombre_del_producto);
        printf("Ingrese el precio del producto: "); scanf("%f", &inventario[*cantidad_de_productos].precio_del_producto);
        printf("Ingrese la cantidad de producto: "); scanf("%d", &inventario[*cantidad_de_productos].cantidad_de_producto);
        printf("Desea agregar algo mas?(s/n) "); scanf(" %c", &otra_orden);
    } while (tolower(otra_orden) == 's');

    return false;
}

bool mostrar_inventario(al_chile *inventario, int cantidad_de_productos)
{
    char opcion;

    limpiar_pantalla();
    printf("%d", cantidad_de_productos);
    printf("Inventario Al Chile.\n\n");
    printf("PRODUCTO                PRECIO      CANTIDAD\n");
    printf("--------------------------------------------\n");
    for (int i = 1; i <= cantidad_de_productos; i++)
    {
        printf("%s                  %.2f          %d           \n", inventario[i].nombre_del_producto, inventario[i].precio_del_producto, inventario[i].cantidad_de_producto);
    }
    printf("--------------------------------------------\n");
    printf("Salir(s/n): "); scanf(" %c", &opcion);
    
    if (tolower(opcion) == 's')
        return false;
    else    
        return true;
}

bool switch_inventario(al_chile *inventario)
{
    bool volver_atras;

    do
    {
        volver_atras = true;
        switch (menu_inventario(&volver_atras))
        {
            case OPI_VER_INVENTARIO:

                volver_atras = mostrar_inventario(inventario, cantidad_de_productos);

            break;

            case OPI_AGREGAR_AL_INVENTARIO:

                volver_atras = agregar_al_inventario(inventario, &cantidad_de_productos);

            break;

            case OPI_ELIMINAR_DEL_INVENTARIO:

                

            break;

            case OPI_MODIFICAR_INVENTARIO:
            break;

            case OPI_VOLVER_ATRAS: volver_atras = true; break;
        }   
    } while(volver_atras == false);
    return true;
}