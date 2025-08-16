# 🏥 Healthcare Management System

A **console-based Healthcare Management System** developed in **C**.  
This project is designed to help small to medium-sized healthcare facilities manage **administrative** and **clinical data** efficiently.  
It uses **file handling** to store data, making the system **self-contained and portable**.

---

## ✨ Features

- 🔑 **Role-Based Access Control (RBAC):**
  - **Administrator**: Full access, user management, and data backup.
  - **Doctor**: Manage patient records, prescriptions, and test results.
  - **Receptionist**: Handle patient registration, appointments, and test reports.

- 👩‍⚕️ **Patient Management**: Add, view, update, search, and delete patient records.
- 🧑‍⚕️ **Doctor Management**: Add, view, and delete doctor profiles.
- 📅 **Appointments & Prescriptions**: Schedule appointments and create prescriptions.
- 🧪 **Lab Management**: Order, record, and view medical test results.
- 📂 **File-Based Data Storage**: Data stored in `.txt` files — no external DB required.

---

## 📂 Project Files

- `main.c` → Main source code file
- `hdata.txt` → Patient data
- `ddata.txt` → Doctor data
- `login.txt` → User login credentials
- `adata.txt` → Appointment details
- `presdata.txt` → Prescription information
- `tdata.txt` → Patient test data

---

## 🚀 Getting Started

### 🔧 Prerequisites
- A **C compiler** (e.g., GCC, MinGW)

### ⚙️ Compilation
```bash
gcc main.c -o hms.exe
