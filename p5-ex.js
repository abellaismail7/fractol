var minval = -0.5;
var maxval = 0.5;

var xSlider;
var ySlider;
var zoomSlider;
var btn;
var zoom = 1;
var cx = 100;
var cy = 100;
var frDiv;
  var maxiterations = 300;

function setup() {
  createCanvas(200, 200);
  
  pixelDensity(1);

  xSlider = createSlider(0, 1, 1, 0.001);
  ySlider = createSlider(0, 1, 1, 5);
  zoomSlider = createSlider(0, 2, 1, 0.00001);


  xSlider.size(500, 20);
  xSlider.changed = (val) =>{
    console.log("x:" + val);
  }
  ySlider.changed = (val) =>{
    console.log("y:" +val);
  }
  ySlider.size(500, 20);
  zoomSlider.size(500, 20);
  zoomSlider.changed = (val) =>{
    console.log("zoom:" + val);
  }
  btn = createButton("INC");
  btn.mouseClicked(incall);
  
  frDiv = createDiv('');
}

function incall()
{
   maxiterations += 100;
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
      var n = xSlider.value();
      var  _x = map(cx, 0, width , width * zoom / -2 , width * zoom /2 ) * n;
      var  _y = map(cy, 0, width , width * zoom / -2, width * zoom /2 );
      var a = map(_x + x, 0, width  * zoom, -min, min);
      var b = map(_y + y, 0, height * zoom, -min, min);

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


