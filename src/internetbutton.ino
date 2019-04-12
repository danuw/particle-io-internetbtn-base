// version control

// v0.1: initial template

#include "InternetButton.h"

/* This InternetButton library has some useful functions.
Here we blink ALL the LEDs instead of just one.*/

InternetButton b = InternetButton();

String version = "#{buildinfo}#";

int lastPublish;
int publishPause = 5000; // in ms - delay before next publish

bool canPublish() {
  return millis() > (lastPublish + publishPause);
}

// Program
void setup() {
    
    lastPublish = millis();
    Particle.publish("started", version);
    // First, declare all of our pins. This lets our device know which ones will be used for outputting voltage, and which ones will read incoming voltage.

    Particle.variable("version", version);

    // Use b.begin(1); if you have the original SparkButton, which does not have a buzzer or a plastic enclosure
    // to use, just add a '1' between the parentheses in the code below.
    // Tell b to get everything ready to go
    b.begin();    
}


// Next is the loop function...

void loop() {
    
    // TODO: update with you running logic here
    String command = "loop-CHANGEME";
    if(canPublish()){
        Particle.publish("command", "{ \"command\":\""+command +"\", \"version\":"+ version+", \"othervalue\":"+"0 }");
        lastPublish = millis();
    }
    
    b.allLedsOn(0,20,20);
    delay(1000);
    b.allLedsOff();
    delay(5000);
}
