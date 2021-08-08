/**
 * Model class for RegisterRequest object.
 *
 * @author Khai Phan (03/07/2020)
 */

package com.example.assignment2;

import com.android.volley.Response;
import com.android.volley.toolbox.StringRequest;

import java.util.HashMap;
import java.util.Map;

public class RegisterRequest extends StringRequest {
    private static final String REGISTER_REQUEST_URL = "https://received-blueprints.000webhostapp.com/register.php" ;
    private Map<String, String> params;

    /**
     * take the parameter and send it to the server for database storage
     * @param username contains username string user entered
     * @param password contain password string user entered
     * @param rePassword contain rePassword string user entered
     * @param listener contain listener to listen for any feedback or response
     */
    RegisterRequest(String username, String password, String rePassword, Response.Listener<String> listener){
        super(Method.POST, REGISTER_REQUEST_URL, listener, null);
        params = new HashMap<>();
        params.put("username", username);
        params.put("password", password);
        params.put("rePassword", rePassword);
    }

    /**
     * create a Map that stored the params (username and password) of user
     * @return that stored the username and password of user
     */
    @Override
    public Map<String, String> getParams() {
        return params;
    }
}

