var minval = -0.5;
var maxval = 0.5;

var minxSlider;
var maxxSlider;
var minySlider;
var maxySlider;
var btn;
var zoom = 1;
var cx = 100;
var cy = 100;
var frDiv;
  var maxiterations = 300;

function setup() {
  createCanvas(200, 200);
  
  pixelDensity(1);

  text("x")
  minxSlider = createSlider(-2, 2, 2, 0.001);

  maxxSlider = createSlider(-2, 2, 2, 0.001);
    text("y")

  minySlider = createSlider(-2, 2, 2, 0.001);
  maxySlider = createSlider(-2, 2, 2, 0.001);


  minxSlider.size(800, 20);
  maxxSlider.size(800, 20);
  minySlider.size(800, 20);
  maxySlider.size(800, 20);
 
  
}

function mouseWheel(event) {
  let delta = event.delta;
  cx = event.x;
  cy = event.y;
  if (delta < 0)
  {
    zoom -= zoom * 0.1;
  }else{
    zoom += zoom * 0.01;
  }
}

function draw() {

  loadPixels();
  for (var x = 0; x < width; x++) {
    for (var y = 0; y < height; y++) {
      var min = 2 / zoom;
     
      var a = map( x, 0, width  , minxSlider.value(), maxxSlider.value());
      var b = map( y, 0, height , minySlider.value(), maxySlider.value());

      var ca = a;
      var cb = b;

      var n = 0;

      while (n < maxiterations) {
        var aa = a * a - b * b;
        var bb = 2 * a * b;
        a = aa + ca;
        b = bb + cb;
        if (a * a + b * b > 4) {
          break;
        }
        n++;
      }

      var bright = map(n, 0, maxiterations, 0, 1);
      bright = map(sqrt(bright), 0, 1, 0, 255);

      if (n == maxiterations) {
        bright = 0;
      }

      var pix = (x + y * width) * 4;
      pixels[pix + 0] = bright;
      pixels[pix + 1] = bright;
      pixels[pix + 2] = bright;
      pixels[pix + 3] = 255;
    }
  }
  updatePixels();
  fill(0, 200, 0)
  ellipse(50, 50 , 5);
}



