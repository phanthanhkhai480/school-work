// Data for the "HTML Lists" Page
var fruits = [ "Apples","Oranges","Pears","Grapes","Pineapples","Mangos" ];

var directory = [
    {type: "file", name: "file1.txt"},
    {type: "file", name: "file2.txt"},
    {type: "directory", name: "HTML Files", files: [{type: "file", name: "file1.html"},{type: "file", name: "file2.html"}]},
    {type: "file", name: "file3.txt"},
    {type: "directory", name: "JavaScript Files", files: [{type: "file", name: "file1.js"},{type: "file", name: "file2.js"},{type: "file", name: "file3.js"}]}
];


window.onload = function()
{
	var show = document.querySelector("#Fruits");
	var order = document.createElement("ol");
		for(var counter = 0; counter < fruits.length; counter++)
		{
			var list = document.createElement("li");
			var fruit = document.createTextNode(fruits[counter]);
			list.appendChild(fruit);
			order.appendChild(list);
		}
	show.appendChild(order);
	
	var show = document.querySelector("#Directory");
	var unorder = document.createElement("ul");
		for(var counter = 0; counter < directory.length; counter++)
		{
			if(directory[counter].type == "file")
			{
				var one = document.createElement("li");
				var two = document.createTextNode(directory[counter].name);
				one.appendChild(two);
				unorder.appendChild(one);
			}
			else
			{
				var three = document.createElement("li");
				var four = document.createTextNode(directory[counter].name);
				three.appendChild(four);
				var five = document.createElement("ul");
				for (var count = 0; count < directory[counter].files.length; count++)
				{
					var six = document.createElement("li");
					var seven = document.createTextNode(directory[counter].files[count].name);
					six.appendChild(seven);
					five.appendChild(six);
				}
				three.appendChild(five);
				unorder.appendChild(three);
			}
		}
	show.appendChild(unorder);
}



