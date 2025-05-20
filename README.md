# Automated Greenhouse

**Project by Banu Simona and Plămădeală Victor**
<br>
Plants play a crucial role in human life, serving as the main source of oxygen and contributing to
air purification. Globally, approximately 80% of daily caloric intake comes from plant-based
foods.
<br>
With the world's population growing at an alarming rate, there is an increasing risk of major food
supply shortages. Therefore, food production must be optimized to achieve high yield and
quality, while maintaining long-term harmony with the environment.
<br>
Our proposed solution is an **automated greenhouse prototype** , built at a reduced scale,
designed to create an ideal environment for the fast and healthy growth of plants. We focused
on controlling three essential factors for plant development: **temperature, humidity, and light**.
<br><br>
**Functionality and Expert Recommendations**
<br>
After discussions with Dr. Emilian Mirea, a horticulture specialist, we learned that plants respond
differently to various light spectrums:

- **White light** – Offers the full spectrum, simulating natural sunlight.
- **Blue light** – Stimulates leaf and stem growth.
- **Red light** – Supports photosynthesis and vertical growth, being highly absorbed by plants.
- **Red-blue combination** – Ideal for flowering and maturation phases.

In our prototype, we currently use a **white LED** , with plans to upgrade to **multispectral lighting**
in future versions.
**Ventilation** is another critical aspect. Even within the optimal temperature range (20–25°C), a
constant low-intensity airflow is recommended to prevent air stagnation and mold formation.
To address this, we implemented a **PWM-controlled fan** , which adjusts its speed based on
different environmental conditions:

- At normal temperatures, the fan runs at low speed to ensure gentle air circulation.
- Below the minimum threshold, a **ceramic heating resistor** activates to warm the
environment.
- When the temperature exceeds the set limit, the fan gradually increases its speed,
effectively and smoothly cooling the interior.

This system maintains a **stable internal climate** , ideal for healthy plant growth.
**Irrigation** is handled automatically through a custom-built **solenoid valve** , which opens when
the soil moisture sensor detects that the plant needs water.
**Possible Future Improvements**

- **Remote control** via Wi-Fi module (e.g., ESP8266)
- **Real-time notifications** through mobile applications
- **Smart-home integration** with platforms like **Blynk** or **Home Assistant

**Conclusion**<br>
This project integrates essential concepts from **electronics and embedded programming** ,
including analog/digital sensor interfacing, motor control, power actuation via transistors, and
real-time data display on an LCD.<br>
It serves as a practical example of an **autonomous system applicable to agriculture** , with
great potential for expansion and real-world implementation.


## Components Used

- 1 Arduino UNO No. Component Quantity
- 2 Soil moisture sensor
- 3 SG90 Servo motor
- 4 Photoresistor (LDR)
- 5 LED resistor (220Ω)
- 6 High-power LED
- 7 DHT11 Temperature sensor
- 8 Ceramic resistor
- 9 Fan
- 10 NPN Transistors
- 11 1kΩ Resistors
- 12 16x2 LCD 1
- 13 External Power Supply (9V) 1
- 14 Jumper wires, Breadboard -

