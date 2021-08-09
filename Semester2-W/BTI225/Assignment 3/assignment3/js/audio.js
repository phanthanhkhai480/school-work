// Data for the "HTML Audio" Page

var audio = {
    controls: true, 
    source: [
        {src: "https://github.com/allanrandall/BTI225W17/raw/master/Track03.mp3", type: "audio/mpeg"},
        {src: "https://github.com/allanrandall/BTI225W17/raw/master/Track03.ogg", type: "audio/ogg"}
    ]
};
window.onload = function()
{
	var display = document.querySelector("#Audio");
	for (var counter = 0; counter < audio.source.length; counter++)
	{
		display.innerHTML += "<figure>" + "<audio controls>" + "<source src='" + audio.source[counter].src + "' type='" + audio.source[counter].type 
							+ "'/>" + "Your Browswe does not support audio tag used";
	}
	display.innerHTML += "</audio> </figure>";
}

// window.onload = function()
// {
	// var display = document.querySelector("#Audio");
	// var one = document.createElement('figure');
	// var two = document.createElement('audio');
	// two.getAttribute('control');
	// for(var counter = 0; counter < audio.source.length; counter++)
	// {
		// var three = document.createElement('source');
		// var four = document.createTextNode("src='");
		// var five = document.createTextNode(audio.source[counter].src);
		// var six = document.createTextNode (";, type='");
		// var seven = document.createTextNode(audio.source[counter].type);
		// var eight = document.createTextNode("'");
		// three.appendChild(eight);
	// }
	// two.appendChild(three);
	// one.appendChild(two);
	// display.appendChild(one);
// }


