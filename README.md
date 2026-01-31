\# Smart Irrigation Embedded System 🌱💧



\## 📌 Overview

This project consists of the design and implementation of a smart irrigation system based on an embedded microcontroller (Arduino).  

The system automatically controls water irrigation depending on soil moisture levels, using a sensor, a relay module, and a water pump.



The goal of this project is to demonstrate fundamental concepts of embedded systems, including sensor acquisition, decision logic, and actuator control.



---



\## 🎯 Objectives

\- Measure soil moisture using an analog sensor  

\- Automatically decide when irrigation is needed  

\- Control a water pump through a relay module  

\- Structure the software using modular Embedded C/C++  

\- Validate the system through real hardware tests  



---



\## 🧠 System Architecture

The system follows a simple control loop:



1\. The soil moisture sensor measures the humidity level

2\. The microcontroller reads the analog value

3\. A threshold-based decision is applied

4\. The system activates or deactivates:

&nbsp;  - an LED (status indicator)

&nbsp;  - a water pump (via relay)



This architecture reflects a basic \*\*sense → decide → act\*\* embedded system.



---



\## 🧩 Hardware Components

\- \*\*Arduino Uno\*\* – Main microcontroller

\- \*\*Soil Moisture Sensor\*\* – Measures soil humidity

\- \*\*Relay Module (5V)\*\* – Isolates and controls the pump

\- \*\*DC Water Pump\*\* – Provides irrigation

\- \*\*External Battery Pack\*\* – Powers the pump

\- \*\*LED + Resistor\*\* – Visual status indicator

\- \*\*Jumper Wires \& Tubing\*\*



---



\## 💻 Software Architecture

The software is written in Embedded C/C++ and organized in a modular way:





