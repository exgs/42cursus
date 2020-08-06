use mysql;
update user set plugin='' where User='root';
flush privileges;

-- wordpress 설정
create database wordpress;
create user yunslee@localhost identified by '1234';
grant all privileges on wordpress.* to yunslee@localhost;
