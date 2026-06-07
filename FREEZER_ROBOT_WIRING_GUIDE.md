# ⚡ Freezer Robot - Wiring Guide & Setup Instructions

## 🔌 Hardware Wiring Diagram

### **OLED Display to ESP32 (I2C Connection)**

```
OLED 0.96" Display Pins → ESP32 Pins
━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
GND (Ground)         → GND (any GND pin)
VCC (Power)          → 3.3V (or 5V - display accepts both)
SCL (Clock)          → GPIO 22
SDA (Data)           → GPIO 21
```

**What this means:**
- GND = Ground (black wire)
- VCC = Power (red wire)
- SCL = Data Clock (yellow wire)
- SDA = Data Signal (blue wire)

---

### **Battery to Charging Module to ESP32**

```
LiPo Battery (2 wires)
    ↓
TP4056 Charging Module
    ├─ Micro USB Input (connect to power adapter)
    ├─ B+ (Battery +) → Keep on charging module
    ├─ B- (Battery -) → Keep on charging module
    ├─ OUT + → ESP32 5V (or 3.3V with regulator)
    └─ OUT - → ESP32 GND

ESP32
    ├─ VIN (5V input)
    ├─ GND (ground)
    └─ Connects to charging module OUT
```

---

### **Push Button to ESP32 (Optional - Add Later)**

```
Push Button (2 pins)
    ├─ Pin 1 → GPIO 4 (Data pin)
    └─ Pin 2 → GND (Ground)
```

---

## 📋 Step-by-Step Wiring Instructions

### **Phase 1: OLED Display Connection (Required First)**

**You'll need:**
- ESP32 dev board
- 0.96" OLED I2C display
- 4 jumper wires (male-to-female)

**Steps:**

1. **Identify OLED pins** (look at the back/side of the display)
   - Find: GND, VCC, SCL, SDA
   - Mark with tape if hard to see

2. **Connect wires:**
   ```
   OLED GND → Breadboard Column (if using) or direct to ESP32 GND
   OLED VCC → Breadboard positive rail or direct to ESP32 3.3V
   OLED SCL → Jumper wire to ESP32 GPIO 22
   OLED SDA → Jumper wire to ESP32 GPIO 21
   ```

3. **Double-check before powering:**
   - [ ] GND to GND (black wire)
   - [ ] VCC to 3.3V (red wire)
   - [ ] SCL to GPIO 22
   - [ ] SDA to GPIO 21
   - [ ] No wires touching each other
   - [ ] No wires loose/disconnected

4. **Plug in USB cable to ESP32**
5. **Upload code** (see software section below)
6. **Check OLED lights up** (should show text immediately)

---

### **Phase 2: Battery Connection (After OLED Works)**

**You'll need:**
- 3.7V LiPo battery
- TP4056 charging module
- Jumper wires or solder
- USB cable

**Steps:**

1. **Connect LiPo to TP4056:**
   - Battery + (red) → B+ pin on TP4056
   - Battery - (black) → B- pin on TP4056
   - *(Use JST connector if your battery has one, or solder carefully)*

2. **Connect TP4056 to ESP32:**
   - TP4056 OUT+ → ESP32 VIN (5V pin)
   - TP4056 OUT- → ESP32 GND

3. **Plug micro USB into TP4056:**
   - Charging starts immediately
   - Red LED = charging, Blue LED = charged

4. **Test it:**
   - Unplug USB from ESP32
   - OLED should still work (powered by battery!)
   - If it doesn't: check TP4056 output, resolder connections

---

### **Phase 3: Button Connection (Optional - Add When Ready)**

**You'll need:**
- 12mm push button
- 2 jumper wires
- Optional: 10kΩ resistor (if button is flaky)

**Steps:**

1. **Connect button:**
   ```
   Button Pin 1 → GPIO 4
   Button Pin 2 → GND
   ```

2. **Buttons usually have 4 pins but only 2 work:**
   - Diagonal pins are connected (test with multimeter if unsure)
   - Just use any 2 pins, if button doesn't work, try the other 2

3. **Upload updated code** (with button logic)
4. **Press button:**
   - Device wakes up
   - Shows greeting
   - Auto-sleeps after 1 minute

---

## 💻 Software Setup

### **Step 1: Install Arduino IDE**

1. Go to [arduino.cc/en/software](https://www.arduino.cc/en/software)
2. Download Arduino IDE
3. Install on your computer

### **Step 2: Add ESP32 Board Package**

1. Open Arduino IDE
2. Go to **File → Preferences**
3. Find "Additional Boards Manager URLs"
4. Paste this URL:
   ```
   https://dl.espressif.com/dl/package_esp32_index.json
   ```
5. Click OK
6. Go to **Tools → Boards → Boards Manager**
7. Search for "ESP32"
8. Click install on "esp32 by Espressif Systems"
9. Wait 2-3 minutes

### **Step 3: Install Required Libraries**

1. Go to **Sketch → Include Library → Manage Libraries**
2. Search and install:
   - `Adafruit GFX Library` (by Adafruit)
   - `Adafruit SSD1306` (by Adafruit)
3. Click install for each
4. Wait for completion

### **Step 4: Select Board Settings**

1. **Tools → Board → ESP32 Dev Module**
2. **Tools → Port → COM... (your port)**
3. **Tools → Upload Speed → 921600**
4. **Tools → Partition Scheme → Default (OTA)**

### **Step 5: Upload Code**

1. Copy the complete code from `freezer-robot.ino`
2. Paste into Arduino IDE (replace everything)
3. Click **Upload** (right arrow button)
4. Wait for "Hash of data verified"

### **Step 6: Check Serial Output (Optional)**

1. **Tools → Serial Monitor**
2. Set speed to **115200**
3. Press reset button on ESP32
4. Should see:
   ```
   AP IP: 192.168.4.1
   ```

---

## 📱 Using the Device

### **Connect from Phone:**

1. **WiFi:** Open WiFi settings on phone
2. **Network:** Look for "FreezerList"
3. **Password:** `12345678`
4. **Open browser:** Go to `192.168.4.1`
5. **Add item:** Type name + expiry date
6. **Watch OLED:** Updates in real-time

### **What You Should See:**

```
First 2 seconds:
╔══════════════════╗
║ Yo, See What's   │
║      Fresh!      │
╚══════════════════╝

Next 2 seconds:
╔══════════════════╗
║ Milk             │
║ Exp: 5 July      │
╚══════════════════╝

Next 2 seconds:
╔══════════════════╗
║ Cheese           │
║ Exp: 8 July      │
╚══════════════════╝

(Repeats...)
```

---

## 🔍 Troubleshooting

### **OLED Shows Nothing (Black Screen)**

**Causes & Fixes:**

1. **Wrong wires:**
   - [ ] Check GND is connected
   - [ ] Check VCC has power
   - [ ] Swap SCL/SDA (sometimes mislabeled on display)

2. **I2C Address mismatch:**
   - Code assumes address `0x3C`
   - If display is address `0x3D`, change code line:
   ```cpp
   // Change this line:
   if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
   // To:
   if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) {
   ```

3. **Display not powered:**
   - [ ] Check 3.3V actually goes to VCC pin
   - [ ] Use multimeter to test voltage (3.2V ± 0.5V is OK)

4. **Library not installed:**
   - [ ] Verify Adafruit SSD1306 is installed
   - [ ] Restart Arduino IDE after install

---

### **Can't Connect to WiFi "FreezerList"**

**Causes & Fixes:**

1. **Code didn't upload successfully:**
   - Check serial monitor for errors
   - Try uploading again

2. **ESP32 isn't creating hotspot:**
   - [ ] Press reset button on ESP32
   - [ ] Wait 5 seconds
   - [ ] Check WiFi list again

3. **Wrong password:**
   - [ ] WiFi password is `12345678` (exactly)
   - [ ] No spaces

---

### **Can't Open 192.168.4.1**

**Causes & Fixes:**

1. **Not connected to FreezerList WiFi:**
   - Disconnect from other WiFi first
   - Connect to FreezerList

2. **Wrong address:**
   - Try `192.168.4.1` exactly (not without the .1)
   - Try in incognito/private mode (clears cache)

3. **ESP32 not running:**
   - Check USB cable is connected
   - Check "AP IP: 192.168.4.1" appears in Serial Monitor

---

### **Button Doesn't Work**

1. **Button might be wired wrong:**
   - Buttons have 4 pins in a square
   - Diagonal pins are connected
   - Try the other diagonal pair

2. **GPIO 4 might be conflicting:**
   - Try a different pin (GPIO 5, 13, 15)
   - Update code: `#define BUTTON_PIN 5`

3. **Loose wire:**
   - Reseat the button in breadboard
   - Check jumper wire connection

---

### **Battery Doesn't Charge**

1. **TP4056 LEDs:**
   - [ ] Red LED = charging (normal)
   - [ ] Blue LED = fully charged (normal)
   - [ ] No LED = check power cable

2. **Check connections:**
   - [ ] USB cable plugged into TP4056 (not ESP32)
   - [ ] Battery wires connected to B+/B- (not OUT+/OUT-)

3. **Battery might be dead:**
   - Try 30 seconds first charge
   - If no LEDs appear, battery might be bad

---

## 📐 Wiring Checklist (Before Powering On)

- [ ] All GND wires connected to GND
- [ ] All VCC wires connected to 3.3V
- [ ] SCL connected to GPIO 22
- [ ] SDA connected to GPIO 21
- [ ] No loose wires touching each other
- [ ] No metal parts touching (short circuit risk)
- [ ] USB cable about to be inserted
- [ ] OLED display sitting safely (not falling off)

---

## 🎯 First Power-On Checklist

1. **Plug USB into ESP32**
2. **Check:** OLED lights up (might take 2 seconds)
3. **Check:** WiFi "FreezerList" appears in phone
4. **Check:** Can access `192.168.4.1` in browser
5. **Check:** Can add an item
6. **Check:** OLED updates with your item

**If all 5 pass:** You're done! Device is working! 🎉

---

## Common Mistakes (Don't Do These!)

❌ **Don't:**
- Mix up 3.3V and 5V (some OLED displays fail with 5V)
- Leave GND disconnected (ground everything!)
- Use 5V logic pins with 3.3V display
- Solder while circuit is powered
- Ignore the small text on component labels

✅ **Do:**
- Double-check wire colors before plugging in
- Use a multimeter to verify voltages
- Take a photo of working setup (for reference)
- Keep spare jumper wires (they break sometimes)
- Document your pin connections

---

## Need Help?

1. **Check Serial Monitor** (Tools → Serial Monitor, set to 115200)
2. **Google the error** (most ESP32 issues are documented)
3. **Restart Arduino IDE** (fixes 50% of problems)
4. **Unplug/Replug USB** (fixes another 25%)
5. **Check solder joints** if you soldered anything

---

**You're ready to build!** 🚀

Next step: Order components, wait for delivery, then follow this guide.

Good luck! 🤖
