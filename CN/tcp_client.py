import socket
if __name__=="__main__":
    host = '127.0.0.1'
    port=4455
    
    server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    server.connect((host,port))
    data = input("Enter a word: ")

    server.send(bytes(data,"utf-8"))
    buff = server.recv(1024)
    buff = buff.decode("utf-8")
    print(f"Server: {buff}")



