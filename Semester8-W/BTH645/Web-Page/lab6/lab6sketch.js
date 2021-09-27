//initialize variable use for circle
let x, y;
function setup() {  
  //create a canvas view of 720 in width and 480 in height (that's 720p size)
  createCanvas(720, 480);  
  
  //initialize value of of x and y to be in middle
  x = width / 2;
  y = height;
}

function draw() {
  //set colour background to 200
  background(200);
  
  //create a text
  //select a colour
  let text1 = color(0, 0, 0);
  //fill the text with color
  fill(text1);
  //select a text size
  textSize(16);
  //select a text font
  textFont('Georgia');
  //insert the text and coordination where to start
  text('Image and color of all shapes', 50, 30);
  
  //draw a circle
  //select a colour
  let a = color(255, 255, 0);
  //apply the colour to the next object
  fill(a);
  //create a circle
  circle(30, 30, 30);
  
  //draw a square(horizontal, vertical, side)
  //select a colour
  let b = color(255, 0, 0);
  //apply the colour to the next object
  fill(b);
  //create a square
  square(50, 50, 30)
 
  //draw a triangle
  //select a colour
  let c = color(0, 255, 0);
  //apply the colour to the next object
  fill(c);
  //create a triangle
  triangle(90, 110, 110, 90, 130, 110);
  
  
  //draw a rectangle
  //select a colour
  let d = color(0, 0, 255);
  //apply the colour to the next object
  fill(d);
  //create a rectangle
  rect(150, 130, 30, 30, 5);
  
  //draw a quad shape (210,190)
  //select a colour
  let e = color(0, 255, 255);
  //apply the colour to the next object
  fill(e);
  //create a rectangle
  quad(220, 210, 240, 230, 230, 190, 200, 200);
  
  //create a text
  //select a colour
  let text2 = color(255, 0, 255);
  //fill the text with color
  fill(text2);
  //select a text size
  textSize(20);
  //select a text font
  textFont('Cabliri');
  //insert the text and coordination where to start
  text('Pixel Image', 350, 30);
  //draw an image
  drawImage();
}

//function to draw pixel image
function drawImage() {
  //create a local variable
  let x, y;
  //create an image of size 100 x 100
  let img = createImage(100, 100);
  //load pixel into the image
  img.loadPixels();
  
  
  // fill with random colors
  for (y = 0; y < img.height; y++) {
    for (x = 0; x < img.width; x++) {
      let red = random(255);
      let green = random(255);
      let blue = random(255);
      let alpha = 255;
      writeColor(img, x, y, red, green, blue, alpha);
    }
  }

  // draw a red line
  y = 0;
  //draw colour to 
  for (x = 0; x < img.width; x++) {
    writeColor(img, x, y, 255, 0, 0, 255);
  }

  // draw a green line
  y = img.height - 1;
  for (x = 0; x < img.width; x++) {
    writeColor(img, x, y, 0, 255, 0, 255);
  }

  img.updatePixels();
  image(img, 400, 50);
}

// helper for writing color to array
function writeColor(image, x, y, red, green, blue, alpha) {
  let index = (x + y * width) * 4;
  image.pixels[index] = red;
  image.pixels[index + 1] = green;
  image.pixels[index + 2] = blue;
  image.pixels[index + 3] = alpha;
}

