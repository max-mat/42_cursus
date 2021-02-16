# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatsego <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/13 13:13:54 by mmatsego          #+#    #+#              #
#    Updated: 2021/02/16 14:18:38 by mmatsego         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Install the base image
FROM debian:buster

# Update package list & upgrade system
RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install vim

# NGINX
RUN apt-get -y install nginx

# MARIADB
# RUN apt-get -y install mariadb-server

# PHP set of extentions to communicate with MariaDB
# RUN apt-get -y install php-fpm php-mysql

# Expose port 80 for HTTP and 443 for HTTPS. So container listens these ports
EXPOSE 80 443

# Create the root-directory for our domain
RUN mkdir /var/www/localhost

# NGINX
COPY srcs/localhost.conf /etc/nginx/sites-available/localhost.conf
RUN ln -s /etc/nginx/sites-available/localhost.conf /etc/nginx/sites-enabled/
RUN rm -rf /etc/nginx/sites-enabled/default
RUN mkdir /var/www/localhost/autoindex
COPY srcs/localhost.conf /var/www/localhost/autoindex
COPY srcs/autoindex_off.conf /var/www/localhost/autoindex
COPY srcs/autoindex_on.sh .
COPY srcs/autoindex_off.sh .
#RUN chown -R www-data:www-data /var/www/localhost && \
#	chmod -R 755 /var/www/localhost

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
