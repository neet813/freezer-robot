# 🛒 Freezer Robot - Parts List & Shopping Guide

## Complete Component List

### **Essential Components**

| # | Component | Quantity | Approx Cost (₹) | Amazon Search | Notes |
|---|-----------|----------|------------------|---------------|-------|
| 1 | ESP32 Dev Module (WROOM-32) | 1 | ₹250 | "ESP32 wifi development board" | Dual core, WiFi + Bluetooth |
| 2 | 0.96" OLED Display (SSD1306 I2C) | 1 | ₹200 | "0.96 inch OLED display I2C" | 128x32 pixels, crisp display |
| 3 | Jumper Wires (Male-Female 40 pack) | 1 | ₹50 | "jumper wires male female 40" | Reusable, use 4 for OLED |
| 4 | 3.7V LiPo Battery (1000mAh) | 1 | ₹299 | "3.7v 1000mAh lithium polymer battery" | Model 402535P recommended |
| 5 | TP4056 Charging Module | 1 | ₹55 | "TP4056 USB charging module" | Micro USB input, overcharge protection |
| 6 | Push Button (12mm) | 1 | ₹6 | "12mm tactile push button switch" | Get 10-pack, use 1 |
| 7 | Magnetic Strips/Squares | 1 | ₹33 | "adhesive magnet tape" or "neodymium magnetic squares" | To stick on fridge |
| **TOTAL** | | | **~₹900** | | One-time investment |

---

## Optional Components (Add Later)

| Component | Cost | Why | When to Buy |
|-----------|------|-----|-------------|
| Micro USB Cable | ₹30-50 | Charging cable for battery module | If not included with TP4056 |
| Plastic Case/Box | ₹200-500 | Protect components, look finished | After 2-week testing period |
| 3D Printed Case | ₹200-400 | Custom-designed enclosure | If you have access to 3D printer |
| Motion Sensor (PIR) | ₹200-300 | Light up when fridge opens | Future enhancement |
| Breadboard | ₹50-100 | For prototyping (optional) | If you don't have one |

---

## Amazon Shopping Links (India)

### **Recommended Sellers:**

**ESP32:**
- Search: `ESP32 Dev Module`
- Price: ₹200-300
- Brands: SquadPixel, Robocraze, UNIVERSAL HUB

**OLED Display:**
- Search: `0.96 OLED I2C display`
- Price: ₹150-250
- Look for: SSD1306 controller, I2C interface

**Battery + Charging:**
- Battery: `3.7V 1000mAh lithium polymer`
- Charging Module: `TP4056 USB charging`
- Total for both: ₹300-400

**Jumper Wires:**
- Search: `jumper wires male female 40 pack`
- Price: ₹40-80
- Get 40-piece set (you'll have extras)

**Magnetic Strips:**
- Search: `adhesive magnet tape` or `magnetic squares`
- Price: ₹100-150
- Either strips or individual squares work

---

## Cost Breakdown

```
Essential Cost Analysis:
┌─────────────────────────┬──────────┐
│ Component               │ Cost (₹) │
├─────────────────────────┼──────────┤
│ ESP32                   │   250    │
│ OLED Display            │   200    │
│ Jumper Wires            │    50    │
│ Battery (LiPo)          │   299    │
│ Charging Module         │    55    │
│ Push Button             │     6    │
│ Magnetic Strips         │    33    │
├─────────────────────────┼──────────┤
│ TOTAL                   │   893    │
└─────────────────────────┴──────────┘

Compared to alternatives:
- Smart fridge thermometer: ₹2000-5000
- Pre-built IoT device: ₹1500-3000
- DIY solution: ₹900 ✓ (cheapest!)
```

---

## Shopping Tips

### **Best Practices:**

1. **Check seller ratings** (aim for 4+ stars)
2. **Read reviews** (especially for batteries - quality matters)
3. **Compare prices** (same component, different sellers)
4. **Bundle deals** (Amazon sometimes offers 10% off when buying 2+ items)
5. **Check delivery dates** (some take 2-3 weeks)

### **Bulk vs Individual:**

- **Push buttons:** Get 10-pack (only need 1, extras for future projects)
- **Jumper wires:** Get 40-pack (reusable, you'll use them again)
- **Magnets:** Get set of 12 (backup + extras)

### **Quality Matters:**

- ✅ **Batteries:** Buy from trusted brands (UNIVERSAL HUB, Robocraze, SquadPixel)
- ✅ **TP4056:** Authentic modules (look for "Overcharge Protection" label)
- ✅ **OLED:** Must be I2C SSD1306 (not parallel interface)
- ✅ **ESP32:** Buy from reputable sellers (counterfeits exist)

---

## Pre-Order Checklist

Before ordering, verify:

- [ ] ESP32 is "WROOM-32" or "Dev Module" variant
- [ ] OLED is "0.96 inch" with "I2C" interface (not SPI)
- [ ] Battery is "3.7V" (not 5V) and "1000mAh+" capacity
- [ ] TP4056 has "Micro USB" input (not mini USB)
- [ ] All items are in stock (check delivery dates)
- [ ] Seller has good reviews (4+ stars)

---

## Expected Delivery (June 2026 India)

- Standard delivery: 3-7 days
- Express delivery: 1-2 days
- Free delivery available on most items

**Total time from order to building:** ~1 week

---

## Troubleshooting If Components Don't Match

**If your OLED display doesn't work:**
- Make sure it's **SSD1306 I2C** (not SPI)
- Check if it needs address `0x3C` or `0x3D` (code handles both)

**If battery doesn't fit:**
- 1000mAh is standard size (about 5cm long)
- If too big, use smaller 500mAh (less runtime though)

**If button doesn't work:**
- 12mm tactile switches are universal (any brand works)
- Make sure it's "normally open" (most common type)

---

## Already Have Some Components?

Skip and don't re-order:
- ✅ Have jumper wires? Don't buy again
- ✅ Have USB cable? TP4056 might come with one
- ✅ Have a breadboard? Not essential but helpful

---

## Total Time to First Build

- **Shopping:** 1-2 days (order online)
- **Delivery:** 3-7 days
- **Building:** 2-3 hours
- **Testing:** Start immediately after!

**Total:** ~1 week from start to working prototype

---

## Pro Tips for Ordering

1. **Bundle items from same seller** (faster delivery, might get discount)
2. **Order all at once** (don't order in batches - wastes time)
3. **Save seller links** (for future Arduino projects)
4. **Check return policy** (in case something arrives broken)
5. **Join Arduino communities** (local Maker spaces might have spare parts)

---

## Need Help Identifying Components?

If you're unsure which product to buy:
1. Search on Amazon India
2. Look at the product photos (shows actual component)
3. Read 3-5 reviews (people mention what they used it for)
4. Check "Specifications" tab (voltage, current, interface)

---

**Ready to order? 🛒**

Go to Amazon, search each component above, and add to cart. Total should be around ₹900.

Once delivered, come back for the wiring guide!
