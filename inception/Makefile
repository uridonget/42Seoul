all : up

up :
	if [ ! -d "/home/haejeong/data" ]; then \
		mkdir /home/haejeong/data; \
	fi
	if [ ! -d "/home/haejeong/data/html" ]; then \
		mkdir /home/haejeong/data/html; \
	fi
	if [ ! -d "/home/haejeong/data/mysql" ]; then \
		mkdir /home/haejeong/data/mysql; \
	fi
	docker-compose -f srcs/docker-compose.yml up --build

down :
	docker-compose -f srcs/docker-compose.yml down

clean : down
	docker stop $$(docker ps -q); \
	docker rm $$(docker ps -a -q); \
	docker image rmi -f $$(docker image ls -q); \
	docker volume rm $$(docker volume ls -q); \
	docker builder prune -f

	rm -rf /home/haejeong/data/html/*
	rm -rf /home/haejeong/data/mysql/*

.PHONY : all up down clean
