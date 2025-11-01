FROM alpine:3.22.2

ENV MARIADB_DATA_DIR=/var/lib/mysql \
    MARIADB_RUN_DIR=/run/mysqld \
    MARIADB_LOG_DIR=/var/log/mysql

WORKDIR /usr/local/bin/

COPY ./tools/ .
COPY ./conf/99_my.cnf /etc/my.cnf

# openrc
RUN apk update && \
    apk add --no-cache mariadb mariadb-client && \
    mkdir -p $MARIADB_DATA_DIR $MARIADB_RUN_DIR $MARIADB_LOG_DIR && \
    chown -R mysql:mysql $MARIADB_DATA_DIR $MARIADB_RUN_DIR $MARIADB_LOG_DIR && \
    chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 3306

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
