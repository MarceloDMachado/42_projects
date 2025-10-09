#!/bin/sh
set -e

# Inicializa o diretório de dados se estiver vazio
if [ ! -d "/var/lib/mysql/mysql" ]; then
  echo "🔹 Inicializando banco de dados..."
  mysql_install_db --user=mysql --ldata=/var/lib/mysql > /dev/null

  # Inicia temporariamente o servidor para configurar usuário root e DB
  mysqld_safe --skip-networking &
  pid="$!"

  # Espera o MySQL iniciar
  for i in $(seq 30); do
    if mysqladmin ping &>/dev/null; then
      break
    fi
    sleep 1
  done

  echo "🔹 Criando usuário e banco..."
  mysql -uroot <<-EOSQL
    ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PASSWORD}';
    CREATE DATABASE IF NOT EXISTS \`${MARIADB_DATABASE}\`;
    CREATE USER '${MARIADB_USER}'@'%' IDENTIFIED BY '${MARIADB_PASSWORD}';
    GRANT ALL PRIVILEGES ON \`${MARIADB_DATABASE}\`.* TO '${MARIADB_USER}'@'%';
    FLUSH PRIVILEGES;
EOSQL

  # Executa scripts de inicialização customizados, se houver
  for f in /docker-entrypoint-initdb.d/*; do
    case "$f" in
      *.sql)    echo "🔹 Executando $f"; mysql -uroot -p${MARIADB_ROOT_PASSWORD} ${MARIADB_DATABASE} < "$f" ;;
      *)        echo "Ignorando $f" ;;
    esac
  done

  # Finaliza processo temporário
  mysqladmin -uroot -p${MARIADB_ROOT_PASSWORD} shutdown
  wait "$pid"
fi

echo "✅ MariaDB pronto!"
exec "$@"
