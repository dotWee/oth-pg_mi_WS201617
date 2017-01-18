#include<my_global.h>
#include<mysql.h>
#include<stdio.h>

MYSQL* connect_to_mysql() {
	MYSQL *con = mysql_init(NULL);
	if(con == NULL) {
		printf("ERROR: %s\n", mysql_error(con));
		return NULL;
	}

	if(mysql_real_connect(con, "localhost", "root", NULL, NULL, 0, NULL, 0) == NULL) {
		printf("ERROR: %s\n", mysql_error(con));
		mysql_close(con);
		return NULL;
	}
	return con;	
}

int main(void) {
	printf("MySQL-Beispiel 1\n");
	printf("----------------\n");

	MYSQL *con = connect_to_mysql();
	if(con == NULL) {
		printf("Fehler beim Verbindungsaufbau mit mysql\n");
		exit(1);
	} else {
		printf("Datenbankverbindung aufgebaut\n");
	}

	mysql_close(con);
	printf("Datenbankverbindung wieder geschlossen\n");

	return 0;
}
