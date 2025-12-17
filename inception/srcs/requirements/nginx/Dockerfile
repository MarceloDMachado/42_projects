FROM alpine:3.22

RUN apk add --no-cache \
    nginx \
    openssl \
    envsubst

WORKDIR /run/nginx

RUN addgroup -g 1000 inception \
    && addgroup nginx inception

COPY ./conf/nginx.conf /etc/nginx/my_nginx.conf.template

COPY ./tools/entrypoint.sh /run/nginx/entrypoint.sh

RUN chmod +x /run/nginx/entrypoint.sh

ENTRYPOINT ["/run/nginx/entrypoint.sh"]