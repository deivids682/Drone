package eliseo.dronecontroller;

import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;


public class MainActivity extends AppCompatActivity implements View.OnClickListener {


    Button mPUP, mPDOWN, mAvanti, mIndietro, mSinistra, mDestra, mConnetti;

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
        switch (v.getId()){
            case R.id.button5: //Aumenta altezza
                break;
            case R.id.button6: //Diminuisci altezza
                break;
            case R.id.button: //Vai avanti
                break;
            case R.id.button2: //Vai indietro
                break;
            case R.id.button3: //Vai a sinistra
                break;
            case R.id.button4: //Vai a destra
                break;
            case R.id.button7: //Connetti
                break;

        }
    }
}
