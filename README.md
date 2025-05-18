
🛰️ Monitor and Log Environmental Conditions using Low-Cost Open-Source Hardware
===============================================================================

Onan Agaba¹*, Elad Levintal², Devi Sarai Orozco Fuentes², Thuc Thi Nguyen²  
¹ French Associates Institute for Agriculture and Biotechnology of Drylands  
² Zuckerberg Institute for Water Research, Ben-Gurion University of the Negev, Israel  
🔗 Project Repository: https://github.com/OnanAgaba/monitor-and-log-environmental-conditions

📑 Table of Contents
--------------------
1. Overview  
2. System Components  
3. Wiring & Assembly  
4. Programming & Data Logging  
5. Bill of Materials  
6. Results  
7. Conclusion  
8. References

1. Overview
-----------
This project demonstrates how to monitor indoor environmental conditions—temperature (T), relative humidity (RH), and carbon dioxide (CO₂)—using low-cost open-source hardware over a 3-day period.

2. System Components
---------------------
- Microcontroller: Arduino UNO  
- Sensors: SHTC3 (T/RH), SCD-40 (CO₂/T/RH)  
- Storage: microSD card via breakout module

3. Wiring & Assembly
---------------------
Sensors and storage were wired to the Arduino via jumper wires and a STEMMA QT cable. Powered via USB, the setup logged real-time sensor data.

4. Programming & Data Logging
------------------------------
Using Arduino IDE v2.3.4, the code (C++) logged sensor values every 10 seconds using `millis()` for timestamps. Data was saved to a microSD card for offline analysis.

5. Bill of Materials
---------------------
| Component       | Description           | Cost    |
|----------------|-----------------------|---------|
| Arduino UNO     | Microcontroller       | $12.90  |
| SHTC3 Sensor    | T/RH Sensor (I2C)     | $6.95   |
| SCD-40 Sensor   | CO₂/T/RH Sensor (I2C) | $44.95  |
| microSD Module  | SD card interface     | $5.95   |
| SD Card         | SanDisk Ultra HC1     | $15.00  |
| Cables          | Jumper wires & USB    | $6.98   |

6. Results
----------
Measurements began on May 14, 2025 at 22:00, and ran for three days.  
- CO₂ levels spiked during occupancy  
- T readings were consistent across sensors  
- RH values varied: SHTC3 reported higher values than SCD-40

7. Conclusion
--------------
This setup shows that affordable, scalable, open-source tools can effectively support indoor environmental monitoring. Future improvements could include:
- Real-Time Clock (RTC)
- Wireless data transfer
- Sensor calibration

8. References
--------------
1. Chan et al. (2021). Progress in Physical Geography, 45(3).  
2. Horsburgh et al. (2019). Frontiers in Earth Science, 7.  
3. Kumar et al. (2015). Environment International, 75.  
4. Mahan & Yeater (2008). Computers and Electronics in Agriculture, 64(2).  
5. Thompson (2016). Trends in Environmental Analytical Chemistry, 11.
