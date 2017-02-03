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

    mysql_close(con);

    return 0;
}
