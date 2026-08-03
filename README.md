# Arduino Parking Assist System

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Hardware: Arduino](https://img.shields.io/badge/Hardware-Arduino-blue.svg)](https://www.arduino.cc/)

A smart parking assistance system using Arduino Uno, HC-SR04 ultrasonic sensor, LEDs, a buzzer, and an I2C 16x2 LCD display. It helps drivers avoid collisions by providing real-time visual and auditory feedback based on the vehicle's proximity to an obstacle.

## Screenshots
*(Add screenshots here)*
<!-- TODO: insert screenshots/demo images -->

## Installation Guide
1. Clone this repository: `git clone https://github.com/yourusername/parking-assist.git`
2. Open `software/ParkingAssist/ParkingAssist.ino` in the Arduino IDE.
3. Install the required `LiquidCrystal_I2C` library via Library Manager.
4. Select `Arduino Uno` as the board and choose the correct COM port.
5. Click **Upload**.

## Hardware Requirements
- Arduino Uno
- HC-SR04 Ultrasonic Distance Sensor
- I2C 16x2 LCD Display
- 3x LEDs (Green, Yellow, Red)
- Active Buzzer
- Breadboard & Jumper Wires
- 330 ohm resistors

## Software Architecture
The core software is a procedural loop that continuously polls the ultrasonic sensor and updates state. See [Software Documentation](software/SOFTWARE.md) for full details, including algorithms and flowcharts.

## Project Structure
- `docs/` - Project reports, testing logs, future work, changelogs.
- `hardware/` - Hardware documentation, wiring overviews, BOM, pin configurations.
- `images/` - Root level images for README.
- `software/` - The Arduino code (`.ino`) and software architecture documentation.

## Wiring Table
| Component | Pin Function | Arduino Pin |
|-----------|--------------|-------------|
| HC-SR04   | TRIG         | D9          |
| HC-SR04   | ECHO         | D10         |
| I2C LCD   | SDA          | A4          |
| I2C LCD   | SCL          | A5          |
| Green LED | Anode        | D2          |
| Yellow LED| Anode        | D3          |
| Red LED   | Anode        | D4          |
| Buzzer    | Positive     | D5          |

See [Pin Configuration](hardware/pin-configuration.md) for full details.

## Future Work
See [Future Work](docs/FutureWork.md) for upcoming enhancements including wireless connectivity and machine learning.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contribution Guide
1. Fork the project.
2. Create your feature branch (`git checkout -b feature/AmazingFeature`).
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`).
4. Push to the branch (`git push origin feature/AmazingFeature`).
5. Open a Pull Request.

## Acknowledgements
- Thanks to the open-source community for the I2C LCD libraries.
