import socket
if __name__=="__main__":
    host = '127.0.0.1'
    port=4455

    server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    server.bind((host,port))
    server.listen(2)

    while True:
        client, addr = server.accept()
        print(f"Connection established - {addr[0]}:{addr[1]}")
        
        data = client.recv(1024)
        data=  data.decode("utf-8")
        print("Client: ",data)
        data = data.upper()
        client.send(bytes(data,"utf-8"))

        client.close()
