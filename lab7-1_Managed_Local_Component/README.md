# Lab 7-1: Local Component Demo

## คำอธิบาย
การทดลองนี้แสดงการใช้งาน component ที่มีอยู่ในโฟลเดอร์ `components/` ของ project โดยประกอบด้วย `Sensors` component และ `Display` component ที่สร้างขึ้นมาใหม่

## สรุปคำสั่งที่ใช้ และผลลัพธ์ที่ได้

ในการทดลองนี้ เราได้ทำตามขั้นตอนต่างๆ เพื่อสร้างและใช้งาน Local Components ในโปรเจค ESP-IDF ซึ่งสามารถสรุปได้ดังนี้

### 1. การเตรียมโครงสร้างโปรเจคและ Component
- สร้างโฟลdeอร์สำหรับโปรเจคและ components ตามโครงสร้างที่กำหนด:
  ```bash
  # สร้างโฟลเดอร์ components และโปรเจคหลัก
  mkdir Lab-07-ESP32-Components\components
  mkdir Lab-07-ESP32-Components\components\Sensors
  mkdir Lab-07-ESP32-Components\components\Display
  mkdir Lab-07-ESP32-Components\lab7-1_Managed_Local_Component
  mkdir Lab-07-ESP32-Components\lab7-1_Managed_Local_Component\main
  ```
- สร้างไฟล์ source code (.c, .h) และ `CMakeLists.txt` สำหรับ component `Sensors` และ `Display` รวมถึงไฟล์ของโปรเจค `lab7-1`

### 2. การตั้งค่าและ Build โปรเจค
- แก้ไขไฟล์ `docker-compose.yml` เพื่อเปลี่ยนชื่อ container เป็น `esp32-lab7` เพื่อไม่ให้ซ้ำซ้อน
- เริ่มการทำงานของ Docker container:
  ```bash
  cd Lab-07-ESP32-Components
  docker-compose up -d
  ```
- **Build ครั้งแรก (ล้มเหลว):** เมื่อสั่ง build ครั้งแรก พบ error `fatal error: sensor.h: No such file or directory` เนื่องจากโปรเจคยังไม่รู้จักตำแหน่งของ component
- **แก้ไข Build:** เพิ่ม `set(EXTRA_COMPONENT_DIRS "../components")` ในไฟล์ `lab7-1_Managed_Local_Component/CMakeLists.txt` เพื่อระบุตำแหน่งของ external components
- **Build ครั้งที่สอง (สำเร็จ):** หลังจากแก้ไข `CMakeLists.txt` แล้ว โปรเจคสามารถ build ได้สำเร็จ

### 3. การทำโจทย์ท้าทาย (Challenge)
- สร้าง `Display` component ขึ้นมาใหม่ในโฟลเดอร์ `components/Display`
- แก้ไขไฟล์ `main/lab7-1.c` ให้มีการเรียกใช้งาน `sensor_init()`, `display_init()`, `sensor_read_data()` และ `display_update()` เพื่อแสดงการทำงานร่วมกันของทั้งสอง components
- **Build ครั้งสุดท้าย (สำเร็จ):** หลังจากเพิ่ม `Display` component เข้าไป พบว่าต้องใช้คำสั่ง `idf.py fullclean` เพื่อล้างค่าเก่าของ build ก่อน จากนั้นจึงสั่ง `idf.py build` อีกครั้ง ซึ่งทำให้โปรเจค build ผ่านและทำงานได้อย่างสมบูรณ์

### ผลลัพธ์สุดท้าย
โปรเจคสามารถ build ได้สำเร็จ โดยมีการเรียกใช้งานฟังก์ชันจากทั้ง `Sensors` และ `Display` component ที่อยู่ในโฟลเดอร์ `components/` ภายนอกโปรเจคหลัก ซึ่งแสดงให้เห็นถึงความเข้าใจในการจัดการและใช้งาน Local Components ใน ESP-IDF
