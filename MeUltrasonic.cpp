#include <NewPing.h>

const int SagOnUltraSonikPin   = 13;
const int SolOnUltrasonikPin   = 12;
const int SagArkaUltrasonicPin = 11;
const int SolArkaUltrasonicPin = 10;
const int SagOnOkumayiBaslat   = 0;
const int SolOnOkumayiBaslat   = 1;
const int SagArkaOkumayiBaslat = 2;
const int SolArkaOkumayiBaslat = 3;
const int MaximumDistance      = 200;
const int SensorSayisi = 4;
;
/*NewPing sonar[0](SagOnUltraSonikPin,SagOnUltraSonikPin);
NewPing sonar[1](SolOnUltrasonikPin,SolOnUltrasonikPin);*/
NewPing sonar[SensorSayisi] = {     
  NewPing(SagOnUltraSonikPin, SagOnUltraSonikPin, MaximumDistance),
  NewPing(SolOnUltrasonikPin, SolOnUltrasonikPin, MaximumDistance),
  NewPing(SagArkaUltrasonicPin, SagArkaUltrasonicPin, MaximumDistance),
  NewPing(SolArkaUltrasonicPin, SolArkaUltrasonicPin, MaximumDistance)
};
void setup() {
 Serial.begin(115200);

}

void loop() {
  delay(50);
  unsigned int SagOn= sonar[SagOnOkumayiBaslat].ping();
  unsigned int SolOn= sonar[SolOnOkumayiBaslat].ping();
  unsigned int SagArka= sonar[SagArkaOkumayiBaslat].ping();
  unsigned int SolArka= sonar[SolArkaOkumayiBaslat].ping();
  Serial.print(" SAG ON : ");
  Serial.print(SagOn / US_ROUNDTRIP_CM); // convert time into distance
  Serial.print("cm");
  Serial.print(" SOL ON : ");
  Serial.print(SolOn / US_ROUNDTRIP_CM); // convert time into distance
  Serial.print("cm");
    Serial.print(" SAG ARKA : ");
  Serial.print(SagArka / US_ROUNDTRIP_CM); // convert time into distance
  Serial.print("cm");
  Serial.print(" SOL ARKA : ");
  Serial.print(SolArka / US_ROUNDTRIP_CM); // convert time into distance

Serial.println("cm");
}
