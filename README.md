# monitor-and-log-environmental-conditions
A beginner-friendly environmental monitoring system built with open-source hardware and tools like Arduino


Monitor and Log Environmental Conditions Using Low-Cost Open-Source Hardware
Onan Agaba<sup>1</sup>, Elad Levintal<sup>2</sup>, Devi Sarai Orozco Fuentes<sup>2</sup>, and Thuc Thi Nguyen<sup>2</sup>*
<sup>1</sup>French Associates Institute for Agriculture and Biotechnology of Drylands
<sup>2</sup>Zuckerberg Institute for Water Research, Ben-Gurion University of the Negev, Israel
🔗 GitHub Project Repository

1. Introduction
Environmental monitoring is essential for assessing hydrological, meteorological, and ecological changes due to both human activity and natural events like climate change. High-resolution, real-time environmental data is often inaccessible in resource-limited settings due to the cost of industrial sensors. To address this, we developed a low-cost, open-source system to monitor and log:

🌡️ Temperature (T)

💧 Relative Humidity (RH)

🫁 Carbon Dioxide (CO₂)

The system operates over three consecutive days using readily available sensors and microcontrollers inside a caravan environment.

2. Experimental Design
The monitoring system comprises:

An Arduino microcontroller

SHTC3 sensor for T and RH

SCD-40 sensor for CO₂, T, and RH

A microSD card module for data logging

2.1 Wiring and Assembly
The SHTC3 and microSD card were wired using jumper wires.

The SCD-40 connected using a STEMMA QT cable.

Powered via USB from a computer.

🛠️ See Figure 1a for system schematic and Figure 2 for physical layout.

2.2 Programming and Logging
Developed using Arduino IDE 2.3.4.

Measurements every 10 seconds.

Timestamps via millis() function.

Data logged on the SD card for 3 days.

📜 Pseudocode and flow diagram shown in Figure 1b.

2.3 Bill of Materials
Component	Description	Cost	Link
Arduino UNO	Microcontroller board (DFROBOT V3.0 R3)	$12.90	Arduino Uno
microSD Module	SparkFun microSD Transflash	$5.95	SD Breakout
SD Card	SanDisk Ultra HC1	$15.00	SD Card
SHTC3 Sensor	Temperature & Humidity (I2C)	$6.95	SHTC3
SCD-40 Sensor	CO₂, Temperature, Humidity (I2C)	$44.95	SCD40
Cables & Wires	Jumper wires and USB	$6.98	Wires

2.4 System Overview
The system logs environmental parameters to a microSD card using:

Arduino UNO

SHTC3 (Temp + RH)

SCD-40 (CO₂ + Temp + RH)

🔧 Refer to Figures 2–4 for hardware assembly and pin assignments.

2.5 Port Assignments
Port	Function
A4, A5	SDA & SCL for I2C communication
10–13	CS, MOSI, MISO, CLK for SPI with SD card
3.3V, 5V	Power supply to peripherals
GND	Circuit grounding

3. Results
Measurements began on May 14, 2025 at 22:00 and ran for three days. Key observations:

🫁 CO₂ levels increased with room occupancy.

🌡️ Temperature trends were consistent across both sensors.

💧 Relative Humidity varied between sensors: SHTC3 reported consistently higher RH than SCD-40.

📈 Figure 5 shows plotted trends over time. Dual-axis plots were used to separate RH and T due to unit differences.

4. Conclusion
This project shows that low-cost, open-source electronics like Arduino, SHTC3, and SCD-40 can be effectively used for indoor environmental monitoring. The approach is scalable and adaptable, particularly for educational or low-budget deployments.

🚧 Limitations:

No Real-Time Clock (RTC) limits absolute timestamping.

Lack of enclosure may expose components to damage.

🔧 Future Improvements:

Integrate RTC for real-time synchronization.

Add wireless data transmission (e.g., Wi-Fi or LoRa).

Calibrate sensors for greater accuracy.

📚 References
Chan, K. et al. (2021). Low-cost electronic sensors for environmental research: Pitfalls and opportunities. Progress in Physical Geography, 45(3), 305–338.

Horsburgh, J. S. et al. (2019). Low-cost, open-source, and low-power: But what to do with the data? Frontiers in Earth Science, 7, 67.

Kumar, P. et al. (2015). The rise of low-cost sensing for managing air pollution in cities. Environment International, 75, 199–205.

Mahan, J. R. & Yeater, K. M. (2008). Agricultural applications of a low-cost infrared thermometer. Computers and Electronics in Agriculture, 64(2), 262–267.

Thompson, J. E. (2016). Crowd-sourced air quality studies: A review of the literature & portable sensors. Trends in Environmental Analytical Chemistry, 11, 23–34.

