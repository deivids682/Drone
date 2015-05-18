package eliseo.dronecontroller;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;

import eliseo.dronecontroller.utils.SocketClient;


public class MainActivity extends AppCompatActivity implements View.OnClickListener {


    Button mPUP, mPDOWN, mAvanti, mIndietro, mSinistra, mDestra, mConnetti;
    SocketClient socketClient;
    int altezza = 100;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mPUP = (Button) findViewById(R.id.button5);
        mPDOWN = (Button) findViewById(R.id.button6);
        mAvanti = (Button) findViewById(R.id.button);
        mIndietro = (Button) findViewById(R.id.button2);
        mSinistra = (Button) findViewById(R.id.button3);
        mDestra = (Button) findViewById(R.id.button4);
        mConnetti = (Button) findViewById(R.id.button7);

    }

    @Override
    public void onClick(View v) {

        try {
            if (v.getId() == R.id.button7) { //Connetti
                socketClient = new SocketClient("192.168.1.1", 8569);

            } else if (socketClient.isInitialized()) {
                switch (v.getId()) {
                    case R.id.button5: //Aumenta altezza
                        altezza = altezza+10; if (altezza > 350) altezza = 350;
                        break;
                    case R.id.button6: //Diminuisci altezza
                        altezza = altezza-10; if (altezza < 100) altezza = 100;
                        break;
                    case R.id.button: //Vai avanti
                        socketClient.sendMessageSocket("1");
                        break;
                    case R.id.button2: //Vai indietro
                        socketClient.sendMessageSocket("2");
                        break;
                    case R.id.button3: //Vai a sinistra
                        socketClient.sendMessageSocket("3");
                        break;
                    case R.id.button4: //Vai a destra
                        socketClient.sendMessageSocket("4");
                        break;
                }
            }
        } catch (Throwable e){
            e.printStackTrace();
        }
    }
}
