var express = require("express");
var express1 = require("./data-service.js");
var app = express();
var path = require("path");

var HTTP_PORT = process.env.PORT || 8080;
app.listen(HTTP_PORT, onHttpStart);
app.use(express.static('public'));

function onHttpStart() 
{
  console.log("Express HTTP server listening on: " + HTTP_PORT);
}

app.get("/", function(req,res)
{
   res.sendFile(path.join(__dirname + "/views/home.html"));
});

app.get("/about", function(req,res)
{
   res.sendFile(path.join(__dirname + "/views/about.html"));
});

app.get("/employees", (req,res) =>
{
  if(req.query.status)
  {
    express1.getEmployeesByStatus(req.query.status).then((data) => 
    {
      res.json(data);
    }).catch((err) =>
    {
      res.json('No Result');
    })
  }
  else if(req.query.department)
  {
    express1.getEmployeesByDepartment(req.query.department).then((data) => 
    {
      res.json(data);
    }).catch((err) =>
    {
      res.json('No Result');
    })
    
  }
  else if(req.query.manager)
  {
    express1.getEmployeesByManager(req.query.manager).then((data) => 
    {
      res.json(data);
    }).catch((err) =>
    {
      res.json('No Result');
    })
  }
  else
  {
    express1.getAllEmployees().then((data) => 
    {
      res.json(data);
    }).catch((err) =>
    {
      res.json('No Result');
    })
  }
}); 


app.get("/employees/:value", (req,res) =>
{
  express1.getEmployeeByNum(req.params.value).then((data =>
  {
    res.json(data);
  }).catch((err) =>
  {
    res.json('No Result');
  }))
});


app.get("/managers", (req,res) =>
{
  express1.getManagers().then((data) => 
  {
    res.json(data);
  }).catch((err) =>
  {
    res.json('No Result');
  })
});

app.get("/departments", (req,res) =>
{
  express1.getDepartments().then((data) => 
  {
    res.json(data);
  }).catch((err) =>
  {
    res.json('No Result');
  })
});

app.use((req, res) => {
  res.status(404).send("Error: Page not found.");
});


