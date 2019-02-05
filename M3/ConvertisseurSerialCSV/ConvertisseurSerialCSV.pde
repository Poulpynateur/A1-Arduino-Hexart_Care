//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output;
Serial udSerial;

void setup() {
  udSerial = new Serial(this, Serial.list()[0], 9600);
  output = createWriter ("Battements.csv");
  /*output.print("Date");
  output.print(';');
  output.print("Heure");
  output.print(';');
  output.println("Bpm");*/
}

  void draw() {
    if (udSerial.available() > 0) {
      String SenVal = udSerial.readString();
      if (SenVal != null) {
        output.print(day());
        output.print('/');
        output.print(month());
        output.print(';');
        output.print(hour());
        output.print(':');
        output.print(minute());
        output.print(':');
        output.print(second());
        output.print(';');
        output.print(SenVal);
      }
    }
  }

  void keyPressed(){
    output.flush();
    output.close();
    exit(); 
}
