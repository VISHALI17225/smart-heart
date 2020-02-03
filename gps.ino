#include <NeoSWSerial.h>
#include <TinyGPS.h>
NeoSWSerial gpsSerial( 2, 3 );
TinyGPS gps; // create gps object
long lat,lon;
void setup()
{
  Serial.begin( 9600 );
  gpsSerial.begin( 9600 );
}

void loop()
{
 // Serial.write( gpsSerial.read() );
  if (gpsSerial.available())
  {
   Serial.write( gpsSerial.read() );
    delay(1000);
    gps.get_position(&lat,&lon);
    Serial.print("Position: ");
    Serial.print("lat: ");Serial.print(lat);Serial.print(" ");// print latitude
    Serial.print("lon: ");Serial.println(lon); // print longitude
  }
}