/**
 * Class to implement a login request.
 *
 * @author Khai Phan and Carlianz Pura (03/07/2020)
 */

package com.example.assignment2;

import com.android.volley.Response;
import com.android.volley.toolbox.StringRequest;

import java.util.HashMap;
import java.util.Map;

public class LoginRequest extends StringRequest {
    private static final String LOGIN_REQUEST_URL = "https://received-blueprints.000webhostapp.com/login.php" ;
    private Map<String, String> params;

    /**
     * initialize a request for login, send the data to server for comparision
     * @param username contains username string user entered
     * @param password contain password string user entered
     * @param listener contain listener to listen for any feedback or response
     */
    LoginRequest(String username, String password, Response.Listener<String> listener){
        super(Method.POST, LOGIN_REQUEST_URL, listener, null);
        params = new HashMap<>();
        params.put("username", username);
        params.put("password", password);
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