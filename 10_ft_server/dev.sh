docker container prune -f
docker build -t try .
docker run --name prova -it -p 80:80 -p 443:443 try
