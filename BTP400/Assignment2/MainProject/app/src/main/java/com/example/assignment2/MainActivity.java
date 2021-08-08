/**
 * Activity to implement the login and register features.
 *
 * @author Khai Phan and Carlianz Pura (03/07/2020)
 */

package com.example.assignment2;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.toolbox.Volley;

import org.json.JSONException;
import org.json.JSONObject;

//First activity that is loaded when the app starts.
public class MainActivity extends AppCompatActivity {

    EditText username, password;
    TextView info2;
    Button btnLogin, btnRegister;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //assigning all EditText field to local attribute for any later modification
        username = (EditText)findViewById(R.id.userName);
        password = (EditText)findViewById(R.id.password);
        info2 = (TextView)findViewById(R.id.info2);
        btnLogin = (Button)findViewById(R.id.btnLogin);
        btnRegister = (Button)findViewById(R.id.btnRegister);

        /*
         * attempt to login by fetching username and password information
         * send the data information to LoginRequest where it will handle information comparison
         */
        btnLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                final String m_username = username.getText().toString();
                final String m_password = password.getText().toString();

                Response.Listener<String> responseListener = new Response.Listener<String>() {
                    @Override
                    public void onResponse(String response) {

                        try {
                            //create an object and wait for the response message from system
                            JSONObject jsonResponse = new JSONObject(response);
                            boolean success = jsonResponse.getBoolean("success");

                            //check for the response message matching
                            if(success) {
                                Intent intent = new Intent(MainActivity.this, SecondActivity.class);
                                startActivity(intent);
                            } else {
                                alert();
                                info2.setText(R.string.signup);
                            }

                        } catch (JSONException e) {     e.printStackTrace();    }

                    }
                };


                //passing information to LoginRequest to compare with database
                LoginRequest loginRequest = new LoginRequest(m_username, m_password, responseListener);

                //add RegisterRequest to queue if there is other operation performing
                RequestQueue queue = Volley.newRequestQueue(MainActivity.this);
                queue.add(loginRequest);

            }
        });

        /*
         * open Register tab for Register Service
         */
        btnRegister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, RegisterActivity.class);
                startActivity(intent);
            }
        });
    }

    /**
     * alert method that pop-up when user entered a wrong password or username
     */
    private void alert() {
        AlertDialog.Builder dialogBuilder = new AlertDialog.Builder(MainActivity.this);
        dialogBuilder.setMessage("Username or Password is incorrect");
        dialogBuilder.setPositiveButton("OK", null);
        dialogBuilder.show();
    }
}
