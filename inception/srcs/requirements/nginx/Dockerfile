FROM alpine:3.22.2

RUN apk update && \
    apk add --no-cache nginx openssl && \
    mkdir -p /run/nginx /var/www/html /etc/nginx/certs && \
    chown -R nginx:nginx /var/www/html /var/lib/nginx /var/log/nginx /etc/nginx

RUN rm -rf /etc/nginx/conf.d/*

WORKDIR /var/www/html

# COPY ./html/ /var/www/html
COPY ./conf/nginx.conf /etc/nginx/nginx.conf

RUN openssl req -x509 -nodes -days 365 \
    -subj "/C=BR/ST=SP/L=SaoPaulo/O=LocalDev/CN=localhost" \
    -addext "subjectAltName=DNS:localhost" \
    -newkey rsa:2048 \
    -keyout /etc/nginx/certs/server.key \
    -out /etc/nginx/certs/server.crt && \
    chmod 644 /etc/nginx/certs/server.key /etc/nginx/certs/server.crt && \
    chown -R nginx:nginx /etc/nginx/certs

EXPOSE 443

USER nginx
CMD ["nginx", "-g", "daemon off;"]