# Lab 7-3: Custom ESP32 Components (Sensor + Display)

## คำอธิบาย
การทดลองนี้แสดงการสร้าง component ใหม่ด้วยคำสั่ง `idf.py create-component`
สร้าง 2 components:
1. **Sensor Component** - อ่านค่า temperature, humidity และคำนวณ heat index
2. **Display Component** - แสดงผลข้อมูลในรูปแบบตาราง

## โครงสร้างโฟลเดอร์หลังใช้ create-component
lab7-3_esp32_Component/
├── CMakeLists.txt
├── components/
│   ├── sensor/
│   │   ├── CMakeLists.txt
│   │   ├── include/
│   │   │   └── sensor.h
│   │   └── sensor.c
│   └── display/
│       ├── CMakeLists.txt
│       ├── include/
│       │   └── display.h
│       └── display.c
├── main/
│   ├── CMakeLists.txt
│   └── lab7-3.c
├── build/
└── README.md

## ผลลัพธ์ที่คาดหวัง
- แสดงข้อความการเริ่มต้น sensor และ display components
- แสดงข้อมูล temperature และ humidity
- คำนวณและแสดง heat index
- แสดงข้อมูลในรูปแบบตารางผ่าน display component
- แสดงสถานะความปลอดภัยตามค่า heat index

## ความแตกต่างจาก Lab อื่นๆ
- **Lab 7-1**: ใช้ local component (โฟลเดอร์ components ของ project)
- **Lab 7-2**: ใช้ managed component จาก GitHub URL
- **Lab 7-3**: สร้าง component ใหม่ด้วย `idf.py create-component` (2 components ในโฟลเดอร์ components/)

## ข้อดีของการใช้โฟลเดอร์ components/
1. **การจัดระเบียบ** - แยก components ออกจาก main application
2. **การทำงานเป็นทีม** - แต่ละคนสามารถรับผิดชอบ component ต่างกันได้
3. **GitHub Collaboration** - ง่ายต่อการ review code และ merge
4. **Modularity** - component สามารถนำไปใช้ใน project อื่นได้
5. **ESP-IDF Standard** - เป็นมาตรฐานของ ESP-IDF project

## การใช้งาน
1. สร้าง components ด้วยคำสั่ง `idf.py create-component`
2. แก้ไขไฟล์ CMakeLists.txt, .h และ .c ของแต่ละ component
3. เขียน main application ที่เรียกใช้ทั้ง 2 components
4. Build และทดสอบด้วย QEMU
