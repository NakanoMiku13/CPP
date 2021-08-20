//Code by NakanoMiku13
//Check more codes on https://github.com/NakanoMiku13/
#include<graphics.h>
#include <iostream>
#include<bits/stdc++.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
char text[2];
char num;
int main() {
	//Variables para detección de drivers de video, gdrive se usa con DETECT para que use
	//El driver default del equipo, gmode es el tipo de modo, en este caso Graphic mode
	int gdriver = DETECT, gmode;
	//Se inicia colocando el gdriver y el gmode, el último parámtero indica la ubicación
	//del driver de vide, si se ponen comillas sin datos, ocupará el default del equipo
    initgraph(&gdriver, &gmode, "");
    //Colocando el color azul
    setcolor(BLUE);
    char* let="a";
    for(int j=1,top=10,bottom=60,y=32;j<=5;j++,top+=60,bottom+=60,y+=60){
	    for(int i=1,right=60,left=10,x=32;i<=5;i++,left+=60,right+=60,x+=60){
	    	//Función para indexar una variable int o cualquier tipo a una cadena String o char[]
	    	sprintf(text,"%d",i*j);
	    	//Función para imprimir texto en las posiciones X y Y
	    	outtextxy(x,y,text);
	    	//Imprimiendo un rectangulo con esos parámetros
	    	//int left, int top, int right, int bottom
	    	rectangle(left,top,right,bottom);
		}	
	}
	//Dibujando una linea
	line(10,350,100,350);
	//Función para generar una pausa y esperando una entrada por teclado
	getch();
	//Finaliza modo gráfico
   	closegraph();
   	int x;
   	cin>>x;
   	//Iniciando nuevamente modo gráfico
   	initgraph(&gdriver, &gmode, "");
   	//Convirtiendo el número ingresado por teclado a string
   	sprintf(text,"%d",x);
   	//Imprimiendo el numero previamente ingresado
   	outtextxy(10,100,text);
   	//Espera de input
   	getch();
   	//Cierre de modo gráfico
   	closegraph();
}