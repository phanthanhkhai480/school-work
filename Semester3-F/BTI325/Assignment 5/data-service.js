const Sequelize = require('sequelize');


var sequelize = new Sequelize('dfq1b16g0knn5j', 
'ehkqdawyulwqnn', 
'ba11eef7592be43245d7573d2e9f3100fc7249dae875e3043efe90f3d63fc69c', 
    {
        host: 'ec2-184-72-230-93.compute-1.amazonaws.com',
        dialect: 'postgres',
        port: 5432,
        dialectOptions: 
        {
            ssl: true
        }
});

sequelize
.authenticate()
.then(function() 
{
    console.log('Connection has been established successfully.');
}).catch(function(err) 
{
    console.log('Unable to connect to the database:', err);
});

var employees = sequelize.define('employees',
{
  employeeNum: {type: Sequelize.INTEGER,
                primaryKey: true,
                autoIncrement: true},
  firstName: Sequelize.STRING,
  lastName: Sequelize.STRING,
  email: Sequelize.STRING,
  SSN: Sequelize.STRING,
  addressStreet: Sequelize.STRING,
  addressCity: Sequelize.STRING,
  addressState: Sequelize.STRING,
  addressPostal: Sequelize.STRING,
  martialStatus: Sequelize.STRING,
  isManager: Sequelize.BOOLEAN,
  employeeManagerNum: Sequelize.INTEGER,
  status: Sequelize.STRING,
  department: Sequelize.INTEGER,
  hireDate: Sequelize.STRING
});

var departments = sequelize.define('departments',
{
  departmentID: {type: Sequelize.INTEGER,
    primaryKey: true,
    autoIncrement: true},
  departmentName: Sequelize.STRING
});

sequelize.sync().then(function()
{
    employees.create(
    {
      title: 'employees',
      description: 'employees table'
    }).then(function (employees) 
    {
      console.log("Table Employees created!")
    }).catch(function (error) 
    {
      console.log("Something went wrong (Employees Table)!");
    });

    departments.create(
      {
        title: 'departments',
        description: 'departments table'
      }).then(function (departments) 
      {
        console.log("Table Department created!")
      }).catch(function (error) 
      {
        console.log("Something went wrong (Department Table)!");
      });
});

module.exports.initialize = function () 
{
    return new Promise(function (resolve, reject) 
    {    
        sequelize.sync().then( () => 
        {   
            resolve();
        }).catch(() => 
        {
            reject();
        });
    });    
};

module.exports.getAllEmployees = function () 
{
    return new Promise(function (resolve, reject) {  
        employees.findAll(
        {
            order: ['employeeNum']
        }).then(function(data)
        {
            resolve(data);
    }).catch(function(data)
        {
            reject("Something went wrong!");
        })
})};


module.exports.getEmployeesByStatus = function (status) 
{
    return new Promise(function (resolve, reject) {
        employees.findAll( 
            {
                where: {status: status}
            }).then(function(data)
            {
                resolve(data);
        }).catch(function(data)
            {
                reject("Something went wrong!");
            })
})};

module.exports.getEmployeesByDepartment = function (dep) 
{
    return new Promise(function (resolve, reject) {
        employees.findAll(
            {
                where: {department: dep}
            }).then(function(data)
            {
                resolve(data);
        }).catch(function(data)
            {
                reject("Something went wrong!");
            })
})};

module.exports.getEmployeesByManager = function (manager) 
{
    return new Promise(function (resolve, reject) {
        employees.findAll(
            {
                where: {employeeManagerNum: manager}
            }).then(function(data)
            {
                resolve(data);
        }).catch(function(data)
            {
                reject("Something went wrong!");
            })
})};

module.exports.getManagers = function () 
{
    return new Promise(function (resolve, reject) 
    {
        employees.findAll(
            {
                where: {isManager: true}
            }).then(function(data)
            {
                resolve(data);
            }).catch(function(data)
                {
                    reject("Something went wrong!");
                })
})};

module.exports.getEmployeeByNum = function (num) 
{
    return new Promise(function (resolve, reject) {
        sequelize.sync().then(function()
        {
            employees.findAll(
                { 
                    where: {employeeNum: num}    
                }).then(function(data)
                {
                    resolve(data[0]);
                }).catch(function(data)
                {
                    reject("Something went wrong!");
                })
        }).catch(function(){
            reject("unable to update employee.");
        });
})};

module.exports.getDepartments = function () 
{
    return new Promise(function (resolve, reject) {  
        var check = 0;
        departments.findAll(
        {
            order: ['departmentID']
        }).then(function(data)
        {
            resolve(data);
        }).catch(function(data)
            {
                reject("Something went wrong!");
            })
})};

module.exports.addEmployee = function (employeeData) 
{
    return new Promise(function (resolve, reject) 
    {
        sequelize.sync().then(function()
        {
            for (let a in employeeData) 
            {
                if(employeeData[a] == "") 
                {
                    employeeData[a] = null;
                }
            }
            employees.create({
                employeeNum: employeeData.employeeNum,
                firstName: employeeData.firstName,
                lastName: employeeData.lastName,
                email: employeeData.email,
                SSN: employeeData.SSN,
                addressStreet: employeeData.addressStreet,
                addressCity: employeeData.addressCity,
                addressState: employeeData.addressState,
                addressPostal: employeeData.addressPostal,
                martialStatus: employeeData.martialStatus,
                isManager: employeeData.isManager,
                employeeManagerNum: employeeData.employeeManagerNum,
                status: employeeData.status,
                department: employeeData.department,
                hireDate: employeeData.hireDate
            }).then(function(data) 
            {
                resolve(data);
            }).catch(function(err)
            {
                reject("Unable to create Employee.");
            });
        }).catch(function()
        {
            reject("Unable to create Employee.");
        });
    })};

module.exports.updateEmployee = function(employeeData) 
{
    return new Promise(function (resolve, reject) 
    {
        employeeData.isManager = (employeeData.isManager)? true : false;  
        for (var a in employeeData) 
        {
            if (employeeData[a] == "") 
            {
               employeeData[a] = null;
            }
        }
        employees.update(employeeData, {where: {employeeNum: employeeData.employeeNum }}).then(function() 
        {
            resolve();
        }).catch(function() 
        {
            reject("Could not update employee");
        })
    });
}

module.exports.addDepartment = function(departmentData)
{ 
    return new Promise(function (resolve, reject) 
    {
        sequelize.sync().then(function()
        {
            for (let a in departmentData) 
            {
                if(departmentData[a] == "") 
                {
                    departmentData[a] = null;
                }
            }
            departments.create({
                departmentID: departmentData.departmentID,
                departmentName: departmentData.departmentName
            }).then(function() 
            {
                resolve(departments);
            }).catch(function(err)
            {
                reject("unable to create department.");
            });
        }).catch(function()
        {
            reject("unable to create department.");
        });
    });
};

module.exports.updateDepartment = function(departmentData) 
{
    return new Promise (function(resolve, reject) 
    {
        for (a in departmentData) 
        {
            if (departmentData[a] == "") 
            {
                departmentData[a] = null;
            }
        }
        departments.update({
            departmentName: departmentData.departmentName},
            {where: { departmentID: departmentData.departmentID }
        }).then(function() 
        {
            resolve();
        }).catch(function() 
        {
            reject("Could not update department");
        })
    })
}

module.exports.getDepartmentByID = function(ID)
{
    return new Promise(function (resolve, reject) 
    {
        departments.findAll(
            {
                where: {departmentID: ID}
            }).then(function(data)
            {
                resolve(data[0]);
            }).catch(function(error)
            {
                reject("Something went wrong!");
            })
})};

module.exports.deleteEmployeeByNum = function(empNum)
{ 
    return new Promise(function(resolve,reject)
    {
        sequelize.sync().then(function()
        {
            resolve(employees.destroy(
            {
                where:
                {
                    employeeNum: empNum
                }
            }));
        }).catch(function(err)
        {
            reject();
        });           
    });
};

