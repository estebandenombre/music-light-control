#include <Arduino.h>
#include <arduinoFFT.h>

const int micPin = A0;
const int ledPin = 5; // Pin donde está conectada la tira LED
const int samples = 64; // Debe ser una potencia de 2
double vReal[samples];
double vImag[samples];

arduinoFFT FFT = arduinoFFT();

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < samples; i++) {
    vReal[i] = analogRead(micPin);
    vImag[i] = 0;
    delay(1);
  }

  FFT.Windowing(vReal, samples, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.Compute(vReal, vImag, samples, FFT_FORWARD);
  FFT.ComplexToMagnitude(vReal, vImag, samples);

  double maxMagnitude = 0;
  for (int i = 2; i < (samples / 2); i++) {
    if (vReal[i] > maxMagnitude) {
      maxMagnitude = vReal[i];
    }
  }

  int ledBrightness = map(maxMagnitude, 0, 1024, 0, 255);
  analogWrite(ledPin, ledBrightness);

  delay(100);
}
