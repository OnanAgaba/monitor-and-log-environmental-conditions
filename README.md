# Monitor and Log Environmental Conditions Using Low-Cost Open-Source Hardware

**Authors**: Onan Agaba\*, Elad Levintal, Devi Sarai Orozco Fuentes, and Thuc Thi Nguyen  
**Affiliations**:  
1. French Associates Institute for Agriculture and Biotechnology of Drylands  
2. Zuckerberg Institute for Water Research, Ben-Gurion University of the Negev, Israel  
🔗 [GitHub Repository](https://github.com/OnanAgaba/monitor-and-log-environmental-conditions)

---

## Table of Contents

- [1. Introduction](#1-introduction)
- [2. Experimental Design](#2-experimental-design)
  - [2.1 Wiring and Assembly](#21-wiring-and-assembly)
  - [2.2 Programming and Logging](#22-programming-and-logging)
  - [2.3 Bill of Materials](#23-bill-of-materials)
  - [2.4 System Overview](#24-system-overview)
- [3. Results](#3-results)
- [4. Conclusion](#4-conclusion)
- [5. References](#5-references)

---

## 1. Introduction

Environmental monitoring is critical for assessing hydrological, meteorological, and ecological trends. This project presents a low-cost system using open-source hardware to monitor temperature, relative humidity (RH), and carbon dioxide (CO₂) over three days in a caravan.

---

## 2. Experimental Design

### 2.1 Wiring and Assembly

Components include an Arduino UNO, SHTC3 sensor (for T/RH), SCD-40 sensor (for CO₂/T/RH), and microSD storage. Sensors and storage were connected via jumper wires and STEMMA QT cables.

### 2.2 Programming and Logging

The Arduino was programmed using Arduino IDE to log measurements every 10 seconds. Data was timestamped and saved to a microSD card.

### 2.3 Bill of Materials

| Component          | Description                                | Cost   |
|-------------------|--------------------------------------------|--------|
| Arduino UNO        | Microcontroller                            | $12.90 |
| MicroSD Module     | SD card interface                          | $5.95  |
| SD Card            | Data storage                               | $15.00 |
| SHTC3 Sensor       | Temp and RH sensor                         | $6.95  |
| SCD-40 Sensor      | CO₂, Temp, RH sensor                       | $44.95 |
| Cables             | USB and jumper wires                       | $6.98  |

### 2.4 System Overview

The system continuously logs T, RH, and CO₂ indoors using connected sensors and Arduino.

![image](https://github.com/user-attachments/assets/e0f1f834-6a34-4a42-9150-55a551d3d491)
Fig 1. System components; 1) power into the board through the USB cable, 2) SHTC3 sensor, 3) Arduino UNO, 4) jump wires, 5) SCD-40, 6) microSD card, and 7) microSD card breakout module.

![image](https://github.com/user-attachments/assets/7be6bab0-f67e-475b-bb66-318a08fec83a)
Fig 2. illustration of system connection layouts a) connection of SD card module and other sensors to the Arduino UNO board, b) card layout of connections

---

## 3. Results

- Logging began on May 14, 2025.
- CO₂ levels increased during periods of occupancy.
- Both sensors agreed on temperature trends; RH values varied.
- SHTC3 showed consistently higher RH than SCD-40.

---

## 4. Conclusion

The project validates the use of affordable, open-source hardware for reliable environmental monitoring. Future versions may include real-time clocks and wireless transmission.

---

## 5. References

1. Chan et al. (2021) - Low-cost sensors in geography  
2. Horsburgh et al. (2019) - Managing data from open systems  
3. Kumar et al. (2015) - Air pollution monitoring  
4. Mahan & Yeater (2008) - Agricultural IR thermometers  
5. Thompson (2016) - Crowd-sourced air quality

---

*For questions, contact: [Onan Agaba](mailto:onan.agaba@example.com)*
