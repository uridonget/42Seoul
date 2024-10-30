FROM    debian:bullseye

RUN apt-get -y update
RUN apt-get -y install nginx openssl tini

# Self-signed certificate 생성
RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
       -out /etc/nginx/ssl/haejeong.crt \
       -keyout /etc/nginx/ssl/haejeong.key \
       -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=haejeong/CN=haejeong/"

COPY ./conf/default.conf /etc/nginx/conf.d

RUN mkdir -p /run/nginx

EXPOSE 443

ENTRYPOINT ["/usr/bin/tini", "--"]

CMD ["nginx", "-g", "daemon off;"]