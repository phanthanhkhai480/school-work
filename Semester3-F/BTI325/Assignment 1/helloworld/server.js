/*********************************************************************************
* BTI325 – Assignment 1
* I declare that this assignment is my own work in accordance with Seneca Academic Policy.
* No part of this assignment has been copied manually or electronically from any other source
* (including web sites) or distributed to other students.
*
* Name: Khai Phan Student ID: 100901164 Date: Sep 12th, 2017
*
* Online (Heroku) URL: https://guarded-taiga-51375.herokuapp.com/
*
********************************************************************************/ 

var HTTP_PORT = process.env.PORT || 8080;
var express = require("express");
var app = express();

// setup a 'route' to listen on the default url path
app.get("/", (req, res) => {
    res.send("Khai Phan - 100901164");
});

// setup http server to listen on HTTP_PORT
app.listen(HTTP_PORT);