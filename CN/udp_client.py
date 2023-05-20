import socket
if __name__=="__main__":
    host = '127.0.0.1'
    port=4455
    addr= (host,port)

    client = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

    while True:
        data = input("Enter a word: ")
        data=data.encode("utf-8")

        client.sendto(data,addr)

        data , addr = client.recvfrom(1024)

        data.decode("utf-8")

        print("Server: ",data)

