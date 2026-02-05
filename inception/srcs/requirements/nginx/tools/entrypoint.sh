#!/bin/ash

if ! cat /etc/nginx/nginx.conf | grep -w "${WORDPRESS_DOMAIN}";
then
	envsubst '$NGINX_PORT \
		$WORDPRESS_DOMAIN \
		$WORDPRESS_HOST \
		$WORDPRESS_PORT' \
		< /etc/nginx/my_nginx.conf.template \
		> /etc/nginx/nginx.conf;
fi

if [ ! -f /etc/nginx/ssl/${WORDPRESS_DOMAIN}.crt ] \
	|| [ ! -f /etc/nginx/ssl/${WORDPRESS_DOMAIN}.key ];
then
	mkdir -p /etc/nginx/ssl; \
	openssl req -x509 \
		-newkey rsa:4096 \
		-keyout /etc/nginx/ssl/${WORDPRESS_DOMAIN}.key \
		-out /etc/nginx/ssl/${WORDPRESS_DOMAIN}.crt \
		-days 365 \
		-nodes \
		-subj "/O=42/CN=${WORDPRESS_DOMAIN}" > /dev/null 2>&1;
fi

echo "nginx is running"

exec nginx -g 'daemon off;'