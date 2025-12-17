FROM alpine:3.22

RUN apk add --no-cache \
    php83 \
    php83-fpm \
    php83-mysqli \
    php83-curl \
    php83-xml \
    php83-zlib \
    php83-mbstring \
    php83-opcache \
    php83-phar \
    php83-pecl-redis \
    php83-tokenizer \
    php83-ctype \
    envsubst \
    wget

WORKDIR /var/www/html/wordpress

RUN addgroup -g 1000 inception \
    && adduser -D -H -s /bin/ash -G www-data www-data \
    && addgroup www-data inception \
    && chown -R www-data:inception ./
    
RUN wget https://wordpress.org/latest.tar.gz \
    && tar -xzf latest.tar.gz -C /var/www/html/

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -O wp-cli \
    && chmod +x wp-cli \
    && mv wp-cli /bin

COPY ./conf/www.conf /etc/php83/php-fpm.d/my_www.conf.template

COPY ./tools/entrypoint.sh /run/wordpress/entrypoint.sh

RUN chmod +x /run/wordpress/entrypoint.sh

CMD ["/run/wordpress/entrypoint.sh"]