#include <my_global.h>
#include <mysql.h>

#include <stdio.h>

int main() {
    MYSQL *con = mysql_init(NULL);
    if(con == NULL) {
        printf("ERROR: con is NULL\n");
        return 1;
    }
    if(mysql_real_connect(con, "localhost", "root", 
        "PASSWORT", "patv", 0, NULL, 0) == NULL) {
        
        printf("ERROR: %s", mysql_error(con));
        mysql_close(con);
        return 2;
    }
    
    char *sql = "create table patient (id int primary key auto_increment, vorname varchar(50), nachname varchar(50))";
    if(mysql_query(con, sql)) {
        // if es liefert einen Fehler
        printf("ERROR: %s\n", mysql_error(con));
        mysql_close(con);
        return 3;
    } else {
        // wenns erfolgreich war
        printf("Tabelle Patient angelegt\n");
    }

    mysql_close(con);

    return 0;
}
