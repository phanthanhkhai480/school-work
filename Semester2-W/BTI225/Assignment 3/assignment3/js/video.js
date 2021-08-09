// Data for the "HTML Video" Page

var video = {
    controls: true, 
    width: 320,
    height: 240,
    source: [
        {src: "https://github.com/allanrandall/BTI225W17/raw/master/movie.mp4", type: "video/mp4"},
        {src: "https://github.com/allanrandall/BTI225W17/raw/master/movie.ogg", type: "video/ogg"},
        {src: "https://github.com/allanrandall/BTI225W17/raw/master/movie.webm", type: "video/webm"}
    ]
};
window.onload = function()
{
	var display = document.querySelector("#Video");
	for (var counter = 0; counter < video.source.length; counter++)
	{
		display.innerHTML += "<figure>" + "<video width='" + video.width + "' height='" + video.height + "' controls>"
							+ "<source src='" + video.source[counter].src + "' type='" + video.source[counter].type 
							+ "'/>" + "Your Browswe does not support audio tag used";
	}
	display.innerHTML += "</audio> </figure>";
}

// <figure>
		// <video width="320" height="240" controls>
			// <source src="https://github.com/allanrandall/BTI225W17/raw/master/movie.mp4", type="video/mp4"/>
			// <source src="https://github.com/allanrandall/BTI225W17/raw/master/movie.ogg", type="video/ogg"/>
			// <source src="https://github.com/allanrandall/BTI225W17/raw/master/movie.webm", type="video/webm"/>
		// </video>
	// </figure>	
	
// window.onload = function()
// {
	// var display = document.querySelector("#Video");
	// var one = document.createElement('figure');
	// var two = document.createElement('video');
	// var three = document.createTextNode('width');
	// var four = document.createTextNode(video.width);
	// var five = document.createTextNode('height');
	// var six = document.createTextNode(video.height);
	// two.getAttribute('control');
	// for(var counter = 0; counter < video.source.length; counter++)
	// {
		// var seven = document.createElement('source');
		// var eight = document.createTextNode("src='");
		// var nine = document.createTextNode(video.source[counter].src);
		// var ten = document.createTextNode ("', type='");
		// var eleven = document.createTextNode(video.source[counter].type);
		// var twelve = document.createTextNode("'");
		// seven.appendChild(twelve);
	// }
	// two.appendChild(seven);
	// one.appendChild(two);
	// display.appendChild(one);
// }
// };

