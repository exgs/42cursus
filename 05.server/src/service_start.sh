#!bin/bash
#!bin/sh

service mysql start

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt << EOF
KO
Seoul
Seoul City
innovation academy
42Seoul
yunslee
yunslee@naver.com
EOF
openssl dhparam -out /etc/ssl/certs/dhparam.pem 2048

#Setting root password
mysql_secure_installation << EOF
y
y
1234
1234
y
y
y
y
EOF
echo "secure_installatioin end!"
mysql << EOF
source config.sql
EOF
echo "config mysql end!"

service nginx start
service php7.3-fpm start
#bash
