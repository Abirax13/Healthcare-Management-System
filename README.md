# 🏥 Healthcare Management System

This is a **console-based Healthcare Management System** developed in **C**.
It is designed to help small to medium-sized healthcare facilities manage **administrative** and **clinical data** efficiently.
The system uses **file handling** to store data, ensuring it is **self-contained and portable**.

---

## ✨ Features

* **Role-Based Access Control (RBAC)**: Different levels of access for three user types:

  * **Administrator**: Full access to all features, including user management and data backup.
  * **Doctor**: Manages patient records, prescriptions, and test results.
  * **Receptionist**: Handles patient registration, appointments, and test reports.

* **Patient Management**: Add, view, update, search for, and delete patient records.

* **Doctor Management**: Add, view, and delete doctor profiles.

* **Appointment & Prescription**: Schedule appointments and create prescriptions for patients.

* **Lab Management**: Order and record medical test results, and generate patient reports.

* **File-Based Data Storage**: All data is stored in simple text files (`.txt`), so no external database is required.

---

## 📂 Files

* `main.c` → Main source code file for the entire application
* `hdata.txt` → Stores patient data
* `ddata.txt` → Stores doctor data
* `login.txt` → Stores user login credentials
* `adata.txt` → Stores appointment details
* `presdata.txt` → Stores prescription information
* `tdata.txt` → Stores patient test data

---

## 🚀 Getting Started

### Prerequisites

* A C compiler (e.g., **GCC**, **MinGW**)

### Compilation

```bash
gcc main.c -o hms.exe
```

### Running the Application

```bash
./hms.exe
```

---

## 🖥️ How to Use

The application is **menu-driven**. Follow the on-screen prompts to navigate the system and perform various tasks.

---

## 🔐 Default Credentials

For initial testing, the following default credentials are provided:

**Administrator**

* User ID: `admin`
* Password: `adminpass123`

**Doctor**

* User ID: `dsmith`
* Password: `docpass123`

**Receptionist**

* User ID: `reception`
* Password: `recpass123`
