#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Producto{
                 int ProductoID;
                 int Cantidad;
                 char *TipoProducto;
                 float PrecioUnitario;
};typedef struct Producto producto;

struct Cliente {
                int ClienteID;
                char *NombreCliente;
                int CantidadProductoAPedir;
                producto *Productos;
};typedef struct Cliente cliente;

char *TipoProducto[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

void cargarDatos(cliente *pcliente,int n, producto *productos);
producto obtnerProducto(int id );
void cargarProductos(cliente pcliente);
void mostrarProducto(producto producto);
void MostrarP(producto *producto,int cantidad);
void mostrarCliente(cliente pcliente);
void MostrarC( cliente *pcliente, int n );
float totalProducto(producto producto);
float totalCliente(cliente pcliente);

           int main(){
               srand(time(NULL));
               cliente *pcliente;
               producto *p_producto;
               int n_clientes;

               printf("Ingrese la cantidad de clientes: \n");
               scanf("%d",&n_clientes);
               fflush(stdin);

               pcliente=(cliente*)malloc(sizeof(cliente)* n_clientes);

               cargarDatos(pcliente,n_clientes,p_producto);
               MostrarC(pcliente,n_clientes);
               free(pcliente);

           return 0;

}

void cargarDatos(cliente *pcliente,int n, producto *productos){
        for(int i=0; i < n ; i++){
                pcliente[i].ClienteID = i+1;
                printf("--- INGRESE LOS DATOS DEL CLIENTE [%d] ---\n", i+1);
                fflush(stdin);
                pcliente[i].NombreCliente= (char*)malloc(50*sizeof(char));
                printf("Nombre del Cliente : ");
                gets(pcliente[i].NombreCliente);
                pcliente[i].CantidadProductoAPedir = 1 + rand() % 5 ;
                fflush(stdin);
                pcliente[i].Productos=(producto*)malloc(pcliente[i].CantidadProductoAPedir*sizeof(producto*));
                printf("Cantidad de productos : %d \n" , pcliente[i].CantidadProductoAPedir);
                fflush(stdin);
                cargarProductos(pcliente[i]);
                printf("---PRODUCTO ID [%d]----\n", i + 1);
                MostrarP(pcliente[i].Productos, pcliente[i].CantidadProductoAPedir);
        }

}

producto obtnerProducto(int id ){
    producto p_producto;
    p_producto.ProductoID= id;
    p_producto.Cantidad = 1 + rand()%10;
    p_producto.TipoProducto= (char*)malloc(sizeof(char)); 
    p_producto.TipoProducto = TipoProducto[rand()%5] ;
    p_producto.PrecioUnitario = 10 + rand() % 91;

    return p_producto;
}

void cargarProductos(cliente pcliente){
    for(int i = 0; i < pcliente.CantidadProductoAPedir;i++){
        pcliente.Productos[i]=obtnerProducto( i + 1);
    }
}

float totalProducto(producto producto){
    float total= 0;
    total = producto.Cantidad * producto.PrecioUnitario;
    return total;
}

float totalCliente(cliente pcliente){
    float total = 0;
    for(int i = 0; i < pcliente.CantidadProductoAPedir; i++){
        total = total + totalProducto(pcliente.Productos[i]);
    }
    return total;
}


void mostrarProducto(producto producto){
    printf("----ID DEL PRODUCTO : %d ----\n",producto.ProductoID);
    printf("CANTIDAD : %d \n" , producto.Cantidad);
    printf("TIPO : %s \n", producto.TipoProducto);
    printf("-----PRECIO UNITARIO : $%.2f -----\n" , producto.PrecioUnitario);
    printf("-----PRECIO TOTAL : $%.2f -----\n", totalProducto(producto));
    printf("\n");
}

void MostrarP(producto *producto,int cantidad){
    for(int i = 0; i < cantidad; i ++){
        mostrarProducto(producto[i]);

    }
}

void mostrarCliente(cliente pcliente){
    printf("ID DEL CLIENTE: %d \n",pcliente.ClienteID);
    printf("NOMBRE: %s\n", pcliente.NombreCliente);
    printf("-----PRODUCTOS-----\n");
    MostrarP(pcliente.Productos,pcliente.CantidadProductoAPedir);
    printf("TOTAL A PAGAR : $%.2f \n", totalCliente(pcliente));

}

void MostrarC( cliente *pcliente, int n ){
    printf("--------------COMPRAS DEL CLIENTE --------------\n");
    for(int i=0; i < n ; i++){
        mostrarCliente(pcliente[i]);
    }
}
