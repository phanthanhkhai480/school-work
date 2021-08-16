var Label = function(labelText,x,y){
	var that = {};
	var labelText_=labelText || "";
	var x_=x || 200;
	var y_=y || 200;
	var width_ = labelText_.length * 10;
	var height_ = 40;

	//To get the position of the label for decorator
	that.width = width_;
	that.height = height_;
	that.x = x_;
	that.y = y_;
	that.lt = labelText_;

	that.draw = function(){
		strokeWeight(1);
		stroke(0,0,0);
		fill(0,0,0);
		textAlign(CENTER,CENTER);
		text(labelText_,x_,y_);
	}
	

	return that;
};

function thickDecorator(label){
	this.label = (label);
	this.label.width+=10;
	this.label.height+=10;

	this.draw = function(){
		this.thick();
		this.label.draw();
	}

	this.thick = function(){
			rectMode(CENTER);
			strokeWeight(3);
			stroke(0,0,0);
			noFill();
			rect(this.label.x,this.label.y,this.label.width,this.label.height);	
	}
}

function dotDecorator(label){
	this.label = label;
	this.label.width+=10;
	this.label.height+=10;

	this.dots = function(){
		ellipseMode(CENTER);
		strokeWeight(1);
		fill(255,0,0);
		stroke(255,0,0);
		//above label
		for(var i=0;i<this.label.width/10 + 1;i++){
			ellipse((this.label.x-this.label.width/2+i*10),(this.label.y-this.label.height/2),5,5);
		}
		//below label
		for(var i=0;i<this.label.width/10 +1;i++){
			ellipse((this.label.x-this.label.width/2+i*10),(this.label.y+this.label.height/2),5,5);
		}
		//left of label
		for(var i=0;i<this.label.height/10-1;i++){
			ellipse((this.label.x-this.label.width/2),(this.label.y-this.label.height/2+((i+1)*10)),5,5);
		}
		//right of label
		for(var i=0;i<this.label.height/10-1;i++){
			ellipse((this.label.x+this.label.width/2),(this.label.y-this.label.height/2+((i+1)*10)),5,5);
		}
	}

	this.draw = function(){
		this.dots();
		this.label.draw();
	}
}

function thinDecorator(label){
	this.label = label;
	this.label.width+=10;
	this.label.height+=10;

	this.thin = function() {
		rectMode(CENTER);
		strokeWeight(1);
		stroke(0,0,0);
		noFill();
		rect(this.label.x,this.label.y,this.label.width,this.label.height);	
		//add new width and height to the label's width and height
	}

	this.draw = function(){
		this.thin();
		this.label.draw();
	}

}

var labels=[];
var thickBorderButton;
var borderButton;
var dotButton;
var removeButton;
var selectLabelRadio;
var selected;
var numLabels;
var dec;

/*
  these four functions are called when button is pressed
  modify the "add" functions to apply decorator to the 
  selected label.   
*/
function addThinBorder(){
	//labels[selected] = new thinDecorator(labels[selected]);
	//labels[selected].toggleThinBorder();
	thinDecorator(labels[selectLabelRadio.value()]);

	//labels[selected] = new thinDecorator(labels[selected]);
}
function addThick(){
	//labels[selected] = new thickDecorator(labels[selected]);
	thickDecorator(labels[selectLabelRadio.value()]);
}
function addDots(){
	dotDecorator(labels[selectLabelRadio.value()]);
	//labels[selected] = new dotDecorator(labels[selected]);
}

/*
  Challenge: removeLastBorder function.  If you add this feature
  use this function to remove the most recent decorator 
  from the selected label
 */
function removeLastBorder(){

}


/*********************************************************/
/* NOTHING BELOW THIS COMMENT IS TO BE MODIFIED          */
/*********************************************************/

function setup(){
	createCanvas(600,500);	

    thickBorderButton=createButton("Add Thick Border");
    thickBorderButton.mousePressed(addThick);
    thickBorderButton.position(10,550);
    borderButton=createButton("Add Thin Border");
    borderButton.mousePressed(addThinBorder);
    borderButton.position(160,550);
    dotButton=createButton("Add Dots Border");
    dotButton.mousePressed(addDots);
    dotButton.position(310,550);

    removeButton=createButton("Remove Last");
    removeButton.mousePressed(removeLastBorder);
    removeButton.position(460,550);

	selectLabelRadio=createRadio();
	numLabels=5;
	for(var i=0;i<numLabels;i++){
		selectLabelRadio.option(""+i,"Label "+(i+1));
		labels[i] = Label("Label "+(i+1), random(50,550), random(20,480));
	}
    selectLabelRadio.selected(0);

}


/* This function is not to be modified*/
function draw(){
	selected=selectLabelRadio.value();
	console.log(selected);
	background(255,255,255);
	for(var i=0;i<numLabels;i++){
		labels[i].draw();
	}
}
	