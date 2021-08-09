// Data for the "HTML Tables" Page

var users = [
    {first_name: "Kaitlin", last_name: "Burns", age: 23, email: "kburns99753@usermail.com"},
    {first_name: "Joshua", last_name: "Feir", age: 31, email: "josh319726@usermail.com"},
    {first_name: "Stephen", last_name: "Shaw", age: 28, email: "steve.shaw47628@usermail.com"},
    {first_name: "Timothy", last_name: "McAlpine", age: 37, email: "Timbo72469@usermail.com"},
    {first_name: "Sarah", last_name: "Connor", age: 19, email: "SarahC6320@usermail.com"}
];
window.onload = function() {
 var table = document.querySelector("#third");

 var first_raw = '<table border="1">' +
     "<caption>Users</caption>" + 
     "<tr>" + 
         "<th>First Name</th>" +
         "<th>Last Name</th>" +
         "<th>Age</th>" +
         "<th>Email</th>" +
     "</tr>";
 var last_raw = "</table>";
 var others = "";

 for(var i = 0; i < users.length; i++) {    
     others += "<tr>" +
          "<td>" + users[i].first_name + "</td>" +
          "<td>" + users[i].last_name + "</td>" +
          "<td>" + users[i].age + "</td>" +
          "<td>" + '<a href="mailto:allan.randall@senecacollege.ca">' + users[i].email + "</a>" + "</td>" +
          "</tr>";
 }

 table.innerHTML = first_raw + others + last_raw + "<p></p>";
 document.querySelector("#third").appendChild(table);
}; 

window.onload = function() 
{
	var table = document.querySelector("#Chart");
	var one = '<table border="1">' + 
				"<tr>" + 
					"<th> First Name </th>" +
					"<th> Last Name </th>" +
					"<th> Age </th>" +
					"<th> Email </th>" +
				"</tr>";
	var two = "</table>";
	var three = "";

	for(var counter = 0; counter < users.length; counter++) 
	{    
		three += "<tr>" + "<th>" + users[counter].first_name + "</th>" + "<th>" + users[counter].last_name + "</th>" + "<th>" + users[counter].age + "</th>" + 
						  "<th>" + '<a href="mailto:' + users[counter].email + '">' + users[counter].email + "</a>" + "</th>" + "</tr>";
	}
	table.innerHTML = one + three + two + "<p></p>";
	table.appendChild(table);
};

 // window.onload = function()
 // {
	// var show = document.querySelector("#Chart");
	// //var thetable = document.createElement('table');
	// //thetable.getAttribute("border = '1'");
	
	// var table = show.innerHTML = "<th> First Name </th>" +
								 // "<th> Last Name </th>" +
								 // "<th> Age </th>" +
								 // "<th> Email </th>";
	
	// for (var counter = 0; counter < users.length; counter++)
	// {
		// var one = document.createElement('tr');
		
		// var two = document.createElement('th');
		// var three = document.createTextNode(users[counter].first_name);
		// two.appendChild(three);
		
		// var open1 = document.createElement('th');
		// var four = document.createTextNode(users[counter].last_name);
		// open1.appendChild(four);
		
		// var open2 = document.createElement('th');
		// var five = document.createTextNode(users[counter].age);
		// open2.appendChild(five);
		
		// var open3 = document.createElement('th');
		// var hyper = open3.innerHTML = "<a href='mailto:" + users[counter].email + "'>";
		// var seven = document.createTextNode(users[counter].email);
		// var eight = seven.innerHTML = "</a>";
		// open3.appendChild(seven);
		
		
		// one.appendChild(two);
		// one.appendChild(open1);
		// one.appendChild(open2);
		// one.appendChild(open3);
		// show.appendChild(one);
	// }
// }