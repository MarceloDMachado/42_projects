FROM alpine:3.22.2

ENV WORDPRESS_VERSION=6.7.1 \
    PHP_FPM_USER=www-data \
    PHP_FPM_GROUP=www-data \
    PHP_INI_DIR=/etc/php83 \
    WORDPRESS_PATH=/var/www/html

RUN apk add --no-cache \
    php83 \
    php83-fpm \
    php83-mysqli \
    php83-json \
    php83-openssl \
    php83-curl \
    php83-dom \
    php83-exif \
    php83-fileinfo \
    php83-gd \
    php83-intl \
    php83-mbstring \
    php83-xml \
    php83-zip \
    php83-session \
    php83-simplexml \
    php83-tokenizer \
    php83-pecl-imagick \
    curl \
    tar \
    unzip \
    shadow

RUN mkdir -p ${WORDPRESS_PATH} && \
    adduser -S ${PHP_FPM_USER} -G ${PHP_FPM_GROUP}

WORKDIR ${WORDPRESS_PATH}

RUN curl -o /tmp/wordpress.tar.gz -fSL https://wordpress.org/wordpress-${WORDPRESS_VERSION}.tar.gz && \
    tar -xzf /tmp/wordpress.tar.gz -C /tmp && \
    cp -R /tmp/wordpress/* ${WORDPRESS_PATH}/ && \
    chown -R ${PHP_FPM_USER}:${PHP_FPM_GROUP} ${WORDPRESS_PATH} && \
    rm -rf /tmp/wordpress /tmp/wordpress.tar.gz && \
    chown -R ${PHP_FPM_USER}:${PHP_FPM_GROUP} /var/log/php83

RUN sed -i "s|^user = nobody|user = ${PHP_FPM_USER}|" /etc/php83/php-fpm.d/www.conf && \
    sed -i "s|^group = nobody|group = ${PHP_FPM_GROUP}|" /etc/php83/php-fpm.d/www.conf && \
    sed -i "s|^listen = 127.0.0.1:9000|listen = 0.0.0.0:9000|" /etc/php83/php-fpm.d/www.conf && \
    sed -i "s|^;listen.owner = nobody|listen.owner = ${PHP_FPM_USER}|" /etc/php83/php-fpm.d/www.conf && \
    sed -i "s|^;listen.group = nobody|listen.group = ${PHP_FPM_GROUP}|" /etc/php83/php-fpm.d/www.conf && \
    sed -i "s|^;listen.mode = 0660|listen.mode = 0660|" /etc/php83/php-fpm.d/www.conf

EXPOSE 9000

USER ${PHP_FPM_USER}

CMD ["php-fpm83", "-F"]
