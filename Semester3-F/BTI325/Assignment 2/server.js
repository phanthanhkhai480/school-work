/***********************************************************************
*  BTI325 – Assignment 2
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  No part *  of this assignment has been copied manually or electronically from any other source 
*  (including 3rd party web sites) or distributed to other students.
* 
*  Name: Khai Phan Student ID: 100901164 Date: September 18th, 2017
*
*  Online (Heroku) Link: https://rocky-hollows-23468.herokuapp.com/
*
***********************************************************************/ 



var express = require("express");
var app = express();
var path = require("path");

var HTTP_PORT = process.env.PORT || 8080;

function onHttpStart() 
{
  console.log("Express http server listening on: " + HTTP_PORT);
}

app.get("/", function(req,res)
{
   res.sendFile(path.join(__dirname + "/views/home.html"));
});

app.get("/about", function(req,res)
{
   res.sendFile(path.join(__dirname + "/views/about.html"));
});

app.listen(HTTP_PORT, onHttpStart);
app.use(express.static('public'));