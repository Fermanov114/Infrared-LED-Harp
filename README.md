# Infrared LED Electronic Harp 🎵

An Arduino-based interactive musical instrument that uses **infrared LEDs and photodiodes** to simulate harp strings. When an object blocks the IR beam (like plucking a string), the system plays the corresponding musical note.

---

## 🔧 Features

- Safe alternative to traditional laser harps using **invisible IR beams**
- 8-note musical scale (C4 to C5)
- Two play modes: **Chord simulation** and **Arpeggio**
- Visual LED feedback
- Fully implemented using Arduino Nano, IR sensors, and speaker

---

## 🖼️ How It Works

Each “string” consists of:

- An **infrared LED emitter**
- A **photodiode** as receiver
- A **normal LED** and Arduino pin for signal feedback

When a finger blocks the beam:

- The photodiode detects a voltage drop
- Arduino registers a digital LOW
- Corresponding note is played through speaker
- LED turns off as visual cue

### 🎼 Modes

- `CHORD_MODE = 1`: Simulates a chord by rapidly switching between notes
- `CHORD_MODE = 0`: Plays notes sequentially (arpeggio) depending on motion pattern

---

## 💻 How to Run

### 🔋 Hardware Requirements

- Arduino Nano or Uno  
- 8× Infrared LEDs  
- 8× Photodiodes  
- 8× Indicator LEDs  
- Resistors: 1kΩ and 10kΩ  
- Speaker  
- 4.5V external power supply  
- Arduino IDE installed

### ⚙️ Setup Instructions

```bash
git clone https://github.com/Fermanov114/Infrared-LED-Harp.git
Open the .ino file (e.g. main.ino) in Arduino IDE

Connect all components as shown in the circuit diagram (see schematics/)

Upload the code to your Arduino Nano board

Power the circuit using a 4.5V external supply

Pluck the “strings” (i.e., block the IR beams) to produce musical notes

You may toggle between modes in the code:

Set CHORD_MODE = 1 for chord simulation (rapid sequential notes)

Set CHORD_MODE = 0 for arpeggio mode (notes played one by one)

Set DEBUG_MODE = 1 to print sensor values to Serial Monitor

📐 Circuit Overview
Transmitter Side:
8 Infrared LEDs connected in parallel

A single 30Ω resistor in series

Powered by a 4.5V battery pack

Receiver Side:
8 sets of:

Infrared photodiode

Normal LED for visual cue

10kΩ resistor

Each set connected to one of the Arduino digital input pins D2–D9

Output:
Speaker connected to D12

Note generation uses tone() function from Arduino standard libraries

📁 File Structure
File/Folder	Description
main.ino	Main Arduino program file
pitches.h	Definitions for musical note frequencies
report/	Full project report in PDF format
schematics/	Circuit diagrams and design references

🔬 Experimental Results
Functionality: The IR harp successfully detects blocked beams and produces corresponding notes

Modes: Both chord simulation and arpeggio work as expected

Stability: Minor interference observed due to scattered IR light

Safety: Compared to laser harps, IR-based design is safe and eye-friendly

⚠️ Known Limitations
IR LEDs are invisible, alignment can be challenging during assembly

The speaker can only play one tone at a time, so chords are simulated

Interference between IR beams may reduce sensitivity; shielding is recommended

Current code is designed for 8 notes only (C4–C5)

🚀 Future Improvements
Add MIDI output for professional audio integration

Replace the speaker with a digital synthesizer module

Implement adjustable pitch or octave switching

Improve signal isolation using IR filters or housing

👥 Contributors
This project was developed as part of a Year 2 electrical engineering course at the University of Liverpool.

Supervisor: Dr. Naser Sedghi

📄 License
This project is released for educational and non-commercial purposes.
Feel free to fork and adapt. Please credit the authors when appropriate.

🙏 Acknowledgements
University of Liverpool — Department of Electrical Engineering and Electronics

Dr. Naser Sedghi — for project supervision

Arduino community — for open-source libraries and documentation






红外电子竖琴 🎵
这是一个基于 Arduino 的交互式电子乐器，使用红外发光二极管与光电二极管模拟竖琴琴弦。当手指挡住红外光束（如拨动琴弦）时，系统播放对应的音符。

🔧 项目特色
使用不可见红外线替代激光，更安全

实现 C4 至 C5 八音音阶

两种演奏模式：和弦模拟 & 琶音演奏

LED 灯实时反馈

基于 Arduino Nano 完整实现

🖼️ 工作原理
每根“琴弦”由以下组件组成：

一枚红外 LED（发射端）

一枚光电二极管（接收端）

一枚普通 LED 作为提示

当红外光束被遮挡：

光电二极管检测不到信号

Arduino 播放对应音符

提示灯熄灭，提供视觉反馈

🎼 模式说明
CHORD_MODE = 1：模拟和弦（快速轮流播放多音）

CHORD_MODE = 0：琶音演奏（按顺序播放）

💻 运行方法
📦 所需组件
Arduino Nano 或 Uno

红外 LED ×8

光电二极管 ×8

普通 LED ×8

电阻（1kΩ、10kΩ）

扬声器 ×1

外部电源（4.5V）

Arduino IDE 编程环境

⚙️ 运行步骤
bash
复制
编辑
git clone https://github.com/Fermanov114/Infrared-LED-Harp.git
在 Arduino IDE 中打开 .ino 文件

上传程序至 Arduino

按电路图连接所有元件

给系统供电

用手“拨动”红外琴弦开始演奏！

📐 电路说明
发射端：8 个红外 LED 并联 + 30Ω 串联电阻

接收端：8 组接收模块（光电二极管 + LED + 10kΩ 电阻）连接至 D2–D9

扬声器：连接至 Arduino 的 D12 引脚

📁 项目结构
文件 / 文件夹	内容说明
main.ino	主控制程序
pitches.h	音符频率定义
report/	项目完整文档（PDF）
schematics/	电路图
