const int sensorPin= A0;
int sensorValue = 0;
float sensorVoltage=0;
float windSpeed=0;

float voltageConversionConstant=0.00425;
int sensorDelay=1000;

float voltageMin=0.4;
float windSpeedMin=0;

float voltageMax=2.0;
float windSpeedMax=32;


void setup() { Serial.begin(9600); }

void loop() { sensorValue = analogRead(sensorPin);

sensorVoltage = sensorValue * voltageConversionConstant;

if (sensorVoltage <= voltageMin) { windSpeed = 0; }

else { windSpeed = (sensorVoltage - voltageMin)

*windSpeedMax/(voltageMax - voltageMin); }

Serial.print("Voltage: ");

Serial.print(sensorVoltage);

Serial.print("\t");

Serial.print("Wind speed: ");

Serial.println(windSpeed);

delay(sensorDelay); }