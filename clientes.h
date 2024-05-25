enum op_menu_cliente {OPMC_ORDENAR = 1, OPMC_BUSCAR_CLIENTE, OPMC_VOLVER_ATRAS};

int menu_cliente()
{
    int opcion = 0;
    
    limpiar_pantalla();
    printf("Menu\n");
    printf("1 --> Ordenar.\n");
    printf("2 --> Buscar Cliente.\n");
    printf("3 --> Volver Atras\n");
    printf("Ingrese su opcion: "); scanf("%d", &opcion);

    return opcion;
}
