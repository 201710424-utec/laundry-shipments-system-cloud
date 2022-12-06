FROM alpine
WORKDIR /app
COPY src/ src/
COPY Makefile .
RUN apk --no-cache add make gcc g++
RUN make
WORKDIR ./laundry-shipments-system
CMD ["./laundry-shipments-system.exe"]
