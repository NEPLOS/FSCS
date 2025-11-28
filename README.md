# FSCS — From Scratch Cloud Server

FSCS is a **multi-phase, from-scratch cloud server project** written in C++.  
The goal is to build a fully self-hosted cloud platform with **HTTP handling, storage, database integration , etc...**, entirely from scratch, without relying on prebuilt frameworks (well except MySQL... i dont want to build an entire database engine from scratch).

This repository is an **ongoing work in progress**.  

---

## 🔹 Project Vision

FSCS aims to be a personal cloud server that supports:

- HTTP request parsing and routing
- Dynamic routes with parameter extraction
- MySQL database interaction
- File handling and storage
- Multi-phase expansion into a full cloud server platform
- And also encryption, can't go anywhere without it

This is a **LEARNING-FOCUSED project**, experimenting with modern C++ and server architecture.

---

## 📂 Project Structure

```
.
├── include
│   ├── inc.h
│   ├── MySql.h
│   ├── request.h
│   ├── router.h
│   └── trie.h
├── lib
├── Makefile
├── output
├── README.md
└── src
    ├── main.cpp
    ├── MySql.cpp
    ├── request.cpp
    ├── router.cpp
    └── trie.cpp

```


---

## 🔹 Current Phase

FSCS is currently building the **foundational backend components**, including:

- **HTTP request parsing and routing**  
  - Handles static and dynamic routes with parameter extraction  
- **MySQL database integration**  
  - Basic connection and query execution (will integrate with routing later)  
- **Single-threaded server**  
  - Fully functional for now...almost; demonstrates that routing works and can be tested via a browser
  - Handles requests sequentially, leaving room to expand to multi-threaded or async in the future
- **Multi-phase architecture**  
  - Designed to grow into a complete cloud server platform  

Example usage:

```cpp
Router router;

// Static route
router.addRoute(GET, "/home/setting", [](auto& params) {
    std::cout << "GET /home/setting\n";
});

// Dynamic route
router.addRoute(GET, "/home/{param}", [](auto& params) {
    std::cout << "Dynamic param: " << params["param"] << "\n";
});

// Same dynamic route with different method
router.addRoute(POST, "/home/{param}", [](auto& params) {
    std::cout << "Dynamic param: " << params["param"] << " , Method: Post" << "\n";
});

```
