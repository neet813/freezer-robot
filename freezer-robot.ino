#include <WiFi.h>
#include <WebServer.h>
#include <Preferences.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

WebServer server(80);
Preferences prefs;

const char* ssid = "FreezerList";
const char* password = "12345678";

const int MAX_ITEMS = 10;
String names[MAX_ITEMS];
String dates[MAX_ITEMS];

String esc(String s) {
  s.replace("&", "&amp;");
  s.replace("<", "&lt;");
  s.replace(">", "&gt;");
  s.replace("\"", "&quot;");
  return s;
}

void loadItems() {
  prefs.begin("freezer", false);
  for (int i = 0; i < MAX_ITEMS; i++) {
    names[i] = prefs.getString(("n" + String(i)).c_str(), "");
    dates[i] = prefs.getString(("d" + String(i)).c_str(), "");
  }
  prefs.end();
}

void saveItem(int i, String n, String d) {
  prefs.begin("freezer", false);
  prefs.putString(("n" + String(i)).c_str(), n);
  prefs.putString(("d" + String(i)).c_str(), d);
  prefs.end();
}

void removeItem(int i) {
  prefs.begin("freezer", false);
  prefs.remove(("n" + String(i)).c_str());
  prefs.remove(("d" + String(i)).c_str());
  prefs.end();
}

int firstEmpty() {
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (names[i].length() == 0) return i;
  }
  return -1;
}


void updateDisplay() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  int count = 0;
  int itemIndices[MAX_ITEMS];

  for (int i = 0; i < MAX_ITEMS; i++) {
    if (names[i].length() > 0) {
      itemIndices[count] = i;
      count++;
    }
  }

  unsigned long now = millis();
  int eyeState = (now / 500) % 4;

  if (eyeState == 3) {
    display.drawLine(52, 6, 58, 6, SSD1306_WHITE);
  } else {
    display.drawCircle(55, 6, 3, SSD1306_WHITE);
  }

  if (eyeState == 3) {
    display.drawLine(70, 6, 76, 6, SSD1306_WHITE);
  } else {
    display.drawCircle(73, 6, 3, SSD1306_WHITE);
  }

  if (count == 0) {
    drawCenteredText("(empty)", 16);
  } else {
    int page = (now / 3000) % count;
    int idx = itemIndices[page];

    String name1 = names[idx];
    if (name1.length() > 16) name1 = name1.substring(0, 16);
    drawCenteredText(name1, 10);

    String expiry1 = "E:" + dates[idx];
    if (expiry1.length() > 16) expiry1 = expiry1.substring(0, 16);
    drawCenteredText(expiry1, 22);
  }

  display.display();
}

String pageHTML() {
  String p = "";
  p += "<!DOCTYPE html><html><head>";
  p += "<meta name='viewport' content='width=device-width,initial-scale=1'>";
  p += "<title>Freezer List</title>";
  p += "<style>";
  p += "body{font-family:Arial,sans-serif;background:#f4f7fb;margin:0;padding:0;color:#102033}";
  p += ".header{padding:24px 16px;background:#2563eb;color:#fff}";
  p += ".header h1{margin:0;font-size:28px}";
  p += ".header p{margin:6px 0 0;font-size:14px;opacity:.9}";
  p += ".wrap{max-width:720px;margin:0 auto;padding:16px}";
  p += ".panel{background:#fff;border-radius:16px;padding:16px;margin-top:-10px;box-shadow:0 6px 20px rgba(0,0,0,.08)}";
  p += "input,button{width:100%;font-size:16px;padding:12px;border-radius:12px;margin:6px 0;box-sizing:border-box;border:none}";
  p += "input{background:#f8fafc;border:1px solid #dbe2ea}";
  p += "button{background:#2563eb;color:#fff;font-weight:700}";
  p += ".cards{margin-top:16px;display:grid;gap:12px}";
  p += ".card{background:#fff;border-radius:16px;padding:16px;box-shadow:0 6px 20px rgba(0,0,0,.08)}";
  p += ".item{font-size:20px;font-weight:700;margin-bottom:6px}";
  p += ".date{color:#6b7280;font-size:14px;margin-bottom:12px}";
  p += ".actions{display:grid;grid-template-columns:1fr 1fr;gap:8px}";
  p += "a.btn{display:block;text-align:center;text-decoration:none;border-radius:12px;padding:12px 10px;color:#fff;font-weight:700;font-size:15px}";
  p += "a.edit{background:#16a34a}";
  p += "a.del{background:#dc2626}";
  p += ".empty{text-align:center;color:#6b7280;padding:24px 10px;font-size:15px}";
  p += "</style></head><body>";
  p += "<div class='header'><div class='wrap'><h1>Freezer List</h1><p>OLED updates automatically.</p></div></div>";
  p += "<div class='wrap'><div class='panel'>";
  p += "<form action='/add' method='POST'>";
  p += "<input name='name' placeholder='Item name' required>";
  p += "<input name='date' placeholder='Expiry date' required>";
  p += "<button type='submit'>Add Item</button>";
  p += "</form></div>";
  p += "<div class='cards'>";
  bool any = false;
  for (int i = 0; i < MAX_ITEMS; i++) {
    if (names[i].length() > 0) {
      any = true;
      p += "<div class='card'>";
      p += "<div class='item'>" + esc(names[i]) + "</div>";
      p += "<div class='date'>Expiry: " + esc(dates[i]) + "</div>";
      p += "<div class='actions'>";
      p += "<a class='btn edit' href='/edit?id=" + String(i) + "'>Edit</a>";
      p += "<a class='btn del' href='/delete?id=" + String(i) + "' onclick=\"return confirm('Delete?')\">Delete</a>";
      p += "</div></div>";
    }
  }
  if (!any) {
    p += "<div class='empty'>No items yet.</div>";
  }
  p += "</div></div></body></html>";
  return p;
}

String editHTML(int id) {
  String p = "<!DOCTYPE html><html><head>";
  p += "<meta name='viewport' content='width=device-width,initial-scale=1'>";
  p += "<title>Edit</title>";
  p += "<style>";
  p += "body{font-family:Arial;background:#f4f7fb;margin:0;padding:16px}";
  p += ".card{background:#fff;border-radius:16px;padding:18px;box-shadow:0 6px 20px rgba(0,0,0,.08)}";
  p += "input,button,a{width:100%;font-size:16px;padding:12px;border-radius:12px;margin:8px 0;box-sizing:border-box;border:none}";
  p += "input{background:#f8fafc;border:1px solid #dbe2ea}";
  p += "button{background:#2563eb;color:#fff;font-weight:700}";
  p += "a{text-decoration:none;text-align:center;background:#e5e7eb;color:#102033;font-weight:700}";
  p += "</style></head><body>";
  p += "<div class='card'><h2>Edit</h2>";
  p += "<form action='/update' method='POST'>";
  p += "<input type='hidden' name='id' value='" + String(id) + "'>";
  p += "<input name='name' value='" + esc(names[id]) + "' required>";
  p += "<input name='date' value='" + esc(dates[id]) + "' required>";
  p += "<button type='submit'>Save</button>";
  p += "</form><a href='/'>Back</a></div></body></html>";
  return p;
}

void handleRoot() { server.send(200, "text/html", pageHTML()); }
void handleAdd() {
  String n = server.arg("name");
  String d = server.arg("date");
  int i = firstEmpty();
  if (i >= 0) { names[i] = n; dates[i] = d; saveItem(i, n, d); }
  server.sendHeader("Location", "/");
  server.send(303);
}
void handleEdit() {
  int id = server.arg("id").toInt();
  if (id < 0 || id >= MAX_ITEMS || names[id].length() == 0) { server.send(404, "text/plain", "Not found"); return; }
  server.send(200, "text/html", editHTML(id));
}
void handleUpdate() {
  int id = server.arg("id").toInt();
  if (id >= 0 && id < MAX_ITEMS) { names[id] = server.arg("name"); dates[id] = server.arg("date"); saveItem(id, names[id], dates[id]); }
  server.sendHeader("Location", "/");
  server.send(303);
}
void handleDelete() {
  int id = server.arg("id").toInt();
  if (id >= 0 && id < MAX_ITEMS) { removeItem(id); names[id] = ""; dates[id] = ""; }
  server.sendHeader("Location", "/");
  server.send(303);
}


void drawCenteredText(String text, int y) {
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(text, 0, 0, &x1, &y1, &w, &h);
  int x = (SCREEN_WIDTH - w) / 2;
  display.setCursor(x, y);
  display.print(text);
}

void setup() {
  Serial.begin(115200);
  delay(100);

  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED failed");
  } else {
    display.clearDisplay();
    display.display();
  }

  loadItems();

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  server.on("/", handleRoot);
  server.on("/add", HTTP_POST, handleAdd);
  server.on("/edit", HTTP_GET, handleEdit);
  server.on("/update", HTTP_POST, handleUpdate);
  server.on("/delete", HTTP_GET, handleDelete);

  server.begin();

  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
  server.handleClient();
  updateDisplay();
}
