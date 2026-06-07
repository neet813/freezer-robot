# 🤖 Freezer Robot

A tiny smart companion for your fridge that helps you track what’s inside, avoid duplicate shopping, and reduce food waste.

## Why I Built This

I kept forgetting what was already in my fridge.

One day, I found:
- Litchi gone moldy after wasting money.
- Syrup, jam, and peanut butter sitting there for months.
- Myself opening the fridge hoping there was nothing inside — but there always was.

Every time I went grocery shopping, I’d forget what I already had. That meant buying duplicates, wasting food, and wasting money.

So I built **Freezer Robot**: a small fridge-mounted device that shows what’s inside, lets me manage items from my phone, and makes the whole process a little more fun.

## What It Does

Freezer Robot is built with an **ESP32** and a **0.96" OLED display**. It:

- Displays fridge/freezer items on a tiny screen.
- Shows a cute robot face when running.
- Cycles through stored items automatically.
- Lets you add, edit, and delete items from your phone.
- Saves data locally, so it survives power loss.
- Creates its own Wi‑Fi hotspot, so no internet is needed.

The idea is simple: check the screen before you cook or shop, and waste less food.

## Features

- Wi‑Fi hotspot with no internet required.
- Mobile-friendly web interface.
- Add, edit, and delete items.
- Local flash storage using ESP32 Preferences.
- OLED display for quick glance information.
- Cute robot-style face animation.
- Compact fridge-mountable design.

## Hardware

| Component | Quantity | Unit Price | Total | Purpose |
|-----------|----------|------------|-------|---------|
| ESP32 Dev Board (Wi‑Fi + Bluetooth) | 1 | ₹650 | ₹650 | Main controller |
| 0.96" OLED Display (I2C SSD1306) | 1 | ₹200 | ₹200 | Tiny display |
| 3.7V LiPo Battery (1000mAh) | 1 | ₹299 | ₹299 | Portable power |
| TP4056 Charging Module | 1 | ₹55 | ₹55 | Battery charging |
| Jumper Wires Pack | 1 | ₹150 | ₹150 | Wiring |
| Push Button Pack | 1 | ₹59 | ₹59 | Wake/sleep / future controls |
| Magnetic Squares Pack | 1 | ₹399 | ₹399 | Mounting on fridge |
| Delivery Fees | - | - | ₹150 | Shipping |

### Estimated Cost

- **Minimum viable build:** around **₹1200–₹1300**
- **My actual cost:** around **₹2000** because I bought extra parts, spares, and multiple deliveries for future projects.

## Wiring

### OLED to ESP32

| OLED Pin | ESP32 Pin |
|----------|-----------|
| GND | GND |
| VCC | 3.3V |
| SCL | GPIO 22 |
| SDA | GPIO 21 |

Use jumper wires and double-check the connections before powering on.

## How to Build It

### 1. Install the tools
- Download Arduino IDE.
- Install the ESP32 board package.
- Install **Adafruit GFX** and **Adafruit SSD1306** libraries.

### 2. Wire the hardware
- Connect the OLED to the ESP32 using the wiring table above.
- If using battery power later, connect the charging module carefully.

### 3. Upload the code
- Open the `.ino` file in Arduino IDE.
- Select your ESP32 board.
- Select the correct port.
- Upload the sketch.

### 4. Connect to the hotspot
- On your phone, connect to **FreezerList**.
- Password: **12345678**
- Open the web page in your browser and start adding items.

### 5. Mount it on the fridge
- Stick magnetic squares to the back.
- Place it at eye level.
- Power it with USB or battery.

## How to Use It

1. Open the web page from your phone.
2. Add an item name and expiry date.
3. Check the OLED screen before shopping or cooking.
4. Edit or delete items when used up.

## Results

After testing it for a month, I noticed:

- Less impulse grocery shopping.
- Fewer forgotten condiments.
- A nicer habit of checking the fridge list first.
- A surprisingly fun little robot face on the door.

Estimated savings: **₹500–₹1000 per month** from reduced wasted food.

## What I Learned

- Hardware can be fun and surprisingly satisfying.
- Small constraints force better design.
- Solving your own problem first is a great way to build something useful.
- Documentation matters.
- Testing with real use is more valuable than guessing.
- Using AI as a coding and writing assistant is just using a tool well.

## Future Ideas

- Better robot expressions.
- Motion sensor support.
- Expiry countdown warnings.
- Shopping list sync.
- Multi-user support.
- Battery optimization and sleep mode.
- A cleaner 3D-printed case.

## Project Structure

```text
freezer-robot/
├── README.md
├── freezer-robot.ino
├── PARTS.md
├── WIRING.md
└── photos/
```

## FAQ

### How much does it cost?
About **₹2000** with extras, or around **₹1200–₹1300** for a basic version.

### How long does it take to build?
Roughly **2–3 hours** for wiring, uploading, and testing.

### Does it need Wi‑Fi?
No. It creates its own hotspot.

### How long does the battery last?
Around **5–7 days** in its current form, depending on usage and power setup.

### Can I customize it?
Yes. The project is open source and easy to adapt.

## Why Build This?

Because I was tired of:
- Opening the fridge just to check.
- Forgetting what I bought last week.
- Wasting food that could have been used.
- Building software that felt less physical and less personal.

I wanted to make something small, useful, and fun.

## Resources

- [Random Nerd Tutorials - ESP32 OLED](https://randomnerdtutorials.com/esp32-ssd1306-oled-display-arduino-ide/)
- [Adafruit GFX Documentation](https://learn.adafruit.com/adafruit-gfx-graphics-library)
- [Arduino Official Docs](https://www.arduino.cc/reference/en/)

## Photos

Add photos of:
- The breadboard prototype.
- OLED showing items.
- Mounted on the fridge.
- The phone interface.
- Close-up of the robot face.

## License

Open source. Use it, modify it, share it, and build your own version.

Built with ❤️ by Navneet | June 2026 | First Hardware Project
