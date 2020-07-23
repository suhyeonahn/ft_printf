FROM debian:buster
MAINTAINER suahn <suahn@student.42.fr>

RUN apt-get update && apt-get upgrade -y && apt-get install -y nginx \
php7.3 php-fpm \
mariadb-server php-mysql
RUN echo "\ndaemon off;" >> /etc/nginx/nginx.conf

COPY srcs/nginx-host-conf /etc/nginx/sites-available/localhost
#RUN ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/localhost
#RUN rm /etc/nginx/sites-enabled/default

COPY srcs/setup.sh ./
#RUN echo "<?php phpinfo(); ?>" >> /var/www/html/phpinfo.php
#RUN mkdir -p /run/php && touch /run/php/php7.3-fpm.sock
#RUN mkdir -p /run/mysqld && touch /run/mysqld/mysqld.sock

CMD bash setup.sh

#RUN chown -R www-data:www-data /var/
#RUN chmod -R 755 /var/

#CMD service mysql start
#RUN echo "CREATE DATABASE suahn;" | mysql -u root --skip-password \
#	&& echo "GRANT ALL PRIVILEGES ON suahn.* TO 'root'@'localhost';" | mysql -u root --skip-password \
#	&& echo "update mysql.user set plugin = 'mysql_native_password' where user='root';" | mysql -u root --skip-password \
#	&& echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password

#WORKDIR /etc/nginx

#EXPOSE 80

#CMD service php7.3-fpm restart \
#	&& service nginx restart \
#	nginx