# Mbed Heating Tank Monitor
## Summary
The purpose of this project is to develop a monitoring system for a heating tank in an industrial process and simulate this using the Mbed simulator. This tank consists of two sensors, one for temperature and the other for level. Furthermore, there are four output states that must be detected, each triggering a different audible status tone:

**1. Tank is full, temperature too high (upper third of temperature range)**: two-tone

**2. Tank is full, temperature is good (middle third of temperature range)**: steady continuous tone

**3. Tank is full, temperature too low (lower third of temperature range)**: single beeping tone

**4. Tank level is too low (tank less than three quarters full), any temperature**: frequency-modulated “warble” tone, flashing LED

## Project Setup
These are the components used to allow the project to run successfully.
<p align="center">
  <img src="Images/Demo.png" width="1000">
</p>
<p align="center">
Figure 3: Components added for the Mbed machine control system.
</p>

- **p5**: LED used to indicate the tank level is too low
- **p15**: Potentiometer for the tank temperature
- **p16**: Potentiometer for the tank level
- **p21**: Speaker used to generate the appropriate sound signals