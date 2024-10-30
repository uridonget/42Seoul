#!/bin/sh
set -e

if [ -f "/var/www/html/wp-config.php" ]
then
    echo "WordPress already configured."
else
    wget https://github.com/wp-cli/wp-cli/releases/download/v2.5.0/wp-cli-2.5.0.phar
    chmod +x wp-cli-2.5.0.phar
    mv wp-cli-2.5.0.phar /usr/local/bin/wp
    chmod +x /usr/local/bin/wp
    chown -R www-data:www-data /var/www/html
    wp core download --path=$WP_PATH --allow-root
    wp config create --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=mariadb --path=$WP_PATH --allow-root --skip-check
    wp core install --path=$WP_PATH --url=$DOMAIN_NAME --title=$WP_TITLE --admin_user=$WP_ADMIN_USER --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --skip-email --allow-root
    wp user create $WP_USER $WP_USER_EMAIL --role=author --path=$WP_PATH --user_pass=$WP_USER_PASSWORD --allow-root
fi

/usr/sbin/php-fpm7.4 -F
