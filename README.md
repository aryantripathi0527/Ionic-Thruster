# Ionic-Thruster
⚡ Servo‑Controlled Ionic Thruster (EHD)
An experimental ionic (electrohydrodynamic) thruster prototype that generates thrust using high electric fields instead of fuel or combustion.
The system uses servo‑controlled electrode geometry driven by an ESP32‑S3 microcontroller.
🔬 Concept
High voltage ionizes air near the aluminium (+) electrode
Ions accelerate toward the copper (–) electrode
Ion motion transfers momentum to air → ionic wind → thrust
F = q E
E = V/d
F=qE,E=V/d
This is an atmospheric EHD propulsion system (not a space ion engine).
🎮 Control System
ESP32‑S3 microcontroller
3 servo motors
Joystick input
Servos dynamically adjust electrode angle and gap, enabling real‑time control of:
Thrust magnitude
Direction
Electric field strength
🧩 Hardware
ESP32‑S3
High‑voltage power supply
Aluminium (+) electrode
Copper (–) electrode
3 × Servos
Joystick module
⚠️ Safety
⚠️ Uses high voltage.
Operate with proper insulation and grounding.
📌 Notes
No combustion
No propellant tank
No moving propellers
Works only in air
