FROM alpine:3.22.1

ENV MARIADB_ROOT_PASSWORD=root
ENV MARIADB_DATABASE=meubanco
ENV MARIADB_USER=usuario
ENV MARIADB_PASSWORD=senha


RUN apk add --no-cache mariadb mariadb-client mariadb-server-utils

RUN mkdir -p /run/mysqld /var/lib/mysql && chown -R mysql:mysql /run/mysqld /var/lib/mysql

COPY ./tools ./docker-entrypoint-initdb.d

#COPY ./conf/my.cnf /etc/my.cnf

COPY ./tools/docker-entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/docker-entrypoint.sh

EXPOSE 3306

ENTRYPOINT ["docker-entrypoint.sh"]
CMD ["mysqld_safe"]