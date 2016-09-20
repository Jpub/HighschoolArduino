import processing.serial.*;

Serial serial;

boolean started = false;

String s_windDirection;
float humidity = 0, temperature = 0;
float windDir = 0, windSpeed = 0, rainGauge = 0;

int len;

void setup() {
  size(500, 500);
  println(Serial.list());
  serial = new Serial(this, Serial.list()[1], 9600);
  ellipseMode(CENTER);
  fill(255);
  stroke(0);
}


void draw() {
  
    String humNtemp="", artRobotWeather="";
    String tempString = "";
    if (serial.available() > 0) {
      tempString = serial.readStringUntil('\n');
      if (tempString != null) {
        println(tempString);
        if(match(tempString, "DHT22.*OK.*Humidity.*Temperature.*") != null) {
          humNtemp = tempString;
          println("humidity & temperature read accept");
        } else if (match(tempString, "ArtRobot.*WindDirection.*WindSpeed.*Rain.*") != null) {
          artRobotWeather = tempString;
          println("ArtRobot Info read accept");
        }
      }
     
    String[] humTempRawInfo = humNtemp.split(",");
    if(humTempRawInfo.length == 6) {
      String s_humidity = humTempRawInfo[3];
      String s_temperature = humTempRawInfo[5];
      humidity = Float.parseFloat(s_humidity);
      temperature = Float.parseFloat(s_temperature);
    }
      String[] windWaterRawInfo = artRobotWeather.split(" ");
    
    if(windWaterRawInfo.length == 11) {
      String[] windDirections = windWaterRawInfo[6].split("/");
      String s_windSpeed = windWaterRawInfo[8].split("\\(")[0];
      String s_rain = windWaterRawInfo[10].split("\\(")[0];
      windDir = Float.parseFloat(windDirections[1]);
      s_windDirection = windDirections[0];
      windSpeed = Float.parseFloat(s_windSpeed);
      rainGauge = Float.parseFloat(s_rain);
    }
      
    }
    
    
    background(rainbow(temperature));
    textSize(15);
    textAlign(RIGHT);
    text(     "humidity :",120,30);
    text(  "temperature :",120,60);
    text("windDirection :",120,90);
    text(    "windSpeed :",120,120);
    text(    "rainGauge :",120,150);
    textAlign(LEFT);
    text(humidity           ,125,30);
    text(temperature        ,125,60);
    text(s_windDirection + " (" + windDir + ")"
                              ,125,90);
    text(windSpeed          ,125,120);
    text(rainGauge          ,125,150);
    
    translate(250, 250);
    rotate(windDir / 180 * PI);
    
    len = (int)(windSpeed * 30);
   if (len > 210) len = 210;
    pushMatrix();
      line(0, - len, 0, len);
      fill(255);
      ellipse(0, len, 80, 80);
      fill(0);
      arc(0, len, 80, 80, 0, humidity / 100 * TWO_PI, PIE);
      drawFlag((int)windSpeed);
    popMatrix();
  
}

color rainbow(float state) {
  final  float CC = 0, C = 18, H = 32, HH = 40;
  if (state > HH)
    return color(255, 0, 0);
  else if (state > H)
    return color(255, (HH - state)/(HH - H) * 255, 0);
  else if (state > C)
    return color((state - C)/(H - C) * 255, 255, (H - state)/(H - C) * 255);
  else if (state > CC)
    return color(0, state/(C - CC) * 255, 255);
  else
    return color(0, 0, 255);
}

void drawFlag(int val) {
  int fPos = -len;
  fill(0);
  while(val >= 25) {
    triangle(0, fPos + 10, 50, fPos - 40, 0, fPos);
    fPos += 50;
    val -= 25;
  }
  while(val >= 5) {
    line(0, fPos, 50, fPos - 50);
    fPos += 40;
    val -= 5;
  }
  if (val >= 2)
    line(0, fPos, 30, fPos - 30);
}