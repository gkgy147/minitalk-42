# minitalk-42
Create a communication program - in C - in the form of a client and server. The server is the first one to be launched, having to display its PID after. The client will take as parameters the server PID and the string to be sent. Once the string has been received by the server, this one should display it.

This communication should only be done using Unix signals. Only two signals can be used SIGUSR1 and SIGUSR2. The executable files are named client and server.
