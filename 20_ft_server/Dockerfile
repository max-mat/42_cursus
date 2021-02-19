# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/13 13:13:54 by mmatsego          #+#    #+#              #
#    Updated: 2021/02/17 16:37:57 by mmatsego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Install the base image
FROM debian:buster

# Update package list & upgrade system
RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install wget vim mc

# NGINX
RUN apt-get -y install nginx

# MARIADB
RUN apt-get -y install mariadb-server

# PHP set of extentions to communicate with MariaDB
RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring

# Expose port 80 for HTTP and 443 for HTTPS. So container listens these ports
EXPOSE 80 443

# Create the root-directory for our domain
RUN mkdir /var/www/localhost

# PHPMYADMIN
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz
RUN tar -xvf phpMyAdmin-5.0.4-all-languages.tar.gz && \
	rm -rf phpMyAdmin-5.0.4-all-languages.tar.gz
RUN mv phpMyAdmin-5.0.4-all-languages/ /var/www/localhost/phpmyadmin
COPY /srcs/config.inc.php /var/www/localhost/phpmyadmin

# WORDPRESS. chown = change owner
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz && rm -rf latest.tar.gz
RUN mv wordpress/ /var/www/localhost/wordpress
COPY srcs/wp-config.php /var/www/localhost/wordpress

# NGINX
COPY srcs/localhost.conf /etc/nginx/sites-available/localhost
RUN ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/
RUN rm -rf /etc/nginx/sites-enabled/default
RUN mkdir /var/www/localhost/autoindex
COPY srcs/localhost.conf /var/www/localhost/autoindex
COPY srcs/autoindex_off.conf /var/www/localhost/autoindex
COPY srcs/autoindex_on.sh .
COPY srcs/autoindex_off.sh .
#COPY srcs/index.html /var/www/localhost

RUN chown -R www-data:www-data /var/www/localhost && \
	chmod -R 755 /var/www/localhost

# SSL
RUN apt-get install openssl -y
RUN mkdir /etc/nginx/ssl
RUN chmod 700 /etc/nginx/ssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout /etc/nginx/ssl/example.key -out /etc/nginx/ssl/example.crt \
	-subj "/C=IT/ST=Lazio/L=Rome/O=42/OU=Luiss/CN=localhost"

#COPY srcs/index.html /var/www/localhost/
COPY srcs/start.sh ./

# Command to run when container starts
CMD bash start.sh
