#!/bin/bash

cp /var/www/localhost/autoindex/localhost.conf /etc/nginx/sites-available/
service nginx restart
echo "autoindex on"
