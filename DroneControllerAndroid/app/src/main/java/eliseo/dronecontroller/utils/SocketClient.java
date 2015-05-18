package eliseo.dronecontroller.utils;

/**
 * Created by eliseomartelli on 18/05/15.
 */

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;

public class SocketClient {

    Socket connection;

    public SocketClient(String host, int port) throws Throwable{
        connection = new Socket(host, port);
    }

    public void sendMessageSocket(String message) throws Throwable {
        DataOutputStream dataOutputStream = new DataOutputStream(connection.getOutputStream());
        dataOutputStream.writeUTF(message);
        dataOutputStream.flush();
    }

    public String receiveMessageSocket() throws Throwable{
        DataInputStream dataInputStream = new DataInputStream(connection.getInputStream());

        return dataInputStream.readUTF();
    }


    public boolean isConnected(){
        return connection.isConnected();
    }

}