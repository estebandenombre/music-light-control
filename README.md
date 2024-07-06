# Music Light Control

![Project Cover](boiler_room_cover.png)

This project controls an LED strip based on the music playing in the environment. An ESP32 listens to the ambient sound through a microphone, processes the sound frequencies, and sends signals to control the LED strip accordingly.

## Hardware Requirements
- ESP32
- MAX4466 Microphone
- LED strip
- Connecting wires

## Connection Diagram

![Connection Diagram](images/connection_diagram.png)

## Installation and Setup

1. Clone the repository:
    ```sh
    git clone https://github.com/tu-usuario/music-light-control.git
    cd music-light-control
    ```
2. Open the `src` folder in Arduino IDE.
3. Upload the code to your ESP32.

## Usage
- The ESP32 will analyze the ambient sound and control the LED strip based on the sound frequencies and intensity.

## License
- This project is licensed under [Your License].
