#!/bin/ash

envsubst '$MARIADB_PORT' < /etc/my.cnf.d/99_my.cnf > /etc/my.cnf.d/mariadb-server.cnf

mariadbd --user=mysql --skip-networking > /dev/null 2>&1 &
pid=$!

until mariadb-admin ping --silent; do
	sleep 1
done

if [ $(mariadb -u root -sse "SELECT EXISTS(SELECT 1 FROM mysql.user WHERE user = '$MARIADB_USER');") -eq 0 ];
then
	mariadb -u root -sse "
	CREATE DATABASE IF NOT EXISTS $MARIADB_DATABASE;
	CREATE USER IF NOT EXISTS 'root'@'%' IDENTIFIED BY '$(cat /run/secrets/mariadb_root_password)';
	GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;
	CREATE USER IF NOT EXISTS '$MARIADB_USER'@'%' IDENTIFIED BY '$(cat /run/secrets/mariadb_user_password)';
	GRANT ALL PRIVILEGES ON *.* TO '$MARIADB_USER'@'%' WITH GRANT OPTION;
	FLUSH PRIVILEGES;"
fi

kill $pid

exec mariadbd --user=mysql --datadir=/var/lib/mysql