/**
 * Activity to implement the register feature.
 *
 * @author Khai Phan (03/07/2020)
 */

package com.example.assignment2;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.toolbox.Volley;

import org.json.JSONException;
import org.json.JSONObject;

public class RegisterActivity extends AppCompatActivity {
    EditText userName, password, rePassword;
    Button btnRegister, registerBack;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        //assigning all EditText field to local attribute for any later modification
        userName = (EditText)findViewById(R.id.userName);
        password = (EditText)findViewById(R.id.password);
        rePassword = (EditText)findViewById(R.id.rePassword);
        btnRegister = (Button)findViewById(R.id.btnRegister);
        registerBack = (Button)findViewById(R.id.registerBack);

        /*
         * fetch current information in the EditText and do some checks
         * pass the information into RegisterRequest for insert into cloud database
         * use dialog to promp user whether their account has been created or not
         */
        btnRegister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                final String m_username = userName.getText().toString();
                final String m_password = password.getText().toString();
                final String m_rePassword = rePassword.getText().toString();

                if(!m_username.equals("") || !m_password.equals("") || !m_rePassword.equals("")) {
                    if(m_rePassword.equals(m_password)) {

                        //create a listener for the JSON data
                        Response.Listener<String> responseListener = new Response.Listener<String>() {
                            @Override
                            public void onResponse(String response) {
                                try {
                                    //create an object and wait for the response message from system
                                    JSONObject jsonResponse = new JSONObject(response);
                                    boolean success = jsonResponse.getBoolean("success");

                                    //check for the response message matching
                                    if(success){ create();
                                    } else { alert(); }

                                    //throw an exception if something is fail
                                } catch (JSONException e) {     e.printStackTrace();    }
                            }
                        };

                        //passing information to RegisterRequest to update database
                        RegisterRequest registerRequest = new RegisterRequest(m_username, m_password, m_rePassword, responseListener);

                        //add RegisterRequest to queue if there is other operation performing
                        RequestQueue queue = Volley.newRequestQueue(RegisterActivity.this);
                        queue.add(registerRequest);
                    } else { alert(); }
                } else
                    Toast.makeText(RegisterActivity.this, "Field(s) is missing!!", Toast.LENGTH_SHORT).show();
            }
        });

        /*
         * going back to the previous activity
         */
        registerBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(RegisterActivity.this, MainActivity.class);
                startActivity(intent);
            }
        });
    }

    /**
     * create dialog method for display a password alert
     */
    private void alert() {
        AlertDialog.Builder dialogBuilder = new AlertDialog.Builder(RegisterActivity.this);
        dialogBuilder.setMessage("Password Does Not Match");
        dialogBuilder.setPositiveButton("OK", null);
        dialogBuilder.show();
    }

    /**
     * create dialog method to display user has been created
     */
    private void create() {
        AlertDialog.Builder alertDialog = new AlertDialog.Builder(RegisterActivity.this);
        alertDialog.setMessage("Account has been created successfully!");
        alertDialog.setPositiveButton("OK", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                Intent intent = new Intent(RegisterActivity.this, MainActivity.class);
                startActivity(intent);
            }
        });
        alertDialog.show();
    }
}
