#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	// Estructura especial para almacenar resultados de consultas
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	int id_jugador;
	char nombre_usuario[15];
	int edad;
	char consulta [80];
	char consulta2 [80];
	char id[10];
	sprintf(id, "%d", id_jugador);
	//Creamos una conexion al servidor MYSQL
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexiￃﾳn: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//inicializar la conexion
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "Entrega1",0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexiￃﾳn: %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
		
		printf ("Dame el ID del usuario que quieres consultar su historial\n");
		scanf ("%s", id);
		// construimos la consulta SQL
		strcpy (consulta,"SELECT id_jugador FROM jugadores WHERE id_jugador = '");
		strcat (consulta, id);
		strcat (consulta,"'");
		// hacemos la consulta
		err=mysql_query (conn, consulta);
		if (err!=0) {
			printf ("Error al consultar datos de la base %u %s\n",
					mysql_errno(conn), mysql_error(conn));
			exit (1);
		}
		resultado = mysql_store_result (conn);
		row = mysql_fetch_row (resultado);
		if (row == NULL)
			printf ("No se han obtenido datos en la consulta\n");
		else
		{
			strcpy (consulta2,"SELECT * FROM historial WHERE id_jugador = '");
			strcat (consulta2, id);
			strcat (consulta2,"'");
			err=mysql_query (conn, consulta2);
			if (err!=0) {
			printf ("Error al consultar datos de la base %u %s\n",
					mysql_errno(conn), mysql_error(conn));
			exit (1);
			}
			//recogemos el resultado de la consulta
			resultado = mysql_store_result (conn);
			row = mysql_fetch_row (resultado);
			if (row == NULL)
				printf ("No se han obtenido datos en la consulta\n");
			else
				printf ("ID: %s, Partidas jugadas: %s, Partidas ganadas: %s, Beneficio total: %s", row[0], row[1], row[2],row[3]);	
		}
		// cerrar la conexion con el servidor MYSQL
		
		mysql_close (conn);
		exit(0);
}