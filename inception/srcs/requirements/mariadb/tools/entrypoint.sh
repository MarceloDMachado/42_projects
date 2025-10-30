#!/bin/sh
set -e

DATA_DIR=$MARIADB_DATA_DIR
RUN_DIR=$MARIADB_RUN_DIR
LOG_DIR=$MARIADB_LOG_DIR

mkdir -p $DATA_DIR $RUN_DIR $LOG_DIR
chown -R mysql:mysql $DATA_DIR $RUN_DIR $LOG_DIR

# Inicializa o banco se estiver vazio
if [ ! -d "$DATA_DIR/mysql" ]; then
    echo "Inicializando MariaDB..."
    mariadb-install-db --user=mysql --datadir=$DATA_DIR > /dev/null 2>&1
    mysqld_safe --datadir=$DATA_DIR &
    
    sleep 5
    
    if [ -f ./init.sql ]; then
        echo "Executando ./init.sql..."
        mariadb -u root < ./init.sql
    fi

    if [ -f ./insert_users.sql ]; then
         echo "Executando ./insert_users.sql..."
         mariadb -u root < ./insert_users.sql
    fi
    touch test.txt

    mysqladmin -u root shutdown
fi

exec mysqld_safe --datadir=$DATA_DIR
