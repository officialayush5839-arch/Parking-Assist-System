# Future Work

The current system is a basic proof-of-concept. Future iterations could incorporate:

- **Bluetooth/WiFi**: Integrate wireless modules to send parking data to a smartphone.
- **ESP32 Upgrade**: Migrate from Arduino Uno to ESP32 for native WiFi/Bluetooth support and faster processing.
- **Mobile App**: Develop an Android/iOS app to visualize parking data in real-time.
- **Voice Alerts**: Replace the basic buzzer with a DFPlayer Mini module to provide spoken audio alerts ("Stop", "Warning").
- **OLED Display**: Replace the 16x2 LCD with an I2C OLED display for better graphics and animations.
- **Camera Integration**: Add an ESP32-CAM module to provide a real-time video feed along with the overlay of distance.
- **AI/ML**: Use Machine Learning to identify the *type* of obstacle (e.g., pedestrian vs. wall) using a camera feed.
- **Cloud Connectivity**: Log parking events to an AWS/GCP IoT cloud dashboard for analysis.
