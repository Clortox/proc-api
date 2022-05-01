FROM ubuntu:latest AS build

RUN apt-get update && apt-get install -y curl build-essential git libboost-all-dev
RUN curl https://github.com/CrowCpp/Crow/releases/download/v1.0%2B2/crow-v1.0+2.deb -o crow.deb -L
RUN apt-get purge -y curl
RUN apt install -y ./crow.deb

WORKDIR /work
COPY ./ ./
RUN make clean && make



FROM ubuntu:latest
#WORKDIR /opt/proc-api
COPY --from=build /work/bin/proc-api ./

ENV PORT="5000"
ENV NAME="proc-api"
ENV THREADS="2"
ENV AUTH=""

CMD ./proc-api -p $PORT -n $NAME -t $THREADS $(if [ -z $AUTH ]; then echo ""; else echo "-a $AUTH"; fi)
