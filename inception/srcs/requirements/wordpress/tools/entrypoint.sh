#!/bin/ash

if [ ! -f wp-config.php ];
then
	until wp-cli config create \
		--dbhost="$MARIADB_HOST:$MARIADB_PORT" \
		--dbname="$MARIADB_DATABASE" \
		--dbuser="$MARIADB_USER" \
		--dbpass="$(cat /run/secrets/mariadb_user_password)" \
		--dbprefix="wp_" \
		--allow-root;
	do
		sleep 5;
	done;

	sed -i "/^<?php$/a \
		\$_SERVER['HTTP_HOST'] = '${WORDPRESS_DOMAIN}';" wp-config.php
fi

if [ ! -f /etc/php83/php-fpm.d/www/conf ];
then
	envsubst '$WORDPRESS_PORT' \
	< /etc/php83/php-fpm.d/my_www.conf.template \
	> /etc/php83/php-fpm.d/www.conf;
fi

if ! wp-cli core is-installed --allow-root;
then

	wp-cli core install \
		--url="$WORDPRESS_DOMAIN" \
		--title="$WORDPRESS_TITLE" \
		--admin_user=$WORDPRESS_ROOT \
		--admin_password=$(cat /run/secrets/wordpress_root_password) \
		--admin_email=$WORDPRESS_ROOT_EMAIL \
		--skip-email \
		--allow-root;

	wp-cli user create --allow-root \
		"$WORDPRESS_USER" \
		"$WORDPRESS_USER_EMAIL" \
		--user_pass=$(cat /run/secrets/wordpress_user_password) \
		--role="author" \
		--path=/var/www/html/wordpress

	wp-cli theme activate twentytwentyfour --allow-root

	wp-cli config set WP_CACHE true --raw --allow-root;

	chown -R www-data:inception ./
fi

echo "wordpress is alive"

exec php-fpm83 -F