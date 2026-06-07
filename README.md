# 🤖 Freezer Robot: A Tiny Companion for Your Fridge

**A smart OLED display device that tracks what's in your freezer and stops you from wasting food.**

---

## 🤔 **The Problem (Why I Built This)**

I kept forgetting what I had in my fridge.

One day, I found:
- **Litchi gone moldy** (₹200 wasted)
- **Syrup, jam, peanut butter** sitting there for months
- **Opening the fridge hoping nothing's inside** (but there always was)

Every time I'd buy groceries, I'd forget what I already had. **Food waste = money wasted.**

I'm not alone. Students living alone, busy professionals, anyone who cooks irregularly—we all have this problem.

**So I asked:** What if there was a tiny robot on my fridge that showed me what's inside? Something cute, something that actually helps?

---

## ✨ **The Solution**

**Freezer Robot** = A 0.96" OLED screen + ESP32 microcontroller that:
- 📋 Displays your fridge contents on a tiny screen
- 🤖 Shows a cute happy robot face when you open it
- 🔄 Cycles through items automatically (every 2 seconds)
- 📱 Add/remove items from your phone (web interface)
- 💾 Saves everything locally (survives power loss)
- 🧲 Sticks to your fridge with magnets

**The idea:** Check the screen before you buy groceries or cook. Reduce waste. Save money.

---

## 🛠️ **What I Used**

### **Hardware:**
| Component | Cost | Why |
|-----------|------|-----|
| ESP32 Dev Board (WiFi + Bluetooth) | ₹250 | Brain of the device |
| 0.96" OLED Display (I2C SSD1306) | ₹200 | Tiny, crisp screen |
| 3.7V LiPo Battery (1000mAh) | ₹299 | Powers without USB cable |
| TP4056 Charging Module | ₹55 | Safe battery charging |
| Jumper Wires (male-to-female) | ₹50 | Connections |
| Push Button (12mm) | ₹6 | Wake/sleep device |
| Magnetic Squares | ₹33 | Stick to fridge |
| **Total** | **~₹900** | One-time cost |

### **Software:**
- Arduino IDE (free)
- Adafruit GFX + SSD1306 libraries (free)
- C++ embedded code (no external dependencies)

---

## 📦 **How to Build It**

### **Step 1: Wire the OLED to ESP32**

```
OLED Pins → ESP32 Pins
GND      → GND
VCC      → 3.3V
SCL      → GPIO 22
SDA      → GPIO 21
```

Use jumper wires. Take your time, check twice.

### **Step 2: Flash the Code**

1. Download Arduino IDE
2. Install ESP32 board package
3. Install Adafruit GFX + SSD1306 libraries
4. Copy the code (see below)
5. Upload to ESP32
6. Done!

### **Step 3: Connect to WiFi**

1. From your phone, connect to WiFi: **FreezerList**
2. Password: **12345678**
3. Open browser: **192.168.4.1**
4. Add your first item!

### **Step 4: Mount on Fridge**

1. Glue magnetic squares to back
2. Stick on fridge at eye level
3. Plug in USB power (or battery when ready)
4. Start adding items

---

## 💻 **The Code**

Full Arduino sketch is in the GitHub repo: [neet813/freezer-robot](https://github.com/neet813/freezer-robot)

**Key features:**
- WiFi hotspot (no internet needed)
- Web interface for add/edit/delete
- Carousel display (2 items per page, cycles every 2 seconds)
- Happy robot face greeting
- Data persists on device (flash memory)
- Battery-safe sleep mode (ready for button integration)

---

## 🎯 **How to Use It**

1. **Add items:** Open phone browser → 192.168.4.1 → type item + expiry date → done
2. **Check status:** Glance at OLED screen on fridge
3. **Before shopping:** Check the device → don't buy duplicates
4. **Delete items:** Mark as used when empty → removed from display

---

## 📊 **Results (First Month Testing)**

- ✅ Reduced impulse grocery shopping (checked device first)
- ✅ Found 2 forgotten condiments before they went bad
- ✅ Actually smiled at the little robot face
- ✅ Easier than opening fridge "just to check"

**Estimated savings:** ₹500-1000/month (stopped wasting forgotten food)

---

## 🚀 **Next Steps**

### **Short term:**
- [x] Get ESP32 + OLED working
- [x] Build web interface
- [x] Test for 2+ weeks
- [ ] Add battery + charging
- [ ] Add wake button (battery lasts 2-3 weeks)
- [ ] Make cute case (3D printed)

### **Long term:**
- Better personalities (different emotions/faces)
- Motion sensor (lights up when you open fridge)
- Expiry countdown warnings
- Shopping list sync
- Multi-user support

---

## 🧠 **What I Learned**

1. **Hardware is fun** (and less stressful than web apps sometimes)
2. **Constraints force creativity** (0.96" screen = minimal design)
3. **Solve your own problem first** (then others might want it)
4. **Document as you build** (future you will thank you)
5. **Test with real usage** (don't assume it's useful)

---

## 📁 **Project Structure**

```
freezer-robot/
├── README.md (this file)
├── freezer-robot.ino (main code)
├── parts-list.md (component shopping list)
├── wiring-diagram.md (how to connect everything)
├── build-guide.md (step-by-step instructions)
└── photos/ (build process images)
```

---

## 🙋 **Questions?**

- **How much does it cost?** ~₹900 initial investment
- **How long to build?** 2-3 hours (wiring + code upload + testing)
- **Does it need WiFi?** No, it creates its own hotspot
- **How long does battery last?** 5-7 days (currently USB powered for testing)
- **Can I customize it?** Yes! Full code is open source

---

## 🎨 **Why Build This?**

Because I was tired of:
- Opening the fridge hoping nothing's inside
- Forgetting what I bought last week
- Wasting money on food that rots
- Building web apps that felt soulless

Instead, I built something **small, physical, and actually useful.**

If you have the same problem, build your own. It's easier than you think.

---

## 📚 **Resources Used**

- [Random Nerd Tutorials - ESP32 OLED](https://randomnerdtutorials.com/esp32-ssd1306-oled-display-arduino-ide/)
- [Adafruit GFX Documentation](https://learn.adafruit.com/adafruit-gfx-graphics-library)
- [Arduino Official Docs](https://www.arduino.cc/reference/en/)

---

## 📸 **Photos**

[Add photos of:
- The breadboard prototype
- OLED showing items
- Mounted on fridge
- Phone interface
- Close-up of happy robot face
]

---

## 🤝 **Want to Build One?**

1. Fork this repo
2. Follow the build guide
3. Add your own personality
4. Share your version!

**Tag me:** [@just_nav.neet](https://instagram.com/just_nav.neet) (I'd love to see your builds!)

---

## 📝 **License**

Open source. Do whatever you want with it. Build, share, sell, modify.

Just remember: solve a real problem, document your journey, and share it with the world.

---

**Built with ❤️ by Navneet** | June 2026 | First Hardware Project
