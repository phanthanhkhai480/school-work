/***********************************************************************
*  BTI325 – Assignment 3
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  No part *  of this assignment has been copied manually or electronically from any other source 
*  (including 3rd party web sites) or distributed to other students.
* 
*  Name: Khai Phan Student ID: 100901164 Date: ________________
*
*  Online (Heroku) Link: ________________________________________________________
*
***********************************************************************/ 

const fs = require('fs');
var employees = [];
var departments = [];

module.exports.initialize = function () 
{
    return new Promise(function (resolve, reject) 
    {
        fs.readFile('./data/employees.json', (err, data) =>
        {
            if (err) 
            {
                reject("could not open employees.json");
            }
            else
            {
                employees = JSON.parse(data);
                fs.readFile('./data/departments.json', (err, data) => 
                {
                    if (err) 
                    {
                        reject("could not open departments.json");
                    }
                    else
                    {
                        departments = JSON.parse(data);
                        resolve();
                    }
                });
            }
        });
    });
};


module.exports.getAllEmployees = function () 
{
   return new Promise(function (resolve, reject) 
    {  
        if (employees.length == 0) 
        {
            reject("query returned 0 results");
        }
       resolve(employees);
    });
};

module.exports.getEmployeesByStatus = function (status) 
{
    return new Promise(function (resolve, reject) 
    {
       var filteredEmployeees = [];
       for (let a = 0; a < employees.length; a++) 
        {
            if (employees[a].status == status) 
            {
               filteredEmployeees.push(employees[a]);
            }
        }
        if (filteredEmployeees.length == 0) 
        {
             reject("query returned 0 results");
        }
        resolve(filteredEmployeees);
    });
};

module.exports.getEmployeesByDepartment = function (department) 
{
    return new Promise(function (resolve, reject) 
    {
        var filteredEmployeees = [];
        for (let a = 0; a < employees.length; a++) 
        {
           if (employees[a].department == department) 
            {
                filteredEmployeees.push(employees[a]);
            }
        }
        if (filteredEmployeees.length == 0) 
        {
            reject("query returned 0 results");
        }

       resolve(filteredEmployeees);
   });
};

module.exports.getEmployeesByManager = function (manager) 
{
    return new Promise(function (resolve, reject) 
    {
        var filteredEmployeees = [];
        for (let i = 0; i < employees.length; i++) 
        {
            if (employees[i].employeeManagerNum == manager) 
            {
                filteredEmployeees.push(employees[i]);
            }
        }
        if (filteredEmployeees.length == 0) 
        {
            reject("query returned 0 results");
        }

        resolve(filteredEmployeees);
   });
};

module.exports.getManagers = function () 
{
   return new Promise(function (resolve, reject) 
   {
        var filteredEmployeees = [];
        for (let i = 0; i < employees.length; i++) 
        {
            if (employees[i].isManager == true) 
            {
                filteredEmployeees.push(employees[i]);
            }
        }

        if (filteredEmployeees.length == 0) 
        {
            reject("query returned 0 results");
        }
        resolve(filteredEmployeees);
   });
};

module.exports.getEmployeeByNum = function (num) 
{
    return new Promise(function (resolve, reject) 
    {
        var foundEmployee = null;
        for (let i = 0; i < employees.length; i++) 
        {
            if (employees[i].employeeNum == num) 
            {
                foundEmployee = employees[i];
            }
        }
        if (!foundEmployee) 
        {
            reject("query returned 0 results");
        }
        resolve(foundEmployee);
    });
};

module.exports.getDepartments = function () 
{
    return new Promise(function (resolve, reject) 
    {
        if (departments.length == 0) 
        {
            reject("query returned 0 results");
        }
        resolve(departments);
    });
};