import socket
if __name__=="__main__":
    host = '127.0.0.1'
    port=4455

    server = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    server.bind((host,port))

    while True:
        data, addr = server.recvfrom(1024)
        data.decode("utf-8")

        print("Client: ",data)

        data=data.upper()

        server.sendto(data,addr)
