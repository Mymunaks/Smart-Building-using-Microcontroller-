# Smart-Building-using-Microcontroller
# Project Title
In this modern era, due to the improvement in technology many systems are being automated. Among them home appliances, automation and security system are being more popular. Therefore, we decided to make such an approach through our project in the lab. Our main purpose of project is to decrease the waste of energy by making home appliances automated and controlled. Another idea is to ensure home security by preventing unwanted happenings like gas leakage, fire etc. We have been successful in making a model of the home automation system. 
In this project, we attempted to use two different microcontroller-based control systems for a smart home. Arduino Uno is the microcontroller for the alarm systems and the ESP-32 is the microcontroller for the home-appliance automation systems. Arduino UNO is a very reliable module so it has been used for alarm systems. ESP-32 is very customizable so it is used in home-appliance automation. The reason for two distinct systems is the avoidance of failure of one system due to the fault of another. 

## Table of Contents
- [Automated Home Appliance Control System](#automated-home-appliance-control-system)
- [Fire and Gas Protection System](#fire-and-gas-protection-system)
- [Implementation](#implementation)
- [Impact](#impact)
- [Challenges](#challenges)

## Automated Home Appliance Control System
For the home-appliance automation system, we use LDR sensors so that lights do not turn on upon having a threshold intensity of sunlight. Secondly, we used LD2410 sensor module to detect both static and dynamic human presence.We used a 5V DC fan to model a real fan and an LED to model room light.

## Fire and Gas Protection System
The fire protection system uses a flame sensor module, which is used to detect flame. If there is any fire outbreak this sensor will send signal to the controller and the controller would command the fire extinguisher to extinguish the fire. A 5V buzzer is used to make alarming sound when there is any flame. A 5V mini water pump is used as a fire extinguisher.  
The gas detection system uses a MQ2 sensor to detect any gas such as: carbon dioxide, cooking gas, smoke etc. A threshold is set for the sensor. If the density of gas around the sensor crosses the threshold the buzzer makes sound to alert people. A 5V buzzer is used to make alarming sound when there is any gas leakage. 

## Implementation
We used cork-sheet to construct a prototype for our smart home. There we set up our sensors at prime locations for their perfect reading and sensing of parameters. The microcontrollers were placed at the bottom of the floor and for fire extinguishing, a bowl full of water was kept and the water pump, a model for fire extinguisher was immersed in it. This is how the simulation of the project was done in hardware implementation for real-life and real-time demonstration.

## Impact
The project has many environmental and societal benefits such as,  
A) Automation: This helped to ease human life and especially elderly people and children to turn on and off appliances without any effort.  
B) Energy Saving: Since this project senses light intensity and human presence, it prevents the unnecessary switching of fan and light in the room.  
C) Ensuring Safety: Safety of the people has been ensured as fire and gas leakage are the two topmost fatal accidents occurring in modern day buildings due to man-made errors and mistakes.

## Challenges
a) A proper static human sensor was not available. So, a thorough investigation had to be done.  
b) The static human sensor used was not compatible with Arduino UNO due to its BAUD rate. For this reason, ESP 32 had to be used.  
c) Some of the components caused the system not to function properly and so faulty equipment had to be tested out and troubleshooted.

