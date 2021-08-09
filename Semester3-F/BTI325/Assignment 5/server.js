/***********************************************************************
*  BTI325 – Assignment 5
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  No part *  of this assignment has been copied manually or electronically from any other source 
*  (including 3rd party web sites) or distributed to other students.
* 
*  Name: Khai Phan Student ID: 100901164 Date: Dec 7th, 2017
*
*  Online (Heroku) Link: https://pacific-waters-90722.herokuapp.com/
*
***********************************************************************/ 


var express = require("express");
var app = express();
var path = require("path");
var dataService = require("./data-service.js");
const exphbs = require('express-handlebars');
const bodyParser = require('body-parser');
const Sequelize = require('sequelize');
var HTTP_PORT = process.env.PORT || 8080;
app.use(express.static('public'));
app.use(bodyParser.urlencoded({ extended: true }));
app.set("view engine", ".hbs");


app.engine(".hbs", exphbs({
  extname: ".hbs",
  defaultLayout: 'layout',
  helpers: {
    equal: function (lvalue, rvalue, options) {
      if (arguments.length < 3)
        throw new Error("Handlebars Helper equal needs 2 parameters");
      if (lvalue != rvalue) {
        return options.inverse(this);
      } else {
        return options.fn(this);
      }
    }
  }
}));

function onHttpStart() 
{
  console.log("Express http server listening on: " + HTTP_PORT);
};

dataService.initialize().then(function () 
{
  app.listen(HTTP_PORT, onHttpStart);
}).catch(function () 
{
  console.log("unable to start dataService");
});

app.get("/", (req, res) => 
{
  res.render("home");
});

app.get("/about", (req, res) => 
{
  res.render("about");
});

app.get("/employees", (req, res) => 
{

  if (req.query.status) 
  {
    dataService.getEmployeesByStatus(req.query.status).then((data) => 
    {
      res.render("employeeList", { data: data, title: "Employees" });
    }).catch((err) => 
    {
      res.render("employeeList", { data: {}, title: "Employees" });
    });
  }

  else if (req.query.department) 
  {
    dataService.getEmployeesByDepartment(req.query.department).then((data) => 
    {
      res.render("employeeList", { data: data, title: "Employees"});
    }).catch((err) => 
    {
      res.render("employeeList", { data: {}, title: "Employees" });
    });
  }

  else if (req.query.manager) 
  {
    dataService.getEmployeesByManager(req.query.manager).then((data) => 
    {
      res.render("employeeList", { data: data, title: "Employees" });
    }).catch((err) => 
    {
      res.render("employeeList", { data: {}, title: "Employees" });
    });
  }

  else 
  {
    dataService.getAllEmployees().then((data) => 
    {
      res.render("employeeList", { data: data, title: "Employees" });
    }).catch((err) => 
    {
      res.render("employeeList", { data: {}, title: "Employees" });
    });
  }
});

app.get("/employee/:empNum", (req, res) => 
{
    // initialize an empty object to store the values
    let viewData = {};
    dataService.getEmployeeByNum(req.params.empNum)
    .then((data) => 
    {
      viewData.data = data; //store employee data in the "viewData" object as "data"
    }).catch(()=>
    {
      viewData.data = null; // set employee to null if there was an error 
    }).then(dataService.getDepartments)
    .then((data) => 
    {
      viewData.departments = data; // store department data in the "viewData" object as "departments"
        // loop through viewData.departments and once we have found the departmentId that matches
        // the employee's "department" value, add a "selected" property to the matching 
        // viewData.departments object
       for (let i = 0; i < viewData.departments.length; i++) 
       {
          if (viewData.departments[i].departmentId == viewData.data.department) 
          {
            viewData.departments[i].selected = true;
          }
        }
    }).catch(()=>
    {
      viewData.departments=[]; // set departments to empty if there was an error
    }).then(()=>
    {
      if(viewData.data == null)
      { // if no employee - return an error
        res.status(404).send("Employee Not Found");
      }
      else
      {
        res.render("employee", { viewData: viewData }); // render the "employee" view
      }
    });
});
  
app.get("/managers", (req, res) => 
{
  dataService.getManagers().then((data) => 
  {
    res.render("employeeList", { data: data, title: "Employees (Managers)" });
  }).catch((err) => 
  {
    res.render("employeeList", { data: {}, title: "Employees (Managers)" });
  });
});  

app.get("/departments", (req, res) => 
{
  dataService.getDepartments().then((data) => 
  {
    res.render("departmentList", { data: data, title: "Departments" });
  }).catch((err) => 
  {
    res.render("departmentList", { data: {}, title: "Departments" });
  });
});

app.get("/employees/add", (req,res) => 
{
  dataService.getDepartments().then((data) => 
  {
    res.render("addEmployee", {departments: data});
  }).catch((err) => 
  {
    res.render("addEmployee", {departments: []}); 
  });
});

app.post("/employees/add", (req, res) => 
{
  dataService.addEmployee(req.body).then(()=>
  {
    res.redirect("/employees");
  });
});

app.post("/employee/update", (req, res) => 
{
  dataService.updateEmployee(req.body).then(() =>
  {
    res.redirect("/employees");
  });
});

app.get("/departments/add", (req,res) => 
{
  res.render("addDepartment");
});

app.post("/departments/add", (req,res) => 
{
  dataService.addDepartment(req.body).then(() => 
  {
    res.redirect("/departments");
  });
});

app.post("/departments/update", (req,res) => 
{
  dataService.updateDepartment(req.body).then(() => 
  {
    res.redirect("/departments");
  });
});

app.get("/department/:departmentID", (req,res) => 
{
  dataService.getDepartmentByID(req.params.departmentID).then((data) => 
  {
    res.render("department", { data: data });
  }).catch((err) => 
  {
    res.status(404).send("Department Not Found");
  });
});

app.get("/employee/delete/:empNum", (req, res) =>
{
  dataService.deleteEmployeeByNum(req.params.empNum).then((data) =>
  {
    res.redirect("/employees");
  }).catch((err) =>
  {
    res.status(500).send("Unable to Remove Employee / Employee not found");
  })
});

app.use((req, res) => 
{
  res.status(404).send("Page Not Found");
});

