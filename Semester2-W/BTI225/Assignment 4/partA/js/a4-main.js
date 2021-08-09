var filterType = ""; // sets the filter type to "" (will later be dog, cat or bird)
var filterAgeMin = 0; // sets the filter age min to 0 (for no minimum age filter)
var filterAgeMax = Number.MAX_VALUE; // sets the filter age max to the largest number possible (for no maximum age filter)

window.onload = function ()
{
	loadTableWithFilter();
}

loadTableWithFilter = function()
{
	var display = document.querySelector("#main-table-body");
	for(var counter = 0; counter < petData.length; counter++)
	{
		var one = document.createElement("tr");
		var two = document.createElement("td");
			var three = document.createElement("img");
			three.setAttribute("src", petData[counter].image.src);
			three.setAttribute("alt", petData[counter].image.alt);
			three.setAttribute("width", petData[counter].image.width);
			three.setAttribute("height", petData[counter].image.height);
			document.body.appendChild(three);
			two.appendChild(three);
		one.appendChild(two);
		var four = document.createElement("td");
			var five = document.createElement("h4");
			var six = document.createTextNode(petData[counter].name);
		five.appendChild(six);
		four.appendChild(five);
		var seven = document.createElement("p");
			var eight = seven.innerHTML += petData[counter].description;
		four.appendChild(seven);
		var nine = document.createElement("span");
			var ten = nine.innerHTML += "Age: " + petData[counter].age + " years old";
		four.appendChild(nine);
		one.appendChild(four);
		display.appendChild(one);
	}
}

function filterDog()
{
	filterType = dog;
	loadTableWithFilter();
	// for (var counter = 0; counter < petData.length; counter++)
	// {
		// var display = document.querySelector("#main-table-body");
		// if(petData[counter].type == "dog")
		// {
			// var one = document.createElement("tr");
		// var two = document.createElement("td");
        // var three = document.createElement("img");
			// three.setAttribute("src", petData[counter].image.src);
			// three.setAttribute("alt", petData[counter].image.alt);
			// three.setAttribute("width", petData[counter].image.width);
			// three.setAttribute("height", petData[counter].image.height);
		// document.body.appendChild(three);
		// two.appendChild(three);
		// one.appendChild(two);
		// var four = document.createElement("td");
			// var five = document.createElement("h4");
			// var six = document.createTextNode(petData[counter].name);
		// five.appendChild(six);
		// four.appendChild(five);
		// var seven = document.createElement("p");
			// var eight = seven.innerHTML += petData[counter].description;
		// four.appendChild(seven);
		// var nine = document.createElement("span");
			// var ten = nine.innerHTML += "Age: " + petData[counter].age + " years old";
		// four.appendChild(nine);
		// one.appendChild(four);
		// display.appendChild(one);
		// }
	// }
}

var filterCat = function()
{
	filterType = "cat";
	document.getElementsByClassName("center").onclick = loadTableWithFilter();
	// for (var counter = 0; counter < petData.length; counter++)
	// {
		// if(petData[counter].type == "cat")
		// {
			// var one = document.createElement("tr");
		// var two = document.createElement("td");
        // var three = document.createElement("img");
			// three.setAttribute("src", petData[counter].image.src);
			// three.setAttribute("alt", petData[counter].image.alt);
			// three.setAttribute("width", petData[counter].image.width);
			// three.setAttribute("height", petData[counter].image.height);
		// document.body.appendChild(three);
		// two.appendChild(three);
		// one.appendChild(two);
		// var four = document.createElement("td");
			// var five = document.createElement("h4");
			// var six = document.createTextNode(petData[counter].name);
		// five.appendChild(six);
		// four.appendChild(five);
		// var seven = document.createElement("p");
			// var eight = seven.innerHTML += petData[counter].description;
		// four.appendChild(seven);
		// var nine = document.createElement("span");
			// var ten = nine.innerHTML += "Age: " + petData[counter].age + " years old";
		// four.appendChild(nine);
		// one.appendChild(four);
		// display.appendChild(one);
		// }
	// }
}

var filterBird = function()
{
	filterType = "bird";
	document.getElementsByClassName("center").onclick = loadTableWithFilter();
	// for (var counter = 0; counter < petData.length; counter++)
	// {
		// if(petData[counter].type == "bird")
		// {
			// var one = document.createElement("tr");
		// var two = document.createElement("td");
        // var three = document.createElement("img");
			// three.setAttribute("src", petData[counter].image.src);
			// three.setAttribute("alt", petData[counter].image.alt);
			// three.setAttribute("width", petData[counter].image.width);
			// three.setAttribute("height", petData[counter].image.height);
		// document.body.appendChild(three);
		// two.appendChild(three);
		// one.appendChild(two);
		// var four = document.createElement("td");
			// var five = document.createElement("h4");
			// var six = document.createTextNode(petData[counter].name);
		// five.appendChild(six);
		// four.appendChild(five);
		// var seven = document.createElement("p");
			// var eight = seven.innerHTML += petData[counter].description;
		// four.appendChild(seven);
		// var nine = document.createElement("span");
			// var ten = nine.innerHTML += "Age: " + petData[counter].age + " years old";
		// four.appendChild(nine);
		// one.appendChild(four);
		// display.appendChild(one);
		// }
	// }
}

var filter_zero_1 = function()
{
	filterAgeMin = 0;
	filterAgeMax = 1;
	document.getElementsByClassName("center").onclick = loadTableWithFilter();
	// for (var counter = 0; counter < petData.length; counter++)
	// {
		// if(petData[counter].age ) >= 0 && petData[counter].age < 1)
		// {
			// var one = document.createElement("tr");
		// var two = document.createElement("td");
        // var three = document.createElement("img");
			// three.setAttribute("src", petData[counter].image.src);
			// three.setAttribute("alt", petData[counter].image.alt);
			// three.setAttribute("width", petData[counter].image.width);
			// three.setAttribute("height", petData[counter].image.height);
		// document.body.appendChild(three);
		// two.appendChild(three);
		// one.appendChild(two);
		// var four = document.createElement("td");
			// var five = document.createElement("h4");
			// var six = document.createTextNode(petData[counter].name);
		// five.appendChild(six);
		// four.appendChild(five);
		// var seven = document.createElement("p");
			// var eight = seven.innerHTML += petData[counter].description;
		// four.appendChild(seven);
		// var nine = document.createElement("span");
			// var ten = nine.innerHTML += "Age: " + petData[counter].age + " years old";
		// four.appendChild(nine);
		// one.appendChild(four);
		// display.appendChild(one);
		// }
	// }
}


var filter_1_3 = function()
{
	filterAgeMin = 1;
	filterAgeMax = 3;
	document.getElementsByClassName("center").onclick = loadTableWithFilter();
	// for (var counter = 0; counter < petData.length; counter++)
	// {
		// if(petData[counter].age ) >= 1 && petData[counter].age < 4)
		// {
			// var one = document.createElement("tr");
		// var two = document.createElement("td");
        // var three = document.createElement("img");
			// three.setAttribute("src", petData[counter].image.src);
			// three.setAttribute("alt", petData[counter].image.alt);
			// three.setAttribute("width", petData[counter].image.width);
			// three.setAttribute("height", petData[counter].image.height);
		// document.body.appendChild(three);
		// two.appendChild(three);
		// one.appendChild(two);
		// var four = document.createElement("td");
			// var five = document.createElement("h4");
			// var six = document.createTextNode(petData[counter].name);
		// five.appendChild(six);
		// four.appendChild(five);
		// var seven = document.createElement("p");
			// var eight = seven.innerHTML += petData[counter].description;
		// four.appendChild(seven);
		// var nine = document.createElement("span");
			// var ten = nine.innerHTML += "Age: " + petData[counter].age + " years old";
		// four.appendChild(nine);
		// one.appendChild(four);
		// display.appendChild(one);
		// }
	// }
}

var filter_4_plus = function()
{
	filterAgeMin = 4;
	filterAgeMax = Number.MAX_VALUE;
	document.getElementsByClassName("center").onclick = loadTableWithFilter();
	// for (var counter = 0; counter < petData.length; counter++)
	// {
		// if(petData[counter].age ) >= 4)
		// {
			// var one = document.createElement("tr");
		// var two = document.createElement("td");
        // var three = document.createElement("img");
			// three.setAttribute("src", petData[counter].image.src);
			// three.setAttribute("alt", petData[counter].image.alt);
			// three.setAttribute("width", petData[counter].image.width);
			// three.setAttribute("height", petData[counter].image.height);
		// document.body.appendChild(three);
		// two.appendChild(three);
		// one.appendChild(two);
		// var four = document.createElement("td");
			// var five = document.createElement("h4");
			// var six = document.createTextNode(petData[counter].name);
		// five.appendChild(six);
		// four.appendChild(five);
		// var seven = document.createElement("p");
			// var eight = seven.innerHTML += petData[counter].description;
		// four.appendChild(seven);
		// var nine = document.createElement("span");
			// var ten = nine.innerHTML += "Age: " + petData[counter].age + " years old";
		// four.appendChild(nine);
		// one.appendChild(four);
		// display.appendChild(one);
		// }
	// }
}

var filterAllPets =  function()
{
	filterType = "";
	filterAgeMin = 0;
	filterAgeMax = Number.MAX_VALUE;
	document.getElementsByClassName("center").onclick = loadTableWithFilter();
	// var display = document.querySelector("#main-table-body");
    // for(var counter = 0; counter < petData.length; counter++)
    // {
        // var one = document.createElement("tr");
		// var two = document.createElement("td");
        // var three = document.createElement("img");
			// three.setAttribute("src", petData[counter].image.src);
			// three.setAttribute("alt", petData[counter].image.alt);
			// three.setAttribute("width", petData[counter].image.width);
			// three.setAttribute("height", petData[counter].image.height);
		// document.body.appendChild(three);
		// two.appendChild(three);
		// one.appendChild(two);
		// var four = document.createElement("td");
			// var five = document.createElement("h4");
			// var six = document.createTextNode(petData[counter].name);
		// five.appendChild(six);
		// four.appendChild(five);
		// var seven = document.createElement("p");
			// var eight = seven.innerHTML += petData[counter].description;
		// four.appendChild(seven);
		// var nine = document.createElement("span");
			// var ten = nine.innerHTML += "Age: " + petData[counter].age + " years old";
		// four.appendChild(nine);
		// one.appendChild(four);
		// display.appendChild(one);
    // }
}


