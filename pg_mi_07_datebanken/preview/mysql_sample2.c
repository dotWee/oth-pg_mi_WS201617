#include<my_global.h>
#include<mysql.h>
#include<stdio.h>

/*
 * Verbindung zur Datenbank aufbauen
 */
MYSQL* connect_to_mysql() {
	MYSQL *con = mysql_init(NULL);
	if(con == NULL) {
		printf("ERROR: %s\n", mysql_error(con));
		return NULL;
	}

	if(mysql_real_connect(con, "localhost", "root", "PASSWORT", NULL, 0, NULL, 0) == NULL) {
		printf("ERROR: %s\n", mysql_error(con));
		mysql_close(con);
		return NULL;
	}
	return con;	
}

/*
 * testdb ggf. löschen und dann wieder anlegen
 */
void recreate_testdb(MYSQL *con) {
	if(mysql_query(con, "DROP DATABASE IF EXISTS testdb")) {
		printf("ERROR: %s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}
	printf("Wenn die Datenbank 'testdb' bereits existiert hat wurde sie soeben gelöscht\n");

	if(mysql_query(con, "CREATE DATABASE testdb")) {
		printf("ERROR: %s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}
	printf("Neue Datenbank 'testdb' angelegt\n");

	char *create_stmt = "CREATE TABLE testdb.kunden (id integer primary key auto_increment, "
		            "name varchar(50), vorname varchar(50))";

	if(mysql_query(con, create_stmt)) {
		printf("ERROR: %s/n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}
	printf("Neue Tabelle 'kunden' angelegt\n");
}

/*
 * 100 Zeilen in die Tabelle einfügen
 */
void insert_kunden(MYSQL *con) {
	char *template = "insert into testdb.kunden values (%d, 'Mustermann %d', 'Max %d')";
	char sql[strlen(template)+20];

	for(int i = 1; i < 100; i++) {
		sprintf(sql, template, i, i, i);
		if(mysql_query(con, sql)) {
			printf("ERROR: %s\n", mysql_error(con));
			mysql_close(con);
			exit(1);
		}
	}

	printf("Datensatz in die Tabelle eingefügt\n");
}

/*
 * Einige Zeilen aus der Tabelle lesen
 */
void read_kunden(MYSQL *con, int from, int to) {
	char *template = "select * from testdb.kunden where id between %d and %d";
	char sql[strlen(template)+20];

	sprintf(sql, template, from, to);
	if(mysql_query(con, sql)) {
		printf("ERROR: %s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}

	MYSQL_RES *result = mysql_store_result(con);
	if(result == NULL) {
		printf("ERROR: %s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}

	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;
  
	while ((row = mysql_fetch_row(result))) { 
		for(int i = 0; i < num_fields; i++) { 
			printf("%s ", row[i] ? row[i] : "NULL"); 
		} 
		printf("\n"); 
	}
  
	mysql_free_result(result);
}

/*
 * Main mit den Aufrufen der versch. Funktionen
 */
int main(void) {
	printf("\n");
	printf("----------------\n");
	printf("MySQL-Beispiel 2\n");
	printf("----------------\n");

	MYSQL *con = connect_to_mysql();
	if(con == NULL) {
		printf("Fehler beim Verbindungsaufbau mit mysql\n");
		exit(1);
	}
	printf("Datenbankverbindung aufgebaut\n");
	
	recreate_testdb(con);
	insert_kunden(con);
	read_kunden(con, 10, 20);
	mysql_close(con);

	printf("Datenbankverbindung wieder geschlossen\n");

	return 0;
}
